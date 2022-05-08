/*
 * Config_Port.c
 *
 *  Created on: Apr 14, 2022
 *      Author: nghia
 */

#include <stdbool.h>
#include <stdint.h>
#include "stdlib.h"
#include <stdbool.h>
#include "inc/hw_types.h"//macro
#include "inc/hw_uart.h"
#include "inc/hw_memmap.h"//base address of the memories and peripherals.
#include "inc/hw_gpio.h"//Defines and Macros for GPIO hardware.
#include "inc/hw_ints.h"//Macros that define the interrupt assignment
#include "inc/hw_pwm.h"
#include "driverlib/debug.h"
#include "driverlib/sysctl.h"//SYSCTL register
#include "driverlib/rom.h"//ROM library
#include "driverlib/rom_map.h"//ROM map
#include "driverlib/pin_map.h"//ort/Pin Mapping Definitions
#include "driverlib/gpio.h"//Defines and Macros for GPIO API
#include "driverlib/interrupt.h"//Interrupt library
#include "driverlib/timer.h"//Prototypes for the timer module
#include "driverlib/uart.h"//Defines and Macros for the UART
#include "utils/uartstdio.h"//UARTSTDIO
#include "driverlib/systick.h"//Systick
#include "driverlib/udma.h"
#include "driverlib/pwm.h"
#include "driverlib/ssi.h"
#include <string.h>
#include "Config_Port.h"

void PortF_Init(void){
    ROM_SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
    ROM_GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3);
    HWREG(GPIO_PORTF_BASE + GPIO_O_LOCK) = GPIO_LOCK_KEY;
    HWREG(GPIO_PORTF_BASE + GPIO_O_CR) |= 0x01;
    HWREG(GPIO_PORTF_BASE + GPIO_O_LOCK) = 0;
    ROM_GPIOPinTypeGPIOInput(GPIO_PORTF_BASE, GPIO_PIN_0|GPIO_PIN_4);
    ROM_GPIOPadConfigSet(GPIO_PORTF_BASE, GPIO_PIN_0|GPIO_PIN_4, GPIO_STRENGTH_2MA, GPIO_PIN_TYPE_STD_WPU);
}


