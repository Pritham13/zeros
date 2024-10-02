#include "thread.h"
tcb *currentTcb ;
void systick_init(uint32_t ticks) {
  if ((ticks - 1) > 0xffffff) return;  // Systick timer is 24 bit
  SYSTICK->LOAD = ticks - 1;
  SYSTICK->VAL = 0;
  SYSTICK->CTRL = BIT(0) | BIT(1) | BIT(2);  // Enable systick
  RCC->APB2ENR |= BIT(14);
}

uint32_t Context_Switch(uint32_t lr , uint32_t caleeRegs ) {
  
  for (int i = 0 ; i < NUM_OF_CALEE_REGS; i++ ) {
    currentTcb -> calleeRegs[i] = caleeRegs[i];
  }

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
  __set_PSPLIM ((uint32_t)(currentContext -> stackLimit));
  __set_PSP((uint32_t)(currentContext -> stackPtr));
  return currentTcb -> lr ;

}

__attribute__((naked)) void SysTick_Handler(void) {
  __asm(
            "CPSID   I\n" 
            "PUSH    {r4-r11}\n"
            "MOV     r1,sp\n"
            "MOV     r0,lr\n"
            "BL      Context_Switch\n"
            "POP     {r4-r11}\n"
            "BX      r0\n"
            "CPSIE   I" 
        ); 
}
