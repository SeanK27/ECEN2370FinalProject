/*
 * ApplicationCode.c
 *
 *  Created on: Dec 2, 2024
 *      Author: seank
 */

#include "ApplicationCode.h"

void applyPower(uint8_t speedLeft, uint8_t speedRight) {

	motor_ApplyPower(speedLeft, speedRight);
}

void brakeAll() {

	motor_BrakeAll();
}

void getJoy(joyPosTypeDef joyPos, ADC_HandleTypeDef hadc1, ADC_HandleTypeDef hadc2) {

	joystick_getCoords(joyPos, &hadc1, &hadc2);
}

void noPower() {

	motor_noPower();
}

void calculatePower(uint16_t xPos, uint16_t yPos, motorPowTypeDef motorPow) {

	motor_CalculatePower(xPos, yPos, &motorPow);
}
