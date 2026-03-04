#ifndef _SENSOR_H
#define _SENSOR_H

// Includes
#include <math.h>

//struct for calibrated values
typedef struct {
    uint16_t sin_max, sin_min, cos_max, cos_min;
} Calibrated_Values;

typedef struct {
    uint16_t sin, cos;
} Sensor_Values;

// Pin definitions - not sure if this is necessary
#define COS_PIN    GPIO_PIN_2 //COS PIN - PA2
#define COS_PORT   GPIOA
#define SIN_PIN    GPIO_PIN_3 //SIN PIN - PA3
#define SIN_PORT   GPIOA

// Function definitions
Sensor_Values Read_Sensor(ADC_HandleTypeDef* hadc);

float Calculate_Angle(Sensor_Values* s);

#endif
