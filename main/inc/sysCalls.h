#include<stdint.h> 

/* Constants */
#define SYSTICK ((struct systick *) 0xe000e010)

/* structure to get data on systick registers */
struct systick {
  volatile uint32_t CTRL, LOAD, VAL, CALIB;
};

/* Functions declarations */
void systick_init(uint32_t ticks);

