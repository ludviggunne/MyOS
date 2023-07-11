.section ".text.boot"

.globl _start
_start:
    mrs     x0, mpidr_el1
    and     x0, x0, #0xFF
    cbz     x0, main_core
    b       halt_core

halt_core:
    b       halt_core

main_core:
    adr     x0, bss_begin
    adr     x1, bss_end
//    bl      memzero
    
//    mov     sp, #LOW_MEMORY     // TODO: Define LOW_MEMORY
    bl      kmain
