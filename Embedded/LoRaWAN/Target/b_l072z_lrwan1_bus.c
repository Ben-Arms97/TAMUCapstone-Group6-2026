/**
  ******************************************************************************
  * @file           : b_l072z_lrwan1_bus.c
  * @brief          : source file for the BSP BUS IO driver
  ******************************************************************************
  */

#include "b_l072z_lrwan1_bus.h"
#include "b_l072z_lrwan1_errno.h"
#include "stm32l0xx_hal.h"

#define TIMEOUT_DURATION 1000U

__weak HAL_StatusTypeDef MX_SPI1_Init(SPI_HandleTypeDef *hspi);

/* Private variables ---------------------------------------------------------*/
SPI_HandleTypeDef hspi1;

#if (USE_HAL_SPI_REGISTER_CALLBACKS == 1)
static uint32_t IsSPI1MspCbValid = 0;
#endif

/* Private function prototypes -----------------------------------------------*/
static void SPI1_MspInit(SPI_HandleTypeDef *spiHandle);
static void SPI1_MspDeInit(SPI_HandleTypeDef *spiHandle);
static uint32_t SPI_GetPrescaler(uint32_t clock_src_hz, uint32_t baudrate_hz);

/* Exported functions --------------------------------------------------------*/

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

  hspi1.Instance = SPI1;

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
  * @brief  Write Data through SPI BUS.
  * @param  pData Pointer to data buffer
  * @param  len   Length of data in bytes
  * @retval BSP status or number of bytes sent
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
  * @brief  Receive Data from SPI BUS.
  * @param  pData Pointer to data buffer
  * @param  len   Length of data in bytes
  * @retval BSP status or number of bytes received
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
  * @brief  Send and receive data over SPI BUS (full duplex).
  * @param  pTxData Pointer to TX data
  * @param  pRxData Pointer to RX data
  * @param  len     Length of data in bytes
  * @retval BSP status or number of bytes transferred
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

#if (USE_HAL_SPI_REGISTER_CALLBACKS == 1)
/**
  * @brief  Register default BSP SPI1 BUS MSP callbacks.
  * @retval BSP status
  */
int32_t BSP_SPI1_RegisterDefaultMspCallbacks(void)
{
  __HAL_SPI_RESET_HANDLE_STATE(&hspi1);

  if (HAL_SPI_RegisterCallback(&hspi1, HAL_SPI_MSPINIT_CB_ID, SPI1_MspInit) != HAL_OK)
  {
    return BSP_ERROR_PERIPH_FAILURE;
  }

  if (HAL_SPI_RegisterCallback(&hspi1, HAL_SPI_MSPDEINIT_CB_ID, SPI1_MspDeInit) != HAL_OK)
  {
    return BSP_ERROR_PERIPH_FAILURE;
  }

  IsSPI1MspCbValid = 1U;
  return BSP_ERROR_NONE;
}

/**
  * @brief  Register SPI1 MSP callbacks.
  * @param  Callbacks pointer to callback structure
  * @retval BSP status
  */
int32_t BSP_SPI1_RegisterMspCallbacks(BSP_SPI_Cb_t *Callbacks)
{
  __HAL_SPI_RESET_HANDLE_STATE(&hspi1);

  if (HAL_SPI_RegisterCallback(&hspi1, HAL_SPI_MSPINIT_CB_ID, Callbacks->pMspSpiInitCb) != HAL_OK)
  {
    return BSP_ERROR_PERIPH_FAILURE;
  }

  if (HAL_SPI_RegisterCallback(&hspi1, HAL_SPI_MSPDEINIT_CB_ID, Callbacks->pMspSpiDeInitCb) != HAL_OK)
  {
    return BSP_ERROR_PERIPH_FAILURE;
  }

  IsSPI1MspCbValid = 1U;
  return BSP_ERROR_NONE;
}
#endif /* USE_HAL_SPI_REGISTER_CALLBACKS */

/**
  * @brief  Return system tick in ms.
  * @retval Tick value
  */
int32_t BSP_GetTick(void)
{
  return (int32_t)HAL_GetTick();
}

/**
  * @brief  SPI1 init function.
  * @param  hspi SPI handle pointer
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
  * @brief  SPI1 MSP Init.
  * @param  spiHandle SPI handle pointer
  * @retval None
  */
static void SPI1_MspInit(SPI_HandleTypeDef *spiHandle)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  (void)spiHandle;

  /* Enable GPIO clocks */
  BUS_SPI1_SCK_GPIO_CLK_ENABLE();
  BUS_SPI1_MISO_GPIO_CLK_ENABLE();
  BUS_SPI1_MOSI_GPIO_CLK_ENABLE();

  /* Enable SPI1 peripheral clock */
  __HAL_RCC_SPI1_CLK_ENABLE();

  /* SPI1 GPIO Configuration
   * PB3  ------> SPI1_SCK
   * PA6  ------> SPI1_MISO
   * PA7  ------> SPI1_MOSI
   */
  GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;

  GPIO_InitStruct.Alternate = BUS_SPI1_SCK_GPIO_AF;
  GPIO_InitStruct.Pin = BUS_SPI1_SCK_GPIO_PIN;
  HAL_GPIO_Init(BUS_SPI1_SCK_GPIO_PORT, &GPIO_InitStruct);

  GPIO_InitStruct.Alternate = BUS_SPI1_MISO_GPIO_AF;
  GPIO_InitStruct.Pin = BUS_SPI1_MISO_GPIO_PIN;
  HAL_GPIO_Init(BUS_SPI1_MISO_GPIO_PORT, &GPIO_InitStruct);

  GPIO_InitStruct.Alternate = BUS_SPI1_MOSI_GPIO_AF;
  GPIO_InitStruct.Pin = BUS_SPI1_MOSI_GPIO_PIN;
  HAL_GPIO_Init(BUS_SPI1_MOSI_GPIO_PORT, &GPIO_InitStruct);
}

/**
  * @brief  SPI1 MSP DeInit.
  * @param  spiHandle SPI handle pointer
  * @retval None
  */
static void SPI1_MspDeInit(SPI_HandleTypeDef *spiHandle)
{
  (void)spiHandle;

  __HAL_RCC_SPI1_CLK_DISABLE();

  HAL_GPIO_DeInit(BUS_SPI1_SCK_GPIO_PORT,  BUS_SPI1_SCK_GPIO_PIN);
  HAL_GPIO_DeInit(BUS_SPI1_MISO_GPIO_PORT, BUS_SPI1_MISO_GPIO_PIN);
  HAL_GPIO_DeInit(BUS_SPI1_MOSI_GPIO_PORT, BUS_SPI1_MOSI_GPIO_PIN);
}

/**
  * @brief  Compute SPI prescaler from source clock and target baudrate.
  * @param  clock_src_hz Source clock frequency in Hz
  * @param  baudrate_hz  Desired SPI baudrate in Hz
  * @retval SPI prescaler constant
  */
static uint32_t SPI_GetPrescaler(uint32_t clock_src_hz, uint32_t baudrate_hz)
{
  uint32_t divisor = 0U;
  uint32_t spi_clk = clock_src_hz;
  uint32_t presc = SPI_BAUDRATEPRESCALER_2;

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

  while ((spi_clk > baudrate_hz) && (divisor < 8U))
  {
    presc = baudrate[divisor];
    divisor++;
    spi_clk >>= 1;
  }

  return presc;
}












