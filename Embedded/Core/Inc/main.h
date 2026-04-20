/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2026 STMicroelectronics.
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
#include "stm32l0xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */
typedef struct {
    int angle_val;
    uint8_t changed;
} Angle_Return;
/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */
//Haptic Feedback - DA7280
#define HAPTIC_ADDR    		(0x4A << 1)

//Magnetometer - LIS2MDL
#define MAGNETOMETER_ADDR 	(0x1E << 1)
#define CFG_REG_A           0x60
#define CFG_REG_B           0x61
#define CFG_REG_C           0x62
#define INT_CRTL_REG        0x63
#define STATUS_REG          0x67
#define OUTX_L              0x68

//Capacitive Sensor
#define CAP_SENSE_PIN       GPIO_PIN_2
#define CAP_SENSE_PORT      GPIOB

#define M_PI 				3.14159265358979323846

//Calibration stage enum
typedef enum {
	CALIB_DONE,
	CALIB_OPEN,
	CALIB_CLOSED
} CALIBRATION_STAGE;

//Rotation direction enum - direction rotated during calibration
typedef enum {
	CW,             // Clockwise - Open > Closed
	CCW,            // Counter clockwise - Closed > Open
	CW_OVF,         // Clockwise where one val overflows (wraps around 360)
    CCW_OVF         // Counter clockwise where one val overflows
} ROTATION_DIRECTION;
/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */
void Read_Angle_Sensor(void);

void Vibrate(uint8_t val);

void Calibrate_Function();

void Haptic_Init();

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/

/* USER CODE BEGIN Private defines */
extern Angle_Return angle_reading;
/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
