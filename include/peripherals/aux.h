#ifndef _AUX_H_
#define _AUX_H_

#include "peripherals/pbase.h"
#include <stdint.h>

struct __attribute__((packed)) aux_regs {
  volatile uint32_t aux_irq;
  volatile uint32_t aux_enables;
  volatile uint8_t  _padding0[0x40 - 0x04 - 0x04];
  volatile uint32_t aux_mu_io_reg;
  volatile uint32_t aux_mu_ier_reg;
  volatile uint32_t aux_mu_iir_reg;
  volatile uint32_t aux_mu_lcr_reg;
  volatile uint32_t aux_mu_mcr_reg;
  volatile uint32_t aux_mu_lsr_reg;
  volatile uint32_t aux_mu_msr_reg;
  volatile uint32_t aux_mu_scratch;
  volatile uint32_t aux_mu_cntl_reg;
  volatile uint32_t aux_mu_stat_reg;
  volatile uint32_t aux_mu_baud_reg;
  // TODO: add more registers
};

#define AUX_BASE (PBASE + 0x00215000)
#define AUX_REGS (*(struct aux_regs*)AUX_BASE)

#endif
