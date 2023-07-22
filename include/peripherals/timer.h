
#ifndef _TIMER_H_
#define _TIMER_H_

#include "peripherals/pbase.h"
#include <stdint.h>

struct __attribute__((packed)) timer_regs {
  volatile uint32_t cs;
  volatile uint32_t clo;
  volatile uint32_t chi;
  volatile uint32_t c0;
  volatile uint32_t c1;
  volatile uint32_t c2;
  volatile uint32_t c3;
};

#define TIMER_BASE (PBASE + 0x00003000)
#define TIMER_REGS (*(struct timer_regs*)TIMER_BASE)

#endif
