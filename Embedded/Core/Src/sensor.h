#ifndef _SENSOR_H
#define _SENSOR_H

// Includes
#include <math.h>
#include "main.h"

struct Sensor_Values {
    uint16_t sin, cos;
};

// Pin definitions - not sure if this is necessary
#define COS_PIN    GPIO_PIN_2 //COS PIN - PA2
#define COS_PORT   GPIOA
#define SIN_PIN    GPIO_PIN_3 //SIN PIN - PA3
#define SIN_PORT   GPIOA

// Variables 
uint16_t adc_values[2];

// Function definitions
void adc_dma_init(void)
{
    // 1. Enable clocks
    RCC->IOPENR |= RCC_IOPENR_GPIOAEN;
    RCC->APB2ENR |= RCC_APB2ENR_ADC1EN;
    RCC->AHBENR |= RCC_AHBENR_DMA1EN;

    // 2. Configure PA2, PA3 as analog
    GPIOA->MODER |= (3 << (2 * 2)) | (3 << (3 * 2));
    GPIOA->PUPDR &= ~((3 << (2 * 2)) | (3 << (3 * 2)));

    // 3. Configure DMA (one-shot, not circular)
    DMA1_Channel1->CCR = 0;  // Disable first

    DMA1_Channel1->CPAR = (uint32_t)&ADC1->DR;
    DMA1_Channel1->CMAR = (uint32_t)adc_values;
    DMA1_Channel1->CNDTR = 2;

    DMA1_Channel1->CCR |= 
        DMA_CCR_MINC |       // Memory increment
        DMA_CCR_PSIZE_0 |    // 16-bit peripheral
        DMA_CCR_MSIZE_0;     // 16-bit memory

    DMA1_Channel1->CCR |= DMA_CCR_EN;

    // 4. Make sure ADC is disabled
    if (ADC1->CR & ADC_CR_ADEN) {
        ADC1->CR |= ADC_CR_ADDIS;
        while (ADC1->CR & ADC_CR_ADEN);
    }

    // 5. Calibrate ADC
    ADC1->CR |= ADC_CR_ADCAL;
    while (ADC1->CR & ADC_CR_ADCAL);

    // 6. Configure ADC
    ADC1->CFGR1 = ADC_CFGR1_DMAEN;  // DMA enabled, no continuous mode

    // 7. Sampling time (adjust if needed)
    ADC1->SMPR |= ADC_SMPR_SMP_1;

    // 8. Select channels (PA2 = CH2, PA3 = CH3)
    ADC1->CHSELR = ADC_CHSELR_CHSEL2 | ADC_CHSELR_CHSEL3;

    // 9. Enable ADC
    ADC1->CR |= ADC_CR_ADEN;
    while (!(ADC1->ISR & ADC_ISR_ADRDY));
}

void adc_dma_start(void)
{
    // Reset DMA transfer count (important for re-use)
    DMA1_Channel1->CCR &= ~DMA_CCR_EN;
    DMA1_Channel1->CNDTR = 2;
    DMA1_Channel1->CCR |= DMA_CCR_EN;

    // Start ADC conversion
    ADC1->CR |= ADC_CR_ADSTART;

    // Wait for DMA transfer complete
    while (!(DMA1->ISR & DMA_ISR_TCIF1));
    DMA1->IFCR |= DMA_IFCR_CTCIF1;  // Clear flag
}

#endif
