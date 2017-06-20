#include "NuestroLib.h"

typedef struct s_RccType
{
  uint32_t notUsedZone01[12];
  volatile uint32_t AHB1ENR;       /*!< RCC AHB1 peripheral clock register,                          Address offset: 0x30 */
  volatile uint32_t  AHB2ENR;      /*!< RCC AHB2 peripheral clock register,                          Address offset: 0x34 */
  volatile uint32_t AHB3ENR;       /*!< RCC AHB3 peripheral clock register,                          Address offset: 0x38 */
  uint32_t notUsedZone02[1];     /*!< Reserved, 0x3C                                                                    */
  volatile uint32_t APB1ENR;       /*!< RCC APB1 peripheral clock enable register,                   Address offset: 0x40 */
  volatile uint32_t APB2ENR;       /*!< RCC APB2 peripheral clock enable register,                   Address offset: 0x44 */
  uint32_t notUsedZone03[16];
} RccType;

#define RCC 0x40023800U
#define GPIOF 0x40021400U
#define OurRCC ((RccType*)(0x40000000U+ 0x00020000U+0x3800U))

void initGPIO(int LEDVERDE, int LEDNARANJA)
{
  initGpioPinMode(GPIOF, LEDVERDE, GPIO_Mode_OUT);
	initGpioPinMode(GPIOF, LEDNARANJA, GPIO_Mode_OUT);
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