/*
 * joystickDriver.h
 *
 *  Created on: Dec 2, 2024
 *      Author: seank
 */

#ifndef INC_JOYSTICKDRIVER_H_
#define INC_JOYSTICKDRIVER_H_

typedef struct joyPosTypeDef {
	uint8_t xPos;
	uint8_t yPos;
};

joyPosTypeDef joystick_getCoords();

#endif /* INC_JOYSTICKDRIVER_H_ */
