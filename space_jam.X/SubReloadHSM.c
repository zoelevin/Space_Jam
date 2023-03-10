/*
 * File:   SubReloadHSM.c
 * Author: Demetrius Rauck, Zoe Levin
 * 
 * This file controls the reloading state machine of the spacejam robot. It 
 * orients itself along the left wall and drives backwards following the right
 * wall until it reaches the reloading section.
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

#define BACKSENSOR AD_PORTW8
#define FRONTSENSOR AD_PORTW5
#define SWEETSPOTSENSOR AD_PORTW4
#define TOOCLOSESENSOR AD_PORTW3

typedef enum {
    InitPSubReloadState,
    SubReloadState,
    SubBackOrientState,
    SubBackCloseState,
    SubBackSweetSpotState,
    SubBackFarState,
    SubBackCornerState,
    SubBackRightTurnState,
    SubForward,
} SubHSMState_t;

static const char *StateNames[] = {
    "InitPSubReloadState",
    "SubReloadState"
    "SubBackOrientState",
    "SubBackCloseState",
    "SubBackSweetSpotState",
    "SubBackFarState",
    "SubBackCornerState",
    "SubBackRightTurnState",
    "SubForward",

};



/*******************************************************************************
 * PRIVATE MODULE VARIABLES                                                            *
 ******************************************************************************/
static SubHSMState_t CurrentState = InitPSubReloadState;
static uint8_t MyPriority;

/*******************************************************************************
 * PUBLIC FUNCTIONS                                                            *
 ******************************************************************************/

/**
 * @Function InitReloadSubHSM(uint8_t Priority)
 * @param Priority - internal variable to track which event queue to use
 * @return TRUE or FALSE
 * @brief This will get called by the framework at the beginning of the code
 *        execution. It will post an ES_INIT event to the appropriate event
 *        queue, which will be handled inside ReloadSubHSM function.
 *        Returns TRUE if successful, FALSE otherwise
 * @author Zoe Levin, Demetrius Rauck */
uint8_t InitReloadSubHSM(void) {
    ES_Event returnEvent;

    CurrentState = InitPSubReloadState;
    returnEvent = RunReloadSubHSM(INIT_EVENT);
    if (returnEvent.EventType == ES_NO_EVENT) {
        return TRUE;
    }
    return FALSE;
}

/**
 * @Function RunReloadSubHSM(ES_Event ThisEvent)
 * @param ThisEvent - the event (type and param) to be responded.
 * @return Event - return event (type and param), in general should be ES_NO_EVENT
 * @brief This state machine happens after the ping pong balls have been shot.
 * The robot uses IR sensors to follow the right wall backwards into the reload 
 * zone
 * @author Zoe Levin, Demetrius Rauck, Gabriel Elkaim */
ES_Event RunReloadSubHSM(ES_Event ThisEvent) {
    uint8_t makeTransition = FALSE; // use to flag transition
    SubHSMState_t nextState; 

    //ES_Tattle(); // trace call stack

    switch (CurrentState) {
        case InitPSubReloadState:
            if (ThisEvent.EventType == ES_INIT)// only respond to ES_Init
            {
                DC_Speed(900);
                DC_Tank_Right();
                nextState = SubBackSweetSpotState;
                makeTransition = TRUE;
                ThisEvent.EventType = ES_NO_EVENT;
            }
            break;
        //Orienting to wall
        case SubBackOrientState:
            switch (ThisEvent.EventType) {
                case ES_ENTRY:
                    DC_Tank_Right();
                    break;
                case ES_EXIT:
                    LED_SetBank(LED_BANK1, 0x0);
                    break;
                case IR_R_SWEETSPOT:
                    //JUST RIGHT
                    nextState = SubBackSweetSpotState;
                    makeTransition = TRUE;
                    ThisEvent.EventType = ES_NO_EVENT;
                    break;
                case IR_R_TOO_CLOSE:
                    // TOO CLOSE
                    nextState = SubBackCloseState;
                    makeTransition = TRUE;
                    ThisEvent.EventType = ES_NO_EVENT;

                    break;
                default:
                    DC_Tank_Right();
                    break;
            }
            break;
        //is close to the right wall but not close enough to bump it
        case SubBackSweetSpotState:
            switch (ThisEvent.EventType) {
                case ES_ENTRY:
                    LED_SetBank(LED_BANK1, 0x02);
                    DC_Speed(900);
                    DC_Back();
                    break;
                case ES_EXIT:
                    LED_SetBank(LED_BANK1, 0x0);

                    break;
                case IR_R_TOO_CLOSE:
                    // TOO CLOSE
                    nextState = SubBackCloseState;
                    makeTransition = TRUE;
                    ThisEvent.EventType = ES_NO_EVENT;

                    break;
                case IR_R_TOO_FAR:
                    // TOO FAR
                    nextState = SubBackFarState;
                    makeTransition = TRUE;
                    ThisEvent.EventType = ES_NO_EVENT;
                    break;
                case IR_B_TOO_CLOSE:
                    //forward obstacle
                    if (AD_ReadADPin(SWEETSPOTSENSOR) < IR_THRESHOLD) {
                        nextState = SubBackRightTurnState;
                        makeTransition = TRUE;
                        ThisEvent.EventType = ES_NO_EVENT;
                    } else {
                        nextState = SubBackCornerState;
                        makeTransition = TRUE;
                        ThisEvent.EventType = ES_NO_EVENT;
                    }
                    break;
                default:
                    break;
            }
            break;
        //
        case SubBackCloseState: 
            switch (ThisEvent.EventType) {
                case ES_ENTRY:
                    DC_Back_Arc_Left();
                    break;
                case ES_EXIT:
                    LED_SetBank(LED_BANK1, 0x0);
                    break;
                case IR_R_SWEETSPOT:
                    //JUST RIGHT
                    nextState = SubBackSweetSpotState;
                    makeTransition = TRUE;
                    ThisEvent.EventType = ES_NO_EVENT;
                    break;
                case IR_B_TOO_CLOSE:
                    //forward obstacle
                    if (AD_ReadADPin(SWEETSPOTSENSOR) < IR_THRESHOLD) { //left sweet on
                        nextState = SubBackRightTurnState;
                        makeTransition = TRUE;
                        ThisEvent.EventType = ES_NO_EVENT;
                    } else {
                        nextState = SubBackCornerState;
                        makeTransition = TRUE;
                        ThisEvent.EventType = ES_NO_EVENT;
                    }
                    break;
                case IR_R_TOO_FAR:
                    // TOO FAR
                    nextState = SubBackFarState;
                    makeTransition = TRUE;
                    ThisEvent.EventType = ES_NO_EVENT;
                    break;

                default:
                    break;
            }
            break;
        //Robot is too far from the right wall
        case SubBackFarState: 
            switch (ThisEvent.EventType) {
                case ES_ENTRY:
                    DC_Back_Arc_Right();
                    break;
                case ES_EXIT:
                    break;
                case IR_R_SWEETSPOT:
                    //JUST RIGHT
                    nextState = SubBackSweetSpotState;
                    makeTransition = TRUE;
                    ThisEvent.EventType = ES_NO_EVENT;
                    break;
                case IR_R_TOO_CLOSE:
                    // TOO CLOSE
                    nextState = SubBackCloseState;
                    makeTransition = TRUE;
                    ThisEvent.EventType = ES_NO_EVENT;

                    break;
                case IR_B_TOO_CLOSE:
                    //forward obstacle
                    if (AD_ReadADPin(SWEETSPOTSENSOR) < IR_THRESHOLD) {
                        nextState = SubBackRightTurnState;
                        makeTransition = TRUE;
                        ThisEvent.EventType = ES_NO_EVENT;
                    } else {
                        nextState = SubBackCornerState;
                        makeTransition = TRUE;
                        ThisEvent.EventType = ES_NO_EVENT;
                    }
                    break;
                default:
                    break;
            }
            break;
        //Robot is backed into a corner
        case SubBackCornerState:
            switch (ThisEvent.EventType) {
                case ES_ENTRY:
                    LED_SetBank(LED_BANK3, 0xF);
                    DC_Speed(900);
                    DC_Tank_Right();
                    ES_Timer_InitTimer(B_CORNER_TIMER, 750);
                    break;
                case ES_EXIT:
                    break;
                case ES_TIMEOUT:
                    if (ThisEvent.EventParam == B_CORNER_TIMER) {
                        if (AD_ReadADPin(BACKSENSOR) < IR_THRESHOLD) { 
                            //Back is on
                            nextState = SubForward;
                            makeTransition = TRUE;
                            ThisEvent.EventType = ES_NO_EVENT;
                        }else {
                            nextState = SubBackSweetSpotState;
                            makeTransition = TRUE;
                            ThisEvent.EventType = ES_NO_EVENT;
                        }
                    }
                    break;
                case IR_R_TOO_CLOSE:
                    if (AD_ReadADPin(BACKSENSOR) > IR_THRESHOLD) { 
                        //BACK is off
                        nextState = SubBackCloseState;
                        makeTransition = TRUE;
                        ThisEvent.EventType = ES_NO_EVENT;
                    }
                    break;
                case IR_R_SWEETSPOT:
                    //JUST RIGHT
                    if (AD_ReadADPin(BACKSENSOR) > IR_THRESHOLD) {
                        nextState = SubBackSweetSpotState;
                        makeTransition = TRUE;
                        ThisEvent.EventType = ES_NO_EVENT;
                    }
                    break;
                default:
                    break;
            }
            break;
        //Robot needs to make a sharp turn
        case SubBackRightTurnState:
            switch (ThisEvent.EventType) {
                case ES_ENTRY:   
                    DC_Speed(900);
                    DC_Tank_Right();
                    ES_Timer_InitTimer(B_NINETY_TURN, 650);
                    break;
                case ES_EXIT:
                    break;
                case ES_TIMEOUT:
                    if (ThisEvent.EventParam == B_NINETY_TURN) {
                        //if BACK is still on-- FORWARDSTATE
                        if (AD_ReadADPin(BACKSENSOR) < IR_THRESHOLD) { //
                            nextState = SubForward;
                            makeTransition = TRUE;
                            ThisEvent.EventType = ES_NO_EVENT;
                        } else {
                            nextState = SubBackSweetSpotState;
                            makeTransition = TRUE;
                            ThisEvent.EventType = ES_NO_EVENT;
                        }
                    }
                    break;
                default:
                    break;
            }
            break;
        //Robot going forward
        case SubForward:
            switch (ThisEvent.EventType) {
                case ES_ENTRY:
                    DC_Speed(900);
                    DC_Fwd();
                    ES_Timer_InitTimer(FORWARD_TIMER, 1000);
                    break;
                case ES_EXIT:
                    break;
                case ES_TIMEOUT:
                    if (ThisEvent.EventParam == FORWARD_TIMER) {
                        nextState = SubBackFarState;
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
    } 

    if (makeTransition == TRUE) { // making a state transition, send EXIT and ENTRY
        // recursively call the current state with an exit event
        RunReloadSubHSM(EXIT_EVENT); 
        CurrentState = nextState;
        RunReloadSubHSM(ENTRY_EVENT); 
    }

    //ES_Tail(); // trace call stack end
    return ThisEvent;
}




