#include "../inc/task.h"
#include "../inc/kernel.h"



void create_task (void ( * function_ptr )( void ) , char *taskName , uint8_t priority , uint16_t stackSize ) { 
    DI_Intr ; // disabling interuppts
    
    tcb *newTcb ;
    newTcb = (tcb *) malloc(sizeof(tcb)) ;
    newTcb->taskName = ( char * ) malloc ( 20 );
    memset ( newTcb->taskName, '\0', 20 );
    strcpy ( newTcb->taskName, taskname );
    newTcb -> priority = priority ;
    // newTcb -> stackPtr =   stackSize + THREAD_STACK_SIZE - NORM_STACK_FRAME_SIZE;
    newTcb -> stackPtr = (uint32_t *) malloc(stackSize * sizeof(int32_t)) ;
    newTcb -> funcPtr = function_ptr;
    newTcb -> threadID = threadID + 1 ;
    threadID += 1 ;
    newTcb -> state = READY ; 
    for (int i = 0 ; i < NUM_OF_CALEE_REGS ; i++ ) 
        newTcb -> calleeRegs[i] = 0 ;
    if (threadID == 1)
        currentTcb = newTcb ;

    EN_Intr ; // enabling interuppts 
}


