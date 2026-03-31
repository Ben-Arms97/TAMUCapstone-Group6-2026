/**
  ******************************************************************************
  * @file              : cmwx1zzabz_0xx_conf.h
  * @brief             : Configuration for Murata CMWX1ZZABZ-078 internal SX1276
  ******************************************************************************
  */

#ifndef __CMWX1ZZABZ_0XX_CONF_H__
#define __CMWX1ZZABZ_0XX_CONF_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "platform.h"

/* Defines ---------------------------------------------------------------*/
#define RADIO_DIO_0_IT_PRIO                        0
#define RADIO_DIO_1_IT_PRIO                        0
#define RADIO_DIO_2_IT_PRIO                        0
#define RADIO_DIO_3_IT_PRIO                        0

/* SPI functions redefinition
 *
 * IMPORTANT:
 * The internal SX1276 in the CMWX1ZZABZ-078 is connected to the STM32L082
 * through the fixed internal radio SPI wiring. Do not remap this to a custom
 * external SPI2 bus.
 *
 * Expected radio bus:
 *   NSS  -> PA15   (software GPIO)
 *   SCK  -> PB3
 *   MISO -> PA6
 *   MOSI -> PA7
 *
 * Keep these mapped to your BSP SPI1 implementation.
 */
#define RADIO_SPI_Init                   BSP_SPI1_Init
#define RADIO_SPI_DeInit                 BSP_SPI1_DeInit
#define RADIO_SPI_SendRecv               BSP_SPI1_SendRecv

#define RADIO_SPI_SCK_GPIO_PIN           GPIO_PIN_3
#define RADIO_SPI_SCK_GPIO_PORT          GPIOB
#define RADIO_SPI_SCK_GPIO_AF            GPIO_AF0_SPI1
#define RADIO_SPI_SCK_GPIO_CLK_ENABLE()  __HAL_RCC_GPIOB_CLK_ENABLE()

#define RADIO_SPI_MISO_GPIO_PIN          GPIO_PIN_6
#define RADIO_SPI_MISO_GPIO_PORT         GPIOA
#define RADIO_SPI_MISO_GPIO_AF           GPIO_AF0_SPI1
#define RADIO_SPI_MISO_GPIO_CLK_ENABLE() __HAL_RCC_GPIOA_CLK_ENABLE()

#define RADIO_SPI_MOSI_GPIO_PIN          GPIO_PIN_7
#define RADIO_SPI_MOSI_GPIO_PORT         GPIOA
#define RADIO_SPI_MOSI_GPIO_AF           GPIO_AF0_SPI1
#define RADIO_SPI_MOSI_GPIO_CLK_ENABLE() __HAL_RCC_GPIOA_CLK_ENABLE()

/* NSS (chip select) */
#define RADIO_NSS_CLK_ENABLE()           __HAL_RCC_GPIOA_CLK_ENABLE()
#define RADIO_NSS_PORT                   GPIOA
#define RADIO_NSS_PIN                    GPIO_PIN_15

/* Radio reset */
#define RADIO_RESET_CLK_ENABLE()         __HAL_RCC_GPIOC_CLK_ENABLE()
#define RADIO_RESET_PORT                 GPIOC
#define RADIO_RESET_PIN                  GPIO_PIN_0

/* LORA DIO pin mapping */
#define RADIO_DIOn                               4U

#define RADIO_DIO_0_PORT                  GPIOB
#define RADIO_DIO_0_PIN                   GPIO_PIN_4
#define RADIO_DIO_0_GPIO_CLK_ENABLE()     __HAL_RCC_GPIOB_CLK_ENABLE()
#define RADIO_DIO_0_EXTI_LINE             EXTI_LINE_4
#define RADIO_DIO_0_IRQn                  EXTI4_15_IRQn
#define H_EXTI_4                          hRADIO_DIO_exti[0]

#define RADIO_DIO_1_PORT                  GPIOB
#define RADIO_DIO_1_PIN                   GPIO_PIN_1
#define RADIO_DIO_1_GPIO_CLK_ENABLE()     __HAL_RCC_GPIOB_CLK_ENABLE()
#define RADIO_DIO_1_EXTI_LINE             EXTI_LINE_1
#define RADIO_DIO_1_IRQn                  EXTI0_1_IRQn
#define H_EXTI_1                          hRADIO_DIO_exti[1]

#define RADIO_DIO_2_PORT                  GPIOB
#define RADIO_DIO_2_PIN                   GPIO_PIN_0
#define RADIO_DIO_2_GPIO_CLK_ENABLE()     __HAL_RCC_GPIOB_CLK_ENABLE()
#define RADIO_DIO_2_EXTI_LINE             EXTI_LINE_0
#define RADIO_DIO_2_IRQn                  EXTI0_1_IRQn
#define H_EXTI_0                          hRADIO_DIO_exti[2]

#define RADIO_DIO_3_PORT                  GPIOC
#define RADIO_DIO_3_PIN                   GPIO_PIN_13
#define RADIO_DIO_3_GPIO_CLK_ENABLE()     __HAL_RCC_GPIOC_CLK_ENABLE()
#define RADIO_DIO_3_EXTI_LINE             EXTI_LINE_13
#define RADIO_DIO_3_IRQn                  EXTI4_15_IRQn
#define H_EXTI_13                         hRADIO_DIO_exti[3]

/* TCXO control */
#define RADIO_TCXO_VCC_CLK_ENABLE()       __HAL_RCC_GPIOA_CLK_ENABLE()
#define RADIO_TCXO_VCC_PORT               GPIOA
#define RADIO_TCXO_VCC_PIN                GPIO_PIN_12

/* RF switch control */
#define RADIO_ANT_SWITCH_CLK_ENABLE_RX()       __HAL_RCC_GPIOA_CLK_ENABLE()
#define RADIO_ANT_SWITCH_PORT_RX               GPIOA
#define RADIO_ANT_SWITCH_PIN_RX                GPIO_PIN_1

#define RADIO_ANT_SWITCH_CLK_ENABLE_TX_BOOST() __HAL_RCC_GPIOC_CLK_ENABLE()
#define RADIO_ANT_SWITCH_PORT_TX_BOOST         GPIOC
#define RADIO_ANT_SWITCH_PIN_TX_BOOST          GPIO_PIN_1

#define RADIO_ANT_SWITCH_CLK_ENABLE_TX_RFO()   __HAL_RCC_GPIOC_CLK_ENABLE()
#define RADIO_ANT_SWITCH_PORT_TX_RFO           GPIOC
#define RADIO_ANT_SWITCH_PIN_TX_RFO            GPIO_PIN_2

#include "radio_conf.h"

#ifdef __cplusplus
}
#endif

#endif /* __CMWX1ZZABZ_0XX_CONF_H__ */
