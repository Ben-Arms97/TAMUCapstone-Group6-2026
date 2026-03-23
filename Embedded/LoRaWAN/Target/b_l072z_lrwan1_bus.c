/**
  ******************************************************************************
  * @file           : b_l072z_lrwan1_bus.c
  * @brief          : source file for the BSP BUS IO driver
  ******************************************************************************
  * This notice applies to any and all portions of this file
  * that are not between comment pairs USER CODE BEGIN and
  * USER CODE END. Other portions of this file, whether
  * inserted by the user or by software development tools
  * are owned by their respective copyright owners.
  *
  * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under Ultimate Liberty license
  * SLA0044, the "License"; You may not use this file except in compliance with
  * the License. You may obtain a copy of the License at:
  *                             www.st.com/SLA0044
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "b_l072z_lrwan1_bus.h"
#include "b_l072z_lrwan1_errno.h"
#include "stm32l0xx_hal.h"

#define TIMEOUT_DURATION 1000

/** @addtogroup BSP
  * @{
  */
__weak HAL_StatusTypeDef MX_SPI1_Init(SPI_HandleTypeDef *hspi);
__weak HAL_StatusTypeDef MX_SPI2_Init(SPI_HandleTypeDef *hspi);

/** @addtogroup NUCLEO_L073RZ
  * @{
  */

/** @defgroup NUCLEO_L073RZ_BUS NUCLEO_L073RZ BUS
  * @{
  */

/** @defgroup NUCLEO_L073RZ_Private_Variables BUS Private Variables
  * @{
  */
SPI_HandleTypeDef hspi1;
SPI_HandleTypeDef hspi2;

#if (USE_HAL_SPI_REGISTER_CALLBACKS == 1)
static uint32_t IsSPI1MspCbValid = 0;
static uint32_t IsSPI2MspCbValid = 0;
#endif /* USE_HAL_SPI_REGISTER_CALLBACKS */
/**
  * @}
  */

/** @defgroup NUCLEO_L073RZ_Private_FunctionPrototypes  Private Function Prototypes
  * @{
  */

static void SPI1_MspInit(SPI_HandleTypeDef *spiHandle);
static void SPI1_MspDeInit(SPI_HandleTypeDef *spiHandle);
static void SPI2_MspInit(SPI_HandleTypeDef *spiHandle);
static void SPI2_MspDeInit(SPI_HandleTypeDef *spiHandle);
static uint32_t SPI_GetPrescaler(uint32_t clock_src_hz, uint32_t baudrate_mbps);

/**
  * @}
  */

/** @defgroup NUCLEO_L073RZ_LOW_LEVEL_Private_Functions NUCLEO_L073RZ LOW LEVEL Private Functions
  * @{
  */

/** @defgroup NUCLEO_L073RZ_BUS_Exported_Functions NUCLEO_L073RZ_BUS Exported Functions
  * @{
  */
/* BUS IO driver over SPI Peripheral */
/*******************************************************************************
                            BUS OPERATIONS OVER SPI
  *******************************************************************************/
/**
  * @brief  Initializes SPI HAL.
  * @retval BSP status
  */
int32_t BSP_SPI1_Init(void)
{
  int32_t ret = BSP_ERROR_NONE;

  hspi1.Instance  = SPI1;
  if (HAL_SPI_GetState(&hspi1) == HAL_SPI_STATE_RESET)
  {
#if (USE_HAL_SPI_REGISTER_CALLBACKS == 0)
    SPI1_MspInit(&hspi1);
#else
    if (IsSPI1MspCbValid == 0U)
    {
      if (BSP_SPI1_RegisterDefaultMspCallbacks() != BSP_ERROR_NONE)
      {
        return BSP_ERROR_MSP_FAILURE;
      }
    }
#endif

    if (MX_SPI1_Init(&hspi1) != HAL_OK)
    {
      ret = BSP_ERROR_BUS_FAILURE;
    }
  }

  return ret;
}

/**
  * @brief  DeInitializes SPI HAL.
  * @retval BSP status
  */
int32_t BSP_SPI1_DeInit(void)
{
  int32_t ret = BSP_ERROR_BUS_FAILURE;

#if (USE_HAL_SPI_REGISTER_CALLBACKS == 0)
  SPI1_MspDeInit(&hspi1);
#endif

  if (HAL_SPI_DeInit(&hspi1) == HAL_OK)
  {
    ret = BSP_ERROR_NONE;
  }

  return ret;
}

/**
  * @brief  Sends a byte on SPI.
  * @retval BSP status
  */
int32_t BSP_SPI1_Send(uint8_t *pData, uint16_t len)
{
  int32_t ret = BSP_ERROR_UNKNOWN_FAILURE;

  if (HAL_SPI_Transmit(&hspi1, pData, len, TIMEOUT_DURATION) == HAL_OK)
  {
    ret = len;
  }

  return ret;
}

/**
  * @brief  Receives a byte on SPI.
  * @retval BSP status
  */
int32_t BSP_SPI1_Recv(uint8_t *pData, uint16_t len)
{
  int32_t ret = BSP_ERROR_UNKNOWN_FAILURE;

  if (HAL_SPI_Receive(&hspi1, pData, len, TIMEOUT_DURATION) == HAL_OK)
  {
    ret = len;
  }

  return ret;
}

/**
  * @brief  Sends and receives on SPI.
  * @retval BSP status
  */
int32_t BSP_SPI1_SendRecv(uint8_t *pTxData, uint8_t *pRxData, uint16_t len)
{
  int32_t ret = BSP_ERROR_UNKNOWN_FAILURE;

  if (HAL_SPI_TransmitReceive(&hspi1, pTxData, pRxData, len, TIMEOUT_DURATION) == HAL_OK)
  {
    ret = len;
  }

  return ret;
}

/* =========================
 * Custom radio bus on SPI2
 * ========================= */
int32_t BSP_SPI2_Init(void)
{
  int32_t ret = BSP_ERROR_NONE;

  hspi2.Instance = SPI2;
  if (HAL_SPI_GetState(&hspi2) == HAL_SPI_STATE_RESET)
  {
#if (USE_HAL_SPI_REGISTER_CALLBACKS == 0)
    SPI2_MspInit(&hspi2);
#else
    if (IsSPI2MspCbValid == 0U)
    {
      return BSP_ERROR_MSP_FAILURE;
    }
#endif

    if (MX_SPI2_Init(&hspi2) != HAL_OK)
    {
      ret = BSP_ERROR_BUS_FAILURE;
    }
  }

  return ret;
}

int32_t BSP_SPI2_DeInit(void)
{
  int32_t ret = BSP_ERROR_BUS_FAILURE;

#if (USE_HAL_SPI_REGISTER_CALLBACKS == 0)
  SPI2_MspDeInit(&hspi2);
#endif

  if (HAL_SPI_DeInit(&hspi2) == HAL_OK)
  {
    ret = BSP_ERROR_NONE;
  }

  return ret;
}

int32_t BSP_SPI2_Send(uint8_t *pData, uint16_t len)
{
  int32_t ret = BSP_ERROR_UNKNOWN_FAILURE;

  if (HAL_SPI_Transmit(&hspi2, pData, len, TIMEOUT_DURATION) == HAL_OK)
  {
    ret = len;
  }

  return ret;
}

int32_t BSP_SPI2_Recv(uint8_t *pData, uint16_t len)
{
  int32_t ret = BSP_ERROR_UNKNOWN_FAILURE;

  if (HAL_SPI_Receive(&hspi2, pData, len, TIMEOUT_DURATION) == HAL_OK)
  {
    ret = len;
  }

  return ret;
}

int32_t BSP_SPI2_SendRecv(uint8_t *pTxData, uint8_t *pRxData, uint16_t len)
{
  int32_t ret = BSP_ERROR_UNKNOWN_FAILURE;

  if (HAL_SPI_TransmitReceive(&hspi2, pTxData, pRxData, len, TIMEOUT_DURATION) == HAL_OK)
  {
    ret = len;
  }

  return ret;
}

/**
  * @brief  SPI1 Init
  * @param  hspi SPI handle
  * @retval HAL status
  */
__weak HAL_StatusTypeDef MX_SPI1_Init(SPI_HandleTypeDef *hspi)
{
  HAL_StatusTypeDef ret = HAL_OK;

  hspi->Instance = SPI1;
  hspi->Init.Mode = SPI_MODE_MASTER;
  hspi->Init.Direction = SPI_DIRECTION_2LINES;
  hspi->Init.DataSize = SPI_DATASIZE_8BIT;
  hspi->Init.CLKPolarity = SPI_POLARITY_LOW;
  hspi->Init.CLKPhase = SPI_PHASE_1EDGE;
  hspi->Init.NSS = SPI_NSS_SOFT;
  hspi->Init.BaudRatePrescaler = SPI_GetPrescaler(HAL_RCC_GetPCLK2Freq(), RADIO_SPI_BAUDRATE);
  hspi->Init.FirstBit = SPI_FIRSTBIT_MSB;
  hspi->Init.TIMode = SPI_TIMODE_DISABLE;
  hspi->Init.CRCCalculation = SPI_CRCCALCULATION_DISABLE;
  hspi->Init.CRCPolynomial = 7;

  if (HAL_SPI_Init(hspi) != HAL_OK)
  {
    ret = HAL_ERROR;
  }

  return ret;
}

/**
  * @brief  SPI2 Init
  * @param  hspi SPI handle
  * @retval HAL status
  */
__weak HAL_StatusTypeDef MX_SPI2_Init(SPI_HandleTypeDef *hspi)
{
  HAL_StatusTypeDef ret = HAL_OK;

  hspi->Instance = SPI2;
  hspi->Init.Mode = SPI_MODE_MASTER;
  hspi->Init.Direction = SPI_DIRECTION_2LINES;
  hspi->Init.DataSize = SPI_DATASIZE_8BIT;
  hspi->Init.CLKPolarity = SPI_POLARITY_LOW;
  hspi->Init.CLKPhase = SPI_PHASE_1EDGE;
  hspi->Init.NSS = SPI_NSS_SOFT;
  hspi->Init.BaudRatePrescaler = SPI_GetPrescaler(HAL_RCC_GetPCLK1Freq(), RADIO_SPI_BAUDRATE);
  hspi->Init.FirstBit = SPI_FIRSTBIT_MSB;
  hspi->Init.TIMode = SPI_TIMODE_DISABLE;
  hspi->Init.CRCCalculation = SPI_CRCCALCULATION_DISABLE;
  hspi->Init.CRCPolynomial = 7;

  if (HAL_SPI_Init(hspi) != HAL_OK)
  {
    ret = HAL_ERROR;
  }

  return ret;
}

static void SPI1_MspInit(SPI_HandleTypeDef *spiHandle)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  BUS_SPI1_SCK_GPIO_CLK_ENABLE();
  BUS_SPI1_MISO_GPIO_CLK_ENABLE();
  BUS_SPI1_MOSI_GPIO_CLK_ENABLE();
  __HAL_RCC_SPI1_CLK_ENABLE();

  GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;

  GPIO_InitStruct.Alternate = BUS_SPI1_MOSI_GPIO_AF;
  GPIO_InitStruct.Pin = BUS_SPI1_MOSI_GPIO_PIN;
  HAL_GPIO_Init(BUS_SPI1_MOSI_GPIO_PORT, &GPIO_InitStruct);

  GPIO_InitStruct.Alternate = BUS_SPI1_MISO_GPIO_AF;
  GPIO_InitStruct.Pin = BUS_SPI1_MISO_GPIO_PIN;
  HAL_GPIO_Init(BUS_SPI1_MISO_GPIO_PORT, &GPIO_InitStruct);

  GPIO_InitStruct.Alternate = BUS_SPI1_SCK_GPIO_AF;
  GPIO_InitStruct.Pin = BUS_SPI1_SCK_GPIO_PIN;
  HAL_GPIO_Init(BUS_SPI1_SCK_GPIO_PORT, &GPIO_InitStruct);
}

static void SPI1_MspDeInit(SPI_HandleTypeDef *spiHandle)
{
  __HAL_RCC_SPI1_CLK_DISABLE();

  HAL_GPIO_DeInit(BUS_SPI1_MOSI_GPIO_PORT, BUS_SPI1_MOSI_GPIO_PIN);
  HAL_GPIO_DeInit(BUS_SPI1_MISO_GPIO_PORT, BUS_SPI1_MISO_GPIO_PIN);
  HAL_GPIO_DeInit(BUS_SPI1_SCK_GPIO_PORT, BUS_SPI1_SCK_GPIO_PIN);
}

static void SPI2_MspInit(SPI_HandleTypeDef *spiHandle)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  BUS_SPI2_SCK_GPIO_CLK_ENABLE();
  BUS_SPI2_MISO_GPIO_CLK_ENABLE();
  BUS_SPI2_MOSI_GPIO_CLK_ENABLE();
  __HAL_RCC_SPI2_CLK_ENABLE();

  GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;

  GPIO_InitStruct.Alternate = BUS_SPI2_SCK_GPIO_AF;
  GPIO_InitStruct.Pin = BUS_SPI2_SCK_GPIO_PIN;
  HAL_GPIO_Init(BUS_SPI2_SCK_GPIO_PORT, &GPIO_InitStruct);

  GPIO_InitStruct.Alternate = BUS_SPI2_MISO_GPIO_AF;
  GPIO_InitStruct.Pin = BUS_SPI2_MISO_GPIO_PIN;
  HAL_GPIO_Init(BUS_SPI2_MISO_GPIO_PORT, &GPIO_InitStruct);

  GPIO_InitStruct.Alternate = BUS_SPI2_MOSI_GPIO_AF;
  GPIO_InitStruct.Pin = BUS_SPI2_MOSI_GPIO_PIN;
  HAL_GPIO_Init(BUS_SPI2_MOSI_GPIO_PORT, &GPIO_InitStruct);
}

static void SPI2_MspDeInit(SPI_HandleTypeDef *spiHandle)
{
  __HAL_RCC_SPI2_CLK_DISABLE();

  HAL_GPIO_DeInit(BUS_SPI2_SCK_GPIO_PORT, BUS_SPI2_SCK_GPIO_PIN);
  HAL_GPIO_DeInit(BUS_SPI2_MISO_GPIO_PORT, BUS_SPI2_MISO_GPIO_PIN);
  HAL_GPIO_DeInit(BUS_SPI2_MOSI_GPIO_PORT, BUS_SPI2_MOSI_GPIO_PIN);
}

static uint32_t SPI_GetPrescaler(uint32_t clock_src_hz, uint32_t baudrate_mbps)
{
  uint32_t divisor = 0;
  uint32_t spi_clk = clock_src_hz;
  uint32_t presc = 0;

  static const uint32_t baudrate[] =
  {
    SPI_BAUDRATEPRESCALER_2,
    SPI_BAUDRATEPRESCALER_4,
    SPI_BAUDRATEPRESCALER_8,
    SPI_BAUDRATEPRESCALER_16,
    SPI_BAUDRATEPRESCALER_32,
    SPI_BAUDRATEPRESCALER_64,
    SPI_BAUDRATEPRESCALER_128,
    SPI_BAUDRATEPRESCALER_256,
  };

  while (spi_clk > baudrate_mbps)
  {
    presc = baudrate[divisor];
    if (++divisor > 7)
    {
      break;
    }

    spi_clk = (spi_clk >> 1);
  }

  return presc;
}

__weak HAL_StatusTypeDef MX_I2C1_Init(I2C_HandleTypeDef *hi2c);

/** @addtogroup BSP
  * @{
  */

/** @addtogroup STM32L0XX_NUCLEO
  * @{
  */

/** @defgroup STM32L0XX_NUCLEO_BUS STM32L0XX_NUCLEO BUS
  * @{
  */

/** @defgroup STM32L0XX_NUCLEO_BUS_Exported_Variables BUS Exported Variables
  * @{
  */

I2C_HandleTypeDef hi2c1;

/**
  * @}
  */

/** @defgroup STM32L0XX_NUCLEO_BUS_Private_Variables BUS Private Variables
  * @{
  */

#if (USE_HAL_I2C_REGISTER_CALLBACKS == 1U)
static uint32_t IsI2C1MspCbValid = 0;
#endif /* USE_HAL_I2C_REGISTER_CALLBACKS */

/**
  * @}
  */

/** @defgroup STM32L0XX_NUCLEO_LOW_LEVEL_Private_FunctionPrototypes LOW LEVEL Private FunctionPrototypes
  * @{
  */

static void I2C1_MspInit(I2C_HandleTypeDef *hI2c);
static void I2C1_MspDeInit(I2C_HandleTypeDef *hI2c);

/**
  * @}
  */

/*******************************************************************************
                            BUS OPERATIONS OVER I2C
  *******************************************************************************/

int32_t BSP_I2C1_Init(void)
{
  int32_t ret = BSP_ERROR_NONE;

  hi2c1.Instance = I2C1;
  if (HAL_I2C_GetState(&hi2c1) == HAL_I2C_STATE_RESET)
  {
#if (USE_HAL_I2C_REGISTER_CALLBACKS == 0)
    I2C1_MspInit(&hi2c1);
#else
    if (IsI2C1MspCbValid == 0U)
    {
      if (BSP_I2C1_RegisterDefaultMspCallbacks() != BSP_ERROR_NONE)
      {
        return BSP_ERROR_MSP_FAILURE;
      }
    }
#endif
    if (MX_I2C1_Init(&hi2c1) != HAL_OK)
    {
      ret = BSP_ERROR_BUS_FAILURE;
    }
  }
  return ret;
}

int32_t BSP_I2C1_DeInit(void)
{
  int32_t ret = BSP_ERROR_BUS_FAILURE;

#if (USE_HAL_I2C_REGISTER_CALLBACKS == 0)
  I2C1_MspDeInit(&hi2c1);
#endif

  if (HAL_I2C_DeInit(&hi2c1) == HAL_OK)
  {
    ret = BSP_ERROR_NONE;
  }

  return ret;
}

int32_t BSP_I2C1_IsReady(uint16_t DevAddr, uint32_t Trials)
{
  int32_t ret;

  if (HAL_I2C_IsDeviceReady(&hi2c1, DevAddr, Trials, TIMEOUT_DURATION) != HAL_OK)
  {
    ret = BSP_ERROR_BUSY;
  }
  else
  {
    ret = BSP_ERROR_NONE;
  }

  return ret;
}

int32_t BSP_I2C1_WriteReg(uint16_t Addr, uint16_t Reg, uint8_t *pData, uint16_t Length)
{
  int32_t ret;

  if (HAL_I2C_Mem_Write(&hi2c1, Addr, (uint16_t)Reg, I2C_MEMADD_SIZE_8BIT, pData, Length, TIMEOUT_DURATION) != HAL_OK)
  {
    if (HAL_I2C_GetError(&hi2c1) == HAL_I2C_ERROR_AF)
    {
      ret = BSP_ERROR_BUS_ACKNOWLEDGE_FAILURE;
    }
    else
    {
      ret =  BSP_ERROR_PERIPH_FAILURE;
    }
  }
  else
  {
    ret = BSP_ERROR_NONE;
  }

  return ret;
}

int32_t BSP_I2C1_ReadReg(uint16_t Addr, uint16_t Reg, uint8_t *pData, uint16_t Length)
{
  int32_t ret;

  if (HAL_I2C_Mem_Read(&hi2c1, Addr, Reg, I2C_MEMADD_SIZE_8BIT, pData, Length, TIMEOUT_DURATION) != HAL_OK)
  {
    if (HAL_I2C_GetError(&hi2c1) == HAL_I2C_ERROR_AF)
    {
      ret = BSP_ERROR_BUS_ACKNOWLEDGE_FAILURE;
    }
    else
    {
      ret = BSP_ERROR_PERIPH_FAILURE;
    }
  }
  else
  {
    ret = BSP_ERROR_NONE;
  }

  return ret;
}

int32_t BSP_I2C1_WriteReg16(uint16_t Addr, uint16_t Reg, uint8_t *pData, uint16_t Length)
{
  int32_t ret;

  if (HAL_I2C_Mem_Write(&hi2c1, Addr, Reg, I2C_MEMADD_SIZE_16BIT, pData, Length, TIMEOUT_DURATION) != HAL_OK)
  {
    if (HAL_I2C_GetError(&hi2c1) == HAL_I2C_ERROR_AF)
    {
      ret = BSP_ERROR_BUS_ACKNOWLEDGE_FAILURE;
    }
    else
    {
      ret = BSP_ERROR_PERIPH_FAILURE;
    }
  }
  else
  {
    ret = BSP_ERROR_NONE;
  }

  return ret;
}

int32_t BSP_I2C1_ReadReg16(uint16_t Addr, uint16_t Reg, uint8_t *pData, uint16_t Length)
{
  int32_t ret;

  if (HAL_I2C_Mem_Read(&hi2c1, Addr, Reg, I2C_MEMADD_SIZE_16BIT, pData, Length, TIMEOUT_DURATION) != HAL_OK)
  {
    if (HAL_I2C_GetError(&hi2c1) == HAL_I2C_ERROR_AF)
    {
      ret = BSP_ERROR_BUS_ACKNOWLEDGE_FAILURE;
    }
    else
    {
      ret = BSP_ERROR_PERIPH_FAILURE;
    }
  }
  else
  {
    ret = BSP_ERROR_NONE;
  }

  return ret;
}

int32_t BSP_I2C1_Send(uint16_t DevAddr, uint8_t *pData, uint16_t Length)
{
  int32_t ret;

  if (HAL_I2C_Master_Transmit(&hi2c1, DevAddr, pData, Length, TIMEOUT_DURATION) != HAL_OK)
  {
    if (HAL_I2C_GetError(&hi2c1) == HAL_I2C_ERROR_AF)
    {
      ret = BSP_ERROR_BUS_ACKNOWLEDGE_FAILURE;
    }
    else
    {
      ret = BSP_ERROR_PERIPH_FAILURE;
    }
  }
  else
  {
    ret = BSP_ERROR_NONE;
  }

  return ret;
}

int32_t BSP_I2C1_Recv(uint16_t DevAddr, uint8_t *pData, uint16_t Length)
{
  int32_t ret;

  if (HAL_I2C_Master_Receive(&hi2c1, DevAddr, pData, Length, TIMEOUT_DURATION) != HAL_OK)
  {
    if (HAL_I2C_GetError(&hi2c1) == HAL_I2C_ERROR_AF)
    {
      ret = BSP_ERROR_BUS_ACKNOWLEDGE_FAILURE;
    }
    else
    {
      ret = BSP_ERROR_PERIPH_FAILURE;
    }
  }
  else
  {
    ret = BSP_ERROR_NONE;
  }

  return ret;
}

int32_t BSP_I2C1_SendRecv(uint16_t DevAddr, uint8_t *pTxdata, uint8_t *pRxdata, uint16_t Length)
{
  int32_t ret;

  if (HAL_I2C_Master_Sequential_Transmit_IT(&hi2c1, DevAddr, pTxdata, Length, I2C_FIRST_FRAME) != HAL_OK)
  {
    ret = BSP_ERROR_PERIPH_FAILURE;
  }
  else if (HAL_I2C_Master_Sequential_Receive_IT(&hi2c1, DevAddr, pRxdata, Length, I2C_LAST_FRAME) != HAL_OK)
  {
    ret = BSP_ERROR_PERIPH_FAILURE;
  }
  else
  {
    ret = BSP_ERROR_NONE;
  }

  return ret;
}

int32_t BSP_GetTick(void)
{
  return (int32_t)HAL_GetTick();
}

__weak HAL_StatusTypeDef MX_I2C1_Init(I2C_HandleTypeDef *hi2c)
{
  HAL_StatusTypeDef ret = HAL_OK;

  hi2c->Instance = I2C1;
  hi2c->Init.Timing = 0x00B1112E;
  hi2c->Init.OwnAddress1 = 0;
  hi2c->Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
  hi2c->Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
  hi2c->Init.OwnAddress2 = 0;
  hi2c->Init.OwnAddress2Masks = I2C_OA2_NOMASK;
  hi2c->Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
  hi2c->Init.NoStretchMode = I2C_NOSTRETCH_DISABLE;

  if (HAL_I2C_Init(hi2c) != HAL_OK)
  {
    ret = HAL_ERROR;
  }
  else if (HAL_I2CEx_ConfigAnalogFilter(hi2c, I2C_ANALOGFILTER_ENABLE) != HAL_OK)
  {
    ret = HAL_ERROR;
  }
  else if (HAL_I2CEx_ConfigDigitalFilter(hi2c, 0) != HAL_OK)
  {
    ret = HAL_ERROR;
  }

  return ret;
}

static void I2C1_MspInit(I2C_HandleTypeDef *hI2c)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  BUS_I2C1_SCL_GPIO_CLK_ENABLE();
  BUS_I2C1_SDA_GPIO_CLK_ENABLE();
  __HAL_RCC_I2C1_CLK_ENABLE();

  GPIO_InitStruct.Pin = BUS_I2C1_SCL_GPIO_PIN;
  GPIO_InitStruct.Mode = GPIO_MODE_AF_OD;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
  GPIO_InitStruct.Alternate = BUS_I2C1_SCL_GPIO_AF;
  HAL_GPIO_Init(BUS_I2C1_SCL_GPIO_PORT, &GPIO_InitStruct);

  GPIO_InitStruct.Pin = BUS_I2C1_SDA_GPIO_PIN;
  GPIO_InitStruct.Alternate = BUS_I2C1_SDA_GPIO_AF;
  HAL_GPIO_Init(BUS_I2C1_SDA_GPIO_PORT, &GPIO_InitStruct);
}

static void I2C1_MspDeInit(I2C_HandleTypeDef *hI2c)
{
  __HAL_RCC_I2C1_CLK_DISABLE();

  HAL_GPIO_DeInit(BUS_I2C1_SCL_GPIO_PORT, BUS_I2C1_SCL_GPIO_PIN);
  HAL_GPIO_DeInit(BUS_I2C1_SDA_GPIO_PORT, BUS_I2C1_SDA_GPIO_PIN);
}

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
