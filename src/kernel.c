
#include "uart.h"
#include "printf.h"
#include "utils.h"

void kmain()
{
  uart_init();

  while (1) {
    printf("Current Exception Level: %d\n\r", get_exception_level());
    delay(1000000);
  }
}
