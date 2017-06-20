#ifndef EXTI_H
#define EXTI_H

#define H_RCC 0x40023800U
#define H_SYSCFG 0x40013800U
#define H_EXTI 0x40013C00U
#define H_NVIC 0xE000E100U

#define SYSCFG_APB2 14
#define SYSCFG_EXTI13 13
#define SYSCFG_GPIOC 2

#define NVIC_EXTI10_15 40

typedef void (*CALLBACK)(void);

void rcc_enable_syscfg(uint32_t selSYSCFG, uint32_t enable);
void confSYSCFG(uint32_t selExti, uint32_t exti_GPIO);

void confExti(uint32_t selExti);

void confNVIC(uint32_t posNVIC);

void enableCALLBACK_E13(CALLBACK callback_fcn);

void tamper_callback(void);

#endif
