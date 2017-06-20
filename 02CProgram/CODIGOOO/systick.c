#include <stdint.h>
#include "systick.h"

uint32_t tickReceived = 0;

void confSysTick(uint32_t reload, uint32_t clk_src){
	uint32_t *pLOAD, *pVAL, *pCTRL;

	pLOAD = (uint32_t*)(H_SYSTICK + 0x04);
	*pLOAD &= ~(0x00FFFFFF << 0x00);
	*pLOAD |= (reload << 0x00);
	
	pVAL = (uint32_t*)(H_SYSTICK + 0x08);
	*pVAL &= ~(0x00FFFFFF << 0x00);
	
	pCTRL = (uint32_t*)(H_SYSTICK + 0x00);
	
	*pCTRL &= ~(0x01 << 2);
	*pCTRL |= (clk_src << 2);
	
	*pCTRL |= (0x03 << 0x00);
	
	//*pCTRL &= ~(0x07 << 0x00)
	//*pCTRL |= (0x07 + clk_src*4 << 0x00)
}

void waitSysTick(void){
	while(!tickReceived);
	tickReceived = 0;
}

void SysTickHandler(){
	tickReceived = 1;
}
