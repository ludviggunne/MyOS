
#include "uart.h"
#include "printf.h"
#include "utils.h"

void kmain()
{

  uart_init();
  while (1) {
    char c = uart_read();
    printf("You sent: %c\n\r", c);
  }
}
