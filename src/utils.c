
#include "utils.h"

void delay(uint64_t t)
{
  while (t--) { asm ( "nop" ); }
}
