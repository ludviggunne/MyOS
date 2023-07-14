
#include "uart.h"
#include "aux.h"
#include "gpio.h"

#include <stdint.h>

#define CORE_FREQ       ((uint64_t) 500000000)
#define BAUDRATE        ((uint64_t) 115200)
#define BAUD_REG_VALUE  ((uint32_t)(CORE_FREQ / (BAUDRATE * 8) - 1))

void uart_init()
{

  uint32_t reg = *(volatile uint32_t*)GPFSEL1;
  reg &= ~(0b111111 << 12); // clear pin 14 & 15
  reg |=  (0b010010 << 12); // set alt5 func for pin 14 & 15 (TDX1 & RDX1)
  *(volatile uint32_t*)GPFSEL1 = reg;

  *(volatile uint32_t*)
  GPIO_PUP_PDN_CNTRL_REG0 &= 0x0fffffff; // disable pull-up /-down resitors for 
                                         // pins 14 & 15

  *(volatile uint32_t*) AUX_ENABLES      = 1;                 // enable mini UART
  *(volatile uint32_t*) AUX_MU_CNTL_REG  = 0;                 // disable transmit & recieve, as well as
                                                              //    auto flow control
  *(volatile uint32_t*) AUX_MU_IER_REG   = 0;                 // disable interrupts
  *(volatile uint32_t*) AUX_MU_MCR_REG   = 2;                 // set RTS line high
  *(volatile uint32_t*) AUX_MU_BAUD_REG  = BAUD_REG_VALUE;    // set 115200 baudrate
  *(volatile uint32_t*) AUX_MU_LCR_REG   = 1;                 // enable 8-bit mode
  *(volatile uint32_t*) AUX_MU_CNTL_REG |= 3;                 // enable transmit & recieve
}

void uart_write(char c)
{
  while (!(*(volatile uint32_t*)AUX_MU_LSR_REG & 0x20));
  *(volatile uint32_t*)AUX_MU_IO_REG = c;
}

char uart_read()
{
  while (!(*(volatile uint32_t*)AUX_MU_LSR_REG & 0x01));
  return *(volatile uint32_t*)AUX_MU_IO_REG & 0xff;
}
