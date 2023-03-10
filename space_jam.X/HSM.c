/*
 * File: HSM.c
 * Author: Zoe Levin, Demetrius Rauck, J. Edward Carryer(Instructor),
 *  Gabriel Elkaim (Instructor)
 * 
 *
 * Set up a Hierarchical State Machine to work with the Events and
 * Services Framework (ES_Framework) on the Uno32 for the CMPE-118/L class. 
 *
 * 
 */


/*******************************************************************************
 * MODULE #INCLUDE                                                             *
 ******************************************************************************/

#include "ES_Configure.h"
#include "ES_Framework.h"
#include "BOARD.h"
#include "HSM.h"
#include "SubHSM.h" //#include all sub state machines called
#include "EventChecker.h"
#include "Service.h"
#include "Wheels.h"
#include <stdio.h>
#include "LED.h"

/*******************************************************************************
 * PRIVATE #DEFINES                                                            *
 ******************************************************************************/
//Include any defines you need to do
#define TEN_SEC 10000
#define HALF_SEC 500
#define FIVE_SEC 5000

#define FOLLOW_WALL_DIST 20

/*******************************************************************************
 * MODULE #DEFINES                                                             *
 ******************************************************************************/


typedef enum {
    InitPState,
    ReloadState,
    WallFollowState,
    BeaconState,
    StallState
} SPACE_JAM_HSMState_t;

static const char *StateNames[] = {
    "InitPState",
    "ReloadState",
    "WallFollowState",
    "BeaconState",
    "StallState"
};



/*******************************************************************************
 * PRIVATE MODULE VARIABLES                                                            *
 ******************************************************************************/

static SPACE_JAM_HSMState_t CurrentState = InitPState; 
static uint8_t MyPriority;


/*******************************************************************************
 * PUBLIC FUNCTIONS                                                            *
 ******************************************************************************/

/**
 * @Function InitHSM(uint8_t Priority)
 * @param Priority - internal variable to track which event queue to use
 * @return TRUE or FALSE
 * @brief This will get called by the framework at the beginning of the code
 *        execution. It will post an ES_INIT event to the appropriate event
 *        queue, which will be handled inside RunHSM function. Remember
 *        to rename this to something appropriate.
 *        Returns TRUE if successful, FALSE otherwise
 * @author Demetrius Rauck, J. Edward Carryer */
uint8_t Init_SPACE_JAM_HSM(uint8_t Priority) {
    MyPriority = Priority;
    // put us into the Initial PseudoState
    CurrentState = InitPState;
    // post the initial transition event
    if (ES_PostToService(MyPriority, INIT_EVENT) == TRUE) {
        return TRUE;
    } else {
        return FALSE;
    }
}

/**
 * @Function PostHSM(ES_Event ThisEvent)
 * @param ThisEvent - the event (type and param) to be posted to queue
 * @return TRUE or FALSE
 * @brief This function is a wrapper to the queue posting function, and its name
 *        will be used inside ES_Configure to point to which queue events should
 *        be posted to. 
 *        Returns TRUE if successful, FALSE otherwise
 * @author J. Edward Carryer, 2011.10.23 19:25 */
uint8_t Post_SPACE_JAM_HSM(ES_Event ThisEvent) {
    return ES_PostToService(MyPriority, ThisEvent);
}

/**
 * @Function Run_SPACE_JAM_HSM(ES_Event ThisEvent)
 * @param ThisEvent - the event (type and param) to be responded.
 * @return Event - return event (type and param), in general should be ES_NO_EVENT
 * @brief This function is where the entire hierarchical state machine is called
 *          but shows the top-level functions. States are 
 *          InitPState: Initial psuedo-state
 *          Reload State: Implement's backwards wall following algorithm and
 *                        stops robot to allow ping pong ball reload
 *          WallFollowState: Implements bot's wall-following algorithm
 *          BeaconState: State for pointing and shooting at beacon
 * @note This function will be called recursively to implement the correct
 *        order for a state transition to be: exit current state -> enter next state
 *        using the ES_EXIT and ES_ENTRY events.
 *       The lower level state machines are run first, to see if the event is dealt
 *       with there rather than at the current level. ES_EXIT and ES_ENTRY events are
 *       not consumed as these need to pass pack to the higher level state machine.
 * @author Zoe Levin
 * @author Demetrius Rauck */

ES_Event Run_SPACE_JAM_HSM(ES_Event ThisEvent) {
    uint8_t makeTransition = FALSE; // use to flag transition
    SPACE_JAM_HSMState_t nextState; 

    //ES_Tattle(); // trace call stack
    static int track_flag = 0;
    switch (CurrentState) {
        case InitPState: // If current state is initial Pseudo State
            if (ThisEvent.EventType == ES_INIT)// only respond to ES_Init
            {             
                // transition from the initial pseudo-state into the actual
                // initial state
                // Initialize all sub-state machines
                InitWallFollowSubHSM();
                InitBeaconSubHSM();
                InitReloadSubHSM();
                // now put the machine into the actual initial state
                nextState = WallFollowState;
                makeTransition = TRUE;
                ThisEvent.EventType = ES_NO_EVENT;

            }
            break;
        case WallFollowState:
            ThisEvent = RunWallFollowSubHSM(ThisEvent);
            switch (ThisEvent.EventType) {
                case ES_ENTRY:       
                    break;
                case ES_EXIT:
                    break;
                case ES_TIMEOUT:
                    //Timer for bot to exit reload zone
                    if (ThisEvent.EventParam == ZONE_TIMER) {
                        nextState = BeaconState;
                        makeTransition = TRUE;
                        ThisEvent.EventType = ES_NO_EVENT;
                    }
                    break;
                default:
                    break;
            }
            break;
        case BeaconState:
            ThisEvent = RunBeaconSubHSM(ThisEvent);
            switch (ThisEvent.EventType) {
                case ES_ENTRY:
                    break;
                case ES_TIMEOUT:
                    //if beacon is not found for 10 seconds, wall-follow
                    if (ThisEvent.EventParam == ORIENT_TWO) {
                        nextState = WallFollowState;
                        makeTransition = TRUE;
                        ThisEvent.EventType = ES_NO_EVENT;
                    }
                    break;
                case SHOTS_FIRED:
                    nextState = ReloadState;
                    makeTransition = TRUE;
                    ThisEvent.EventType = ES_NO_EVENT;
                    break;
                default:
                    break;
            }
            break;
        case ReloadState:
            ThisEvent = RunReloadSubHSM(ThisEvent);
            switch (ThisEvent.EventType) {
                case ES_ENTRY:
                    ES_Timer_InitTimer(STATE_TIMER, 10000);
                    break;
                case ES_TIMEOUT:
                    /* Only backwards wall follow for ten seconds, then wall 
                    follow forwards */
                    if (ThisEvent.EventParam == STATE_TIMER) {
                        nextState = WallFollowState;
                        makeTransition = TRUE;
                        ThisEvent.EventType = ES_NO_EVENT;
                    }
                    break;
                default:
                    break;
            }
            break;
        default:
            break;

    } // end switch on Current State

    if (makeTransition == TRUE) { // making a state transition, send EXIT and ENTRY
        // recursively call the current state with an exit event
        Run_SPACE_JAM_HSM(EXIT_EVENT); // <- rename to your own Run function
        CurrentState = nextState;
        Run_SPACE_JAM_HSM(ENTRY_EVENT); // <- rename to your own Run function
    }

    //ES_Tail(); // trace call stack end
    return ThisEvent;
}


/*******************************************************************************
 * PRIVATE FUNCTIONS                                                           *
 ******************************************************************************/
