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

static int counter1_for_button_pressed[NO_OF_BUTTONS];
static int counter2_for_button_pressed[NO_OF_BUTTONS];

int button_flag[NO_OF_BUTTONS];

void button_reading(){
	for(uint8_t i = 0 ; i < NO_OF_BUTTONS; i++){
		debounce_buffer3[i] = debounce_buffer2[i];
		debounce_buffer2[i] = debounce_buffer1[i];
		uint16_t button_pin = 0;
		switch(i){
		case 0:
			button_pin = BUTTON0_Pin;
			break;
		case 1:
			button_pin = BUTTON1_Pin;
			break;
		case 2:
			button_pin = BUTTON2_Pin;
			break;
		default:
			break;
		}
		debounce_buffer1[i] = HAL_GPIO_ReadPin(GPIOA, button_pin);
		if((debounce_buffer3[i] == debounce_buffer2[i]) && debounce_buffer2[i] == debounce_buffer1[i]){
			button_buffer[i] = debounce_buffer3[i];
			if(button_buffer[i] == PRESSED_STATE){
				if(counter2_for_button_pressed[i]  == WAITING_TIME/TIMER_CYCLE){
					button_flag[i] = 1;
				}
				if(counter2_for_button_pressed[i] > 0){
					counter2_for_button_pressed[i]--;
				} else if(counter1_for_button_pressed[i] > 0){
					counter1_for_button_pressed[i]--;
				} else{
					counter1_for_button_pressed[i] = TIME_OUT_FOR_KEY_PRESSED/TIMER_CYCLE;
					button_flag[i] = 1;
				}
			} else {
				counter1_for_button_pressed[i] = 0;
				counter2_for_button_pressed[i] = WAITING_TIME/TIMER_CYCLE;
			}
		}
	}
}


