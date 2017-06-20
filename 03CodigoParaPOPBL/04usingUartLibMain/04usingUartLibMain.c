#include <stdint.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include "ourRccGpio.h"
#include "ourCom.h"
#include "sysClock.h"

#define LED_PIN 6
#define USED_COM_PORT COM1

void initLed(void);

int main(void)
{
  int i, n=0;
	char str[128];
	
  initSysClock(1000);
	initCom(USED_COM_PORT,9600);
  initLed();
  while(1)
  {
    sprintf(str," %04x\r\n",++n);
    writeToUart(USED_COM_PORT,(uint8_t *)str,strlen(str));
    togleGpioPinValue(GPIOF, LED_PIN);
		for(i=0;i<5;i++) waitSysClockTick();
	}
}

void initLed(void)
{
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOF, 1);
  initGpioPinMode(GPIOF, LED_PIN, GPIO_Mode_OUT);
}
