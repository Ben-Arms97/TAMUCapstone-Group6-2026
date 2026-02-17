#ifndef _SENSOR_H
#define _SENSOR_H

// Includes
#include <math.h>

// Pin definitions - not sure if this is necessary
#define COS_PIN    GPIO_PIN_2 //COS PIN - PA2
#define COS_PORT   GPIOA
#define SIN_PIN    GPIO_PIN_3 //SIN PIN - PA3
#define SIN_PORT   GPIOA

// Function definitions
double Read_Sensor(ADC_HandleTypeDef* hadc);

#endif