/*
 * button.h
 *
 *  Created on: Oct 12, 2022
 *      Author: phamv
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

#include "global.h"

#define NO_OF_BUTTONS 3

#define BUTTON_NORMAL		GPIO_PIN_SET
#define BUTTON_IS_PRESSED	GPIO_PIN_RESET

#define DURATION_AUTO_INCREASING	500

extern int button_flag[NO_OF_BUTTONS];

void button_reading(void);

#endif /* INC_BUTTON_H_ */
