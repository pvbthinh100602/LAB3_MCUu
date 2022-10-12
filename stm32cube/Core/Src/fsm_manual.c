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
			if(timer1_flag){
				HAL_GPIO_TogglePin(LED_RED1_GPIO_Port, LED_RED1_Pin);
				HAL_GPIO_TogglePin(LED_RED2_GPIO_Port, LED_RED2_Pin);
				setTimer1(500);
			}
			if(button_flag[0] == 1){
				button_flag[0] = 0;
				status = MAN_GREEN;
				set_traffic1_green();
				set_traffic2_green();
				setTimer1(500);
			}
			break;
		case MAN_GREEN:
			if(timer1_flag){
				HAL_GPIO_TogglePin(LED_GREEN1_GPIO_Port, LED_GREEN1_Pin);
				HAL_GPIO_TogglePin(LED_GREEN2_GPIO_Port, LED_GREEN2_Pin);
				setTimer1(500);
			}
			if(button_flag[0] == 1){
				button_flag[0] = 0;
				status = MAN_YELLOW;
				set_traffic1_yellow();
				set_traffic2_yellow();
				setTimer1(500);
			}
			break;
		case MAN_YELLOW:
			if(timer1_flag){
				HAL_GPIO_TogglePin(LED_YELLOW1_GPIO_Port, LED_YELLOW1_Pin);
				HAL_GPIO_TogglePin(LED_YELLOW2_GPIO_Port, LED_YELLOW2_Pin);
				setTimer1(500);
			}
			if(button_flag[0] == 1){
				button_flag[0] = 0;
				status = AUTO_RED1;
				setTimer1(3000);
			}
			break;
		default:
			break;
	}
}
