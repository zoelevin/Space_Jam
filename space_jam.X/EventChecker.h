/* 
 * File:   EventChecker.h
 * Author: Zoe Levin
 *
 * File to set up typical EventCheckers for the  Events and Services
 * Framework (ES_Framework) on the Uno32. Defines event checking for 
 * IR sensors and beacon detector on Space Jam robot. 
 * EventChecker only returns TRUE when an event has occurred.
 */

#ifndef EVENTCHECKER_H
#define	EVENTCHECKER_H

/*******************************************************************************
 * PUBLIC #INCLUDES                                                            *
 ******************************************************************************/

#include "ES_Configure.h"   
#include "BOARD.h"


/*******************************************************************************
 * PUBLIC FUNCTION PROTOTYPES                                                  *
 ******************************************************************************/

/**
 * @Function IR_L_Sensing(void)
 * @param none
 * @return TRUE or FALSE
 * @brief This function is an event checker that checks the bottom and top left
 *      active low IR sensor output voltages against two fixed thresholds 
 *      (#defined in the .c file). This function implements hysteresis to 
 *      prevent rapid switching between high and low voltage states. The 
 *      function will post an event IR_L_SWEETSPOT, IR_L_TOO_CLOSE, IR_L_TOO_FAR
 *      based on the chart below
 *                  INPUT           |                |
 *        --------------------------|     OUTPUT     |
 *        FAR_SENSOR | CLOSE_SENSOR |                |
 *        --------------------------|----------------|
 *         LOW       |    LOW       | IR_L_TOO_CLOSE |
 *         LOW       |    HIGH      | IR_L_SWEETSPOT |
 *         HIGH      |    HIGH      | IR_L_TOO_FAR   |
 *              
 *        Returns TRUE if there was an event, FALSE otherwise.
 * @note 
 * @author Zoe Levin */
uint8_t IR_L_Sensing(void);

/**
 * @Function IR_F_Sensing(void)
 * @param none
 * @return TRUE or FALSE
 * @brief This function is an event checker that checks the front
 *      active low IR sensor output voltages against two fixed thresholds 
 *      (#defined in the .c file). This function implements a moving
 *      filter  to prevent rapid switching between high and low voltage states. The 
 *      function will post an event IR_F_TOO_FAR or IR_F_TOO_CLOSE
 *      based on the voltage.
 *        Returns TRUE if there was an event, FALSE otherwise.
 * @note 
 * @author Zoe Levin */
uint8_t IR_F_Sensing(void);

/**
 * @Function IR_B_Sensing(void)
 * @param none
 * @return TRUE or FALSE
 * @brief This function is an event checker that checks the back
 *      active low IR sensor output voltages against two fixed thresholds 
 *      (#defined in the .c file). This function implements a moving
 *      filter  to prevent rapid switching between high and low voltage states. The 
 *      function will post an event IR_B_TOO_FAR or IR_B_TOO_CLOSE
 *      based on the voltage.
 *        Returns TRUE if there was an event, FALSE otherwise.
 * @note 
 * @author Zoe Levin */
uint8_t IR_B_Sensing(void);


/**
 * @Function Beacon_Detection (void)
 * @param none
 * @return TRUE or FALSE
 * @brief This function is an event checker that checks the beacon detection 
 *      circuit's output voltages against two fixed thresholds 
 *      (#defined in the .c file). This function implements a moving
 *      filter  to prevent rapid switching between high and low voltage states.
 *      The function will post an event IN_RANGE or OUT_OF_RANGE
 *      based on the voltage.
 *        Returns TRUE if there was an event, FALSE otherwise.
 * @author Zoe Levin
 */
uint8_t Beacon_Detection(void);

#endif	/* EVENTCHECKER_H */

