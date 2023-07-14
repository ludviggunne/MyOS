
#include "uart.h"
#include "utils.h"

void uart_write_str(const char *str)
{
  while (*str) {
    uart_write(*str);
    str++;
  }
}

void led_test();

void kmain()
{

  led_test();

  uart_init();
  while (1) {
    delay(100000);
    uart_write_str("Hello!\n\r");
  }
}

#include "gpio.h"
#define GPFSEL0 (GPIO_BASE + 0x00)
#define GPSET0  (GPIO_BASE + 0x1c)
#define GPCLR0  (GPIO_BASE + 0x28)

void led_test()
{
  // set pin 4 as output
  *(volatile uint32_t*)GPFSEL0 &= ~(0b111 << 12);
  *(volatile uint32_t*)GPFSEL0 |=  (0b001 << 12);

  // disable pull up/pull down
  *(volatile uint32_t*)GPIO_PUP_PDN_CNTRL_REG0 &= ~(0b11 << 8);

  int state = 0;
  while (1) {

    if (state) {
      *(volatile uint32_t*)GPSET0 |= (1 << 4);
    } else {
      *(volatile uint32_t*)GPCLR0 |= (1 << 4);
    }

    state = !state;
    delay(1000000);
  }
}
