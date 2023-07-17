
#include "printf.h"
#include <stdint.h>

const char *eherr_strs[] = {

  "IRQ_E1t",
  "FIQ_E1t",
  "SError_E1t",
  "Sync_E1t",
  "IRQ_E1h",
  "FIQ_E1h",
  "SError_E1h",
  "Sync_E1h",
  "IRQ_E0_64",
  "FIQ_E0_64",
  "SError_E0_64",
  "Sync_E0_64",
  "IRQ_E0_32",
  "FIQ_E0_32",
  "SError_E0_32",
  "Sync_E0_32"
};

void unimpl_handler_err(uint64_t type, uint64_t addr)
{
  printf(
    "Unimplemented Exception Handler Error:\n\r"
    "   Type:    %s\n\r"
    "   Address: %p\n\r\n",
    eherr_strs[type], addr);
}
