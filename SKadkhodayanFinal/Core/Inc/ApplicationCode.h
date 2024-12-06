/*
 * ApplicationCode.h
 *
 *  Created on: Dec 2, 2024
 *      Author: seank
 */

#ifndef INC_APPLICATIONCODE_H_
#define INC_APPLICATIONCODE_H_

#include "motorDriver.h"
#include "joystickDriver.h"

void applySpeed(uint8_t speedLeft, uint8_t speedRight);

void brakeAll();

void getJoy(joyPosTypeDef joyPos, ADC_HandleTypeDef hadc1, ADC_HandleTypeDef hadc2);

void noPower();

void calculatePower(uint16_t xPos, uint16_t yPos, motorPowTypeDef * motorPow);

#endif /* INC_APPLICATIONCODE_H_ */
