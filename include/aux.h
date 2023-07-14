#ifndef _AUX_H_
#define _AUX_H_

#include "pbase.h"

#define AUX_BASE (PBASE + 0x00215000)

#define AUX_ENABLES     (AUX_BASE + 0x04)
#define AUX_MU_IO_REG   (AUX_BASE + 0x40)
#define AUX_MU_IER_REG  (AUX_BASE + 0x44)
#define AUX_MU_MCR_REG  (AUX_BASE + 0x50)
#define AUX_MU_LCR_REG  (AUX_BASE + 0x4c)
#define AUX_MU_LSR_REG  (AUX_BASE + 0x54)
#define AUX_MU_CNTL_REG (AUX_BASE + 0x60)
#define AUX_MU_BAUD_REG (AUX_BASE + 0x68)

#endif
