/*
 * traffic.h
 *
 *  Created on: Oct 12, 2022
 *      Author: phamv
 */

#ifndef INC_TRAFFIC_H_
#define INC_TRAFFIC_H_

#include "main.h"

void set_traffic1_red();
void set_traffic1_green();
void set_traffic1_yellow();

void set_traffic2_red();
void set_traffic2_green();
void set_traffic2_yellow();
void display_traffic_7SEG(int, unsigned int);
void display_7SEG(int, unsigned int);


#endif /* INC_TRAFFIC_H_ */
