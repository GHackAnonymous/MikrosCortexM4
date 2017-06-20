#include "ourExti.h"
#include <stm32f407xx.h>

#define SYSCFG_HASIERA 0x40013800
#define EXTI_HASIERA 0x40013C00
#define NVIC_HASIERA 0xE000E100

#define EXTICR1_OFFSET 0x08
#define EXTICR4_OFFSET 0x14
#define EXTI_IMR_OFFSET 0x00
#define EXTI_RTSR_OFFSET 0x08
#define EXTI_FTSR_OFFSET 0x0C
#define EXTI_PR_OFFSET 0x14

CALLBACK exti13callback=0;

void enablePA0interruptOnExti0WhenRising(CALLBACK pFun)
{
  uint32_t *p;
  //sysConfig configuratu
  //defektuzkoak bakiodigu
  //  c13 exti 13-ra konekta dezagun
  p=(uint32_t*)(SYSCFG_HASIERA+EXTICR4_OFFSET);
  *p &=~(0x0F<<4);
  *p |= (0x02<<4);
  
  //exti konfiguratu
  p=(uint32_t*)(EXTI_HASIERA+EXTI_RTSR_OFFSET);
  *p|=0x01;
  p=(uint32_t*)(EXTI_HASIERA+EXTI_FTSR_OFFSET);
  *p&=~0x01;
  p=(uint32_t*)(EXTI_HASIERA+EXTI_IMR_OFFSET);
  *p|=0x01;
  //NVIC konfiguratu
  p=(uint32_t*)(NVIC_HASIERA+0);
  *p|=0x01<<6;
  
  exti13callback=pFun;
}

/*void ourExti0Handler(void)
{
  uint32_t *p;

  //PR-rn flag-a reseatu
  p=(uint32_t*)(EXTI_HASIERA+EXTI_PR_OFFSET);
  *p|=0x01;
  
  //if(exti0callback!=0)
    exti0callback();
}*/

void ourExti13Handler(void){
	uint32_t *p;

		//PR-rn flag-a reseatu
		//p=(uint32_t*)(EXTI_HASIERA+EXTI_PR_OFFSET);
		//*p|=0x01;
		
			exti13callback();
}