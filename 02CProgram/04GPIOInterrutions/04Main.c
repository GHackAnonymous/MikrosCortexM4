#include "NuestroLib.h"
#include <stdint.h>

#define LEDVERDE 6
#define LEDNARANJA 7

//boton

#define BTN_1_PIN 0


volatile uint32_t greenNotOrange = 1;
int main(){
	initGPIO();
	//enableGpioInterrupt('A',BTN_1_PIN, 1);
	for(;;){
		setGpioPinValue(GPIOF, LEDVERDE, greenNotOrange);
		int i = 0;
		for(i=0;i<9000000;i++);
		setGpioPinValue(GPIOF, LEDNARANJA, !greenNotOrange);
		
	}
}
