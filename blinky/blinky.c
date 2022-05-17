#include <stdbool.h>
#include <stdint.h>
#include "stdlib.h"
#include <string.h>
#include <math.h>
#include "inc/hw_types.h"//macro
#include "inc/hw_uart.h"
#include "inc/hw_memmap.h"//base address of the memories and peripherals.
#include "inc/hw_gpio.h"//Defines and Macros for GPIO hardware.
#include "inc/hw_ints.h"//Macros that define the interrupt assignment
#include "inc/hw_pwm.h"
#include "inc/hw_adc.h"
#include "inc/hw_ssi.h"
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
#include "driverlib/fpu.h"
#include "driverlib/adc.h"
#include "driver/startup.h"
#include "Nokia5110/SPI.h"
//#include "inc/tm4c123gh6pm.h"

void Delay(unsigned long ulCount){
    do{
        ulCount--;
    }while(ulCount);
}
void Delay100ms(unsigned long count){unsigned long volatile time;
while(count>0){
    time = 727240;  // 0.1sec at 80 MHz
    while(time){
        time--;
    }
    count--;
}
}
int main(){
    SysCtlClockSet(SYSCTL_SYSDIV_4|SYSCTL_USE_PLL|SYSCTL_XTAL_16MHZ|SYSCTL_OSC_MAIN);
    Uart_Init();
    while(1){

    }
}

