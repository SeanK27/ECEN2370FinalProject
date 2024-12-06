/*
 * motorDriver.h
 *
 *  Created on: Nov 30, 2024
 *      Author: seank
 */

#ifndef INC_MOTORDRIVER_H_
#define INC_MOTORDRIVER_H_

#include <stdint.h>

#include "stm32f4xx_hal.h"

typedef struct {
	uint8_t leftPow;
	uint8_t rightPow;
} motorPowTypeDef;

uint16_t mapp(uint16_t x, uint16_t in_min, uint16_t in_max, uint16_t out_min, uint16_t out_max);

void motor_CalculatePower(uint16_t xPos, uint16_t yPos, motorPowTypeDef * motorPow);

void motor_ApplyPower(uint16_t speedLeft, uint16_t speedRight);

void motor_BrakeAll();

void motor_noPower();

#endif /* INC_MOTORDRIVER_H_ */
