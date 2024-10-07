#include "../inc/kernel.h"
#include "../../main/sysCalls.h"
tcb *currentTcb ;

uint32_t Context_Switch(uint32_t lr , uint32_t caleeRegs ) {
  
  for (int i = 0 ; i < NUM_OF_CALEE_REGS; i++ ) {
    currentTcb -> calleeRegs[i] = caleeRegs[i];
  }
  currentTcb -> lr = lr ;
  currentTcb->stackPtr = __get_PSP() ; // gets the Processor stack Pointer for the current task
  /* Scheduling block to be added later */
  if(currentTcb == tcbThreadA)
    currentTcb = *tcbThreadB ;
  
  else if(currentTcb == tcbThreadB)
    currentTcb = *tcbThreadA ;
  
  else
    return -1 ; // indicates error in the thread will be changed to somethng else

  /* end of Scheduling block */

   for (int i = 0 ; i < NUM_OF_CALEE_REGS; i++ ) {
    caleeRegs[i] = currentTcb -> calleeRegs[i] ;
  }
  /* Set PSP and PSP Limit */
  __set_PSPLIM ((uint32_t)(currentTcb -> stackLimit));
  __set_PSP((uint32_t)(currentTcb -> stackPtr));
  return currentTcb -> lr ;

}

void OS_init (void) { 
  systick_init( ) ; // Systick initialization put the clock value later
  
}
extern __attribute__((naked)) void SysTick_Handler(void) {
  SWITCH_STATE;
}
