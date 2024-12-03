/*
 * ApplicationCode.c
 *
 *  Created on: Dec 2, 2024
 *      Author: seank
 */

#include "ApplicationCode.h"

void ApplicationInit();

void applySpeed(uint8_t speedLeft, uint8_t speedRight) {

	motor_ApplySpeeds(speedLeft, speedRight);
}

void brakeAll() {

	motor_BrakeAll();
}
