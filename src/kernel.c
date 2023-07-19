
#include "uart.h"
#include "printf.h"
#include "utils.h"


void kmain()
{
  uart_init();
  
  printf("\n\r-----------------------------------------------"
         "-------------------\n\r");
  asm ("svc #0x0");
}
