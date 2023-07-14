
#ifndef _GPIO_H_
#define _GPIO_H_

#include "pbase.h"

#define GPIO_BASE (PBASE + 0x00200000)

#define GPFSEL1   (GPIO_BASE + 0x04)

#define GPIO_PUP_PDN_CNTRL_REG0 (GPIO_BASE + 0xe4)

#endif
