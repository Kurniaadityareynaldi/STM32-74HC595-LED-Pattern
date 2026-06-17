/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
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
#include "stm32f0xx_hal.h"

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
#define clock_Pin GPIO_PIN_1
#define clock_GPIO_Port GPIOA
#define sign1_Pin GPIO_PIN_2
#define sign1_GPIO_Port GPIOA
#define sign2_Pin GPIO_PIN_3
#define sign2_GPIO_Port GPIOA
#define sign3_Pin GPIO_PIN_4
#define sign3_GPIO_Port GPIOA
#define sign4_Pin GPIO_PIN_5
#define sign4_GPIO_Port GPIOA
#define mr_Pin GPIO_PIN_6
#define mr_GPIO_Port GPIOA
#define latch_Pin GPIO_PIN_7
#define latch_GPIO_Port GPIOA
#define oe_Pin GPIO_PIN_9
#define oe_GPIO_Port GPIOA
#define data_Pin GPIO_PIN_10
#define data_GPIO_Port GPIOA

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
