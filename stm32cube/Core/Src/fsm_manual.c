/*
 * fsm_manual.c
 *
 *  Created on: Oct 12, 2022
 *      Author: phamv
 */

#include "fsm_manual.h"

void fsm_manual_run(){
	switch (status) {
		case MAN_RED:
			if(button_flag[0] == 1){
				button_flag[0] = 0;
				setTimer1(BLINKY_TIME);
			}
			break;
		case MAN_GREEN:
			if(button_flag[0] == 1){
				button_flag[0] = 0;
				setTimer1(BLINKY_TIME);
			}
			break;
		case MAN_YELLOW:
			if(button_flag[0] == 1){
				button_flag[0] = 0;
				setTimer1(BLINKY_TIME);
			}
			break;
		default:
			break;
	}
}
