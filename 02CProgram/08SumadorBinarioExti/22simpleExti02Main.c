#include <stdint.h>
#include "ourRccGpio.h"
#include "ourExti.h"

/*---------------------------------------------------------------------------------------------------
  
-----------------------------------------------------------------------------------------------------*/

#define LEDGREEN_PIN 6
#define LEDORANGE_PIN 7
#define LEDRED_PIN 8
#define LEDGREEN2_PIN 9

  //WKUP GPIOA0
#define BTN_1_PIN 0
//tumper  GPIOC13
#define BTN_2_PIN 13

uint32_t count = 0;

void initGPIO(void);
void sumarintensidad(void);
void restarintensidad(void);

int main(void)
{
  initGPIO();
  enablePA0interruptOnExti0WhenRising(sumarintensidad); 
  enablePC13interruptOnExti0WhenRising(restarintensidad);
	for(;;)
  {
		switch(count){
			case 1:
				setGpioPinValue(GPIOF, LEDGREEN_PIN, 0x01);
				setGpioPinValue(GPIOF, LEDORANGE_PIN, 0x00);
				setGpioPinValue(GPIOF, LEDRED_PIN, 0x00);
				setGpioPinValue(GPIOF, LEDGREEN2_PIN, 0x00);
				break;
			case 2:
				setGpioPinValue(GPIOF, LEDGREEN_PIN, 0x00);
				setGpioPinValue(GPIOF, LEDORANGE_PIN, 0x01);
				setGpioPinValue(GPIOF, LEDRED_PIN, 0x00);
				setGpioPinValue(GPIOF, LEDGREEN2_PIN, 0x00);
				break;
			case 3:
				setGpioPinValue(GPIOF, LEDGREEN_PIN, 0x01);
				setGpioPinValue(GPIOF, LEDORANGE_PIN, 0x01);
				setGpioPinValue(GPIOF, LEDRED_PIN, 0x00);
				setGpioPinValue(GPIOF, LEDGREEN2_PIN, 0x00);
				break;
			case 4:
				setGpioPinValue(GPIOF, LEDGREEN_PIN, 0x00);
				setGpioPinValue(GPIOF, LEDORANGE_PIN, 0x00);
				setGpioPinValue(GPIOF, LEDRED_PIN, 0x01);
				setGpioPinValue(GPIOF, LEDGREEN2_PIN, 0x00);
				break;
			case 5:
				setGpioPinValue(GPIOF, LEDGREEN_PIN, 0x01);
				setGpioPinValue(GPIOF, LEDORANGE_PIN, 0x00);
				setGpioPinValue(GPIOF, LEDRED_PIN, 0x01);
				setGpioPinValue(GPIOF, LEDGREEN2_PIN, 0x00);
				break;
			case 6:
				setGpioPinValue(GPIOF, LEDGREEN_PIN, 0x00);
				setGpioPinValue(GPIOF, LEDORANGE_PIN, 0x01);
				setGpioPinValue(GPIOF, LEDRED_PIN, 0x01);
				setGpioPinValue(GPIOF, LEDGREEN2_PIN, 0x00);
				break;
			case 7:
				setGpioPinValue(GPIOF, LEDGREEN_PIN, 0x01);
				setGpioPinValue(GPIOF, LEDORANGE_PIN, 0x01);
				setGpioPinValue(GPIOF, LEDRED_PIN, 0x01);
				setGpioPinValue(GPIOF, LEDGREEN2_PIN, 0x00);
				break;
			case 8:
				setGpioPinValue(GPIOF, LEDGREEN_PIN, 0x00);
				setGpioPinValue(GPIOF, LEDORANGE_PIN, 0x00);
				setGpioPinValue(GPIOF, LEDRED_PIN, 0x00);
				setGpioPinValue(GPIOF, LEDGREEN2_PIN, 0x01);
				break;
			case 9:
				setGpioPinValue(GPIOF, LEDGREEN_PIN, 0x01);
				setGpioPinValue(GPIOF, LEDORANGE_PIN, 0x00);
				setGpioPinValue(GPIOF, LEDRED_PIN, 0x00);
				setGpioPinValue(GPIOF, LEDGREEN2_PIN, 0x01);
				break;
			case 10:
				setGpioPinValue(GPIOF, LEDGREEN_PIN, 0x00);
				setGpioPinValue(GPIOF, LEDORANGE_PIN, 0x01);
				setGpioPinValue(GPIOF, LEDRED_PIN, 0x00);
				setGpioPinValue(GPIOF, LEDGREEN2_PIN, 0x01);
				break;
			case 11:
				setGpioPinValue(GPIOF, LEDGREEN_PIN, 0x01);
				setGpioPinValue(GPIOF, LEDORANGE_PIN, 0x01);
				setGpioPinValue(GPIOF, LEDRED_PIN, 0x00);
				setGpioPinValue(GPIOF, LEDGREEN2_PIN, 0x01);
				break;
			case 12:
				setGpioPinValue(GPIOF, LEDGREEN_PIN, 0x00);
				setGpioPinValue(GPIOF, LEDORANGE_PIN, 0x00);
				setGpioPinValue(GPIOF, LEDRED_PIN, 0x01);
				setGpioPinValue(GPIOF, LEDGREEN2_PIN, 0x01);
				break;
			case 13:
				setGpioPinValue(GPIOF, LEDGREEN_PIN, 0x01);
				setGpioPinValue(GPIOF, LEDORANGE_PIN, 0x00);
				setGpioPinValue(GPIOF, LEDRED_PIN, 0x01);
				setGpioPinValue(GPIOF, LEDGREEN2_PIN, 0x01);
				break;
			case 14:
				setGpioPinValue(GPIOF, LEDGREEN_PIN, 0x00);
				setGpioPinValue(GPIOF, LEDORANGE_PIN, 0x01);
				setGpioPinValue(GPIOF, LEDRED_PIN, 0x01);
				setGpioPinValue(GPIOF, LEDGREEN2_PIN, 0x01);
				break;
			case 15:
				setGpioPinValue(GPIOF, LEDGREEN_PIN, 0x01);
				setGpioPinValue(GPIOF, LEDORANGE_PIN, 0x01);
				setGpioPinValue(GPIOF, LEDRED_PIN, 0x01);
				setGpioPinValue(GPIOF, LEDGREEN2_PIN, 0x01);
		}
  }
}


void initGPIO(void)
{
	// para iniciarlizar el led verde
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOF, 1);
	initGpioPinMode(GPIOF, LEDGREEN_PIN, GPIO_Mode_OUT);
	
	// para iniciarlizar el led orange
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOF, 1);
	initGpioPinMode(GPIOF, LEDORANGE_PIN, GPIO_Mode_OUT);
	
	// para iniciarlizar el led red
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOF, 1);
	initGpioPinMode(GPIOF, LEDRED_PIN, GPIO_Mode_OUT);
	
	// para iniciarlizar el led verde 2
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOF, 1);
	initGpioPinMode(GPIOF, LEDGREEN2_PIN, GPIO_Mode_OUT) ;
	
	// para inicializar el boton wkup
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, 1);
	initGpioPinMode(GPIOA, BTN_1_PIN, GPIO_Mode_IN);
	
	// para inicializar el boton tamper
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, 1);
	initGpioPinMode(GPIOC, BTN_2_PIN, GPIO_Mode_IN);
}

void sumarintensidad(void){
	if(count<15)
	count=count+1;
}
void restarintensidad(void){
	if(count>0)
	count=count-1;
}
