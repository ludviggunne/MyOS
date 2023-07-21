
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

  AUX_REGS.aux_enables      = 1;                 // enable mini UART
  AUX_REGS.aux_mu_cntl_reg  = 0;                 // disable transmit & recieve, as well as
                                                 //    auto flow control
  AUX_REGS.aux_mu_ier_reg   = 0;                 // disable interrupts
  AUX_REGS.aux_mu_mcr_reg   = 2;                 // set RTS line high
  AUX_REGS.aux_mu_baud_reg  = BAUD_REG_VALUE;    // set 115200 baudrate
  AUX_REGS.aux_mu_lcr_reg   = 3;                 // enable 8-bit mode
  AUX_REGS.aux_mu_cntl_reg |= 3;                 // enable transmit & recieve
}

void uart_write(char c)
{
  while (!(AUX_REGS.aux_mu_lsr_reg & 0x20));
  AUX_REGS.aux_mu_io_reg = c;
}

char uart_read()
{
  while (!(AUX_REGS.aux_mu_lsr_reg & 0x01));
  return AUX_REGS.aux_mu_io_reg & 0xff;
}
