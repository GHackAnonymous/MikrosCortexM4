#ifndef GPIO_H
#define GPIO_H

#define RCC_H 0x40023800U
#define GPIOF_H 0x40021400U
#define GPIOC_H 0x40020800U

#define GPIOF_AHB1 5
#define GPIOC_AHB1 2

#define INPUT 0
#define OUTPUT 1

#define PIN_TAMPER 13
#define PIN_LEDG 6

void rcc_enable_gpio(uint32_t selGPIO, uint32_t enable);
void initgpio_pin_mode(uint32_t hGPIO, uint32_t nPin, uint32_t mode);

void toggleLedStatus(uint32_t hGPIO, uint32_t nPin);
void setLedStatus(uint32_t hGPIO, uint32_t nPin, uint32_t on);


#endif
