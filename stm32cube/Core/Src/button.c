/*
 * button.c
 *
 *  Created on: Oct 12, 2022
 *      Author: phamv
 */
#include "button.h"

static GPIO_PinState button_buffer[NO_OF_BUTTONS];

static GPIO_PinState debounce_buffer1[NO_OF_BUTTONS];
static GPIO_PinState debounce_buffer2[NO_OF_BUTTONS];
static GPIO_PinState debounce_buffer3[NO_OF_BUTTONS];

static uint8_t counter_button_pressed_1s[NO_OF_BUTTONS];

int button_flag[NO_OF_BUTTONS] = {0, 0, 0};

void button_reading(void){
	for(int i = 0; i < NO_OF_BUTTONS; i++){
		debounce_buffer3[i] = debounce_buffer2[i];
		debounce_buffer2[i] = debounce_buffer1[i];
		debounce_buffer1[i] = HAL_GPIO_ReadPin(GPIOA, 1u << (i + 1));
		if(debounce_buffer1[i] == debounce_buffer2[i] && debounce_buffer2[i] == debounce_buffer3[i]){
			if(button_buffer[i] != debounce_buffer3[i]){
				button_buffer[i] = debounce_buffer3[i];
				if(button_buffer[i] == BUTTON_IS_PRESSED){
					counter_button_pressed_1s[i] = DURATION_AUTO_INCREASING/TIMER_CYCLE;
					button_flag[i] = 1;
				}
			} else {
				counter_button_pressed_1s[i]--;
				if(counter_button_pressed_1s[i] == 0){
					button_buffer[i] = BUTTON_NORMAL;
				}
			}
		}
	}
}


