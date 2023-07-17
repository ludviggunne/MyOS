
#ifndef _EL1_ENTRY_
#define _EL1_ENTRY_

// Disable MMU & caches for EL1
#define EL1_ENTRY_SCTLR_EL1 (0)

// Set execution state to aarch64
#define EL1_ENTRY_HCR_EL2 (1 << 31)

// Use EL1h and mask interrupts
#define EL1_ENTRY_SPSR_EL2 ((7 << 6) | (5 << 0)) 

#endif
