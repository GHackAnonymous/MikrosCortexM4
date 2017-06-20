#include <stdint.h>
#include "ourRccGpio.h"
#include "sysTick.h"


#define LEDGREEN_PIN 6  // Este es el pin de led en el array de memoria

void initGPIO(void);

int main(void)
{
	initSysClock(1000); // el contador al que se le inicia el Contador del sysclock
  initGPIO(); // inicializar GPIO para el led
	for(;;) // buble infinito
  {
		togleGpioPinValue(GPIOF, LEDGREEN_PIN); // 
		waitSysClockTick(); // Espera asta que el contador de sysclock llege a cero
	
  }
}


void initGPIO(void)
{
	// para iniciarlizar el led verde
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOF, 1); // habilitar clock para el led
	initGpioPinMode(GPIOF, LEDGREEN_PIN, GPIO_Mode_OUT); // poner el led en modo salida
}
