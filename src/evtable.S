
/*
    Exception Vector Table (EL1)
*/

#include "exception.h"

.globl evtable_init
.globl evtable


.macro  evtentry   label
b       \label
.balign 0x80
.endm


.macro unimplemented_handler type
excep_begin
mov     x0, #\type
mrs     x1, elr_el1
mrs     x2, esr_el1
bl      unimpl_handler_err
excep_end
.endm


// Push registers x0-x30 to stack
.altmacro
.macro push_regs m=0, n=1
stp     x\m, x\n, [sp, #-16]!
.if 28-\m
push_regs %m+2, %n+2
.else
str     x30, [sp, #-16]!
.endif
.endm


// Pop registers x0-x30 from stack
.altmacro
.macro pop_regs m=30, n=31
.if m==30
ldr     x30, [sp], #16
pop_regs %m-2, %n-2
.else
.if n>0
ldp     x\m, x\n, [sp], #16
pop_regs %m-2, %n-2   
.endif
.endif
.endm


// Call when entering exception handler
.macro excep_begin
push_regs
.endm


// Call when exiting exception handler
.macro excep_end
pop_regs
eret
.endm


evtable_init:
    adr       x0, evtable
    msr       vbar_el1, x0
    ret

.align 11
evtable:
    evtentry     Sync_Handler_E1t
    evtentry     IRQ_Handler_E1t
    evtentry     FIQ_Handler_E1t
    evtentry     SError_Handler_E1t

    evtentry     Sync_Handler_E1h
    evtentry     IRQ_Handler_E1h
    evtentry     FIQ_Handler_E1h
    evtentry     SError_Handler_E1h

    evtentry     Sync_Handler_E0_64
    evtentry     IRQ_Handler_E0_64
    evtentry     FIQ_Handler_E0_64
    evtentry     SError_Handler_E0_64

    evtentry     Sync_Handler_E0_32
    evtentry     IRQ_Handler_E0_32
    evtentry     FIQ_Handler_E0_32
    evtentry     SError_Handler_E0_32


Sync_Handler_E1t:
    unimplemented_handler SYNC_E1T

IRQ_Handler_E1t:
    unimplemented_handler IRQ_E1T

FIQ_Handler_E1t:
    unimplemented_handler FIQ_E1T

SError_Handler_E1t:
    unimplemented_handler SERROR_E1T

Sync_Handler_E1h:
    unimplemented_handler SYNC_E1H

IRQ_Handler_E1h:
    unimplemented_handler IRQ_E1H

FIQ_Handler_E1h:
    unimplemented_handler FIQ_E1H

SError_Handler_E1h:
    unimplemented_handler SERROR_E1H

Sync_Handler_E0_64:
    unimplemented_handler SYNC_E0_64

IRQ_Handler_E0_64:
    unimplemented_handler IRQ_E0_64

FIQ_Handler_E0_64:
    unimplemented_handler FIQ_E0_64

SError_Handler_E0_64:
    unimplemented_handler SERROR_E0_64

Sync_Handler_E0_32:
    unimplemented_handler SYNC_E0_32

IRQ_Handler_E0_32:
    unimplemented_handler IRQ_E0_32

FIQ_Handler_E0_32:
    unimplemented_handler FIQ_E0_32

SError_Handler_E0_32:
    unimplemented_handler SERROR_E0_32
