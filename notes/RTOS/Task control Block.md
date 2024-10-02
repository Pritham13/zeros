The task control block is defined as follows : 

```c
typedef struct tcb { 
  int32_t *stackPtr ;
  uint32_t calleeRegs[NUM_OF_CALEE_REGS] ;
  uint32_t pc ;
  uint32_t lr ;
  tcb *nextThreadPtr ;
  uint32_t timeout ;
  uint8_t threadID ;
} tcb
```

stackPtr contains the pointer address of the stack of the thread and `__get_PSP()` can be used to get the address of the current task