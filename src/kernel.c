
#include "uart.h"
#include "printf.h"
#include "utils.h"

void kmain()
{

  uart_init();
  printf("Current Exception level: %d", get_exception_level());
}
