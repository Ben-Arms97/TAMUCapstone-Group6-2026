#ifndef __B_L072Z_LRWAN1_BUS_H
#define __B_L072Z_LRWAN1_BUS_H

#ifdef __cplusplus
extern "C" {
#endif

#include "stm32l0xx_nucleo_conf.h"
#include "b_l072z_lrwan1_errno.h"
#include <stdint.h>

#ifndef USE_HAL_SPI_REGISTER_CALLBACKS
#define USE_HAL_SPI_REGISTER_CALLBACKS 0U
#endif

#ifndef USE_HAL_I2C_REGISTER_CALLBACKS
#define USE_HAL_I2C_REGISTER_CALLBACKS 0U
#endif

/* SPI target speed for SX1276 */
#define RADIO_SPI_BAUDRATE                  1000000U

/* Internal SX1276 SPI bus on CMWX1ZZABZ-078 / STM32L082
 * SPI1:
 *   PB3  = SCK
 *   PA6  = MISO
 *   PA7  = MOSI
 */
#define BUS_SPI1_SCK_GPIO_PIN            GPIO_PIN_3
#define BUS_SPI1_SCK_GPIO_PORT           GPIOB
#define BUS_SPI1_SCK_GPIO_AF             GPIO_AF0_SPI1
#define BUS_SPI1_SCK_GPIO_CLK_ENABLE()   __HAL_RCC_GPIOB_CLK_ENABLE()

#define BUS_SPI1_MISO_GPIO_PIN           GPIO_PIN_6
#define BUS_SPI1_MISO_GPIO_PORT          GPIOA
#define BUS_SPI1_MISO_GPIO_AF            GPIO_AF0_SPI1
#define BUS_SPI1_MISO_GPIO_CLK_ENABLE()  __HAL_RCC_GPIOA_CLK_ENABLE()

#define BUS_SPI1_MOSI_GPIO_PIN           GPIO_PIN_7
#define BUS_SPI1_MOSI_GPIO_PORT          GPIOA
#define BUS_SPI1_MOSI_GPIO_AF            GPIO_AF0_SPI1
#define BUS_SPI1_MOSI_GPIO_CLK_ENABLE()  __HAL_RCC_GPIOA_CLK_ENABLE()

#if (USE_HAL_SPI_REGISTER_CALLBACKS == 1)
typedef struct
{
  pSPI_CallbackTypeDef  pMspSpiInitCb;
  pSPI_CallbackTypeDef  pMspSpiDeInitCb;
} BSP_SPI_Cb_t;
#endif

/* SPI */
int32_t BSP_SPI1_Init(void);
int32_t BSP_SPI1_DeInit(void);
int32_t BSP_SPI1_Send(uint8_t *pData, uint16_t len);
int32_t BSP_SPI1_Recv(uint8_t *pData, uint16_t len);
int32_t BSP_SPI1_SendRecv(uint8_t *pTxData, uint8_t *pRxData, uint16_t len);

int32_t BSP_GetTick(void);

#if (USE_HAL_SPI_REGISTER_CALLBACKS == 1)
int32_t BSP_SPI1_RegisterDefaultMspCallbacks(void);
int32_t BSP_SPI1_RegisterMspCallbacks(BSP_SPI_Cb_t *Callbacks);
#endif

/* I2C1 */
#define BUS_I2C1_INSTANCE                 I2C1
#define BUS_I2C1_SCL_GPIO_PORT            GPIOB
#define BUS_I2C1_SCL_GPIO_AF              GPIO_AF4_I2C1
#define BUS_I2C1_SCL_GPIO_CLK_ENABLE()    __HAL_RCC_GPIOB_CLK_ENABLE()
#define BUS_I2C1_SCL_GPIO_CLK_DISABLE()   __HAL_RCC_GPIOB_CLK_DISABLE()
#define BUS_I2C1_SCL_GPIO_PIN             GPIO_PIN_8

#define BUS_I2C1_SDA_GPIO_PORT            GPIOB
#define BUS_I2C1_SDA_GPIO_AF              GPIO_AF4_I2C1
#define BUS_I2C1_SDA_GPIO_CLK_ENABLE()    __HAL_RCC_GPIOB_CLK_ENABLE()
#define BUS_I2C1_SDA_GPIO_CLK_DISABLE()   __HAL_RCC_GPIOB_CLK_DISABLE()
#define BUS_I2C1_SDA_GPIO_PIN             GPIO_PIN_9

#ifndef BUS_I2C1_POLL_TIMEOUT
#define BUS_I2C1_POLL_TIMEOUT             0x1000U
#endif

#ifndef BUS_I2C1_FREQUENCY
#define BUS_I2C1_FREQUENCY                100000U
#endif

#ifdef __cplusplus
}
#endif

#endif /* __B_L072Z_LRWAN1_BUS_H */
