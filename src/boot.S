.section ".text.boot"

.globl _start
_start:

    // Halt non primary cores
    mrs     x0, mpidr_el1
    and     x0, x0, #0xFF
    cmp     x0, #0x00
    beq     main_core
    b       halt_core

halt_core:
    b       halt_core

main_core:
    // Zero unini ialized data
    ldr     x0, =__bss_begin
    ldr     x1, =__bss_end

.loop0:
    cmp     x0, x1
    beq     .continue0
    mov     x2, #0
    str     x2, [x0]
    add     x0, x0, #0x08
    b       .loop0

.continue0:
    // Setup stack
    ldr     x0, =__kernel_begin
    mov     sp, x0

    // Transfer to kernel, halt if return
    bl      kmain
    b       halt_core
