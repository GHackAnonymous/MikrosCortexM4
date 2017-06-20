#include <stdint.h>
#include "gpio.h"

void rcc_enable_gpio(uint32_t selGPIO, uint32_t enable)
{
	uint32_t *pRCC;
	
	pRCC = (uint32_t*) (RCC_H + 0x30);
	
	*pRCC &= ~(0x01 << selGPIO); // Resetear
	*pRCC |= (enable << selGPIO);
}
void initgpio_pin_mode(uint32_t hGPIO, uint32_t nPin, uint32_t mode)
{
	uint32_t *GPIO_MODER;
	
	GPIO_MODER = (uint32_t*) (hGPIO + 0x00);
	
	*GPIO_MODER &= ~(0x03 << nPin*2);
	*GPIO_MODER |= (mode << nPin*2);
}

void toggleLedStatus(uint32_t hGPIO, uint32_t nPin){
	uint32_t *GPIO_ODR;
	
	GPIO_ODR = (uint32_t*) (hGPIO + 0x14);
	
	*GPIO_ODR ^= (0x01 << nPin);
}

void setLedStatus(uint32_t hGPIO, uint32_t nPin, uint32_t on){
	uint32_t *GPIO_ODR;
	
	GPIO_ODR = (uint32_t*) (hGPIO + 0x14);
	
	*GPIO_ODR &= ~(0x01 << nPin);
	*GPIO_ODR |= (on << nPin);
}
