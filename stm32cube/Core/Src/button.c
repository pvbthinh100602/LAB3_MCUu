/*
 * button.c
 *
 *  Created on: Oct 12, 2022
 *      Author: phamv
 */
#include "button.h"

static int button_buffer[NO_OF_BUTTONS];

static int debounce_buffer1[NO_OF_BUTTONS];
static int debounce_buffer2[NO_OF_BUTTONS];
static int debounce_buffer3[NO_OF_BUTTONS];

static int counter_for_button_pressed[NO_OF_BUTTONS];

int button_flag[NO_OF_BUTTONS];

void button_reading(){
	for(uint8_t i = 0 ; i < NO_OF_BUTTONS; i++){
		debounce_buffer3[i] = debounce_buffer2[i];
		debounce_buffer2[i] = debounce_buffer1[i];
		debounce_buffer1[i] = HAL_GPIO_ReadPin(GPIOA, BUTTON0_Pin << i);
		if((debounce_buffer3[i] == debounce_buffer2[i]) && debounce_buffer2[i] == debounce_buffer1[i]){
			button_buffer[i] = debounce_buffer3[i];
			if(button_buffer[i] == PRESSED_STATE){
				if(counter_for_button_pressed[i] > 0){
					counter_for_button_pressed[i]--;
				} else{
					counter_for_button_pressed[i] = TIME_OUT_FOR_KEY_PRESSED/TIMER_CYCLE;
					button_flag[i] = 1;
				}
			} else {
				counter_for_button_pressed[i] = 0;
			}
		}
	}
}


