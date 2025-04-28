/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
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
#define LED1_Pin GPIO_PIN_13
#define LED1_GPIO_Port GPIOC
#define LED2_Pin GPIO_PIN_14
#define LED2_GPIO_Port GPIOC
#define LED3_Pin GPIO_PIN_15
#define LED3_GPIO_Port GPIOC
#define Motor1_D_Pin GPIO_PIN_2
#define Motor1_D_GPIO_Port GPIOC
#define Motor1_EN_Pin GPIO_PIN_3
#define Motor1_EN_GPIO_Port GPIOC
#define Motor1_IN1_Pin GPIO_PIN_0
#define Motor1_IN1_GPIO_Port GPIOA
#define Motor1_IN2_Pin GPIO_PIN_1
#define Motor1_IN2_GPIO_Port GPIOA
#define Motor2_D_Pin GPIO_PIN_3
#define Motor2_D_GPIO_Port GPIOA
#define Motor2_IN1_Pin GPIO_PIN_6
#define Motor2_IN1_GPIO_Port GPIOA
#define Motor2_IN2_Pin GPIO_PIN_7
#define Motor2_IN2_GPIO_Port GPIOA
#define Motor3_IN1_Pin GPIO_PIN_0
#define Motor3_IN1_GPIO_Port GPIOB
#define Motor3_IN2_Pin GPIO_PIN_1
#define Motor3_IN2_GPIO_Port GPIOB
#define Motor3_D_Pin GPIO_PIN_2
#define Motor3_D_GPIO_Port GPIOB
#define Motor3_EN_Pin GPIO_PIN_10
#define Motor3_EN_GPIO_Port GPIOB
#define Motor2_EN_Pin GPIO_PIN_11
#define Motor2_EN_GPIO_Port GPIOB
#define Switch1_Pin GPIO_PIN_12
#define Switch1_GPIO_Port GPIOB
#define Switch1_EXTI_IRQn EXTI15_10_IRQn
#define Switch2_Pin GPIO_PIN_13
#define Switch2_GPIO_Port GPIOB
#define Switch2_EXTI_IRQn EXTI15_10_IRQn
#define Switch3_Pin GPIO_PIN_14
#define Switch3_GPIO_Port GPIOB
#define Switch3_EXTI_IRQn EXTI15_10_IRQn
#define Switch4_Pin GPIO_PIN_15
#define Switch4_GPIO_Port GPIOB
#define Switch4_EXTI_IRQn EXTI15_10_IRQn

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
