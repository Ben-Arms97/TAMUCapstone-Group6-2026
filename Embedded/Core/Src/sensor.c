#include "sensor.h"
hal_status_t Sensor_Init(ADC_HandleTypeDef* hw){
    hal_status_t status = HAL_ADC_Start(hadc);
    // Additional error checking
    if(status == HAL_ERROR){
        return status;
    }
    status = HAL_ADC_Calibrate(hadc);
    return status;
}

double Read_Sensor(ADC_HandleTypeDef* hadc) {
    // TODO: Implement this function
    return 0;
}
