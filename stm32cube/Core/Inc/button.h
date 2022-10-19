/*
 * button.h
 *
 *  Created on: Oct 12, 2022
 *      Author: phamv
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

#include "main.h"
#include "timer.h"

#define NO_OF_BUTTONS 3
#define TIME_OUT_FOR_KEY_PRESSED 500

#define PRESSED_STATE 0
#define RELEASED_STATE 1

extern int button_flag[];

void button_reading();

#endif /* INC_BUTTON_H_ */
