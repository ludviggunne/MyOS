
#include "peripherals/uart.h"
#include "peripherals/irq_cntl.h"
#include "peripherals/timer.h"
#include "exception.h"
#include "printf.h"
#include "utils.h"
#include "clock.h"

#define INTERVAL TIMER_FREQ

void timer_init()
{
  // enable timer interrupt 1
  IRQ_REGS.irq0_set_en_0 |= 0b0010;

  // init timer 1
  TIMER_REGS.c1 = TIMER_REGS.clo + INTERVAL;

  // unmask (all) interrupts
  irq_unmask();
}

void handle_irq_el1h()
{
  
  printf("Timer interrupt triggered!\n\r");

  // update offset
  TIMER_REGS.c1 += INTERVAL;

  // reset interrupt request line
  TIMER_REGS.cs |= (1 << 1);
}

void kmain()
{
  uart_init();
  printf("\n\r --- RESET --- \n\r");

  timer_init();
  while (1) {
  }
}
