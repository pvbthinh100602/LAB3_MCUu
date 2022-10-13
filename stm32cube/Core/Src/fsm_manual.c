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
			display_traffic_7SEG(0, 1);
			display_traffic_7SEG(1, counter_red);
			if(timer1_flag){
				HAL_GPIO_TogglePin(LED_RED1_GPIO_Port, LED_RED1_Pin);
				HAL_GPIO_TogglePin(LED_RED2_GPIO_Port, LED_RED2_Pin);
				setTimer1(500);
			}
			if(button_flag[0] == 1){
				button_flag[0] = 0;
				status = MAN_GREEN;
				counter_green = config_green;
				set_traffic1_green();
				set_traffic2_green();
				setTimer1(500);
			}
			if(button_flag[1] == 1){
				button_flag[1] = 0;
				counter_red++;
				if(counter_red > 99) counter_red = 1;
			}
			if(button_flag[2] == 1){
				button_flag[2] = 0;
				config_red = counter_red;
				if(config_red <= config_green) config_green = config_red - 1;
				config_yellow = config_red - config_green;
			}
			break;
		case MAN_GREEN:
			display_traffic_7SEG(0, 2);
			display_traffic_7SEG(1, counter_green);
			if(timer1_flag){
				HAL_GPIO_TogglePin(LED_GREEN1_GPIO_Port, LED_GREEN1_Pin);
				HAL_GPIO_TogglePin(LED_GREEN2_GPIO_Port, LED_GREEN2_Pin);
				setTimer1(500);
			}
			if(button_flag[0] == 1){
				button_flag[0] = 0;
				status = MAN_YELLOW;
				counter_yellow = config_yellow;
				set_traffic1_yellow();
				set_traffic2_yellow();
				setTimer1(500);
			}
			if(button_flag[1] == 1){
				button_flag[1] = 0;
				counter_green++;
				if(counter_green > 99) counter_green = 1;
			}
			if(button_flag[2] == 1){
				button_flag[2] = 0;
				config_green = counter_green;
				if(config_green >= config_red) config_red = config_green + 1;
				config_yellow = config_red - config_green;
			}
			break;
		case MAN_YELLOW:
			display_traffic_7SEG(0, 3);
			display_traffic_7SEG(1, counter_yellow);
			if(timer1_flag){
				HAL_GPIO_TogglePin(LED_YELLOW1_GPIO_Port, LED_YELLOW1_Pin);
				HAL_GPIO_TogglePin(LED_YELLOW2_GPIO_Port, LED_YELLOW2_Pin);
				setTimer1(500);
			}
			if(button_flag[0] == 1){
				button_flag[0] = 0;
				status = AUTO_RED1;
				setTimer1(counter_green*1000);
				display_traffic_7SEG(0, counter_red--);
				display_traffic_7SEG(1, counter_green--);
				setTimer2(1000);
			}
			if(button_flag[1] == 1){
				button_flag[1] = 0;
				counter_yellow++;
				if(counter_yellow > 99) counter_yellow = 1;
			}
			if(button_flag[2] == 1){
				button_flag[2] = 0;
				config_yellow = counter_yellow;
				if(config_yellow >= config_red) config_red = config_yellow + 1;
				config_green = config_red - config_yellow;
			}
			break;
		default:
			break;
	}
}
