
#include "peripherals/uart.h"

void _putchar(char character) {

  uart_write(character);
}
