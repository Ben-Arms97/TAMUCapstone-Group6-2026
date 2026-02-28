################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/adc.c \
../Core/Src/adc_if.c \
../Core/Src/dma.c \
../Core/Src/main.c \
../Core/Src/rtc.c \
../Core/Src/rtc_if.c \
../Core/Src/sensor.c \
../Core/Src/stm32_lpm_if.c \
../Core/Src/stm32l0xx_hal_msp.c \
../Core/Src/stm32l0xx_it.c \
../Core/Src/sys_app.c \
../Core/Src/sys_debug.c \
../Core/Src/sys_sensors.c \
../Core/Src/syscalls.c \
../Core/Src/sysmem.c \
../Core/Src/system_stm32l0xx.c \
../Core/Src/usart.c \
../Core/Src/usart_if.c 

OBJS += \
./Core/Src/adc.o \
./Core/Src/adc_if.o \
./Core/Src/dma.o \
./Core/Src/main.o \
./Core/Src/rtc.o \
./Core/Src/rtc_if.o \
./Core/Src/sensor.o \
./Core/Src/stm32_lpm_if.o \
./Core/Src/stm32l0xx_hal_msp.o \
./Core/Src/stm32l0xx_it.o \
./Core/Src/sys_app.o \
./Core/Src/sys_debug.o \
./Core/Src/sys_sensors.o \
./Core/Src/syscalls.o \
./Core/Src/sysmem.o \
./Core/Src/system_stm32l0xx.o \
./Core/Src/usart.o \
./Core/Src/usart_if.o 

C_DEPS += \
./Core/Src/adc.d \
./Core/Src/adc_if.d \
./Core/Src/dma.d \
./Core/Src/main.d \
./Core/Src/rtc.d \
./Core/Src/rtc_if.d \
./Core/Src/sensor.d \
./Core/Src/stm32_lpm_if.d \
./Core/Src/stm32l0xx_hal_msp.d \
./Core/Src/stm32l0xx_it.d \
./Core/Src/sys_app.d \
./Core/Src/sys_debug.d \
./Core/Src/sys_sensors.d \
./Core/Src/syscalls.d \
./Core/Src/sysmem.d \
./Core/Src/system_stm32l0xx.d \
./Core/Src/usart.d \
./Core/Src/usart_if.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/%.o Core/Src/%.su Core/Src/%.cyclo: ../Core/Src/%.c Core/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DDEBUG -DCMWX1ZZABZ0XX -DUSE_HAL_DRIVER -DSTM32L082xx -c -I../Core/Inc -I../Middlewares/SubGHz_Phy/ -I../Middlewares/LoRaWAN/Mac/Region -I../Drivers/BSP/CMWX1ZZABZ_0xx/ -I../Drivers/BSP/B-L072Z-LRWAN1 -I../Middlewares/LoRaWAN/Mac -I../Middlewares/LoRaWAN/Crypto -I../Middlewares/LoRaWAN/LmHandler -I../Middlewares/LoRaWAN/LmHandler/Packages -I../Middlewares/LoRaWAN/Utilities -I../LoRaWAN/App -I../LoRaWAN/Target -I../Drivers/STM32L0xx_HAL_Driver/Inc -I../Drivers/STM32L0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L0xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Core-2f-Src

clean-Core-2f-Src:
	-$(RM) ./Core/Src/adc.cyclo ./Core/Src/adc.d ./Core/Src/adc.o ./Core/Src/adc.su ./Core/Src/adc_if.cyclo ./Core/Src/adc_if.d ./Core/Src/adc_if.o ./Core/Src/adc_if.su ./Core/Src/dma.cyclo ./Core/Src/dma.d ./Core/Src/dma.o ./Core/Src/dma.su ./Core/Src/main.cyclo ./Core/Src/main.d ./Core/Src/main.o ./Core/Src/main.su ./Core/Src/rtc.cyclo ./Core/Src/rtc.d ./Core/Src/rtc.o ./Core/Src/rtc.su ./Core/Src/rtc_if.cyclo ./Core/Src/rtc_if.d ./Core/Src/rtc_if.o ./Core/Src/rtc_if.su ./Core/Src/sensor.cyclo ./Core/Src/sensor.d ./Core/Src/sensor.o ./Core/Src/sensor.su ./Core/Src/stm32_lpm_if.cyclo ./Core/Src/stm32_lpm_if.d ./Core/Src/stm32_lpm_if.o ./Core/Src/stm32_lpm_if.su ./Core/Src/stm32l0xx_hal_msp.cyclo ./Core/Src/stm32l0xx_hal_msp.d ./Core/Src/stm32l0xx_hal_msp.o ./Core/Src/stm32l0xx_hal_msp.su ./Core/Src/stm32l0xx_it.cyclo ./Core/Src/stm32l0xx_it.d ./Core/Src/stm32l0xx_it.o ./Core/Src/stm32l0xx_it.su ./Core/Src/sys_app.cyclo ./Core/Src/sys_app.d ./Core/Src/sys_app.o ./Core/Src/sys_app.su ./Core/Src/sys_debug.cyclo ./Core/Src/sys_debug.d ./Core/Src/sys_debug.o ./Core/Src/sys_debug.su ./Core/Src/sys_sensors.cyclo ./Core/Src/sys_sensors.d ./Core/Src/sys_sensors.o ./Core/Src/sys_sensors.su ./Core/Src/syscalls.cyclo ./Core/Src/syscalls.d ./Core/Src/syscalls.o ./Core/Src/syscalls.su ./Core/Src/sysmem.cyclo ./Core/Src/sysmem.d ./Core/Src/sysmem.o ./Core/Src/sysmem.su ./Core/Src/system_stm32l0xx.cyclo ./Core/Src/system_stm32l0xx.d ./Core/Src/system_stm32l0xx.o ./Core/Src/system_stm32l0xx.su ./Core/Src/usart.cyclo ./Core/Src/usart.d ./Core/Src/usart.o ./Core/Src/usart.su ./Core/Src/usart_if.cyclo ./Core/Src/usart_if.d ./Core/Src/usart_if.o ./Core/Src/usart_if.su

.PHONY: clean-Core-2f-Src

