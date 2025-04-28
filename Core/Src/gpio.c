/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    gpio.c
  * @brief   This file provides code for the configuration
  *          of all used GPIO pins.
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

/* Includes ------------------------------------------------------------------*/
#include "gpio.h"

/* USER CODE BEGIN 0 */
#include "tim.h"
volatile uint32_t lastDebounceTime_Pin12 = 0;
volatile uint32_t lastDebounceTime_Pin13 = 0;
volatile uint32_t lastDebounceTime_Pin14 = 0;
volatile uint32_t lastDebounceTime_Pin15 = 0;
const uint32_t debounceDelay = 50; // w ms
/* USER CODE END 0 */

/*----------------------------------------------------------------------------*/
/* Configure GPIO                                                             */
/*----------------------------------------------------------------------------*/
/* USER CODE BEGIN 1 */

/* USER CODE END 1 */

/** Configure pins as
        * Analog
        * Input
        * Output
        * EVENT_OUT
        * EXTI
*/
void MX_GPIO_Init(void)
{

  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOC, LED1_Pin|LED2_Pin|LED3_Pin|Motor1_D_Pin
                          |Motor1_EN_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, Motor1_IN1_Pin|Motor1_IN2_Pin|Motor2_D_Pin|Motor2_IN1_Pin
                          |Motor2_IN2_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, Motor3_IN1_Pin|Motor3_IN2_Pin|Motor3_D_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : LED1_Pin LED2_Pin LED3_Pin Motor1_D_Pin
                           Motor1_EN_Pin */
  GPIO_InitStruct.Pin = LED1_Pin|LED2_Pin|LED3_Pin|Motor1_D_Pin
                          |Motor1_EN_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pins : Motor1_IN1_Pin Motor1_IN2_Pin Motor2_D_Pin Motor2_IN1_Pin
                           Motor2_IN2_Pin */
  GPIO_InitStruct.Pin = Motor1_IN1_Pin|Motor1_IN2_Pin|Motor2_D_Pin|Motor2_IN1_Pin
                          |Motor2_IN2_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : Motor3_IN1_Pin Motor3_IN2_Pin Motor3_D_Pin */
  GPIO_InitStruct.Pin = Motor3_IN1_Pin|Motor3_IN2_Pin|Motor3_D_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pins : Switch1_Pin Switch2_Pin Switch3_Pin Switch4_Pin */
  GPIO_InitStruct.Pin = Switch1_Pin|Switch2_Pin|Switch3_Pin|Switch4_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING;
  GPIO_InitStruct.Pull = GPIO_PULLDOWN;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /* EXTI interrupt init*/
  HAL_NVIC_SetPriority(EXTI15_10_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(EXTI15_10_IRQn);

}

/* USER CODE BEGIN 2 */
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
    uint32_t currentTime = HAL_GetTick();

    if ((GPIO_Pin == GPIO_PIN_12) && (currentTime - lastDebounceTime_Pin12 > debounceDelay))
    {
        lastDebounceTime_Pin12 = currentTime;
    }
    else if ((GPIO_Pin == GPIO_PIN_13) && (currentTime - lastDebounceTime_Pin13 > debounceDelay))
    {
        lastDebounceTime_Pin13 = currentTime;
    }
    else if ((GPIO_Pin == GPIO_PIN_14) && (currentTime - lastDebounceTime_Pin14 > debounceDelay))
    {
        lastDebounceTime_Pin14 = currentTime;
    }
    else if ((GPIO_Pin == GPIO_PIN_15) && (currentTime - lastDebounceTime_Pin15 > debounceDelay))
    {
        lastDebounceTime_Pin15 = currentTime;
    }
}

void Motor_init()
{
	 HAL_TIM_PWM_Start_IT(&htim2, TIM_CHANNEL_4);
	 HAL_TIM_PWM_Start_IT(&htim2, TIM_CHANNEL_3);


	 HAL_GPIO_WritePin(Motor1_D_GPIO_Port, Motor1_D_Pin,0);
	 HAL_GPIO_WritePin(Motor1_IN1_GPIO_Port, Motor1_IN1_Pin,0);
	 HAL_GPIO_WritePin(Motor1_IN2_GPIO_Port, Motor1_IN2_Pin,0);
	 HAL_GPIO_WritePin(Motor1_EN_GPIO_Port, Motor1_EN_Pin,0);


	 HAL_GPIO_WritePin(Motor2_D_GPIO_Port, Motor2_D_Pin,0);
	 HAL_GPIO_WritePin(Motor2_IN1_GPIO_Port, Motor2_IN1_Pin,0);
	 HAL_GPIO_WritePin(Motor2_IN2_GPIO_Port, Motor2_IN2_Pin,0);
	 __HAL_TIM_SET_COMPARE(&htim2,TIM_CHANNEL_4,0);


	 HAL_GPIO_WritePin(Motor3_D_GPIO_Port, Motor3_D_Pin,0);
	 HAL_GPIO_WritePin(Motor3_IN1_GPIO_Port, Motor3_IN1_Pin,0);
	 HAL_GPIO_WritePin(Motor3_IN2_GPIO_Port, Motor3_IN2_Pin,0);
	 __HAL_TIM_SET_COMPARE(&htim2,TIM_CHANNEL_3,0);



}

void Set_Motor1(int direction)
{
	if(direction==1)
	{
		 HAL_GPIO_WritePin(Motor1_IN1_GPIO_Port, Motor1_IN1_Pin,1);
		 HAL_GPIO_WritePin(Motor1_IN2_GPIO_Port, Motor1_IN2_Pin,0);
		 HAL_GPIO_WritePin(Motor1_EN_GPIO_Port, Motor1_EN_Pin,1);
	}
	else if(direction==-1)
	{
		 HAL_GPIO_WritePin(Motor1_IN1_GPIO_Port, Motor1_IN1_Pin,0);
		 HAL_GPIO_WritePin(Motor1_IN2_GPIO_Port, Motor1_IN2_Pin,1);
		 HAL_GPIO_WritePin(Motor1_EN_GPIO_Port, Motor1_EN_Pin,1);
	}
	else
	{
		 HAL_GPIO_WritePin(Motor1_IN1_GPIO_Port, Motor1_IN1_Pin,0);
		 HAL_GPIO_WritePin(Motor1_IN2_GPIO_Port, Motor1_IN2_Pin,0);
		 HAL_GPIO_WritePin(Motor1_EN_GPIO_Port, Motor1_EN_Pin,0);
	}

}
void Set_Motor2(int direction , int speed)
{
	if(direction==1)
	{
		 HAL_GPIO_WritePin(Motor2_IN1_GPIO_Port, Motor2_IN1_Pin,1);
		 HAL_GPIO_WritePin(Motor2_IN2_GPIO_Port, Motor2_IN2_Pin,0);
		 __HAL_TIM_SET_COMPARE(&htim2,TIM_CHANNEL_4,speed);
	}
	else if(direction==-1)
	{
		 HAL_GPIO_WritePin(Motor2_IN1_GPIO_Port, Motor2_IN1_Pin,0);
		 HAL_GPIO_WritePin(Motor2_IN2_GPIO_Port, Motor2_IN2_Pin,1);
		 __HAL_TIM_SET_COMPARE(&htim2,TIM_CHANNEL_4,speed);
	}
	else
	{
		 HAL_GPIO_WritePin(Motor2_IN1_GPIO_Port, Motor2_IN1_Pin,0);
		 HAL_GPIO_WritePin(Motor2_IN2_GPIO_Port, Motor2_IN2_Pin,0);
		 __HAL_TIM_SET_COMPARE(&htim2,TIM_CHANNEL_4,0);
	}

}
void Set_Motor3(int direction , int speed)
{
	if(direction==1)
	{
		 HAL_GPIO_WritePin(Motor3_IN1_GPIO_Port, Motor3_IN1_Pin,1);
		 HAL_GPIO_WritePin(Motor3_IN2_GPIO_Port, Motor3_IN2_Pin,0);
		 __HAL_TIM_SET_COMPARE(&htim2,TIM_CHANNEL_3,speed);
	}
	else if(direction==-1)
	{
		 HAL_GPIO_WritePin(Motor3_IN1_GPIO_Port, Motor3_IN1_Pin,0);
		 HAL_GPIO_WritePin(Motor3_IN2_GPIO_Port, Motor3_IN2_Pin,1);
		 __HAL_TIM_SET_COMPARE(&htim2,TIM_CHANNEL_3,speed);
	}
	else
	{
		 HAL_GPIO_WritePin(Motor3_IN1_GPIO_Port, Motor3_IN1_Pin,0);
		 HAL_GPIO_WritePin(Motor3_IN2_GPIO_Port, Motor3_IN2_Pin,0);
		 __HAL_TIM_SET_COMPARE(&htim2,TIM_CHANNEL_3,0);
	}

}

/* USER CODE END 2 */
