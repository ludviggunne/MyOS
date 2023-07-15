
# Toolchain
PREFIX   = aarch64-linux-gnu
CC       = $(PREFIX)-gcc
OBJCOPY  = $(PREFIX)-objcopy
LD       = $(PREFIX)-ld
OBJDUMP  = $(PREFIX)-objdump
NM       = $(PREFIX)-nm

CFLAGS   = -Wall -nostdlib -nostartfiles -ffreestanding -mgeneral-regs-only
DEFINES  = -DPRINTF_DISABLE_SUPPORT_FLOAT

BUILD_DIR = build
SRC_DIR   = src
INCLUDE   = include

CSRC   = $(wildcard $(SRC_DIR)/*.c)
ASMSRC = $(wildcard $(SRC_DIR)/*.S)
OBJS   = $(CSRC:$(SRC_DIR)/%.c=$(BUILD_DIR)/%_c.o)
OBJS  += $(ASMSRC:$(SRC_DIR)/%.S=$(BUILD_DIR)/%_s.o)


default: kernel8.img

# Produce kernel image
kernel8.img: $(BUILD_DIR)/kernel8.elf
	$(OBJCOPY) $(BUILD_DIR)/kernel8.elf -O binary kernel8.img

# Link kernel
$(BUILD_DIR)/kernel8.elf: linker.ld $(OBJS)
	$(LD) -T linker.ld -o $(BUILD_DIR)/kernel8.elf $(OBJS)

# Compile C files
$(BUILD_DIR)/%_c.o: $(SRC_DIR)/%.c
	mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -I$(INCLUDE) $(DEFINES) -c $< -o $@

# Compile assembly files
$(BUILD_DIR)/%_s.o: $(SRC_DIR)/%.S
	mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -I$(INCLUDE) -c $< -o $@


.PHONY: clean objdump nm transfer console

clean:
	rm -rf $(BUILD_DIR) *.img

objdump:
	$(OBJDUMP) $(BUILD_DIR)/kernel8.elf -tS

nm:
	$(NM) $(BUILD_DIR)/kernel8.elf -n

transfer:
	mount /dev/sdb1 mount
	cp kernel8.img config.txt mount
	sync
	umount mount

console:
	screen /dev/ttyUSB0 115200
