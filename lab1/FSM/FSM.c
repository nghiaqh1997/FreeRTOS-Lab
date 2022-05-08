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
#include "FSM.h"
uint8_t redCounter = 0;
uint8_t greenCounter = 0;
uint8_t redFlag = 0;
uint8_t greenFlag = 0;
uint16_t ledTimer = 0;
enum ledNumber{LEDRED=0,LEDGREEN,LEDBLUE};
const   uint32_t    ledPin[3]   =   {GPIO_PIN_1,GPIO_PIN_2,GPIO_PIN_3};
enum ledState{OFF=0,ON};
typedef enum SW{PRESSED,RELEASED} sw_t;

void ledControl(enum ledNumber led,enum ledState State){
    if(State){
        GPIOPinWrite(GPIO_PORTF_BASE,ledPin[led], ledPin[led]);
    }
    else{
        GPIOPinWrite(GPIO_PORTF_BASE,ledPin[led], 0);
    }
}
sw_t switchState(SWnumber){
    switch(SWnumber){
    case 1:
        if(GPIOPinRead(GPIO_PORTF_BASE, GPIO_PIN_4) == 0){
            return PRESSED;
        }
        else{
            return RELEASED;
        }
    case 2:
        if(GPIOPinRead(GPIO_PORTF_BASE, GPIO_PIN_0) == 0){
            return PRESSED;
        }
        else{
            return RELEASED;
        }
    default: return PRESSED;
    }
}
//////////////////////////////////////////RED//////////////////////////////////////////////////
typedef enum {S1=0,S2,S3,S4} State_Red;
static State_Red State_R = S1;
void ledRedStateMachineUpdate(void){
    switch(State_R){
    case S1:
        if(switchState(1)==PRESSED){
            State_R = S2;
            //ledTimer = 1000;
        }
        break;
    case S2:
        if(switchState(1)==RELEASED){
            State_R = S3;
            //ledTimer = 1000;
        }
        break;
    case S3:
        if(switchState(1)==PRESSED){
            State_R = S4;
            //ledTimer = 1000;
        }
        break;
    case S4:
        if(switchState(1)==RELEASED){
            State_R = S1;
            //ledTimer = 1000;
        }
        break;
    }
    switch(State_R){
    case S1:
    case S4:
        ledControl(LEDRED,OFF);
        break;
    case S2:
    case S3:
        ledControl(LEDRED,ON);
        break;
    }
}
////////////////////////////////////////////////GREEN//////////////////////////////////////////////////
typedef enum {S_1=0,S_2,S_3,S_4,S_5,S_6} State_Green;
static State_Green State_G;
void ledGreenStateMachineUpdate(void){
    switch(State_G){
    case S_1:
        if(switchState(2)==PRESSED){
            State_G = S_2;
            ledTimer = 3000;
        }
        break;
    case S_2:
        if(switchState(2)==RELEASED){
            State_G = S_1;
        }
        else if(ledTimer==0){
            State_G = S_3;
        }
        break;
    case S_3:
        if(switchState(2)==RELEASED){
            State_G = S_4;
        }
        break;
    case S_4:
        if(switchState(2)==PRESSED){
            State_G = S_5;
            ledTimer = 6000;
        }
        break;
    case S_5:
        if(switchState(2)==RELEASED){
            State_G = S_4;
        }
        else if(ledTimer==0){
            State_G = S_6;
        }
        break;
    case S_6:
        if(switchState(2)==RELEASED){
            State_G = S_1;
        }
        break;
    }
    switch(State_G){
    case S_1:
    case S_2:
    case S_6:
        ledControl(LEDGREEN,OFF);
        break;
    case S_3:
    case S_4:
    case S_5:
        ledControl(LEDGREEN,ON);
    }
}
