#include "../inc/sysTick.h"
#include "../inc/ourRccGpio.h"
#include <stm32f4xx.h>

/*------------------------------------------------------------------
  Program that eveery second togles on/of a led through pin6 of GIPOF
-------------------------------------------------------------------*/

void initGPIO(void);

#define LED_PIN 6

void initGPIO(void);

int main(void)
{
	initSysClock(1000);
	initGPIO();
  for(;;)
  {
    togleGpioPinValue(GPIOF, LED_PIN);
		waitSysClockTick();
  }
}

void initGPIO(void)
{
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOF, 1);
  initGpioPinMode(GPIOF, LED_PIN, GPIO_Mode_OUT);
}

/*int main(void)
{
  uint32_t time;
  
	initSysClock(1000);
	initGPIO();
  for(;;)
  {
    time=getTime();  
    if(time%2 == 0)  setGpioPinValue(GPIOF, LED_PIN, 1);
    else setGpioPinValue(GPIOF, LED_PIN, 0);
		//waitSysClockTick();
  
  }
}*/