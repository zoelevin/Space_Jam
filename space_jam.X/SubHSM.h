/*
 * File: SubHSM.h
 * Author: Zoe Levin, Demetrius Rauck, J. Edward Carryer
 *
 * File to set up a Heirarchical SubState Machine to work with the Events and
 * Services Framework (ES_Framework) on the Uno32 for the CMPE-118/L class.
 *
 */

#ifndef SUB_HSM_H  // <- This should be changed to your own guard on both
#define SUB_HSM_H  //    of these lines


/*******************************************************************************
 * PUBLIC #INCLUDES                                                            *
 ******************************************************************************/

#include "ES_Configure.h"   // defines ES_Event, INIT_EVENT, ENTRY_EVENT, and EXIT_EVENT


/*******************************************************************************
 * PUBLIC FUNCTION PROTOTYPES                                                  *
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
uint8_t InitWallFollowSubHSM(void);

/**
 * @Function InitBeaconSubHSM(uint8_t Priority)
 * @param Priority - internal variable to track which event queue to use
 * @return TRUE or FALSE
 * @brief This will get called by the framework at the beginning of the code
 *        execution. It will post an ES_INIT event to the appropriate event
 *        queue, which will be handled inside RunHSM function.
 *        Returns TRUE if successful, FALSE otherwise
 * @author Zoe Levin, Demetrius Rauck */
uint8_t InitBeaconSubHSM(void);

/**
 * @Function InitReloadSubHSM(uint8_t Priority)
 * @param Priority - internal variable to track which event queue to use
 * @return TRUE or FALSE
 * @brief This will get called by the framework at the beginning of the code
 *        execution. It will post an ES_INIT event to the appropriate event
 *        queue, which will be handled inside RunHSM function.
 *        Returns TRUE if successful, FALSE otherwise
 * @author Zoe Levin, Demetrius Rauck */
uint8_t InitReloadSubHSM(void);

/**
 * @Function RunWallFollowSubHSM(ES_Event ThisEvent)
 * @param ThisEvent - the event (type and param) to be responded.
 * @return Event - return event (type and param), in general should be ES_NO_EVENT
 * @brief This function controls the wall following state machine of the spacejam
 * robot based off of IR sensors. The robot orients itself along the right wall
 * and follows the wall until it leaves the reload zone.
 * @note 
 *       The lower level state machines are run first, to see if the event is dealt
 *       with there rather than at the current level. ES_EXIT and ES_ENTRY events are
 *       not consumed as these need to pass pack to the higher level state machine.
 * @author Zoe Levin, Demetrius Rauck, Gabriel Elkaim */
ES_Event RunWallFollowSubHSM(ES_Event ThisEvent);

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
ES_Event RunBeaconSubHSM(ES_Event ThisEvent);

/**
 * @Function RunReloadSubHSM(ES_Event ThisEvent)
 * @param ThisEvent - the event (type and param) to be responded.
 * @return Event - return event (type and param), in general should be ES_NO_EVENT
 * @brief This state machine happens after the ping pong balls have been shot.
 * The robot uses IR sensors to follow the right wall backwards into the reload 
 * zone
 * @note 
 *       The lower level state machines are run first, to see if the event is dealt
 *       with there rather than at the current level. ES_EXIT and ES_ENTRY events are
 *       not consumed as these need to pass pack to the higher level state machine.
 * @author Zoe Levin, Demetrius Rauck, Gabriel Elkaim */
ES_Event RunReloadSubHSM(ES_Event ThisEvent);
#endif /* SUB_HSM_Template_H */

