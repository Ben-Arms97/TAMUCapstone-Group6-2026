/**
  ******************************************************************************
  * @file    usart.h
  * @brief   LoRaWAN trace UART interface mapped onto project UART1
  ******************************************************************************
  */

#ifndef __USART_H__
#define __USART_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "main.h"

/*
 * Use the application's existing UART1 instance.
 * MX_USART1_UART_Init() and huart1 are expected to be defined elsewhere
 * in the project.
 */
extern UART_HandleTypeDef huart1;

void MX_USART1_UART_Init(void);

#ifdef __cplusplus
}
#endif

#endif /* __USART_H__ */
