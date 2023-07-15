
#include "utils.h"

void delay(uint64_t t)
{
  while (t--) { asm ( "nop" ); }
}

void memzero64(uint64_t *begin, uint64_t *end)
{
  while (begin != end) {
    *begin = 0;
    begin++;
  }
}
