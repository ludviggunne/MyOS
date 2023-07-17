
#include "el1_entry.h"

.section ".text.boot"

.globl _start

_start:
    // Halt non primary cores
    mrs     x0, mpidr_el1
    and     x0, x0, #0xFF
    cmp     x0, #0x00
    beq     main_core
    b       spin_core


main_core:

    // Transition from EL2 to EL1
    ldr     x0, =EL1_ENTRY_SCTLR_EL1
    msr     sctlr_el1, x0

    ldr     x0, =EL1_ENTRY_HCR_EL2
    msr     hcr_el2, x0

    ldr     x0, =EL1_ENTRY_SPSR_EL2
    msr     spsr_el2, x0

    adr     x0, el1_entry
    msr     elr_el2, x0

    eret


el1_entry:
    // Setup stack
    ldr     x0, =__kernel_begin
    mov     sp, x0

    // Zero uninitialized data
    ldr     x0, =__bss_begin
    ldr     x1, =__bss_end
    bl      memzero64

    // Init exception vector table 
    bl      evtable_init

    bl      kmain
    b       spin_core
