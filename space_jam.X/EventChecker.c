/*
 * File:   EventChecker.c
 * Author: Zoe Levin, Demetrius Rauck, Gabriel Elkaim
 *
 * File to set up typical EventCheckers for the  Events and Services
 * Framework (ES_Framework) on the Uno32. Defines event checking for 
 * IR sensors and beacon detector on Space Jam robot. 
 * EventChecker only returns TRUE when an event has occurred.
 *
 * This file includes a test harness that will run the event detectors listed in the
 * ES_Configure file in the project, and will conditionally compile main if the macro
 * EVENTCHECKER_TEST is defined (either in the project or in the file). This will allow
 * you to check you event detectors in their own project, and then leave them untouched
 * for the main project unless you need to alter their post functions.
 */

/*******************************************************************************
 * MODULE #INCLUDE                                                             *
 ******************************************************************************/

#include "ES_Configure.h"
#include "EventChecker.h"
#include "ES_Events.h"
#include "serial.h"
#include <xc.h>
#include "AD.h"
#include "IO_Ports.h"
#include <stdio.h>
#include "LED.h"
#include "pwm.h"
#include "ES_Timers.h"
#include "HSM.h"
/*******************************************************************************
 * MODULE #DEFINES                                                             *
 ******************************************************************************/

#define IR_THRESHOLD 900
#define RELOAD_THRESHOLD 675
#define OUT_OF_RANGE_THRESHOLD 670
#define FILTER_LENGTH 5

/*******************************************************************************
 * EVENTCHECKER_TEST SPECIFIC CODE                                                             *
 ******************************************************************************/

//#define EVENTCHECKER_TEST
#ifdef EVENTCHECKER_TEST
#include <stdio.h>
#define SaveEvent(x) do {eventName=__func__; storedEvent=x;} while (0)

static const char *eventName;
static ES_Event storedEvent;
#endif

/*******************************************************************************
 * PUBLIC FUNCTIONS                                                            *
 ******************************************************************************/

static enum {
    CLOSE_R, FAR_R, SWEETSPOT_R
} lastIR_R_State = CLOSE_R;

uint8_t IR_R_Sensing(void) {

    enum {
        CLOSE_R, FAR_R, SWEETSPOT_R
    } currentIR_R_State;

    uint16_t currentIR_R_SWEETSPOT_Value;
    uint16_t currentIR_R_TOO_CLOSE_Value;
    uint8_t returnVal = FALSE;
    ES_Event ThisEvent;
    ES_EventTyp_t curEvent;

    //GET AD VALUE OF IR SENSORS 
    currentIR_R_SWEETSPOT_Value = AD_ReadADPin(AD_PORTW3);
    currentIR_R_TOO_CLOSE_Value = AD_ReadADPin(AD_PORTW4);

    //EVENT DETECTION
    if ((currentIR_R_SWEETSPOT_Value < IR_THRESHOLD) &&
            (currentIR_R_TOO_CLOSE_Value >= IR_THRESHOLD)) {
        currentIR_R_State = SWEETSPOT_R;
        curEvent = IR_R_SWEETSPOT;
    } else if ((currentIR_R_SWEETSPOT_Value < IR_THRESHOLD) &&
            (currentIR_R_TOO_CLOSE_Value < IR_THRESHOLD)) {
        currentIR_R_State = CLOSE_R;
        curEvent = IR_R_TOO_CLOSE;
    } else if ((currentIR_R_SWEETSPOT_Value >= IR_THRESHOLD) &&
            (currentIR_R_TOO_CLOSE_Value >= IR_THRESHOLD)) {
        currentIR_R_State = FAR_R;
        curEvent = IR_R_TOO_FAR;
    }
    //EVENT DETECTED
    if (currentIR_R_State != lastIR_R_State) {
        ThisEvent.EventType = curEvent;
        returnVal = TRUE;
        lastIR_R_State = currentIR_R_State;
#ifndef EVENTCHECKER_TEST   
        //POST TO SERVICE
        Post_SPACE_JAM_HSM(ThisEvent);
#else
        SaveEvent(ThisEvent);
#endif  
    }
    return returnVal;
}

static enum {
    CLOSE_F, FAR_F
} lastIR_F_State = CLOSE_F;

uint8_t IR_F_Sensing(void) {

    enum {
        CLOSE_F, FAR_F
    } currentIR_F_State;

    uint16_t currentIR_F_Value;
    int flag = 0;
    uint8_t returnVal = FALSE;
    ES_Event ThisEvent;
    static uint16_t arrayIR_F_value[FILTER_LENGTH] = {0};
    ES_EventTyp_t curEvent;

    /* Take a history of last 4 function calls and move them 
     * forward one spot in the array. Add one to flag variable 
     * if out of range, else subtract one. */
    for (int i = 1; i <= FILTER_LENGTH; i++) {
        arrayIR_F_value[i - 1] = arrayIR_F_value[i];
        if (arrayIR_F_value[i - 1] >= IR_THRESHOLD) {
            flag += 1;
        } else {
            flag -= 1;
        }
    }

    currentIR_F_Value = AD_ReadADPin(AD_PORTW5);
    arrayIR_F_value[FILTER_LENGTH] = currentIR_F_Value;

    /*add/subtract flag for according current IR value*/
    if (arrayIR_F_value[FILTER_LENGTH] >= IR_THRESHOLD) {
        flag += 1;
    } else {
        flag -= 1;
    }

    //UNDER OR OVER VOLTAGE 5 TIMES IN A ROW
    if (flag == FILTER_LENGTH) {
        currentIR_F_State = FAR_F;
        curEvent = IR_F_TOO_FAR;
    } else if (flag == -FILTER_LENGTH) {
        currentIR_F_State = CLOSE_F;
        curEvent = IR_F_TOO_CLOSE;
    }

    //EVENT DETECTED
    if (currentIR_F_State != lastIR_F_State) {
        ThisEvent.EventType = curEvent;
        ThisEvent.EventParam = (uint16_t) currentIR_F_Value;
        returnVal = TRUE;
        lastIR_F_State = currentIR_F_State;
#ifndef EVENTCHECKER_TEST           // keep this as is for test harness
        Post_SPACE_JAM_HSM(ThisEvent);
#else
        SaveEvent(ThisEvent);
#endif  
    }
    return returnVal;
}

static enum {
    CLOSE_B, FAR_B
} lastIR_B_State = CLOSE_B;

uint8_t IR_B_Sensing(void) {

    enum {
        CLOSE_B, FAR_B
    } currentIR_B_State;

    uint16_t currentIR_B_Value;
    int flag = 0;
    uint8_t returnVal = FALSE;
    ES_Event ThisEvent;
    static uint16_t arrayIR_B_value[FILTER_LENGTH] = {0};
    ES_EventTyp_t curEvent;

    /* Take a history of last 4 function calls and move them 
     * forward one spot in the array. Add one to flag variable 
     * if out of range, else subtract one. */
    for (int i = 1; i <= FILTER_LENGTH; i++) {
        arrayIR_B_value[i - 1] = arrayIR_B_value[i];
        if (arrayIR_B_value[i - 1] >= IR_THRESHOLD) {
            flag += 1;
        } else {
            flag -= 1;
        }
    }
    currentIR_B_Value = AD_ReadADPin(AD_PORTW8);
    arrayIR_B_value[FILTER_LENGTH] = currentIR_B_Value;

    /*add/subtract flag for according current IR value*/
    if (arrayIR_B_value[FILTER_LENGTH] >= IR_THRESHOLD) {
        flag += 1;
    } else {
        flag -= 1;
    }

    //UNDER OR OVER VOLTAGE 5 TIMES IN A ROW
    if (flag == FILTER_LENGTH) {
        currentIR_B_State = FAR_B;
        curEvent = IR_B_TOO_FAR;
    } else if (flag == -FILTER_LENGTH) {
        currentIR_B_State = CLOSE_B;
        curEvent = IR_B_TOO_CLOSE;
    }

    //EVENT DETECTED
    if (currentIR_B_State != lastIR_B_State) {
        ThisEvent.EventType = curEvent;
        ThisEvent.EventParam = (uint16_t) currentIR_B_Value;
        returnVal = TRUE;
        lastIR_B_State = currentIR_B_State;
#ifndef EVENTCHECKER_TEST           // keep this as is for test harness
        Post_SPACE_JAM_HSM(ThisEvent);
#else
        SaveEvent(ThisEvent);
#endif  
    }
    return returnVal;
}

static enum {
    IN_RANGE, OUT_OF_RANGE
} lastBeaconState = OUT_OF_RANGE;

uint8_t Beacon_Detection(void) {

    static enum {
        IN_RANGE, OUT_OF_RANGE
    } currentBeaconState;

    uint16_t currentBeaconValue;
    uint8_t returnVal = FALSE;
    ES_Event ThisEvent;
    int flag = 0;
    ES_EventTyp_t curEvent;
    uint16_t lastBeaconValue;

    static uint16_t arrayBeaconvalue[FILTER_LENGTH] = {0};

    /* Take a history of last 4 function calls and move them 
     * forward one spot in the array. Add one to flag variable 
     * if out of range, else subtract one. */
    for (int i = 1; i <= FILTER_LENGTH; i++) {
        arrayBeaconvalue[i - 1] = arrayBeaconvalue[i];
        if (arrayBeaconvalue[i - 1] >= RELOAD_THRESHOLD) {
            flag += 1;
        } else if (arrayBeaconvalue[i - 1] <= OUT_OF_RANGE_THRESHOLD) {
            flag -= 1;
        }
    }
    currentBeaconValue = AD_ReadADPin(AD_PORTV3);
    arrayBeaconvalue[FILTER_LENGTH] = currentBeaconValue;

    /* add/subtract flag for according current beacon value */
    if (arrayBeaconvalue[FILTER_LENGTH] >= RELOAD_THRESHOLD) {
        flag += 1;
    } else if (arrayBeaconvalue[FILTER_LENGTH] <= OUT_OF_RANGE_THRESHOLD) {
        flag -= 1;
    }

    //UNDER OR OVER VOLTAGE 5 TIMES IN A ROW
    if (flag == FILTER_LENGTH) {
        currentBeaconState = IN_RANGE;
        curEvent = INRANGE;
    } else if (flag == -FILTER_LENGTH) {
        currentBeaconState = OUT_OF_RANGE;
        curEvent = OUTOFRANGE;
    }

    //EVENT DETECTED
    if (currentBeaconState != lastBeaconState) {
        ThisEvent.EventType = curEvent;
        ThisEvent.EventParam = (uint16_t) currentBeaconValue;
        returnVal = TRUE;
        lastBeaconValue = currentBeaconValue;
        lastBeaconState = currentBeaconState;

#ifndef EVENTCHECKER_TEST           // keep this as is for test harness
        Post_SPACE_JAM_HSM(ThisEvent);
#else
        SaveEvent(ThisEvent);
#endif  
    }
    return returnVal;
}

/* 
 * The Test Harness for the event checkers is conditionally compiled using
 * the EVENTCHECKER_TEST macro (defined either in the file or at the project level).
 * No other main() can exist within the project.
 * 
 * It requires a valid ES_Configure.h file in the project with the correct events in 
 * the enum, and the correct list of event checkers in the EVENT_CHECK_LIST.
 * 
 * The test harness will run each of your event detectors identically to the way the
 * ES_Framework will call them, and if an event is detected it will print out the function
 * name, event, and event parameter. Use this to test your event checking code and
 * ensure that it is fully functional.
 * 
 * If you are locking up the output, most likely you are generating too many events.
 * Remember that events are detectable changes, not a state in itself.
 * 
 * Once you have fully tested your event checking code, you can leave it in its own
 * project and point to it from your other projects. If the EVENTCHECKER_TEST marco is
 * defined in the project, no changes are necessary for your event checkers to work
 * with your other projects.
 */
#ifdef EVENTCHECKER_TEST
#include <stdio.h>
static uint8_t(*EventList[])(void) = {EVENT_CHECK_LIST};

void PrintEvent(void);

void main(void) {
    BOARD_Init();
    /* user initialization code goes here */

    // Do not alter anything below this line
    int i;

    printf("\r\nEvent checking test harness for %s", __FILE__);

    while (1) {
        if (IsTransmitEmpty()) {
            for (i = 0; i< sizeof (EventList) >> 2; i++) {
                if (EventList[i]() == TRUE) {
                    PrintEvent();

                    break;
                }

            }
        }
    }
}

void PrintEvent(void) {
    printf("\r\nFunc: %s\tEvent: %s\tParam: 0x%X", eventName,
            EventNames[storedEvent.EventType], storedEvent.EventParam);
}
#endif