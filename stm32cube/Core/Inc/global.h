/*
 * global.h
 *
 *  Created on: Oct 12, 2022
 *      Author: phamv
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include "timer.h"
#include "button.h"
#include "main.h"
#include "traffic.h"
#include "fsm_button.h"

#define INIT		1
#define AUTO_RED1	2
#define AUTO_RED2	3
#define AUTO_GREEN	4
#define AUTO_YELLOW	5

#define MAN_RED		12
#define MAN_GREEN	13
#define MAN_YELLOW	14

extern int status;

#endif /* INC_GLOBAL_H_ */
