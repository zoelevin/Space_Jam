#include <BOARD.h>
#include <xc.h>
#include <stdio.h>
#include "ES_Configure.h"
#include "ES_Framework.h"
#include "LED.h"
#include "AD.h"
#include "pwm.h"
#include "ES_Timers.h"
#include "IO_Ports.h"
#include "Wheels.h"
//helper functions
unsigned int wait = 0;
#define DELAY(x)    for (wait = 0; wait <= x; wait++) {asm("nop");}
#define A_BIT       40000
#define A_BIT_MORE  60000
#define A_LOT       80000
#define LIGHT_SEQUENCE 4
#define LED_1 0x1
#define TRIGGER_PIN PIN4

typedef enum {
    right,
    left,
} LED_state;



LED_state dir = right;

void LED_light_flip_flop() {
    if (LED_GetBank(LED_BANK1) == 0x01) {
        dir = left;
    } else if (LED_GetBank(LED_BANK1) == 0x08) {
        dir = right;
    }

    if (dir == left) {
        LED_SetBank(LED_BANK1, LED_GetBank(LED_BANK1) << 1);
        LED_SetBank(LED_BANK2, LED_GetBank(LED_BANK2) >> 1);
        LED_SetBank(LED_BANK3, LED_GetBank(LED_BANK3) << 1);
    } else if (dir == right) {
        LED_SetBank(LED_BANK1, LED_GetBank(LED_BANK1) >> 1);
        LED_SetBank(LED_BANK2, LED_GetBank(LED_BANK2) << 1);
        LED_SetBank(LED_BANK3, LED_GetBank(LED_BANK3) >> 1);
    }
    DELAY(A_BIT_MORE);
}

void main(void) {
    ES_Return_t ErrorType;

    BOARD_Init();

    AD_Init();
    AD_AddPins(AD_PORTW4 | AD_PORTW3 | AD_PORTW5 | AD_PORTW6
            | AD_PORTW7 | AD_PORTW8 | AD_PORTV5 | AD_PORTV6 | AD_PORTV3 
            | AD_PORTV7 | AD_PORTV8 | AD_PORTV4);
    PORTX03_TRIS = 0;
    PORTX03_LAT = 1;
    //    AD_AddPins(AD_PORTV3);
    //    AD_AddPins(AD_PORTV4);
    //    AD_AddPins(AD_PORTV5);
    //    AD_AddPins(AD_PORTV6);
    //    AD_AddPins(AD_PORTV8);
    //    AD_AddPins(AD_PORTW3);
    //    AD_AddPins(AD_PORTW5);
    LED_Init();
    //Wheels_Init();
    DC_Init();
    LED_AddBanks(LED_BANK1 | LED_BANK2 | LED_BANK3);
    //IO_PortsSetPortOutputs(PORTV, PIN3);
    //    PWM_Init();
    //    PWM_AddPins(PWM_PORTY12);

    ES_Timer_Init();
    Fly_Init();
    Reload_Init();
    Reload_Off();
    printf("\r\nStarting Events and Services\r\n");
    LED_SetBank(LED_BANK1, 0x01);
    LED_SetBank(LED_BANK2, 0x08);
    LED_SetBank(LED_BANK3, 0x01);

    //IO_PortsSetPortInputs(PORTV, PIN8);
    //    unsigned int freq_test;
    //    PWM_SetFrequency(MIN_PWM_FREQ);
    //    freq_test = PWM_GetFrequency();
    //    printf("current frequency: %u hertz", freq_test);
    //
    //    unsigned int duty = 10;
    //    unsigned int duty_test;
    //    PWM_SetDutyCycle(PWM_PORTY12, duty);
    //    duty_test = PWM_GetDutyCycle(PWM_PORTY12);
    //    printf("\r\ncurrent duty cycle: %u %", duty_test);



    // Your hardware initialization function calls go here

    // now initialize the Events and Services Framework and start it running
    ErrorType = ES_Initialize();
    if (ErrorType == Success) {
        ErrorType = ES_Run();

    }
    //if we got to here, there was an error
    switch (ErrorType) {
        case FailedPointer:
            printf("Failed on NULL pointer");
            break;
        case FailedInit:
            printf("Failed Initialization");
            break;
        default:
            printf("Other Failure: %d", ErrorType);
            break;
    }
    for (;;)
        ;

};

/*------------------------------- Footnotes -------------------------------*/
/*------------------------------ End of file ------------------------------*/
