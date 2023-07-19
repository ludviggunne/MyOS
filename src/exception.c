
#include "printf.h"
#include <stdint.h>

const char *eherr_strs[] = {

  "Sync_E1t",
  "IRQ_E1t",
  "FIQ_E1t",
  "SError_E1t",
  "Sync_E1h",
  "IRQ_E1h",
  "FIQ_E1h",
  "SError_E1h",
  "Sync_E0_64",
  "IRQ_E0_64",
  "FIQ_E0_64",
  "SError_E0_64",
  "Sync_E0_32",
  "IRQ_E0_32",
  "FIQ_E0_32",
  "SError_E0_32"
};

void unimpl_handler_err(uint64_t type, uint64_t addr, uint64_t esr)
{
  printf(
    "Unimplemented Exception Handler Error:\n\r"
    "   Type:    %s\n\r"
    "   Address: 0x%p\n\r"
    "   ESR:     0x%p\n\r",
    eherr_strs[type], addr, esr);
}
