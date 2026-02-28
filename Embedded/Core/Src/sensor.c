#include "main.h"
#include "sensor.h"

Sensor_Values Read_Sensor(ADC_HandleTypeDef hadc) {
    //ADC result values
    uint16_t adc_values[2];

    HAL_ADC_Start_DMA(&hadc, (uint32_t*)adc_values, 2);
    HAL_ADC_PollForConversion(&hadc, 1);
    HAL_ADC_Stop_DMA(&hadc);

    Sensor_Values s;
    s.sin = adc_values[0];
    s.cos = adc_values[1];
    return &s;
}

float Calculate_Angle(Sensor_Values * s){
    return atan2(s.sin/s.cos);
}
