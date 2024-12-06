/*
 * motorDriver.c
 *
 *  Created on: Nov 30, 2024
 *      Author: seank
 */

#include "motorDriver.h"

// Parameter that affects turning sensitivity
#define TURNFACTOR 1

uint16_t mapp(uint16_t x, uint16_t in_min, uint16_t in_max, uint16_t out_min, uint16_t out_max) {
	return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

void motor_CalculatePower(uint16_t xPos, uint16_t yPos, motorPowTypeDef * motorPow) {

	uint16_t base = mapp(xPos, 512, 1024, 0, 100);

	// Adjustment value that is applied to both motors
	uint16_t adjust = (mapp(512 - yPos, 0, 1024, 0, 100)) * TURNFACTOR;

	// Apply adjustment
	uint16_t rightMotor = base - adjust;
	uint16_t leftMotor = base + adjust;

	// When joystick is fully back, send HIGH signal to brakePinLeft then set power to 0.
	if (rightMotor < -240 && leftMotor < -240) {
	    rightMotor = 0;
	    leftMotor = 0;
	}

	else {

		//////////////// Removing values >255 or <0 and setting them to 255 and 0 respectively ///////////////////////
		if (rightMotor < 0) {
			rightMotor = 0;
		}

		if (leftMotor < 0) {
			leftMotor = 0;
		}

		if (rightMotor > 255) {
			rightMotor = 255;
		}

		if (leftMotor > 255) {
			leftMotor = 255;
		}
		//////////////////////////////////////////////////////////////////////////////////////////////////////////////


		// Store motor power
		motorPow->leftPow = leftMotor;
		motorPow->rightPow = rightMotor;
	}
}

void motor_ApplyPower(uint16_t powerLeft, uint16_t powerRight) {

	// TODO: Disable Brakes Here

	TIM3->CCR1 = powerLeft;		// Set the left CCR register to change PWM
	TIM3->CCR3 = powerRight;	// Set the right CCR register to change PWM

}

void motor_BrakeAll() {

	// TODO: Enable both Brakes Here
}

void motor_noPower() {

	TIM3->CCR1 = 0;
	TIM3->CCR3 = 0;
}
