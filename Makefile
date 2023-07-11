
PREFIX   = aarch64-linux-gnu
CC       = $(PREFIX)-gcc
OBJCOPY  = $(PREFIX)-objcopy
LD       = $(PREFIX)-ld
CFLAGS   = -Wall -nostdlib -nostartfiles -ffreestanding -mgeneral-regs-only

BUILD_DIR = build
SRC_DIR   = src

# TODO: Read up on wildcard in make
CSRC   = $(wildcard $(SRC_DIR)/*.c)
ASMSRC = $(wildcard $(SRC_DIR)/*.S)
OBJS   = $(CSRC:$(SRC_DIR)/%.c=$(BUILD_DIR)/%_c.o)
OBJS  += $(ASMSRC:$(SRC_DIR)/%.S=$(BUILD_DIR)/%_s.o)


default: kernel8.img

kernel8.img: $(BUILD_DIR)/kernel8.elf
	$(OBJCOPY) $(BUILD_DIR)/kernel8.elf -O binary kernel8.img

$(BUILD_DIR)/kernel8.elf: linker.ld $(OBJS)
	$(LD) -T linker.ld -o $(BUILD_DIR)/kernel8.elf $(OBJS)

$(BUILD_DIR)/%_c.o: $(SRC_DIR)/%.c
	mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR)/%_s.o: $(SRC_DIR)/%.S
	mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean
clean:
	rm -rf $(BUILD_DIR) *.img
