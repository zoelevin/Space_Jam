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

#ifndef HSM_H  
#define HSM_H  


/*******************************************************************************
 * PUBLIC #INCLUDES                                                            *
 ******************************************************************************/

#include "ES_Configure.h"   // defines ES_Event, INIT_EVENT, ENTRY_EVENT, and EXIT_EVENT


/*******************************************************************************
 * PUBLIC FUNCTION PROTOTYPES                                                  *
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
uint8_t Init_SPACE_JAM_HSM(uint8_t Priority);



/**
 * @Function PostHSM(ES_Event ThisEvent)
 * @param ThisEvent - the event (type and param) to be posted to queue
 * @return TRUE or FALSE
 * @brief This function is a wrapper to the queue posting function, and its name
 *        will be used inside ES_Configure to point to which queue events should
 *        be posted to. 
 *        Returns TRUE if successful, FALSE otherwise
 * @author J. Edward Carryer, 2011.10.23 19:25 */
uint8_t Post_SPACE_JAM_HSM(ES_Event ThisEvent);




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
ES_Event Run_SPACE_JAM_HSM(ES_Event ThisEvent);

#endif /* HSM_Template_H */

