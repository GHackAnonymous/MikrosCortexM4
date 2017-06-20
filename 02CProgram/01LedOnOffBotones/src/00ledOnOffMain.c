#include <stdint.h>

void initGPIO(void);

int main(void)
{
  int i;
  uint32_t *pGPIOF_ODR1; // *pGPIOF_ODR2, *pGPIOF_ODR3, *pGPIOF_ODR4;
	uint32_t *pBoton; 
	
  initGPIO();
  pGPIOF_ODR1=(uint32_t*)(0x40000000U+0x00020000U+0x1400U+0x14); //0x40021414U
	/*pGPIOF_ODR2=(uint32_t*)(0x40000000U+0x00020000U+0x1400U+0x14); //0x40021415U
	pGPIOF_ODR3=(uint32_t*)(0x40000000U+0x00020000U+0x1400U+0x14); //0x40021416U
	pGPIOF_ODR4=(uint32_t*)(0x40000000U+0x00020000U+0x1400U+0x14); //0x40021417U*/
	
	pBoton=(uint32_t*)(0x40000000U+0x00020000U+0x0800U+0x10U);
	
   for(;;)
  {
    *pGPIOF_ODR1 ^= (1<<6); //Led 1 on
		*pGPIOF_ODR1 ^= (0<<7); //Led 2 off
		*pGPIOF_ODR1 ^= (0<<8); //Led 3 off
		*pGPIOF_ODR1 ^= (0<<9); //Led 4 off
		if((!(*pBoton) & (1<<13))){
			for(i=0;i<2000000;i++);  //denbora pasatzeko bukle bat
		}else{
			for(i=0;i<500000;i++);  //denbora pasatzeko bukle bat
		}
		*pGPIOF_ODR1 ^= (1<<6); //Led 1 off
		*pGPIOF_ODR1 ^= (1<<7); //Led 2 on
		*pGPIOF_ODR1 ^= (0<<8); //Led 3 off
		*pGPIOF_ODR1 ^= (0<<9); //Led 4 off
		if((!(*pBoton) & (1<<13))){
			for(i=0;i<2000000;i++);  //denbora pasatzeko bukle bat
		}else{
			for(i=0;i<500000;i++);  //denbora pasatzeko bukle bat
		}
		*pGPIOF_ODR1 ^= (0<<6); //Led 1 off
		*pGPIOF_ODR1 ^= (1<<7); //Led 2 off
		*pGPIOF_ODR1 ^= (1<<8); //Led 3 on
		*pGPIOF_ODR1 ^= (0<<9); //Led 4 off
		if((!(*pBoton) & (1<<13))){
			for(i=0;i<2000000;i++);  //denbora pasatzeko bukle bat
		}else{
			for(i=0;i<500000;i++);  //denbora pasatzeko bukle bat
		}
		*pGPIOF_ODR1 ^= (0<<6); //Led 1 off
		*pGPIOF_ODR1 ^= (0<<7); //Led 2 off
		*pGPIOF_ODR1 ^= (1<<8); //Led 3 off
		*pGPIOF_ODR1 ^= (1<<9); //Led 4 on
	if((!(*pBoton) & (1<<13))){
			for(i=0;i<2000000;i++);  //denbora pasatzeko bukle bat
		}else{
			for(i=0;i<500000;i++);  //denbora pasatzeko bukle bat
		}
		*pGPIOF_ODR1 ^= (1<<9); //Led 4 on
  }
}

void initGPIO(void)
{
  uint32_t *pRCC_AHB1ENR;
  uint32_t *pGPIOF;
	uint32_t *pBoton; 
	
  // Aktibatu GPIOF periferikoa ( DM00031020 Reference manual, 242 orria )
  //pRCC_AHB1ENR=(uint32_t*)(0x40000000U+ 0x00020000U+0x3800U+0x30U); //rcc + ahb + 
	pRCC_AHB1ENR=(uint32_t*)(0x40023800U + 0x30U);
  (*pRCC_AHB1ENR) |= (1<<5);

  // Konfiguratu GPIOF-ko 6. pin-a irteera bezala ( DM00031020 Reference manual, 283 orria )
  pGPIOF=(uint32_t*)(0x40000000U+0x00020000U+0x1400U+0x0U);
  *(pGPIOF+0U) &= ~ (3<< (6*2)); 
  *(pGPIOF+0U) |= 1 << (6*2);
	*(pGPIOF+0U) &= ~ (3<< (7*2)); 
  *(pGPIOF+0U) |= 1 << (7*2);
	*(pGPIOF+0U) &= ~ (3<< (8*2)); 
  *(pGPIOF+0U) |= 1 << (8*2);
	*(pGPIOF+0U) &= ~ (3<< (9*2)); 
  *(pGPIOF+0U) |= 1 << (9*2);
	
	//bouton
	//pBoton=(uint32_t*)(0x40000000U+0x00020000U+0x0800U+0x0U);
 // *(pBoton+0U) &= ~ (3<< (13*2)); 
 // *(pBoton+0U) |= 1 << (13*2);
	
  //defektuz, irteerak push-pull eta low speed daude
}