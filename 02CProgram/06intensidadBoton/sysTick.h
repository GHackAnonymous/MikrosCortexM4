#ifndef SYS_CLOCK_H
#define SYS_CLOCK_H
#include <stdint.h>

//uses external 25MHz clock

void initSysClock(uint32_t ms);
void waitSysClockTick(void);
uint32_t getTime(void);

#endif
