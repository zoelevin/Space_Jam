/*
 * File:   SubBeaconHSM.c
 * Author: Demetrius Rauck, Zoe Levin
 * 
 * This file controls the beacon orientation state machine of the spacejam 
 * robot. It orients the beacon detector to find the beacon then activates 
 * the flywheel and loading actuator to load a ping pong ball in the barrel
 * and shoot it.
 * 
 * Created on November 27, 2022, 3:48 PM
 */


/*******************************************************************************
 * MODULE #INCLUDE                                                             *
 ******************************************************************************/

#include "ES_Configure.h"
#include "ES_Framework.h"
#include "BOARD.h"
#include "HSM.h"
#include "SubHSM.h"
#include "AD.h"
#include <stdio.h>
#include "EventChecker.h"
#include "Service.h"
#include "Wheels.h"


/*******************************************************************************
 * MODULE #DEFINES                                                             *
 ******************************************************************************/
#define HALF_SEC 500
#define FL 0x1
#define FR 0x2
#define RL 0x4
#define RR 0x8

#define FL_AND_FR 0x3
#define RR_AND_RL 0xC

#define TURN_90 90000
#define TOP_SPEED 100
#define LOWER_SPEED 70

typedef enum {
    InitPSubBeaconState,
    SubLeftBeaconState,
    SubDetectedBeaconState,
    SubShootBeaconState
} SubHSMState_t;

static const char *StateNames[] = {
    "InitPSubBeaconState",
    "SubLeftBeaconState",
    "SubDetectedBeaconState",
    "SubShootBeaconState"
};




/*******************************************************************************
 * PRIVATE MODULE VARIABLES                                                            *
 ******************************************************************************/

static SubHSMState_t CurrentState = InitPSubBeaconState;
static uint8_t MyPriority;

/*******************************************************************************
 * PUBLIC FUNCTIONS                                                            *
 ******************************************************************************/

/**
 * @Function InitBeaconSubHSM(uint8_t Priority)
 * @param Priority - internal variable to track which event queue to use
 * @return TRUE or FALSE
 * @brief This will get called by the framework at the beginning of the code
 *        execution. It will post an ES_INIT event to the appropriate event
 *        queue, which will be handled inside BeaconSubHSM function.
 *        Returns TRUE if successful, FALSE otherwise
 * @author Zoe Levin, Demetrius Rauck */
uint8_t InitBeaconSubHSM(void) {
    ES_Event returnEvent;
    CurrentState = InitPSubBeaconState;
    returnEvent = RunBeaconSubHSM(INIT_EVENT);
    if (returnEvent.EventType == ES_NO_EVENT) {
        return TRUE;
    }
    return FALSE;
}

/**
 * @Function RunBeaconSubHSM(ES_Event ThisEvent)
 * @param ThisEvent - the event (type and param) to be responded.
 * @return Event - return event (type and param), in general should be ES_NO_EVENT
 * @brief This function controls the beacon orientation state machine of the spacejam 
 * robot. It orients the beacon detector to find the beacon then activates 
 * the flywheel and loading actuator to load a ping pong ball in the barrel
 * and shoot it.
 * @note 
 *       The lower level state machines are run first, to see if the event is dealt
 *       with there rather than at the current level. ES_EXIT and ES_ENTRY events are
 *       not consumed as these need to pass pack to the higher level state machine.
 * @author Zoe Levin, Demetrius Rauck, Gabriel Elkaim */

ES_Event RunBeaconSubHSM(ES_Event ThisEvent) {
    uint8_t makeTransition = FALSE; // use to flag transition
    SubHSMState_t nextState; 
    static int16_t last_array[40] = {0};
    //ES_Tattle(); // trace call stack
    static int dir = 0;
    switch (CurrentState) {
        case InitPSubBeaconState: // If current state is initial Pseudo State
            if (ThisEvent.EventType == ES_INIT)// only respond to ES_Init
            {
                //puts the machine into the actual initial state from the 
                //pseudo state
                nextState = SubLeftBeaconState;
                dir = 0;
                makeTransition = TRUE;
                ThisEvent.EventType = ES_NO_EVENT;
            }
            break;
        //When the beacon is to the left of the detector
        case SubLeftBeaconState: 
            switch (ThisEvent.EventType) {
                case ES_ENTRY:
                    DC_Speed(900);
                    ES_Timer_InitTimer(ORIENT_TWO, 10000);
                    dir = 0;
                    DC_Tank_Left();
                    break;
                case ES_EXIT:
                    break;
                case INRANGE:
                    nextState = SubDetectedBeaconState;
                    makeTransition = TRUE;
                    ThisEvent.EventType = ES_NO_EVENT;
                    break;
                default:
                    DC_Tank_Left();
                    break;
            }
            break;
        //Beacon has been detected
        //Ping pong balls start loading
        case SubDetectedBeaconState: 
            switch (ThisEvent.EventType) {
                case ES_ENTRY:
                    DC_Tank_Left();
                    ES_Timer_InitTimer(OREINT_TIMER, 75);
                    break;
                case ES_EXIT:
                    break;
                case OUTOFRANGE:
                    break;
                case ES_TIMEOUT:
                    if (ThisEvent.EventParam == OREINT_TIMER) {
                        nextState = SubShootBeaconState;
                        makeTransition = TRUE;
                        ThisEvent.EventType = ES_NO_EVENT;
                        DC_Off();
                    }
                    break;
                default:
                    DC_Tank_Left();
                    break;
            }
            break;
       //Beacon is shooting ping pong balls, stops loading
        case SubShootBeaconState:
            switch (ThisEvent.EventType) {
                case ES_ENTRY:
                    DC_Off();
                    Fly_Speed(900);
                    Fly_On();
                    Reload_Off();
                    ES_Timer_InitTimer(RELOAD_TIMER, 1000);
                    break;
                case ES_EXIT:
                    break;
                case ES_TIMEOUT:
                    if (ThisEvent.EventParam == SHOOT_TIMER) {
                        Fly_Off();
                        Reload_Off();
                        nextState = InitPSubBeaconState;
                        makeTransition = TRUE;
                        ThisEvent.EventType = SHOTS_FIRED;
                    } else if (ThisEvent.EventParam == RELOAD_TIMER) {
                        ES_Timer_InitTimer(SHOOT_TIMER, 5000);
                        Fly_Speed(600);
                        Reload_On();
                        ThisEvent.EventType = ES_NO_EVENT;
                    }
                    break;
                default:
                    break;
            }

            break;
        default:
            break;

    } 


    if (makeTransition == TRUE) { // making a state transition, send EXIT and ENTRY
        // recursively call the current state with an exit event
        RunBeaconSubHSM(EXIT_EVENT); 
        CurrentState = nextState;
        RunBeaconSubHSM(ENTRY_EVENT); 
    }

    //ES_Tail(); // trace call stack end
    return ThisEvent;
}

