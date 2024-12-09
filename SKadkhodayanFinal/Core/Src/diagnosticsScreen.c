/*
 * diagnosticsScreen.c
 *
 *  Created on: Dec 9, 2024
 *      Author: seank
 */

#include "diagnosticsScreen.h"

void displayMovementBase() {
	LCD_Draw_Circle_Fill(120, 80, 50, LCD_COLOR_BLACK);
	LCD_Draw_Circle_Fill(120, 80, 47, LCD_COLOR_WHITE);
}

void displayCurrentMove(joyPosTypeDef joyPos) {
	/*
	// Neutral
	if ((joyPos.xPos <= 515 && joyPos.xPos >= 510) || (joyPos.xPos <= 515 && joyPos.xPos >= 510)) {

		LCD_Draw_Circle_Fill(120, 80, 47, LCD_COLOR_WHITE);
		LCD_Draw_Circle_Fill(120, 80, 20, LCD_COLOR_BLACK);
	}

	// Forward
	if ((joyPos.xPos <= 515 && joyPos.xPos >= 510) || (joyPos.xPos <= 515 && joyPos.xPos >= 510)) {

		LCD_Draw_Circle_Fill(120, 80, 47, LCD_COLOR_WHITE);
		LCD_Draw_Circle_Fill(120, 80-47+20, 20, LCD_COLOR_BLACK);
	}

	// Backward
	if (Position == 2) {

		LCD_Draw_Circle_Fill(120, 80, 47, LCD_COLOR_WHITE);
		LCD_Draw_Circle_Fill(120, 80+47-20, 20, LCD_COLOR_BLACK);
	}

	// Left
	if (Position == 3) {

		LCD_Draw_Circle_Fill(120, 80, 47, LCD_COLOR_WHITE);
		LCD_Draw_Circle_Fill(120-47+20, 80, 20, LCD_COLOR_BLACK);
	}

	// Right
	if (Position == 4) {

		LCD_Draw_Circle_Fill(120, 80, 47, LCD_COLOR_WHITE);
		LCD_Draw_Circle_Fill(120+47-20, 80, 20, LCD_COLOR_BLACK);
	}
	*/

	uint32_t dispJoyPosY = mapp(joyPos.xPos, 0, 1024, 80+47-20, 80-47+20);

	uint32_t dispJoyPosX = mapp(joyPos.yPos, 0, 1024, 120-47+20, 120+47-20);

	LCD_Draw_Circle_Fill(120, 80, 47, LCD_COLOR_WHITE);
	LCD_Draw_Circle_Fill(dispJoyPosX, dispJoyPosY, 20, LCD_COLOR_BLACK);
}
