/*
 * traffic.c
 *
 *  Created on: Oct 12, 2022
 *      Author: phamv
 */
#include "traffic.h"

void set_traffic1_red(){
	HAL_GPIO_WritePin(LED_RED1_GPIO_Port, LED_RED1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LED_GREEN1_GPIO_Port, LED_GREEN1_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(LED_YELLOW1_GPIO_Port, LED_YELLOW1_Pin, GPIO_PIN_SET);
}

void set_traffic2_red(){
	HAL_GPIO_WritePin(LED_RED2_GPIO_Port, LED_RED2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LED_GREEN2_GPIO_Port, LED_GREEN2_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(LED_YELLOW2_GPIO_Port, LED_YELLOW2_Pin, GPIO_PIN_SET);
}

void set_traffic1_green(){
	HAL_GPIO_WritePin(LED_RED1_GPIO_Port, LED_RED1_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(LED_GREEN1_GPIO_Port, LED_GREEN1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LED_YELLOW1_GPIO_Port, LED_YELLOW1_Pin, GPIO_PIN_SET);
}

void set_traffic2_green(){
	HAL_GPIO_WritePin(LED_RED2_GPIO_Port, LED_RED2_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(LED_GREEN2_GPIO_Port, LED_GREEN2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LED_YELLOW2_GPIO_Port, LED_YELLOW2_Pin, GPIO_PIN_SET);
}

void set_traffic1_yellow(){
	HAL_GPIO_WritePin(LED_RED1_GPIO_Port, LED_RED1_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(LED_GREEN1_GPIO_Port, LED_GREEN1_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(LED_YELLOW1_GPIO_Port, LED_YELLOW1_Pin, GPIO_PIN_RESET);
}

void set_traffic2_yellow(){
	HAL_GPIO_WritePin(LED_RED2_GPIO_Port, LED_RED2_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(LED_GREEN2_GPIO_Port, LED_GREEN2_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(LED_YELLOW2_GPIO_Port, LED_YELLOW2_Pin, GPIO_PIN_RESET);
}

void display_traffic_7SEG(int index, unsigned int num){
	if(index < 0 || index >= 2) return;
	if(num < 0 || num >= 100) return;
	display_7SEG(index*2, num/10);
	display_7SEG(index*2 + 1, num%10);
}

void display_7SEG(int index, unsigned int num){
	if(num < 0 || num >= 10) return;
	uint16_t pinA, pinB, pinC, pinD;
	switch(index){
	case 0:
		pinA = DRIVER_7SEG_A0_Pin;
		pinB = DRIVER_7SEG_B0_Pin;
		pinC = DRIVER_7SEG_C0_Pin;
		pinD = DRIVER_7SEG_D0_Pin;
		break;
	case 1:
		pinA = DRIVER_7SEG_A1_Pin;
		pinB = DRIVER_7SEG_B1_Pin;
		pinC = DRIVER_7SEG_C1_Pin;
		pinD = DRIVER_7SEG_D1_Pin;
		break;
	case 2:
		pinA = DRIVER_7SEG_A2_Pin;
		pinB = DRIVER_7SEG_B2_Pin;
		pinC = DRIVER_7SEG_C2_Pin;
		pinD = DRIVER_7SEG_D2_Pin;
		break;
	case 3:
		pinA = DRIVER_7SEG_A3_Pin;
		pinB = DRIVER_7SEG_B3_Pin;
		pinC = DRIVER_7SEG_C3_Pin;
		pinD = DRIVER_7SEG_D3_Pin;
		break;
	default:
		return;
	}
	HAL_GPIO_WritePin(GPIOB, pinA, num & 0x01);
	HAL_GPIO_WritePin(GPIOB, pinB, (num >> 1) & 0x01);
	HAL_GPIO_WritePin(GPIOB, pinC, (num >> 2) & 0x01);
	HAL_GPIO_WritePin(GPIOB, pinD, (num >> 3) & 0x01);
}
