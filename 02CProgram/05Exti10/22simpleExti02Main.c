#include <stdint.h>
#include "ourRccGpio.h"
#include "ourExti.h"

/*---------------------------------------------------------------------------------------------------
  
-----------------------------------------------------------------------------------------------------*/

#define LEDGREEN_PIN 6
#define LEDORANGE_PIN 7

  //WKUP A0
#define BTN_13_PIN 13  

void initGPIO(void);
void ISRarenZatiBat(void);

volatile uint32_t greenNotOrange=1;

int main(void)
{
  initGPIO();
  enablePA0interruptOnExti0WhenRising(ISRarenZatiBat);
  for(;;)
  {
		setGpioPinValue(GPIOF, LEDGREEN_PIN, greenNotOrange);
    setGpioPinValue(GPIOF, LEDORANGE_PIN, !greenNotOrange);
  }
}


void initGPIO(void)
{
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOF, 1);
	initGpioPinMode(GPIOF, LEDGREEN_PIN, GPIO_Mode_OUT) ;
	initGpioPinMode(GPIOF, LEDORANGE_PIN, GPIO_Mode_OUT) ;
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, 1);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_SYSCONFIG, 1);
	initGpioPinMode(GPIOA, BTN_13_PIN, GPIO_Mode_IN);
}

void ISRarenZatiBat(void)
{
  greenNotOrange=!greenNotOrange;
}


