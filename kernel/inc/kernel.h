#include <stdint.h>

#ifndef THREAD_H
#define THREAD_H
/* Constants */
#define NUM_OF_CALEE_REGS 8
#define TOTAL_THREADS 3
#define Stacksize     100
/* macro to switch state */
#define SWITCH_STATE __asm(
            "CPSID   I\n" 
            "PUSH    {r4-r11}\n"
            "MOV     r1,sp\n"
            "MOV     r0,lr\n"
            "BL      Context_Switch\n"
            "POP     {r4-r11}\n"
            "BX      r0\n"
            "CPSIE   I" 
        ); 
#define EN_Intr __asm("CPSIE   I") ;
#define DI_Intr __asm("CPSID   I") ;

// Task control block is implemented as a linked list 
typedef struct tcb { 
  char *taskName ;
  void ( * funcPtr ) (void) ;
  uint8_t priority ;
  uint32_t state ;
  int32_t *stackPtr ;
  uint32_t StackLimit ;
  uint32_t calleeRegs[NUM_OF_CALEE_REGS] ;
  uint32_t pc ;
  uint32_t lr ;
  tcb *nextThreadPtr ; // for iterating through different tasks
  uint32_t timeout ;
  uint8_t threadID ;
} tcb

tcb currentTcb ;
void OS_init (void) ;
void OS_start (void) ;

uint32_t Context_Switch (uint32_t lr , uint32_t calleRegs ) ;



#endif /*THREAD_H*/ 
