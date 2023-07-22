
#ifndef _IRQ_CNTL_H_
#define _IRQ_CNTL_H_

#include "peripherals/pbase.h"
#include <stdint.h>

struct __attribute__((packed)) irq_regs {

  volatile uint8_t  _padding0[0x200];

  volatile uint32_t irq0_pending0;
  volatile uint32_t irq0_pending1;
  volatile uint32_t irq0_pending2;

  volatile uint32_t _padding1;

  volatile uint32_t irq0_set_en_0;
  volatile uint32_t irq0_set_en_1;
  volatile uint32_t irq0_set_en_2;

  volatile uint32_t _padding2;

  volatile uint32_t irq0_clr_en_0;
  volatile uint32_t irq0_clr_en_1;
  volatile uint32_t irq0_clr_en_2;

  // TODO: Add more registers
};

#define IRQ_BASE (PBASE + 0x0000B000)
#define IRQ_REGS (*(struct irq_regs*)IRQ_BASE)

#endif
