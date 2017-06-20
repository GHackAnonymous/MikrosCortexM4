#include <stdint.h>
#include "exti.h"

CALLBACK tamper_fcn = 0;

void rcc_enable_syscfg(uint32_t selSYSCFG, uint32_t enable){
	uint32_t *pRCC;
	
	pRCC = (uint32_t*)(H_RCC + 0x44);
	
	*pRCC &= ~(0x01 << selSYSCFG);
	*pRCC |= (enable << selSYSCFG);
}

void confSYSCFG(uint32_t selExti, uint32_t exti_GPIO){
	uint32_t *pSYSCFG_EXTICR;
	
	pSYSCFG_EXTICR = (uint32_t*) (H_SYSCFG + 0x08);
	
	*(pSYSCFG_EXTICR + selExti/4) &= ~(0x0F << (selExti % 4)*4);
	// Zatiketa : Elige el CR y Hondarra: Elige el bloke                
	*(pSYSCFG_EXTICR + selExti/4) |= (exti_GPIO << (selExti % 4)*4);
}

void confExti(uint32_t selExti){
	uint32_t *pIMR, *pRTSR, *pFTSR;
	
	pIMR = (uint32_t*)(H_EXTI + 0x00);
	*pIMR |= (0x01 << selExti);
	
	pRTSR = (uint32_t*)(H_EXTI + 0x08);
	*pRTSR |= (0x01 << selExti);
	
	pFTSR = (uint32_t*)(H_EXTI + 0x0C);
	*pFTSR &= ~(0x01 << selExti);
}

void confNVIC(uint32_t posNVIC){
	uint32_t *pISER;
	
	pISER = (uint32_t*) (H_NVIC + 0x00);
	
	*(pISER + posNVIC / 32) |= (0x01 << posNVIC % 32);
}

void enableCALLBACK_E13(CALLBACK callback_fcn){
	tamper_fcn = callback_fcn;
}

void exti10_15Handler (){
	uint32_t i;
	uint32_t *pEXTI_PR;
	
	pEXTI_PR = (uint32_t*) (H_EXTI + 0x14);
	
	for(i=10; i <= 15; i++){
		if((*pEXTI_PR & (0x01 << i)) && i == 13) {
			*pEXTI_PR |= (0x01 << i);
			tamper_callback();
		}
	}
}
