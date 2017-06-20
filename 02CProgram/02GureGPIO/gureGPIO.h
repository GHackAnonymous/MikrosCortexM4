#ifndef GUREGPIO
#define GUREGPIO
#include <stdint.h>

void setGPIOFpinValue(uint32_t pinN, int value);
unit32_t getGPIOApinValue(uint32_t pinN);
unit32_t getGPIOCpinValue(uint32_t pinN);
void setGPIOFpinInOutputMode(uint32_t pinN);
void setGPIOApinInInputMode(uint32_t pinN);
void setGPIOCpinInInputMode(uint32_t pinN);
void enableGPIO(uint32_t gpioN);


#endif
