#include "ourExti.h"
#include <stm32f407xx.h>

#define SYSCFG_HASIERA 0x40013800
#define EXTI_HASIERA 0x40013C00
#define NVIC_HASIERA 0xE000E100
#define RCC_HASIERA 0x40023800

#define EXTICR1_OFFSET 0x08
#define EXTICR4_OFFSET 0x14 //esto no es 40 el ofset del exti13 sino el syscfg_exticr4 por que en su interior tiene Exti13 (Referencia: Ref. Manual:289/1710) y te fijas en la tabla, tiene que contener El exti  que te interesa para el boton que quieres habilitar  
#define EXTI_IMR_OFFSET 0x00
#define EXTI_RTSR_OFFSET 0x08
#define EXTI_FTSR_OFFSET 0x0C
#define EXTI_PR_OFFSET 0x14 //pg. 388 de 1748 reference manual - Pending register. Indica si ha ocurrido una interrrupcion.

#define APB2ENR_OFFSET 0x44 //APB2 se usa por que es en el que esta el SYSCFG memory mapping
#define SYSCFG_EN_BIT (0x01<<14)

CALLBACK exti0callback=0;
CALLBACK exti13callback=0;

void enablePA0interruptOnExti0WhenRising(CALLBACK pFun)
{
  uint32_t *p;
  
    //SYSCFG gahitu
  p=(uint32_t*)(RCC_HASIERA+APB2ENR_OFFSET); // EStas dos lineas habilita sysconfig
  *p|=SYSCFG_EN_BIT;
  //sysConfig configuratu
  /*defektuzkoak bakiodigu*/
  //exti konfiguratu
  p=(uint32_t*)(EXTI_HASIERA+EXTI_RTSR_OFFSET); //habilita RTSR
  *p|=0x01;
  p=(uint32_t*)(EXTI_HASIERA+EXTI_FTSR_OFFSET); //Desabilita FTSR
  *p&=~0x01;
  p=(uint32_t*)(EXTI_HASIERA+EXTI_IMR_OFFSET);
  *p|=0x01;  // este 1 sinifica que esta desenmascarado
  //NVIC konfiguratu
  p=(uint32_t*)(NVIC_HASIERA+0);
  *p|=0x01<<6; //Table 61. Vector table for STM32F405xx/07xx and STM32F415xx/17xx
  /*
	destro de la tabla mirar que exti ytilizamos y sacar el valor de la posicion. En nuestro casos el exti0 es posicion 6, 
	poner un 1 en la posicion 6 de NVIC
  */
  
  exti0callback=pFun;
}

void enablePC13interruptOnExti0WhenRising(CALLBACK pFun)
{
  uint32_t *p;
  
    //SYSCFG gahitu
  p=(uint32_t*)(RCC_HASIERA+APB2ENR_OFFSET); // EStas dos lineas habilita sysconfig
  *p|=SYSCFG_EN_BIT;
  //sysConfig configuratu
  p=(uint32_t*)(SYSCFG_HASIERA+EXTICR4_OFFSET); //No me funcionaba por que no tenia syscfg
  *p &=~(0x0F<<4);    //9.2.5.6. REFERENCE MANUAL
  *p |= (0x02<<4);
											//DE 16*9 A SOLO UN ARRAY
  //exti konfiguratu
  p=(uint32_t*)(EXTI_HASIERA+EXTI_RTSR_OFFSET); //habilita RTSR
  *p|=0x01<<13;     //UNA VEZ AQUÍ SOLO NOS PREOCUPAMOS DE UN BUS DE 16
										//SYSCONFIG ACTUA COMO MULTIPLEXADOR, LAS SALIDAS VAN A LAS EXTIS, 16 LINEAS
										//CONFIGURAR CADA UNO
  p=(uint32_t*)(EXTI_HASIERA+EXTI_FTSR_OFFSET); //Desabilita FTSR
  *p&=~(0x01<<13);
  p=(uint32_t*)(EXTI_HASIERA+EXTI_IMR_OFFSET);
  *p|=0x01<<13;  // este 1 sinifica que esta desenmascarado
  //NVIC konfiguratu
  p=(uint32_t*)(NVIC_HASIERA+4);  // SI esto fuera NVIC_HASIERA + 0
  *p|=0x01<<8; //Table 49. NVIC register map and reset values (NVIC_ISER1)  -- *(p+40/32) |= 0x01 << (40%32)
  /*
	destro de la tabla mirar que exti ytilizamos y sacar el valor de la posicion. En nuestro casos el exti0 es posicion 6, 
	poner un 1 en la posicion 6 de NVIC
  */
  
  exti13callback=pFun;
}

void ourExti0Handler(void)
{
  uint32_t *p;

  //PR-rn flag-a reseatu
  p=(uint32_t*)(EXTI_HASIERA+EXTI_PR_OFFSET); // pone el bit del flag para resetearlo. 
  *p|=0x01;
	
  //if(exti0callback!=0)
    exti0callback(); //llama a la funcion que pasamos en pFUN. Preguntar si pFUN es lo que tiene que ejecutar cuando se lanza una interrupcion?
}
void ourExti13Handler(void)
{
  uint32_t *p;

  //PR-rn flag-a reseatu
  p=(uint32_t*)(EXTI_HASIERA+EXTI_PR_OFFSET); // pone el bit del flag para resetearlo. 
  
	//FOR PARA MIRAR DEL 10 AL 15 
	
	uint32_t i;
	uint32_t reg;
	//*reg = *p;
/*	for(i = 10; i <= 15; i++){
		if(!(*p &= (0x01<<i)) && i==13){ //
		  exti13callback(); //llama a la funcion que pasamos en pFUN. Preguntar si pFUN es lo que tiene que ejecutar cuando se lanza una interrupcion?	
		}
	}*/
	
	reg = *p;
	for(i = 10; i <= 15; i++){
		if(reg & (0x01<<i)){ //
			*p|=0x01<<i;
		  if(i==13 && exti13callback!=0)exti13callback(); //llama a la funcion que pasamos en pFUN. Preguntar si pFUN es lo que tiene que ejecutar cuando se lanza una interrupcion?	
		}
	}
	
  //if(exti0callback!=0)
    
}

















