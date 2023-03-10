/*
 * File: SubWallFollowHSM.c
 * Author: Zoe Levin, Demetrius Rauck, Gabriel Elkaim
 *
 * This file controls the wall following state machine of the spacejam
 * robot based off of IR sensors. The robot orients itself along the right wall
 * and follows the wall until it leaves the reload zone.
 */


/*******************************************************************************
 * MODULE #INCLUDE                                                             *
 ******************************************************************************/

#include "ES_Configure.h"
#include "ES_Framework.h"
#include "BOARD.h"
#include "HSM.h"
#include "SubHSM.h"
#include "LED.h"
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
#define IR_THRESHOLD 900
#define SWEETSPOT AD_PORTW3
#define TOO_CLOSE AD_PORTW4
#define FRONT_SENSOR AD_PORTW5

typedef enum {
    InitPSubWallFollowState,
    SubRightWallFollowState,
    SubCloseRightWallFollowState,
    SubFarRightWallFollowState,
    SubCornerRightWallFollowState,
    LeftTurnState,
    SubBackup,
    SubOrientWallState,
    
} SubHSMState_t;

static const char *StateNames[] = {
    "InitPSubWallFollowState",
    "SubRightWallFollowState",
    "SubCloseRightWallFollowState",
    "SubFarRightWallFollowState",
    "SubCornerRightWallFollowState",
    "LeftTurnState",
    "SubBackup",
    "SubOrientWallState",
};





/*******************************************************************************
 * PRIVATE MODULE VARIABLES                                                            *
 ******************************************************************************/

static SubHSMState_t CurrentState = InitPSubWallFollowState;
static uint8_t MyPriority;

/*******************************************************************************
 * PUBLIC FUNCTIONS                                                            *
 ******************************************************************************/

/**
 * @Function InitWallFollowSubHSM(uint8_t Priority)
 * @param Priority - internal variable to track which event queue to use
 * @return TRUE or FALSE
 * @brief This will get called by the framework at the beginning of the code
 *        execution. It will post an ES_INIT event to the appropriate event
 *        queue, which will be handled inside RunHSM function.
 *        Returns TRUE if successful, FALSE otherwise
 * @author Zoe Levin, Demetrius Rauck */
uint8_t InitWallFollowSubHSM(void) {
    ES_Event returnEvent;
    CurrentState = InitPSubWallFollowState;
    returnEvent = RunWallFollowSubHSM(INIT_EVENT);
    if (returnEvent.EventType == ES_NO_EVENT) {
        return TRUE;
    }
    return FALSE;
}

/**
 * @Function RunWallFollowSubHSM(ES_Event ThisEvent)
 * @param ThisEvent - the event (type and param) to be responded.
 * @return Event - return event (type and param), in general should be ES_NO_EVENT
 * @brief This function is where the whole of the hierarchical state
 *        machine is implemented, as this is called any time a new event is passed to the event
 *        queue. This function will be called recursively to implement the correct
 *        order for a state transition to be: exit current state -> enter next state
 *        using the ES_EXIT and ES_ENTRY events.
 * @note 
 *       The lower level state machines are run first, to see if the event is dealt
 *       with there rather than at the current level. ES_EXIT and ES_ENTRY events are
 *       not consumed as these need to pass pack to the higher level state machine.
 * @author Zoe Levin, Demetrius Rauck, Gabriel Elkaim */
ES_Event RunWallFollowSubHSM(ES_Event ThisEvent) {
    uint8_t makeTransition = FALSE; // use to flag transition
    SubHSMState_t nextState; 
    //ES_Tattle(); // trace call stack

    switch (CurrentState) {
        case InitPSubWallFollowState: // If current state is initial Pseudo State
            if (ThisEvent.EventType == ES_INIT)// only respond to ES_Init
            {
                //puts the machine into the actual initial state from the 
                //pseudo state
                DC_Speed(900);
                DC_Tank_Right();
                nextState = SubOrientWallState;
                makeTransition = TRUE;
                ThisEvent.EventType = ES_NO_EVENT;

            }
            break;
        //orients to wall
        case SubOrientWallState:
            switch (ThisEvent.EventType) {
                case ES_ENTRY:
                    DC_Tank_Right();
                    break;
                case ES_EXIT:
                    ES_Timer_InitTimer(ZONE_TIMER, 3500);
                    LED_SetBank(LED_BANK1, 0x0);
                    break;
                case IR_R_SWEETSPOT:
                    //JUST RIGHT
                    nextState = SubRightWallFollowState;
                    makeTransition = TRUE;
                    ThisEvent.EventType = ES_NO_EVENT;
                    break;
                case IR_R_TOO_CLOSE:
                    // TOO CLOSE
                    nextState = SubCloseRightWallFollowState;
                    makeTransition = TRUE;
                    ThisEvent.EventType = ES_NO_EVENT;

                    break;
                default:
                    DC_Tank_Right(); //bot won't tank without this
                    break;
            }
            break;
        //Following the wall straight
        case SubRightWallFollowState: 
            switch (ThisEvent.EventType) {
                case ES_ENTRY:
                    DC_Speed(700);
                    DC_Fwd();
                    break;
                case ES_EXIT:
                    break;
                case IR_R_TOO_CLOSE:
                    // TOO CLOSE
                    nextState = SubCloseRightWallFollowState;
                    makeTransition = TRUE;
                    ThisEvent.EventType = ES_NO_EVENT;

                    break;
                case IR_R_TOO_FAR:
                    // TOO FAR
                    nextState = SubFarRightWallFollowState;
                    makeTransition = TRUE;
                    ThisEvent.EventType = ES_NO_EVENT;
                    break;
                case IR_F_TOO_CLOSE:
                    //forward obstacle
                    if (AD_ReadADPin(SWEETSPOT) < IR_THRESHOLD) {
                        nextState = LeftTurnState;
                        makeTransition = TRUE;
                        ThisEvent.EventType = ES_NO_EVENT;
                    } else {
                        nextState = SubCornerRightWallFollowState;
                        makeTransition = TRUE;
                        ThisEvent.EventType = ES_NO_EVENT;
                    }
                    break;
                default:
                    break;
            }
            break;
        //Following too close to the wall
        case SubCloseRightWallFollowState: 
            switch (ThisEvent.EventType) {
                case ES_ENTRY:
                    DC_Arc_Left();
                    break;
                case ES_EXIT:
                    LED_SetBank(LED_BANK1, 0x0);
                    break;
                case IR_R_SWEETSPOT:
                    //JUST RIGHT
                    nextState = SubRightWallFollowState;
                    makeTransition = TRUE;
                    ThisEvent.EventType = ES_NO_EVENT;
                    break;
                case IR_F_TOO_CLOSE:
                    //forward obstacle
                    if (AD_ReadADPin(SWEETSPOT) < IR_THRESHOLD) {
                        nextState = LeftTurnState;
                        makeTransition = TRUE;
                        ThisEvent.EventType = ES_NO_EVENT;
                    } else {
                        nextState = SubCornerRightWallFollowState;
                        makeTransition = TRUE;
                        ThisEvent.EventType = ES_NO_EVENT;
                    }
                    break;
                case IR_R_TOO_FAR:
                    // TOO FAR
                    nextState = SubFarRightWallFollowState;
                    makeTransition = TRUE;
                    ThisEvent.EventType = ES_NO_EVENT;
                    break;
                default:
                    break;
            }
            break;
        //Following too far from the wall
        case SubFarRightWallFollowState: 
            switch (ThisEvent.EventType) {
                case ES_ENTRY:
                    DC_Arc_Right();
                    break;
                case ES_EXIT:
                    break;
                case IR_R_SWEETSPOT:
                    //JUST RIGHT
                    nextState = SubRightWallFollowState;
                    makeTransition = TRUE;
                    ThisEvent.EventType = ES_NO_EVENT;
                    break;
                case IR_R_TOO_CLOSE:
                    // TOO CLOSE
                    nextState = SubCloseRightWallFollowState;
                    makeTransition = TRUE;
                    ThisEvent.EventType = ES_NO_EVENT;

                    break;
                case IR_F_TOO_CLOSE:
                    //forward obstacle
                    if (AD_ReadADPin(SWEETSPOT) < IR_THRESHOLD) {
                        nextState = LeftTurnState;
                        makeTransition = TRUE;
                        ThisEvent.EventType = ES_NO_EVENT;
                    } else {
                        nextState = SubCornerRightWallFollowState;
                        makeTransition = TRUE;
                        ThisEvent.EventType = ES_NO_EVENT;
                    }
                    break;
                default:
                    break;
            }
            break;
        //Robot is in a corner
        case SubCornerRightWallFollowState:
            switch (ThisEvent.EventType) {
                case ES_ENTRY:
                    LED_SetBank(LED_BANK3, 0xF);
                    DC_Speed(900);
                    DC_Tank_Left();
                    ES_Timer_InitTimer(CORNER_TIMER, 700);
                    break;
                case ES_EXIT:
                    LED_SetBank(LED_BANK3, 0x0);

                    LED_SetBank(LED_BANK2, 0x0);
                    break;
                case ES_TIMEOUT:
                    if (AD_ReadADPin(FRONT_SENSOR) < IR_THRESHOLD) {
                            nextState = SubBackup;
                            makeTransition = TRUE;
                            ThisEvent.EventType = ES_NO_EVENT;
                        } else {
                   
                            nextState = SubRightWallFollowState;
                            makeTransition = TRUE;
                            ThisEvent.EventType = ES_NO_EVENT;
                        }
                    break;
                case IR_R_TOO_CLOSE:
                    //FRONT SENSOR IS OFF
                    if (AD_ReadADPin(FRONT_SENSOR) > IR_THRESHOLD) {
                        // TOO CLOSE
                        nextState = SubCloseRightWallFollowState;
                        makeTransition = TRUE;
                        ThisEvent.EventType = ES_NO_EVENT;
                    }
                    break;
                case IR_R_SWEETSPOT:
                    //JUST RIGHT
                    //FRONT SENSOR IS OFF
                    if (AD_ReadADPin(FRONT_SENSOR) > IR_THRESHOLD) {

                        nextState = SubRightWallFollowState;
                        makeTransition = TRUE;
                        ThisEvent.EventType = ES_NO_EVENT;
                    }
                    break;
           
                default:
                    break;
            }
            break;
        //Robot turns left
        case LeftTurnState:
            switch (ThisEvent.EventType) {
                case ES_ENTRY:
       
                    DC_Speed(900);
                    DC_Tank_Left();
                    ES_Timer_InitTimer(NINETY_TURN, 650);
                    break;
                case ES_EXIT:
                    LED_SetBank(LED_BANK3, 0x0);
                    break;
                case ES_TIMEOUT:
                    if (ThisEvent.EventParam == NINETY_TURN) {
                        //if front is still on-- backupstate
                        if (AD_ReadADPin(FRONT_SENSOR) < IR_THRESHOLD) {
                            nextState = SubBackup;
                            makeTransition = TRUE;
                            ThisEvent.EventType = ES_NO_EVENT;
                        } else {
                    
                            nextState = SubRightWallFollowState;
                            makeTransition = TRUE;
                            ThisEvent.EventType = ES_NO_EVENT;
                        }
                    }
                    break;
                default:
                    break;
            }
            break;
        //Robot Backs up
        case SubBackup:
            switch (ThisEvent.EventType) {
                case ES_ENTRY:
                    DC_Speed(900);
                    DC_Back();
                    ES_Timer_InitTimer(BACKUP_TIMER, 1000);
                    break;
                case ES_EXIT:
                    LED_SetBank(LED_BANK1, 0x0);
                    break;
                case ES_TIMEOUT:
                    if (ThisEvent.EventParam == BACKUP_TIMER) {
                        nextState = SubFarRightWallFollowState;
                        makeTransition = TRUE;
                        ThisEvent.EventType = ES_NO_EVENT;
                    }
                    break;
                default:
                    break;
            }
            break;         
        default: // all unhandled states fall into here
            break;
    } // end switch on Current State

    if (makeTransition == TRUE) { // making a state transition, send EXIT and ENTRY
        // recursively call the current state with an exit event
        RunWallFollowSubHSM(EXIT_EVENT); 
        CurrentState = nextState;
        RunWallFollowSubHSM(ENTRY_EVENT); 
    }
    //ES_Tail(); // trace call stack end
    return ThisEvent;
}




