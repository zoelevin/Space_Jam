#ifndef WHEELS_H
#define WHEELS_H

#include <BOARD.h>
#include "IO_Ports.h"
#include <pwm.h>
#include <serial.h>
#include <AD.h>
#include <IO_Ports.h>
#include <xc.h>

/*******************************************************************************
 * DEFINES                                            *
 ******************************************************************************/

#define WHEELS_MAX_SPEED 100 
#define FORWARD 1
#define REVERSE 0

#define DC_RIGHT_PWM PWM_PORTY10
#define DC_RIGHT_POS_TRIS PORTY11_TRIS
#define DC_RIGHT_NEG_TRIS PORTY09_TRIS
#define DC_RIGHT_POS_LAT PORTY11_LAT
#define DC_RIGHT_NEG_LAT PORTY09_LAT

#define DC_LEFT_PWM PWM_PORTY12
#define DC_LEFT_POS_TRIS PORTY05_TRIS
#define DC_LEFT_NEG_TRIS PORTY06_TRIS
#define DC_LEFT_POS_LAT PORTY05_LAT
#define DC_LEFT_NEG_LAT PORTY06_LAT

#define FLY_WHEEL_PWM PWM_PORTZ06
#define FLY_WHEEL_POS_TRIS PORTZ04_TRIS
#define FLY_WHEEL_NEG_TRIS PORTZ03_TRIS
#define FLY_WHEEL_POS_LAT PORTZ04_LAT
#define FLY_WHEEL_NEG_LAT PORTZ03_LAT

#define RELOAD_PIN RC_PORTZ09

/*******************************************************************************
 * PUBLIC FUNCTION PROTOTYPES                                                  *
 ******************************************************************************/

/**
 * @Function DC_Init(void)
 * @param None.
 * @return None.
 * @brief  Performs all the initialization necessary for the robot's driving
 *  motors. This includes initializing
 * the PWM module, the data directions on some pins, and
 * setting the initial motor directions and speeds.
 * @note  None.
 * @author Zoe Levin */
void DC_Init(void);

/**
 * @Function DC_Left_Off(void)
 * @param None.
 * @return None.
 * @brief  Turns off left wheel motor. 
 * @note  None.
 * @author Zoe Levin */
void DC_Left_Off(void);

/**
 * @Function DC_Right_Off(void)
 * @param None.
 * @return None.
 * @brief  Turns off right wheel motor.
 * @note  None.
 * @author Zoe Levin */
void DC_Right_Off(void);

/**
 * @Function DC_Left_Back(void)
 * @param None.
 * @return None.
 * @brief  Turns left wheel motor to spin backwards
 * at current motor speed.
 * @note  None.
 * @author Zoe Levin */
void DC_Left_Back(void);

/**
 * @Function DC_Left_Fwd(void)
 * @param None.
 * @return None.
 * @brief  Turns left wheel motor to spin forward
 * at current motor speed.
 * @note  None.
 * @author Zoe Levin */
void DC_Left_Fwd(void);

/**
 * @Function DC_Right_Back(void)
 * @param None.
 * @return None.
 * @brief  Turns right wheel motor to spin backwards
 * at current motor speed.
 * @note  None.
 * @author Zoe Levin */
void DC_Right_Back(void);

/**
 * @Function DC_Right_Fwd(void)
 * @param None.
 * @return None.
 * @brief  Turns right wheel motor to spin forward
 * at current motor speed.
 * @note  None.
 * @author Zoe Levin */
void DC_Right_Fwd(void);

/**
 * @Function DC_Fwd(void)
 * @param None.
 * @return None.
 * @brief  Turns wheel motors to spin forward
 * at current motor speed.
 * @note  None.
 * @author Zoe Levin */
void DC_Fwd(void);

/**
 * @Function DC_Back(void)
 * @param None.
 * @return None.
 * @brief  Turns wheel motors to spin backwards
 * at current motor speed.
 * @note  None.
 * @author Zoe Levin */
void DC_Back(void);

/**
 * @Function DC_Off(void)
 * @param None.
 * @return None.
 * @brief  Turns off motors. 
 * @note  None.
 * @author Zoe Levin */
void DC_Off(void);

/**
 * @Function DC_Tank_Left(void)
 * @param None.
 * @return None.
 * @brief  Sets motors to turn robot sharply left
 * @note  Sets motor speeds.
 * @author Zoe Levin */
void DC_Tank_Left(void);

/**
 * @Function DC_Tank_Right(void)
 * @param None.
 * @return None.
 * @brief  Sets motors to turn robot sharply right
 * @note  Sets motor speeds.
 * @author Zoe Levin */
void DC_Tank_Right(void);

/**
 * @Function DC_Arc_Left(void)
 * @param None.
 * @return None.
 * @brief  Sets motors to turn robot slightly left
 * @note  Sets motor speeds.
 * @author Zoe Levin */
void DC_Arc_Left(void);

/**
 * @Function DC_Arc_Right(void)
 * @param None.
 * @return None.
 * @brief  Sets motors to turn robot slightly right
 * @note  Sets motor speeds.
 * @author Zoe Levin */
void DC_Arc_Right(void);

/**
 * @Function DC_Back_Arc_Left(void)
 * @param None.
 * @return None.
 * @brief  Sets motors to turn robot slightly left backwards
 * @note  Sets motor speeds.
 * @author Zoe Levin */
void DC_Back_Arc_Left(void);

/**
 * @Function DC_Back_Arc_Right(void)
 * @param None.
 * @return None.
 * @brief  Sets motors to turn robot slightly right backwards
 * @note  Sets motor speeds.
 * @author Zoe Levin */
void DC_Back_Arc_Right(void);

/**
 * @Function DC_Right_Speed(int speed)
 * @param speed: PWM duty cycle between 0-1000.
 * @return None.
 * @brief  Sets right motor speed.
 * @note  Sets motor speeds.
 * @author Zoe Levin */
void DC_Right_Speed(int speed);

/**
 * @Function DC_Left_Speed(int speed)
 * @param speed: PWM duty cycle between 0-1000.
 * @return None.
 * @brief   Sets left motor speed.
 * @note  Sets motor speeds.
 * @author Zoe Levin */
void DC_Left_Speed(int speed);

/**
 * @Function DC_Speed(int speed)
 * @param speed: PWM duty cycle between 0-1000.
 * @return None.
 * @brief  Sets motor speeds.
 * @note  Sets motor speeds.
 * @author Zoe Levin */
void DC_Speed(int speed);

/**
 * @Function Fly_Init(void)
 * @param None.
 * @return None.
 * @brief  Performs all the initialization necessary for the robot's flywheel
 *  motor. This includes initializing
 * the PWM module, the i/o on corresponding pin, and
 * setting the initial motor direction and speed.
 * @note  None.
 * @author Zoe Levin */
void Fly_Init(void);


/**
 * @Function Fly_Speed(int speed)
 * @param None.
 * @return None.
 * @brief  Sets motor speed.
 * @note  Sets motor speed.
 * @author Zoe Levin */
void Fly_Speed(int speed);

/**
 * @Function Fly_On(void)
 * @param None.
 * @return None.
 * @brief  Turns on flywheel.
 * @note  None.
 * @author Zoe Levin */
void Fly_On(void);

/**
 * @Function Fly_Off(void)
 * @param None.
 * @return None.
 * @brief  Turns off flywheel.
 * @note  None.
 * @author Zoe Levin */
void Fly_Off(void);

/**
 * @Function Reload_Init(void)
 * @param None.
 * @return None.
 * @brief  Performs all the initialization necessary for the robot's reloading
 *  rc servo. This includes initializing
 * the RC module, the i/o on corresponding pin.
 * @note  None.
 * @author Zoe Levin */
void Reload_Init(void);

/**
 * @Function Reload_On(void)
 * @param None.
 * @return None.
 * @brief  Turns on reloading RC servo.
 * @note  None.
 * @author Zoe Levin */
void Reload_On(void);

/**
 * @Function Reload_Off(void)
 * @param None.
 * @return None.
 * @brief  Turns off reloading RC servo.
 * @note  None.
 * @author Zoe Levin */
void Reload_Off(void);
#endif