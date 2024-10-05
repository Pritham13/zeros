#include "../inc/tash.h"
#include "../inc/kernel.h"



void create_task (void ( * function_ptr )( void ) , char *taskName , uint8_t priority , uint16_t stackSize ) { 
  newTcb = (tcb *) malloc(sizeof(tcb)) ;
  newTcb->taskName = ( char * ) malloc ( 20 );
  memset ( newTcb->taskName, '\0', 20 );
  strcpy ( newTcb->taskName, taskname );
  newTcb -> priority = priority ;
  newTcb -> stackPtr =   stackSize + THREAD_STACK_SIZE - NORM_STACK_FRAME_SIZE;
  
  
}
