#include "sysTick.h"
#include <stm32f4xx.h>
#include <core_cm4.h>

//#define CLOCK_FREC  16000000 this would be internal clock
#define CLOCK_FREC  (25000000/8)  //we are going to use (AHB clock / 8 )

volatile uint32_t ticks=0;
volatile uint32_t ticksOld=0;

void initSysClock(uint32_t ms)
{
  uint32_t reg;
	
	RCC->CR &= ~0x00050000;  //reset HSEON and HSEBypass
	RCC->CR |= 0x00010000;    //set HSEON
	while(!(RCC->CR & 0x00020000)); //waits until clock stabilized
	reg=RCC->CFGR;
	reg &= ~ 0x00000003;  
	reg |= 0x00000001;
	RCC->CFGR=reg;  // set HSE as sysclock
  if(ms>0)
  {
	  SysTick->LOAD  = (uint32_t)(CLOCK_FREC/1000*ms - 1UL); 
	  SysTick->VAL   = 0UL;
    SysTick->CTRL  |= 0x00000003; //enable, int enable, AHB clock/8
  }
}

void waitSysClockTick(void)
{
  while(ticksOld==ticks);
  ticksOld++;
}

uint32_t getTime(void)
{
  return ticks;
}

void ourSysTickHandler(void)
{
  ticks++;
}
