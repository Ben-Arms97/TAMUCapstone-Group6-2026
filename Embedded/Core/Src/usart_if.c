/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    usart_if.c
  * @author  MCD Application Team
  * @brief   Configuration of UART driver interface for hyperterminal communication
  *          remapped to project UART1
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "usart_if.h"

/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* External variables ---------------------------------------------------------*/
/**
  * @brief UART handle from the main project UART1
  */
extern UART_HandleTypeDef huart1;

/**
  * @brief buffer to receive 1 character
  */
static uint8_t charRx;

/* USER CODE BEGIN EV */

/* USER CODE END EV */

/* Private typedef -----------------------------------------------------------*/
/**
  * @brief Trace driver callbacks handler
  */
const UTIL_ADV_TRACE_Driver_s UTIL_TraceDriver =
{
  vcom_Init,
  vcom_DeInit,
  vcom_ReceiveInit,
  vcom_Trace_DMA,
};

/* Private variables ---------------------------------------------------------*/
/**
  * @brief  TX complete callback
  */
static void (*TxCpltCallback)(void *);

/**
  * @brief  RX complete callback
  */
static void (*RxCpltCallback)(uint8_t *rxChar, uint16_t size, uint8_t error);

/* Exported functions --------------------------------------------------------*/

UTIL_ADV_TRACE_Status_t vcom_Init(void (*cb)(void *))
{
  TxCpltCallback = cb;

  /*
   * Reuse the already-configured project UART1.
   * If UART1 has not been initialized yet, initialize it now.
   */
  if (HAL_UART_GetState(&huart1) == HAL_UART_STATE_RESET)
  {
    MX_USART1_UART_Init();
  }

  return UTIL_ADV_TRACE_OK;
}

UTIL_ADV_TRACE_Status_t vcom_DeInit(void)
{
  /*
   * Do not deinit UART1 here because it belongs to the whole application,
   * not only the trace layer.
   */
  return UTIL_ADV_TRACE_OK;
}

void vcom_Trace(uint8_t *p_data, uint16_t size)
{
  HAL_UART_Transmit(&huart1, p_data, size, 1000);
}

UTIL_ADV_TRACE_Status_t vcom_Trace_DMA(uint8_t *p_data, uint16_t size)
{
  /*
   * Use blocking transmit on UART1 for reliable debug output.
   * Then manually notify the advanced trace layer that TX is complete.
   */
  if (HAL_UART_Transmit(&huart1, p_data, size, 1000) != HAL_OK)
  {
    return UTIL_ADV_TRACE_HW_ERROR;
  }

  if (TxCpltCallback != NULL)
  {
    TxCpltCallback(NULL);
  }

  return UTIL_ADV_TRACE_OK;
}

UTIL_ADV_TRACE_Status_t vcom_ReceiveInit(void (*RxCb)(uint8_t *rxChar, uint16_t size, uint8_t error))
{
  RxCpltCallback = RxCb;

  /*
   * RX is optional for trace/debug in this project.
   * Start 1-byte interrupt reception on UART1 if desired.
   */
  HAL_UART_Receive_IT(&huart1, &charRx, 1);

  return UTIL_ADV_TRACE_OK;
}

void vcom_Resume(void)
{
  if (HAL_UART_GetState(&huart1) == HAL_UART_STATE_RESET)
  {
    MX_USART1_UART_Init();
  }
}

void HAL_UART_TxCpltCallback(UART_HandleTypeDef *huart)
{
  if ((huart != NULL) && (huart->Instance == USART1))
  {
    if (TxCpltCallback != NULL)
    {
      TxCpltCallback(NULL);
    }
  }
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
  if ((huart != NULL) && (huart->Instance == USART1))
  {
    if ((RxCpltCallback != NULL) && (HAL_UART_ERROR_NONE == huart->ErrorCode))
    {
      RxCpltCallback(&charRx, 1, 0);
    }

    HAL_UART_Receive_IT(huart, &charRx, 1);
  }
}

/* USER CODE BEGIN EF */

/* USER CODE END EF */
