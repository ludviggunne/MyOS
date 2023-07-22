
#ifndef _EXCEPTION_H_
#define _EXCEPTION_H_

#define SYNC_E1T      0
#define IRQ_E1T       1
#define FIQ_E1T       2
#define SERROR_E1T    3
#define SYNC_E1H      4
#define IRQ_E1H       5
#define FIQ_E1H       6
#define SERROR_E1H    7
#define SYNC_E0_64    8
#define IRQ_E0_64     9
#define FIQ_E0_64    10
#define SERROR_E0_64 11
#define SYNC_E0_32   12
#define IRQ_E0_32    13
#define FIQ_E0_32    14
#define SERROR_E0_32 15

#ifndef __ASSEMBLER__

void irq_mask();
void irq_unmask();

#endif

#endif
