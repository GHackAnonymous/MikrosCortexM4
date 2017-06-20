#include <stdint.h>
#include "ourRccGpio.h"
#include "ourExti.h"
#include "sysTick.h"

/*---------------------------------------------------------------------------------------------------
  
-----------------------------------------------------------------------------------------------------*/

#define LEDGREEN_PIN 6

  //WKUP GPIOA0
#define BTN_1_PIN 0
//tumper  GPIOC13
#define BTN_2_PIN 13
#define PHASE_TICKS 10 //-
#define TICK_PER_SEC 1000 //-

void initGPIO(void);
void sumarintensidad(void);
void restarintensidad(void);

volatile uint32_t threshold = 0; //-


int main(void)
{
	uint32_t tickCount = 0; //-
	initSysClock(1000/TICK_PER_SEC); //-
  initGPIO();
  enablePA0interruptOnExti0WhenRising(sumarintensidad); //Permite que el boton "PA01" llame a la interrupción exti0 cuando el boton devuelve 0
  enablePC13interruptOnExti0WhenRising(restarintensidad);
	for(;;)
  {
		if(tickCount++<threshold) setGpioPinValue(GPIOF, LEDGREEN_PIN, 0x01); //-
		else setGpioPinValue(GPIOF, LEDGREEN_PIN, 0x00); //-
		tickCount %= PHASE_TICKS; //-
		waitSysClockTick(); //-
	
	/*
		Está en un bocle infinito para poder comprobar las interrupción
	*/
  }
}


void initGPIO(void)
{
	// para iniciarlizar el led verde
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOF, 1);
	initGpioPinMode(GPIOF, LEDGREEN_PIN, GPIO_Mode_OUT) ;
	
	// para inicializar el boton wkup
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, 1);
	initGpioPinMode(GPIOA, BTN_1_PIN, GPIO_Mode_IN);
	
	// para inicializar el boton tamper
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, 1);
	initGpioPinMode(GPIOC, BTN_2_PIN, GPIO_Mode_IN);
}

void sumarintensidad(void){
	if(threshold<10)
	threshold=threshold+1;
}
void restarintensidad(void){
	if(threshold>0)
	threshold=threshold-1;
}
