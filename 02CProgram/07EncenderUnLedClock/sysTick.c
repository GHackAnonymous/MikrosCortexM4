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
	
	RCC->CR &= ~(0x05 << 16);  //Rsetea el clock SEBypass
	RCC->CR |= (0x01 << 16);    //Ponemos a 1 el bit que inicida que quremos que nos avise cuando el contador llega a cero
	while(!(RCC->CR & 0x01 << 17)); //Esperamos a que el flag de estabilidad este a 1
	//una vez que este a uno seteteamos en numero por el que inicia 
	reg=RCC->CFGR;
	reg &= ~ 0x00000003;  
	reg |= 0x00000001;
	RCC->CFGR=reg;  // set HSE as sysclock
  if(ms>0)
  {
	  SysTick->LOAD  = (uint32_t)(CLOCK_FREC/1000*ms - 1UL);  // cargarmos el contador que vamos a utiilizar
	  SysTick->VAL   = 0UL; // ponemos a cero el valor por el que inicia
    SysTick->CTRL  |= 0x00000003; //Abilitamos en clock + ponemos a 1 el bit que incica que el oscilador esta listo
  }
}

void waitSysClockTick(void)// esta funcion espera hasta que el contador acabe 
{
  while(ticksOld==ticks);
  ticksOld++;
}

uint32_t getTime(void)
{
  return ticks;
}

void ourSysTickHandler(void) // esta se lanza cuando el contador acaba
{
  ticks++;
}
