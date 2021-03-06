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
#include "Config_Port/Config_Port.h"
#include "FSM/FSM.h"
void Systick_Init(void);
void Systick_Handler(void){
    if(ledTimer>0){
        ledTimer--;
    }
    if(redCounter==0){
        redCounter = 50;
        redFlag = 1;
    }
    else{
        redCounter--;
    }
    if(greenCounter==0){
        greenCounter = 50;
        greenFlag = 1;
    }
    else{
        greenCounter--;
    }
    if(redFlag){
        redFlag = 0;
        ledRedStateMachineUpdate();
    }
    if(greenFlag){
        greenFlag = 0;
        ledGreenStateMachineUpdate();
    }
}
void Systick_Init(){
    SysTickPeriodSet(SysCtlClockGet()/1000);
    IntMasterEnable();
    SysTickEnable();
    SysTickIntEnable();
    SysTickIntRegister(Systick_Handler);
}
int main(void){
    SysCtlClockSet(SYSCTL_SYSDIV_2_5|SYSCTL_USE_PLL|SYSCTL_XTAL_16MHZ|SYSCTL_OSC_MAIN);
    PortF_Init();
    Systick_Init();
    while(1){

    }
}

