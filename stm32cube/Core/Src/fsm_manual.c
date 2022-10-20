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

			if(timer1_flag == 1){
				//blinky led
				toggle_traffic_red();
				setTimer1(BLINKY_TIME);
			}

			if(button_flag[0] == 1){
				//button1 pressed, switch to MAN_GREEN
				status = MAN_GREEN;
				button_flag[0] = 0;
				set_traffic1_green();
				set_traffic2_green();
				setTimer1(BLINKY_TIME);
				counter_green = config_green;
				display_traffic_7SEG(0, 2);
				display_traffic_7SEG(1, counter_green);
			}
			break;
		case MAN_GREEN:

			if(timer1_flag == 1){
				//blinky led
				toggle_traffic_green();
				setTimer1(BLINKY_TIME);
			}

			if(button_flag[0] == 1){
				//button1 pressed, switch to MAN_YELLOW
				status = MAN_YELLOW;
				button_flag[0] = 0;
				set_traffic1_yellow();
				set_traffic2_yellow();
				setTimer1(BLINKY_TIME);
				counter_yellow = config_yellow;
				display_traffic_7SEG(0, 3);
				display_traffic_7SEG(1, counter_yellow);
			}
			break;
		case MAN_YELLOW:

			if(timer1_flag == 1){
				//blinky led
				toggle_traffic_yellow();
				setTimer1(BLINKY_TIME);
			}

			if(button_flag[0] == 1){
				//button1 pressed, switch to AUTO_RED1
				status = AUTO_RED1;
				button_flag[0] = 0;
				setTimer1(config_green*1000);
				setTimer2(1000);
				counter_red = config_red;
				counter_green = config_green;
				display_traffic_7SEG(0, counter_red--);
				display_traffic_7SEG(1, counter_green--);
			}
			break;
		default:
			break;
	}
}
