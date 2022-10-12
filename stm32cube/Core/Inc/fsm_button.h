/*
 * fsm_button.h
 *
 *  Created on: Oct 12, 2022
 *      Author: phamv
 */

#ifndef INC_FSM_BUTTON_H_
#define INC_FSM_BUTTON_H_

#include "global.h"

#define BUTTON_RELEASED		1
#define BUTTON_PRESSED		2
#define BUTTON_PRESSED_1S	3

extern int buttonState[3];

void fsm_button_processing(void);


#endif /* INC_FSM_BUTTON_H_ */
