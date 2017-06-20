#ifndef OUR_RCC_H
#define OUR_RCC_H

#include <stdint.h>
#include <stm32f407xx.h>

#define RCC_AHB1Periph_GPIOC ((uint32_t)(0x01<<2))
#define RCC_AHB1Periph_GPIOF ((uint32_t)(0x01<<5))

typedef enum
{ 
  GPIO_Mode_IN   = 0x00, /*!< GPIO Input Mode */
  GPIO_Mode_OUT  = 0x01, /*!< GPIO Output Mode */
//  GPIO_Mode_AF   = 0x02, /*!< GPIO Alternate function Mode */
//  GPIO_Mode_AN   = 0x03  /*!< GPIO Analog Mode */
}GPIOMode_Type;


void initGPIO(int LEDVERDE, int LEDNARANJA);
void initGpioPinMode(GPIO_TypeDef *, uint32_t pin, GPIOMode_Type mode);
void togleGpioPinValue(GPIO_TypeDef *, uint32_t pin); // poner input o output
void setGpioPinValue(GPIO_TypeDef *, uint32_t pin, uint32_t value);
uint32_t getGpioPinValue(GPIO_TypeDef *, uint32_t pin);

#endif
