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
			//switch to AUTO_RED1
			status = AUTO_RED1;
			setTimer1(config_green*1000);
			setTimer2(1000);
			counter_red = config_red;
			counter_green = config_green;
			display_traffic_7SEG(0, counter_red--);
			display_traffic_7SEG(1, counter_green--);
			break;
		case AUTO_RED1:
			//TODO
			set_traffic1_red();
			set_traffic2_green();

			if(timer1_flag == 1){
				// time out, switch to AUTO_RED2
				status = AUTO_RED2;
				setTimer1(config_yellow*1000);
				counter_yellow = config_yellow;
				display_traffic_7SEG(0, counter_red--);
				display_traffic_7SEG(1, counter_yellow--);
				setTimer2(1000);
			}

			if(timer2_flag == 1){
				//display and decrease led 7seg counter
				display_traffic_7SEG(0, counter_red--);
				display_traffic_7SEG(1, counter_green--);
				setTimer2(1000);
			}

			if(button_flag[0] == 1){
				//button1 pressed, switch to MAN_RED
				button_flag[0] = 0;
				status = MAN_RED;
				// set up for blinky led
				set_traffic1_red();
				set_traffic2_red();
				setTimer1(BLINKY_TIME);
				//set up for display 7seg
				counter_red = config_red;
				display_traffic_7SEG(0, 1);
				display_traffic_7SEG(1, config_red);
			}
			break;
		case AUTO_RED2:
			//TODO
			set_traffic1_red();
			set_traffic2_yellow();

			if(timer1_flag == 1){
				// time out, switch to AUTO_GREEN
				status = AUTO_GREEN;
				setTimer1(config_green*1000);
				counter_red = config_red;
				counter_green = config_green;
				display_traffic_7SEG(0, counter_green--);
				display_traffic_7SEG(1, counter_red--);
				setTimer2(1000);
			}

			if(timer2_flag ==1){
				//display and decrease led 7seg counter
				display_traffic_7SEG(0, counter_red--);
				display_traffic_7SEG(1, counter_yellow--);
				setTimer2(1000);
			}

			if(button_flag[0] == 1){
				//button1 pressed, switch to MAN_RED
				button_flag[0] = 0;
				status = MAN_RED;
				set_traffic1_red();
				set_traffic2_red();
				// set up for blinky led
				setTimer1(BLINKY_TIME);
				//set up for display 7seg
				counter_red = config_red;
				display_traffic_7SEG(0, 1);
				display_traffic_7SEG(1, counter_red);
			}
			break;
		case AUTO_GREEN:
			//TODO
			set_traffic1_green();
			set_traffic2_red();

			if(timer1_flag == 1){
				// time out, switch to AUTO_YELLOW
				status = AUTO_YELLOW;
				setTimer1(config_yellow*1000);
				counter_yellow = config_yellow;
				display_traffic_7SEG(0, counter_yellow--);
				display_traffic_7SEG(1, counter_red--);
				setTimer2(1000);
			}

			if(timer2_flag ==1){
				//display and decrease led 7seg counter
				display_traffic_7SEG(0, counter_green--);
				display_traffic_7SEG(1, counter_red--);
				setTimer2(1000);
			}

			if(button_flag[0] == 1){
				//button1 pressed, switch to MAN_RED
				button_flag[0] = 0;
				status = MAN_RED;
				// set up for blinky led
				set_traffic1_red();
				set_traffic2_red();
				setTimer1(BLINKY_TIME);
				//set up for display 7seg
				counter_red = config_red;
				display_traffic_7SEG(0, 1);
				display_traffic_7SEG(1, counter_red);
			}
			break;
		case AUTO_YELLOW:
			//TODO
			set_traffic1_yellow();
			set_traffic2_red();

			if(timer1_flag == 1){
				// time out, switch to AUTO_RED1
				status = AUTO_RED1;
				setTimer1(config_green*1000);
				counter_red = config_red;
				counter_green = config_green;
				display_traffic_7SEG(0, counter_red--);
				display_traffic_7SEG(1, counter_green--);
				setTimer2(1000);
			}

			if(timer2_flag ==1){
				//display and decrease led 7seg counter
				display_traffic_7SEG(0, counter_yellow--);
				display_traffic_7SEG(1, counter_red--);
				setTimer2(1000);
			}

			if(button_flag[0] == 1){
				//button1 pressed, switch to MAN_RED
				button_flag[0] = 0;
				status = MAN_RED;
				// set up for blinky led
				set_traffic1_red();
				set_traffic2_red();
				setTimer1(BLINKY_TIME);
				//set up for display 7seg
				counter_red = config_red;
				display_traffic_7SEG(0, 1);
				display_traffic_7SEG(1, counter_red);
			}
			break;
		default:
			break;
	}
}
