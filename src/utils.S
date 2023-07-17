
.globl get_exception_level
.globl spin_core

get_exception_level:
    mrs     x0, CurrentEL
    lsr     x0, x0, #2
    ret

spin_core:
    b       spin_core
