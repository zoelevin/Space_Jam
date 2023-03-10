/*
 * File:   Wheels.c
 * Author: Zoe Levin
 */


#include <BOARD.h>
#include <xc.h>
#include <stdio.h>
#include "ToneGeneration.h"
#include "RC_Servo.h"
#include "Wheels.h"
#include <pwm.h>
#include <serial.h>
#include <AD.h>
#include <IO_Ports.h>

/*******************************************************************************
 * PUBLIC FUNCTIONS                                                           *
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
void DC_Init(void) {
    PWM_Init();
    PWM_AddPins(DC_RIGHT_PWM | DC_LEFT_PWM);
    PWM_SetFrequency(500);

    PWM_SetDutyCycle(DC_RIGHT_PWM, 900);
    PWM_SetDutyCycle(DC_LEFT_PWM, 900);
    //RIGHT
    DC_RIGHT_POS_TRIS = 0;
    DC_RIGHT_NEG_TRIS = 0;
    //BACK
    DC_RIGHT_POS_LAT = 0;
    DC_RIGHT_NEG_LAT = 0;
    //LEFT
    DC_LEFT_POS_TRIS = 0;
    DC_LEFT_NEG_TRIS = 0;
    //FWD
    DC_LEFT_POS_LAT = 0;
    DC_LEFT_NEG_LAT = 0;
}

/**
 * @Function DC_Left_Off(void)
 * @param None.
 * @return None.
 * @brief  Turns off left wheel motor. 
 * @note  None.
 * @author Zoe Levin */
void DC_Left_Off(void) {
    DC_LEFT_POS_LAT = 0;
    DC_LEFT_NEG_LAT = 0;
}

/**
 * @Function DC_Right_Off(void)
 * @param None.
 * @return None.
 * @brief  Turns off right wheel motor.
 * @note  None.
 * @author Zoe Levin */
void DC_Right_Off(void) {
    DC_RIGHT_POS_LAT = 0;
    DC_RIGHT_NEG_LAT = 0;
}

/**
 * @Function DC_Left_Fwd(void)
 * @param None.
 * @return None.
 * @brief  Turns left wheel motor to spin forward
 * at current motor speed.
 * @note  None.
 * @author Zoe Levin */
void DC_Left_Fwd(void) {
    DC_LEFT_POS_LAT = 1;
    DC_LEFT_NEG_LAT = 0;
}

/**
 * @Function DC_Left_Back(void)
 * @param None.
 * @return None.
 * @brief  Turns left wheel motor to spin backwards
 * at current motor speed.
 * @note  None.
 * @author Zoe Levin */
void DC_Left_Back(void) {
    DC_LEFT_POS_LAT = 0;
    DC_LEFT_NEG_LAT = 1;
}

/**
 * @Function DC_Right_Fwd(void)
 * @param None.
 * @return None.
 * @brief  Turns right wheel motor to spin forward
 * at current motor speed.
 * @note  None.
 * @author Zoe Levin */
void DC_Right_Fwd(void) {
    DC_RIGHT_POS_LAT = 1;
    DC_RIGHT_NEG_LAT = 0;
}

/**
 * @Function DC_Right_Back(void)
 * @param None.
 * @return None.
 * @brief  Turns right wheel motor to spin backwards
 * at current motor speed.
 * @note  None.
 * @author Zoe Levin */
void DC_Right_Back(void) {
    DC_RIGHT_POS_LAT = 0;
    DC_RIGHT_NEG_LAT = 1;
}

/**
 * @Function DC_Right_Speed(int speed)
 * @param speed: PWM duty cycle between 0-1000.
 * @return None.
 * @brief  Sets right motor speed.
 * @note  Sets motor speeds.
 * @author Zoe Levin */
void DC_Right_Speed(int speed) {
    //speed must be between 1 and 1000
    PWM_SetDutyCycle(DC_RIGHT_PWM, speed);
}

/**
 * @Function DC_Left_Speed(int speed)
 * @param speed: PWM duty cycle between 0-1000.
 * @return None.
 * @brief   Sets left motor speed.
 * @note  Sets motor speeds.
 * @author Zoe Levin */
void DC_Left_Speed(int speed) {
    //speed must be between 1 and 1000
    PWM_SetDutyCycle(DC_LEFT_PWM, speed);
}

/**
 * @Function DC_Speed(int speed)
 * @param speed: PWM duty cycle between 0-1000.
 * @return None.
 * @brief  Sets motor speeds.
 * @note  Sets motor speeds.
 * @author Zoe Levin */
void DC_Speed(int speed) {
    //speed must be between 1 and 1000
    DC_Left_Speed(speed);
    DC_Right_Speed(speed);
}

/**
 * @Function DC_Fwd(void)
 * @param None.
 * @return None.
 * @brief  Turns wheel motors to spin forward
 * at current motor speed.
 * @note  None.
 * @author Zoe Levin */
void DC_Fwd(void) {
    DC_Right_Fwd();
    DC_Left_Fwd();
}

/**
 * @Function DC_Back(void)
 * @param None.
 * @return None.
 * @brief  Turns wheel motors to spin backwards
 * at current motor speed.
 * @note  None.
 * @author Zoe Levin */
void DC_Back(void) {
    DC_Right_Back();
    DC_Left_Back();
}

/**
 * @Function DC_Off(void)
 * @param None.
 * @return None.
 * @brief  Turns off motors. 
 * @note  None.
 * @author Zoe Levin */
void DC_Off(void) {
    DC_Right_Off();
    DC_Left_Off();
}

/**
 * @Function DC_Tank_Left(void)
 * @param None.
 * @return None.
 * @brief  Sets motors to turn robot sharply left
 * @note  Sets motor speeds.
 * @author Zoe Levin */
void DC_Tank_Left(void) {
    DC_Speed(700);
    DC_Left_Back();
    DC_Right_Fwd();
}

/**
 * @Function DC_Tank_Right(void)
 * @param None.
 * @return None.
 * @brief  Sets motors to turn robot sharply right
 * @note  Sets motor speeds.
 * @author Zoe Levin */
void DC_Tank_Right(void) {
    DC_Speed(700);
    DC_Right_Back();
    DC_Left_Fwd();
}

/**
 * @Function DC_Arc_Left(void)
 * @param None.
 * @return None.
 * @brief  Sets motors to turn robot slightly left
 * @note  Sets motor speeds.
 * @author Zoe Levin */
void DC_Arc_Left(void) {
    DC_Left_Speed(600);
    DC_Left_Fwd();
    DC_Right_Speed(900);
    DC_Right_Fwd();
}

/**
 * @Function DC_Arc_Right(void)
 * @param None.
 * @return None.
 * @brief  Sets motors to turn robot slightly right
 * @note  Sets motor speeds.
 * @author Zoe Levin */
void DC_Arc_Right(void) {
    DC_Right_Speed(600);
    DC_Right_Fwd();
    DC_Left_Speed(900);
    DC_Left_Fwd();
}

/**
 * @Function DC_Back_Arc_Left(void)
 * @param None.
 * @return None.
 * @brief  Sets motors to turn robot slightly left backwards
 * @note  Sets motor speeds.
 * @author Zoe Levin */
void DC_Back_Arc_Left(void) {
    DC_Left_Speed(500);
    DC_Left_Back();
    DC_Right_Speed(700);
    DC_Right_Back();
}

/**
 * @Function DC_Back_Arc_Right(void)
 * @param None.
 * @return None.
 * @brief  Sets motors to turn robot slightly right backwards
 * @note  Sets motor speeds.
 * @author Zoe Levin */
void DC_Back_Arc_Right(void) {
    DC_Right_Speed(500);
    DC_Right_Back();
    DC_Left_Speed(800);
    DC_Left_Back();
}

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
void Fly_Init(void) {
    PWM_Init();
    PORTZ07_TRIS = 0;
    PORTZ07_LAT = 1;
    PWM_AddPins(FLY_WHEEL_PWM);
    PWM_SetFrequency(500);

    FLY_WHEEL_POS_TRIS = 0;
    FLY_WHEEL_NEG_TRIS = 0;
    FLY_WHEEL_POS_LAT = 0;
    FLY_WHEEL_NEG_LAT = 0;
}

/**
 * @Function Fly_On(void)
 * @param None.
 * @return None.
 * @brief  Turns on flywheel.
 * @note  None.
 * @author Zoe Levin */
void Fly_On(void) {
    FLY_WHEEL_POS_LAT = 1;
    FLY_WHEEL_NEG_LAT = 0;
}

/**
 * @Function Fly_Off(void)
 * @param None.
 * @return None.
 * @brief  Turns off flywheel.
 * @note  None.
 * @author Zoe Levin */
void Fly_Off(void) {
    FLY_WHEEL_POS_LAT = 0;
    FLY_WHEEL_NEG_LAT = 0;
}

/**
 * @Function Fly_Speed(int speed)
 * @param None.
 * @return None.
 * @brief  Sets motor speed.
 * @note  Sets motor speed.
 * @author Zoe Levin */
void Fly_Speed(int speed) {
    PWM_SetDutyCycle(FLY_WHEEL_PWM, speed);
}

/**
 * @Function Reload_Init(void)
 * @param None.
 * @return None.
 * @brief  Performs all the initialization necessary for the robot's reloading
 *  rc servo. This includes initializing
 * the RC module, the i/o on corresponding pin.
 * @note  None.
 * @author Zoe Levin */
void Reload_Init(void) {
    RC_Init();
    RC_AddPins(RELOAD_PIN);
    Reload_Off();
}

/**
 * @Function Reload_On(void)
 * @param None.
 * @return None.
 * @brief  Turns on reloading RC servo.
 * @note  None.
 * @author Zoe Levin */
void Reload_On(void) {
    RC_SetPulseTime(RELOAD_PIN, 1000);
}

/**
 * @Function Reload_Off(void)
 * @param None.
 * @return None.
 * @brief  Turns off reloading RC servo.
 * @note  None.
 * @author Zoe Levin */
void Reload_Off(void) {
    RC_SetPulseTime(RELOAD_PIN, 1500);
}