
#include "uart.h"
#include "printf.h"
#include "utils.h"

void kmain()
{
  uart_init();

  printf("Current Exception Level: %d\n\r", get_exception_level());
  asm ("svc #0");
}
