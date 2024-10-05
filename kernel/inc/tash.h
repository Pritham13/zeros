#include <stdint.h>
#define STACK
void create_task (void ( * function_ptr )( void ) , char *taskName , uint8_t priority , uint16_t stackSize )  
