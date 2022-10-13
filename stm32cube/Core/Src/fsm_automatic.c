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
			counter_red = config_red;
			counter_green = config_green;
			display_traffic_7SEG(0, counter_red--);
			display_traffic_7SEG(1, counter_green--);
			setTimer2(1000);
			break;
		case AUTO_RED1:
			//turn on red1 and green2
			set_traffic1_red();
			set_traffic2_green();
			if(timer1_flag){
				status = AUTO_RED2;
				setTimer1(config_yellow*1000);
				counter_yellow = config_yellow;
				display_traffic_7SEG(0, counter_red--);
				display_traffic_7SEG(1, counter_yellow--);
				setTimer2(1000);
			}
			if(timer2_flag){
				display_traffic_7SEG(0, counter_red--);
				display_traffic_7SEG(1, counter_green--);
				setTimer2(1000);
			}
			if(button_flag[0] == 1){
				button_flag[0] = 0;
				status = MAN_RED;
				counter_red = config_red;
				set_traffic1_red();
				set_traffic2_red();
				setTimer1(500);
			}
			break;
		case AUTO_RED2:
			//turn on red1 and yellow2
			set_traffic1_red();
			set_traffic2_yellow();
			if(timer1_flag){
				status = AUTO_GREEN;
				setTimer1(config_green*1000);
				counter_red = config_red;
				counter_green = config_green;
				display_traffic_7SEG(0, counter_green--);
				display_traffic_7SEG(1, counter_red--);
				setTimer2(1000);
			}
			if(timer2_flag){
				display_traffic_7SEG(0, counter_red--);
				display_traffic_7SEG(1, counter_yellow--);
				setTimer2(1000);
			}
			if(button_flag[0] == 1){
				button_flag[0] = 0;
				status = MAN_RED;
				counter_red = config_red;
				set_traffic1_red();
				set_traffic2_red();
				setTimer1(500);
			}
			break;
		case AUTO_GREEN:
			//turn on green1 and red2
			set_traffic1_green();
			set_traffic2_red();
			if(timer1_flag){
				status = AUTO_YELLOW;
				setTimer1(config_yellow*1000);
				counter_yellow = config_yellow;
				display_traffic_7SEG(0, counter_yellow--);
				display_traffic_7SEG(1, counter_red--);
				setTimer2(1000);
			}
			if(timer2_flag){
				display_traffic_7SEG(0, counter_green--);
				display_traffic_7SEG(1, counter_red--);
				setTimer2(1000);
			}
			if(button_flag[0] == 1){
				button_flag[0] = 0;
				status = MAN_RED;
				counter_red = config_red;
				set_traffic1_red();
				set_traffic2_red();
				setTimer1(500);
			}
			break;
		case AUTO_YELLOW:
			//turn on yellow1 and red2
			set_traffic1_yellow();
			set_traffic2_red();
			if(timer1_flag){
				status = AUTO_RED1;
				setTimer1(config_green*1000);
				counter_red = config_red;
				counter_green = config_green;
				display_traffic_7SEG(0, counter_red--);
				display_traffic_7SEG(1, counter_green--);
				setTimer2(1000);
			}
			if(timer2_flag){
				display_traffic_7SEG(0, counter_yellow--);
				display_traffic_7SEG(1, counter_red--);
				setTimer2(1000);
			}
			if(button_flag[0] == 1){
				button_flag[0] = 0;
				status = MAN_RED;
				counter_red = config_red;
				set_traffic1_red();
				set_traffic2_red();
				setTimer1(500);
			}
			break;
		default:
			break;
	}
}
