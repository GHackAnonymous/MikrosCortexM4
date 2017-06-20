#include <stdint.h>
#include "gpio.h"
#include "systick.h"
#include "exti.h"

void initgpio(void);
void initSystick(void);
void initExti(void);
void tamper_callback(void);

uint32_t t_ms = 700;
uint32_t led_status = 0;

int main(void)
{
	initgpio();
	initSystick();
	initExti();
	
	for(;;){
		
		if(!led_status) setLedStatus(GPIOF_H,PIN_LEDG,0);
		else {
			waitSysTick();
			toggleLedStatus(GPIOF_H,PIN_LEDG);
		}
	}
}

void initgpio(void)
{
	//darle el clock
	
	rcc_enable_gpio(GPIOF_AHB1, 1);
	initgpio_pin_mode(GPIOF_H, PIN_LEDG, OUTPUT);
	rcc_enable_gpio(GPIOC_AHB1, 1);
	initgpio_pin_mode(GPIOC_H, PIN_TAMPER, INPUT);
	
}

void initSystick(){
	uint32_t cntVal;
	
	cntVal = t_ms * FREC_AHB1/1000 - 1;
	cntVal &= (0x00FFFFFF);
	
	confSysTick(cntVal, AHB1);
}

void initExti(void){
	rcc_enable_syscfg(SYSCFG_APB2, 1);
	confSYSCFG(SYSCFG_EXTI13, SYSCFG_GPIOC);
	
	confExti(SYSCFG_EXTI13);
	
	confNVIC(NVIC_EXTI10_15);
	
	//enableCALLBACK_E13(tamper_callback);
}

void tamper_callback(void){
	led_status = !led_status;
}
