/**
  ******************************************************************************
  * @file    usart.h
  * @brief   This file contains all the function prototypes for
  *          the usart.c file
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under Ultimate Liberty license
  * SLA0044, the "License"; You may not use this file except in compliance with
  * the License. You may obtain a copy of the License at:
  *                             www.st.com/SLA0044
  *
  ******************************************************************************
  */
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __USART_H__
#define __USART_H__

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

extern UART_HandleTypeDef huart2;

/* USER CODE BEGIN Private defines */
#define USART_BAUDRATE              115200

#define USARTx_TX_Pin               GPIO_PIN_2
#define USARTx_TX_GPIO_Port         GPIOA
#define USARTx_TX_AF                GPIO_AF4_USART2
#define USARTx_RX_Pin               GPIO_PIN_3
#define USARTx_RX_GPIO_Port         GPIOA
#define USARTx_RX_AF                GPIO_AF4_USART2

#define USARTx_TX_GPIO_CLK_ENABLE() __HAL_RCC_GPIOA_CLK_ENABLE()
#define USARTx_RX_GPIO_CLK_ENABLE() __HAL_RCC_GPIOA_CLK_ENABLE()

#define USARTx_TX_DMA_CHANNEL       DMA1_Channel4
#define USARTx_TX_DMA_REQUEST       DMA_REQUEST_4
#define DMAx_CLK_ENABLE()           __HAL_RCC_DMA1_CLK_ENABLE()

#define USARTx_IRQn                 USART2_IRQn
#define USARTx_DMA_TX_IRQn          DMA1_Channel4_5_6_7_IRQn
#define USARTx_Priority             0
#define USARTx_DMA_Priority         0
/* USER CODE END Private defines */

void MX_USART2_UART_Init(void);

/* USER CODE BEGIN Prototypes */

/* USER CODE END Prototypes */

#ifdef __cplusplus
}
#endif

#endif /* __USART_H__ */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
