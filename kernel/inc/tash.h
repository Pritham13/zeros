#include <stdint.h>
#define THREAD_STACK_SIZE  2048
#define MY_EXC_RETURN 0xFFFFFFFD  /* Return to thread mode using process stack and restore basic stack frame */
#define NORM_STACK_FRAME_SIZE           8
#define NORM_STACK_FRAME_XPSR_OFFSET    7
#define NORM_STACK_FRAME_PC_OFFSET      6
#define NORM_STACK_FRAME_LR_OFFSET      5
#define NORM_STACK_FRAME_R12_OFFSET     4
#define NORM_STACK_FRAME_R3_OFFSET      3
#define NORM_STACK_FRAME_R2_OFFSET      2
#define NORM_STACK_FRAME_R1_OFFSET      1
#define NORM_STACK_FRAME_R0_OFFSET      0
#define DEF_MY_XPSR                     0x01000000
#define MAX_MPU_REGIONS                 8

uint8_t threadID = 0 ;

enum task_states {
    READY,
    SUSPENDED,
}
void create_task (void ( * function_ptr )( void ) , char *taskName , uint8_t priority , uint16_t stackSize ) ;
