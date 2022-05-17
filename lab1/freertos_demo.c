#include "include.h"
#include "FSM/FSM.h"
#include "Nokia5110/SPI.h"
#include "Config_Register/Config_Register.h"
/*-----------------------------------------------------------*/
void vApplicationMallocFailedHook( void )
{
    /* This function will only be called if an API call to create a task, queue
    or semaphore fails because there is too little heap RAM remaining. */
    for( ;; );
}
/*-----------------------------------------------------------*/

void vApplicationStackOverflowHook( xTaskHandle *pxTask, signed char *pcTaskName )
{
    /* This function will only be called if a task overflows its stack.  Note
    that stack overflow checking does slow down the context switch
    implementation. */
    for( ;; );
}
/*-----------------------------------------------------------*/
volatile unsigned int Idle = 0;
void vApplicationIdleHook( void )
{
    /* This example does not use the idle hook to perform any processing. */
    Idle++;
}
/*-----------------------------------------------------------*/

void vApplicationTickHook( void )
{
    /* This example does not use the tick hook to perform any processing. */
}
/*-----------------------------------------------------------*/
TaskHandle_t xTask1Handle;
TaskHandle_t xTask2Handle;

void vTask1(void *pvParameters){
    while(1){
    }
}
void vTask2(void *pvParameters){
    while(1){
    }
}
int main(){
    SysCtlClockSet(SYSCTL_SYSDIV_4|SYSCTL_USE_PLL|SYSCTL_XTAL_16MHZ|SYSCTL_OSC_MAIN);

    IntMasterEnable();
    //UARTprintf("%d",xPortGetFreeHeapSize());
    vTaskStartScheduler();
    while(1){

    }
}
