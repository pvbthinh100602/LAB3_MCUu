/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2022 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f1xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define BUTTON0_Pin GPIO_PIN_1
#define BUTTON0_GPIO_Port GPIOA
#define BUTTON1_Pin GPIO_PIN_2
#define BUTTON1_GPIO_Port GPIOA
#define BUTTON2_Pin GPIO_PIN_3
#define BUTTON2_GPIO_Port GPIOA
#define LED_CHECK_Pin GPIO_PIN_5
#define LED_CHECK_GPIO_Port GPIOA
#define DRIVER_7SEG_A0_Pin GPIO_PIN_0
#define DRIVER_7SEG_A0_GPIO_Port GPIOB
#define DRIVER_7SEG_B0_Pin GPIO_PIN_1
#define DRIVER_7SEG_B0_GPIO_Port GPIOB
#define DRIVER_7SEG_C0_Pin GPIO_PIN_2
#define DRIVER_7SEG_C0_GPIO_Port GPIOB
#define DRIVER_7SEG_C2_Pin GPIO_PIN_10
#define DRIVER_7SEG_C2_GPIO_Port GPIOB
#define DRIVER_7SEG_D2_Pin GPIO_PIN_11
#define DRIVER_7SEG_D2_GPIO_Port GPIOB
#define DRIVER_7SEG_A3_Pin GPIO_PIN_12
#define DRIVER_7SEG_A3_GPIO_Port GPIOB
#define DRIVER_7SEG_B3_Pin GPIO_PIN_13
#define DRIVER_7SEG_B3_GPIO_Port GPIOB
#define DRIVER_7SEG_C3_Pin GPIO_PIN_14
#define DRIVER_7SEG_C3_GPIO_Port GPIOB
#define DRIVER_7SEG_D3_Pin GPIO_PIN_15
#define DRIVER_7SEG_D3_GPIO_Port GPIOB
#define LED_RED1_Pin GPIO_PIN_10
#define LED_RED1_GPIO_Port GPIOA
#define LED_GREEN1_Pin GPIO_PIN_11
#define LED_GREEN1_GPIO_Port GPIOA
#define LED_YELLOW1_Pin GPIO_PIN_12
#define LED_YELLOW1_GPIO_Port GPIOA
#define LED_RED2_Pin GPIO_PIN_13
#define LED_RED2_GPIO_Port GPIOA
#define LED_GREEN2_Pin GPIO_PIN_14
#define LED_GREEN2_GPIO_Port GPIOA
#define LED_YELLOW2_Pin GPIO_PIN_15
#define LED_YELLOW2_GPIO_Port GPIOA
#define DRIVER_7SEG_D0_Pin GPIO_PIN_3
#define DRIVER_7SEG_D0_GPIO_Port GPIOB
#define DRIVER_7SEG_A1_Pin GPIO_PIN_4
#define DRIVER_7SEG_A1_GPIO_Port GPIOB
#define DRIVER_7SEG_B1_Pin GPIO_PIN_5
#define DRIVER_7SEG_B1_GPIO_Port GPIOB
#define DRIVER_7SEG_C1_Pin GPIO_PIN_6
#define DRIVER_7SEG_C1_GPIO_Port GPIOB
#define DRIVER_7SEG_D1_Pin GPIO_PIN_7
#define DRIVER_7SEG_D1_GPIO_Port GPIOB
#define DRIVER_7SEG_A2_Pin GPIO_PIN_8
#define DRIVER_7SEG_A2_GPIO_Port GPIOB
#define DRIVER_7SEG_B2_Pin GPIO_PIN_9
#define DRIVER_7SEG_B2_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
