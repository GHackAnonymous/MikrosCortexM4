#include <stdint.h>

void initGPIO(void);

int main(void)
{
  int i;
  uint32_t *pGPIOF_ODR;
	
  initGPIO();
  pGPIOF_ODR=(uint32_t*)(0x40000000U+0x00020000U+0x1400U+0x14);
  for(;;)
  {
    *pGPIOF_ODR ^= (1<<6);
    for(i=0;i<2000000;i++);  //denbora pasatzeko bukle bat
  }
}

void initGPIO(void)
{
  uint32_t *pRCC_AHB1ENR;
  uint32_t *pGPIOF;
	
  // Aktibatu GPIOF periferikoa ( DM00031020 Reference manual, 242 orria )
  pRCC_AHB1ENR=(uint32_t*)(0x40000000U+ 0x00020000U+0x3800U+0x30U);
  (*pRCC_AHB1ENR) |= (1<<5);

  // Konfiguratu GPIOF-ko 6. pin-a irteera bezala ( DM00031020 Reference manual, 283 orria )
  pGPIOF=(uint32_t*)(0x40000000U+0x00020000U+0x1400U+0x0U);
  *(pGPIOF+0U) &= ~ (3<< (6*2)); 
  *(pGPIOF+0U) |= 1 << (6*2);
  //defektuz, irteerak push-pull eta low speed daude
}