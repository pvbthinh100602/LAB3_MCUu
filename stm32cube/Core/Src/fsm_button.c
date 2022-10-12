/*
 * fsm_button.c
 *
 *  Created on: Oct 12, 2022
 *      Author: phamv
 */
#include "fsm_button.h"

int buttonState[3] = {BUTTON_RELEASED, BUTTON_RELEASED, BUTTON_RELEASED};

void fsm_button_processing(){
	for(int i = 0; i < NO_OF_BUTTONS; i++){
		switch (buttonState[i]) {
				case BUTTON_RELEASED:
					if(is_button_pressed(i)){
						buttonState[i] = BUTTON_PRESSED;
					}
					break;
				case BUTTON_PRESSED:
					if(is_button_pressed(i) == 0){
						buttonState[i] = BUTTON_RELEASED;
					} else if(is_button_pressed_1s(i)){
						buttonState[i] = BUTTON_PRESSED_1S;
						setTimer2(1000);
					}
					break;
				case BUTTON_PRESSED_1S:
					if(is_button_pressed(i) == 0){
						buttonState[i] = BUTTON_RELEASED;
					}
					if(timer2_flag){
						buttonState[i] = BUTTON_PRESSED;
					}
					break;
				default:
					break;
			}
	}

}
