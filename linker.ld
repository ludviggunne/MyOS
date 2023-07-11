
SECTIONS
{
  . = 0x80000; /* Kernel Load Address */
  __kernel_begin = .;

  .text.boot  : { KEEP(*(.text.boot)) }
  .rodata     : { *(.rodata) }
  .data       : { *(.data) }

  . = ALIGN(0x8);
  bss_begin = .;
  .bss : { *(.bss) }
  bss_end = .;

  __kernel_end = .;

  "/DISCARD/" : { *(.eh_frame) *(.comment) }
}
