
/*
    Exception Vector Table (EL1)
*/

.globl evtable_init
.globl evtable

.macro  entry   label
.balign 0x80
b       \label
.endm

.macro  unimplemented_handler  type   id
\type:
    mov     x0, #\id
    mrs     x1, elr_el1
    bl      unimpl_handler_err
    b       spin_core
.endm

evtable_init:
    adr       x0, evtable
    msr       vbar_el1, x0
    ret

evtable:
    entry     IRQ_Handler_E1t
    entry     FIQ_Handler_E1t
    entry     SError_Handler_E1t
    entry     Sync_Handler_E1t

    entry     IRQ_Handler_E1h
    entry     FIQ_Handler_E1h
    entry     SError_Handler_E1h
    entry     Sync_Handler_E1h

    entry     IRQ_Handler_E0_64
    entry     FIQ_Handler_E0_64
    entry     SError_Handler_E0_64
    entry     Sync_Handler_E0_64

    entry     IRQ_Handler_E0_32
    entry     FIQ_Handler_E0_32
    entry     SError_Handler_E0_32
    entry     Sync_Handler_E0_32

unimplemented_handler IRQ_Handler_E1t        0
unimplemented_handler FIQ_Handler_E1t        1
unimplemented_handler SError_Handler_E1t     2
unimplemented_handler Sync_Handler_E1t       3

unimplemented_handler IRQ_Handler_E1h        4
unimplemented_handler FIQ_Handler_E1h        5
unimplemented_handler SError_Handler_E1h     6
unimplemented_handler Sync_Handler_E1h       7

unimplemented_handler IRQ_Handler_E0_64      8
unimplemented_handler FIQ_Handler_E0_64      9
unimplemented_handler SError_Handler_E0_64  10
unimplemented_handler Sync_Handler_E0_64    11

unimplemented_handler IRQ_Handler_E0_32     12
unimplemented_handler FIQ_Handler_E0_32     13
unimplemented_handler SError_Handler_E0_32  14
unimplemented_handler Sync_Handler_E0_32    15
