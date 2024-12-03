/*
 * motorDriver.c
 *
 *  Created on: Nov 30, 2024
 *      Author: seank
 */

#include "motorDriver.h"

void motor_ApplySpeeds(uint8_t speedLeft, uint8_t speedRight) {

	// TODO: Disable Brakes Here

	TIM3->CCR1 = speedLeft;		// Set the left CCR register to change PWM
	TIM3->CCR3 = speedRight;	// Set the right CCR register to change PWM

}

void motor_BrakeAll() {

	// TODO: Enable both Brakes Here
}
