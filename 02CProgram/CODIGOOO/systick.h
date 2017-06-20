#ifndef SYSTICK_H
#define SYSTICK_H

#define H_SYSTICK 0xE000E010U
#define FREC_AHB1 16000000 // 16MHz
#define AHB1 1

void confSysTick(uint32_t reload, uint32_t clk_src);
void waitSysTick(void);

#endif
