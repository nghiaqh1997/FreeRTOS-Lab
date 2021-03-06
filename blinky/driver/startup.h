#ifndef DRIVER_STARTUP_H_
#define DRIVER_STARTUP_H_
#define GPIO_PORTF_DATA_R       (*((volatile uint32_t *)0x400253FC))
void PortF_Init(void);
void Interrupt_GPIO_Init(void);
void PortFIntHandle(void);
void Systick_Handle(void);
void Systick_Init(void);
void UART0IntHandler(void);
void Uart_Init(void);
void Timer0Handle(void);
void Timer_Init(void);
void ADCSS3Handler(void);
void ADC_Timer_Init(void);
#endif /* DRIVER_STARTUP_H_ */
