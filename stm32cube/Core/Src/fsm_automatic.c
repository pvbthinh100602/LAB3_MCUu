/*
 * fsm_automatic.c
 *
 *  Created on: Oct 12, 2022
 *      Author: phamv
 */
#include "fsm_automatic.h"

void fsm_automatic_run(){
	switch (status) {
		case INIT:
			status = AUTO_RED1;
			setTimer1(config_green*1000);
			break;
		case AUTO_RED1:
			//TODO
			if(button_flag[0] == 1){
				button_flag[0] = 0;
				status = MAN_RED;
				setTimer1(BLINKY_TIME);
			} else if(timer1_flag == 1){
				status = AUTO_RED2;
				setTimer1(config_yellow*1000);
			}
			break;
		case AUTO_RED2:
			//TODO
			if(button_flag[0] == 1){
				button_flag[0] = 0;
				status = MAN_RED;
				setTimer1(BLINKY_TIME);
			} else if(timer1_flag == 1){
				status = AUTO_GREEN;
				setTimer1(config_green*1000);
			}
			break;
		case AUTO_GREEN:
			//TODO
			if(button_flag[0] == 1){
				button_flag[0] = 0;
				status = MAN_RED;
				setTimer1(BLINKY_TIME);
			} else if(timer1_flag == 1){
				status = AUTO_YELLOW;
				setTimer1(config_yellow*1000);
			}
			break;
		case AUTO_YELLOW:
			//TODO
			if(button_flag[0] == 1){
				button_flag[0] = 0;
				status = MAN_RED;
				setTimer1(BLINKY_TIME);
			} else if(timer1_flag == 1){
				status = AUTO_RED1;
				setTimer1(config_green*1000);
			}
			break;
		default:
			break;
	}
}
