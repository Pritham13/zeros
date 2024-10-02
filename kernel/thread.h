#include <stdint.h>

#ifndef THREAD_H
#define THREAD_H
/* Macros */ 
#define BIT(x) (1UL << (x))

/* Constants */
#define NUM_OF_CALEE_REGS 8
#define TOTAL_THREADS 3
#define Stacksize     100
#define SYSTICK ((struct systick *) 0xe000e010)

// Task control block is implemented as a linked list 
typedef struct tcb { 
  int32_t *stackPtr ;
  uint32_t StackLimit ;
  uint32_t calleeRegs[NUM_OF_CALEE_REGS] ;
  uint32_t pc ;
  uint32_t lr ;
  tcb *nextThreadPtr ; // for iterating through different tasks
  uint32_t timeout ;
  uint8_t threadID ;
} tcb
// structure to get data on systick registers
struct systick {
  volatile uint32_t CTRL, LOAD, VAL, CALIB;
};


/* Functions declarations */
void systick_init(uint32_t ticks)
  
#endif /*THREAD_H*/ 
