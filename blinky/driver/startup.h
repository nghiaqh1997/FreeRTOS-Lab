#ifndef DRIVER_STARTUP_H_
#define DRIVER_STARTUP_H_

void PortF_Init(void);
void Interrupt_GPIO_Init();
//void PortFIntHandle();
//void Systick_Handle();
void Systick_Init();
//void UARTIntHandler(void);
void Uart_Init(void);
//void Timer0Handle();
void Timer_Init();
#endif /* DRIVER_STARTUP_H_ */