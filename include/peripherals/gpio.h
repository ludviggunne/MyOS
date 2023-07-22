
#ifndef _GPIO_H_
#define _GPIO_H_

#include "peripherals/pbase.h"
#include <stdint.h>

struct __attribute__((packed)) gpio_regs {
  volatile uint32_t gpfsel0;
  volatile uint32_t gpfsel1;
  // . . .
  volatile uint8_t  _padding[0xe4 - 0x08]; // TODO: add regs
  // . . .
  volatile uint32_t gpio_pup_pdn_cntrl_reg0;
};

#define GPIO_BASE (PBASE + 0x00200000)
#define GPIO_REGS (*(struct gpio_regs*)GPIO_BASE)
#endif
