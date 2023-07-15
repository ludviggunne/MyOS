
#include "uart.h"
#include "printf.h"
#include "utils.h"

void kmain()
{

  uart_init();
  
  printf("Hello!\n");
}
