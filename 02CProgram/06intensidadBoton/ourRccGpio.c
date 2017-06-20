#include "ourRccGpio.h"

void RCC_AHB1PeriphClockCmd(uint32_t nPeriph, uint32_t on)
{
	if(on) RCC->AHB1ENR |= nPeriph;
	else RCC->AHB1ENR &= ~nPeriph;
}


void initGpioPinMode(GPIO_TypeDef* gpio, uint32_t pin, GPIOMode_Type mode)
{
 gpio->MODER &= ~ (3<< (pin*2)); 
 gpio->MODER |= mode << (pin*2);
}

void togleGpioPinValue(GPIO_TypeDef * gpio, uint32_t pin)
{
	gpio->ODR ^= (1<<pin);
}

void setGpioPinValue(GPIO_TypeDef * gpio, uint32_t pin, uint32_t value)
{
	uint32_t rValue=0x01<<pin;
	
	if(!value)  rValue<<=16;
	gpio->BSRR=rValue;
}

uint32_t getGpioPinValue(GPIO_TypeDef * gpio, uint32_t pin)
{
	return (gpio->IDR & (0x01<<pin));
}

void setGpioPinAF(GPIO_TypeDef * gpio, uint32_t pin, uint32_t AF)
{
	gpio->AFR[pin<8 ? 0 :1] &= ~(0xF << ((pin % 8)*4));
	gpio->AFR[pin<8 ? 0 :1] |= AF << (pin % 8);
}

