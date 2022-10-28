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

			if(isButtonPressed(1) == 1){
				//button2 pressed, increase value
				counter_red++;
				if(counter_red > 99) counter_red = 2;
				updateBuffer7SEG(1, counter_red);
			}

			if(isButtonPressed(2) == 1){
				//button3 pressed, update the value
				config_red = counter_red;
				if(config_red <= config_green){
					config_green = config_red - 1;
				}
				config_yellow = config_red - config_green;
			}

			if(isButtonPressed(0) == 1){
				//button1 pressed, switch to MAN_GREEN
				status = MAN_GREEN;
				set_traffic1_green();
				set_traffic2_green();
				setTimer1(BLINKY_TIME);
				counter_green = config_green;
				updateBuffer7SEG(2, counter_green);
			}
			break;
		case MAN_GREEN:

			if(timer1_flag == 1){
				//blinky led
				toggle_traffic_green();
				setTimer1(BLINKY_TIME);
			}

			if(isButtonPressed(1) == 1){
				//button2 pressed, increase value
				counter_green++;
				if(counter_green > 99) counter_green = 1;
				updateBuffer7SEG(2, counter_green);
			}

			if(isButtonPressed(2) == 1){
				//button3 pressed, update the value
				config_green = counter_green;
				if(config_red <= config_green){
					config_red = config_green + 1;
				}
				config_yellow = config_red - config_green;
			}

			if(isButtonPressed(0) == 1){
				//button1 pressed, switch to MAN_YELLOW
				status = MAN_YELLOW;
				set_traffic1_yellow();
				set_traffic2_yellow();
				setTimer1(BLINKY_TIME);
				counter_yellow = config_yellow;
				updateBuffer7SEG(3, counter_yellow);
			}
			break;
		case MAN_YELLOW:

			if(timer1_flag == 1){
				//blinky led
				toggle_traffic_yellow();
				setTimer1(BLINKY_TIME);
			}

			if(isButtonPressed(1) == 1){
				//button2 pressed, increase value
				counter_yellow++;
				if(counter_yellow > 99) counter_yellow = 1;
				updateBuffer7SEG(3, counter_yellow);
			}

			if(isButtonPressed(2) == 1){
				//button3 pressed, update the value
				config_yellow = counter_yellow;
				config_red = config_yellow + config_green;
			}

			if(isButtonPressed(0) == 1){
				//button1 pressed, switch to AUTO_RED1
				status = AUTO_RED1;
				setTimer1(config_green*1000);
				setTimer2(1000);
				counter_red = config_red;
				counter_green = config_green;
				updateBuffer7SEG(counter_red--, counter_green--);
			}
			break;
		default:
			break;
	}
}
