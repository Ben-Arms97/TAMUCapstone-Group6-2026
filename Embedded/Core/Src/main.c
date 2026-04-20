/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
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
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "app_lorawan.h"
#include "lora_app.h"
#include "adc.h"
#include "usart.h"
#include "sys_app.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "cmwx1zzabz_0xx.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
//static void uart_print(const char *s);

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
//ADC_HandleTypeDef hadc;

//I2C_HandleTypeDef hi2c1;

UART_HandleTypeDef huart1;

/* USER CODE BEGIN PV */
uint32_t adc_vals_prev [2];
uint32_t open_angle, closed_angle;
Angle_Return angle_reading;
CALIBRATION_STAGE calibration_stage;
ROTATION_DIRECTION rot_dir;

int lower_bound_angle = 0;
int upper_bound_angle = 90;

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
void Cap_Sense_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

static void uart_print(const char *s)
{
  HAL_UART_Transmit(&huart1, (uint8_t *)s, (uint16_t)strlen(s), HAL_MAX_DELAY);
}
/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{

  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */
  RTC_IF_Init();
  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */
  MX_LoRaWAN_Init();



  /* Initialize all configured peripherals */
  MX_ADC_Init();
  MX_USART1_UART_Init();
  MX_ADC_Init();
  MX_USART1_UART_Init();
  BSP_I2C1_Init();
  Cap_Sense_Init();
  Haptic_Init();
  /* USER CODE BEGIN 2 */
  (void)HAL_ADC_Start(&hadc);

  //initialize previous values
  adc_vals_prev[0] = 0;
  adc_vals_prev[1] = 0;
  calibration_stage = CALIB_OPEN;

  APP_LOG(TS_ON, VLEVEL_L, "Attempting to join LoRaWAN...\r\n");

  while(join_flag == 0){
	  MX_LoRaWAN_Process();
  }
  /* USER CODE END 2 */


  APP_LOG(TS_ON, VLEVEL_L, "Awaiting Calibration\r\n");
  Calibrate_Function();

  //int angle = angle_reading.angle_val;

  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
	MX_LoRaWAN_Process();

  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};
  RCC_PeriphCLKInitTypeDef PeriphClkInit = {0};

  /** Configure the main internal regulator output voltage
  */
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI|RCC_OSCILLATORTYPE_MSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.MSIState = RCC_MSI_ON;
  RCC_OscInitStruct.MSICalibrationValue = 0;
  RCC_OscInitStruct.MSIClockRange = RCC_MSIRANGE_5;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_MSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
  PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_USART1|RCC_PERIPHCLK_I2C1;
  PeriphClkInit.Usart1ClockSelection = RCC_USART1CLKSOURCE_PCLK2;
  if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */


void Cap_Sense_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStruct = {0};

	GPIO_InitStruct.Pin = CAP_SENSE_PIN;
	GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
	GPIO_InitStruct.Pull = GPIO_PULLUP;

	HAL_GPIO_Init(CAP_SENSE_PORT, &GPIO_InitStruct);
}

void Haptic_Write(uint8_t reg, uint8_t val)
{
    HAL_I2C_Mem_Write(&hi2c1, HAPTIC_ADDR, reg, 1, &val, 1, HAL_MAX_DELAY);
}

uint8_t Haptic_Read(uint8_t reg)
{
	uint8_t temp;
    HAL_I2C_Mem_Read(&hi2c1, HAPTIC_ADDR, reg, 1, &temp, 1, HAL_MAX_DELAY);
    return temp;
}

void Haptic_Init(){
	//
	uint8_t rev = Haptic_Read(0x00);

	// Write the full-scale of unsigned haptic waveform
	Haptic_Write(0x0C, 1.8f / (23.4e-3f));

	// Write the absolute actuator maximum voltage rating
	Haptic_Write(0x0D, 2.616f / (23.4e-3f));

	// Write the actuator max current rating
	float currMax = 90.0f; // mA
	uint8_t scaledCurrMax = (currMax - 28.6f) / 7.2f;
	Haptic_Write(0x0E, scaledCurrMax);

	// Write the value for translating actuator impedance to output voltage drive level
	float impedance = 40.0f; // Ohms
	uint16_t v2iFactor = (impedance * (scaledCurrMax + 4)) / 1.6104f;
	uint8_t v2iFactor_h = (v2iFactor >> 8) & 0xFF;
	uint8_t v2iFactor_l = v2iFactor & 0xFF;
	Haptic_Write(0x0F, v2iFactor_h);
	Haptic_Write(0x10, v2iFactor_l);

	// Specify the LRA drive frequency
	float lraFreq = 235.0f; // Hz
	uint16_t lraPeriod = 1 / (lraFreq * (1333.32e-9f));
	uint8_t lraPeriod_h = (lraPeriod >> 7) & 0xFF;
	uint8_t lraPeriod_l = lraPeriod & 0x7F;
	Haptic_Write(0x0A, lraPeriod_h);
	Haptic_Write(0x0B, lraPeriod_l);

	// Set to DRO mode (12C)
	Haptic_Write(0x22, 0x01);

	// Set UVLO threshold to 2.7 V
	Haptic_Write(0x5F, 0);

	// Clear all flags
	Haptic_Write(0x03, 0xFF);
}

void Vibrate(uint8_t val)
{
	Haptic_Write(0x23, val);
}


void Calibrate_Function(){


	//2 quick buzzes
	Vibrate(50);
	HAL_Delay(300);
	Vibrate(0);
	HAL_Delay(300);
	Vibrate(50);
	HAL_Delay(300);
	Vibrate(0);

	GPIO_PinState not_touched = HAL_GPIO_ReadPin(CAP_SENSE_PORT, CAP_SENSE_PIN);

	/*Bad way of getting an occasional vibration... Bruh, this works surprisingly well...
		I added a recurring vibration because no one wants to be standing around for
		who knows how long for the device to connect... This lets them know it's ready
		when they come check on it.
	*/
	int wait_counter = 0;
	while(not_touched){ //wait for touch
		not_touched = HAL_GPIO_ReadPin(CAP_SENSE_PORT, CAP_SENSE_PIN);
		wait_counter += 1;
		if(wait_counter == 100000){
			//2 quick buzzes
			Vibrate(50);
			HAL_Delay(300);
			Vibrate(0);
			HAL_Delay(300);
			Vibrate(50);
			HAL_Delay(300);
			Vibrate(0);

			wait_counter = 0;
		}
	}
	Read_Angle_Sensor();
	Vibrate(50);
	HAL_Delay(500);
	Vibrate(0);
	HAL_Delay(5000);

	calibration_stage = CALIB_CLOSED;
	not_touched = HAL_GPIO_ReadPin(CAP_SENSE_PORT, CAP_SENSE_PIN);
	while(not_touched){ //wait for touch
	  not_touched = HAL_GPIO_ReadPin(CAP_SENSE_PORT, CAP_SENSE_PIN);
	}
	Read_Angle_Sensor();

	Vibrate(50);
	HAL_Delay(500);
	Vibrate(0);

	HAL_Delay(1000);

	Vibrate(50);
	HAL_Delay(1000);
	Vibrate(0);
	HAL_Delay(500);
	Vibrate(50);
	HAL_Delay(1000);
	Vibrate(0);


	calibration_stage = CALIB_DONE;
}


uint32_t read_adc_channel(uint32_t channel)
{
	// Making sure channel select works as intended
    HAL_ADC_Stop(&hadc);

    // Stop reading from channel
    ADC1->CHSELR = 0;

    // Select next channel
    if (channel == ADC_CHANNEL_2)
        ADC1->CHSELR |= ADC_CHSELR_CHSEL2;
    else if (channel == ADC_CHANNEL_3)
        ADC1->CHSELR |= ADC_CHSELR_CHSEL3;

    // Read from current channel
    HAL_ADC_Start(&hadc);
    HAL_ADC_PollForConversion(&hadc, HAL_MAX_DELAY);

    // Get value form ADC
    uint32_t val = HAL_ADC_GetValue(&hadc);

    // Stop reading from ADC
    HAL_ADC_Stop(&hadc);

    return val;
}

void Read_Angle_Sensor(){
	uint16_t adc_values[2];

    // Channel 2
	adc_values[0] = (uint32_t)read_adc_channel(ADC_CHANNEL_2);
	// Channel 3
	adc_values[1] = (uint32_t)read_adc_channel(ADC_CHANNEL_3);

	char msg[64];
	snprintf(msg, sizeof(msg), "adc0=%d adc1=%d\r\n", adc_values[0], adc_values[1]);
	APP_LOG(TS_ON, VLEVEL_L, msg);

    // If values don't pass thresholds and not in calibration mode
    if(adc_values[0] < adc_vals_prev[0] + 50 && adc_values[0] > adc_vals_prev[0] - 50 && adc_values[1] < adc_vals_prev[1] + 50 && adc_values[1] > adc_vals_prev[1] - 50 && calibration_stage == 0){
    	//angle_reading.angle_val = 0;
        angle_reading.changed = 0;
        return;
    }

	// Angle calculation - normalize ADC values as sensor readings are offset by VDD/2
    // This corresponds to ADC values being half of ADC max (2048) higher than we want
	int sin = adc_values[0] - 2048;
	int cos = adc_values[1] - 2048;

    // Convert to degrees and make positive
	float angle = (atan2f(sin, cos) * 180/M_PI) + 180;

    // If not in calibration stage, send normalized value to server
	if(calibration_stage == CALIB_DONE){
      if(rot_dir == CW){
    	angle = ((angle - closed_angle)/(open_angle-closed_angle)) * 90;
    	angle_reading.angle_val = angle;
        //angle_reading.angle_val =  angle - closed_angle;
      }
      else if(rot_dir == CCW){
    	angle = ((closed_angle - angle)/(closed_angle-open_angle)) * 90;
    	angle_reading.angle_val = angle;
        //angle_reading.angle_val = -1 * (angle - closed_angle);
      }
      else if(rot_dir == CW_OVF){
        if(angle < 180){
          angle += 360;
        }
    	angle = ((angle - closed_angle)/((open_angle + 360)-closed_angle)) * 90;;
        angle_reading.angle_val = angle;
        //angle_reading.angle_val = angle - closed_angle;
      }
      else if(rot_dir == CCW_OVF){
        if(angle > 180){
          angle -= 360;
        }
        angle = ((closed_angle - angle)/(closed_angle - (open_angle - 360))) * 90;
        angle_reading.angle_val = angle;
        //angle_reading.angle_val = -1 * (angle - closed_angle);
      }
	  angle_reading.changed = 1;


      adc_vals_prev[0] = adc_values[0];
	  adc_vals_prev[1] = adc_values[1];
	  snprintf(msg, sizeof(msg), "angle=%d\r\n", angle_reading.angle_val);
	}
    // If in calibration, take open and closed values
	else if(calibration_stage == CALIB_OPEN){
	  open_angle = angle;
	}
	else if(calibration_stage == CALIB_CLOSED){
	  closed_angle = angle;

      if(closed_angle < open_angle){
        if(open_angle - closed_angle > 180){ // CCW overflow
            rot_dir = CCW_OVF;
        }
        else {
          rot_dir = CW;
        }
      } else{
        if(closed_angle - open_angle > 180){ // CW overflow
          rot_dir = CW_OVF;
        }
        else{
          rot_dir = CCW;
        }
      }
	}
	APP_LOG(TS_ON, VLEVEL_L, msg);

	return;
}


/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}
#ifdef USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
