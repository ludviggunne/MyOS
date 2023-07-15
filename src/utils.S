
.globl get_exception_level

get_exception_level:
    mrs     x0, CurrentEL
    lsr     x0, x0, #2
    ret
