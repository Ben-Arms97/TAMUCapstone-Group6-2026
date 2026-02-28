################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Users/user1/Downloads/i-cube_lrwan2/STM32CubeExpansion_LRWAN_V2.1.0/Drivers/BSP/B-L072Z-LRWAN1/b-l072z-lrwan1.c 

OBJS += \
./Drivers/BSP/B-L072Z-LRWAN1/b-l072z-lrwan1.o 

C_DEPS += \
./Drivers/BSP/B-L072Z-LRWAN1/b-l072z-lrwan1.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/BSP/B-L072Z-LRWAN1/b-l072z-lrwan1.o: C:/Users/user1/Downloads/i-cube_lrwan2/STM32CubeExpansion_LRWAN_V2.1.0/Drivers/BSP/B-L072Z-LRWAN1/b-l072z-lrwan1.c Drivers/BSP/B-L072Z-LRWAN1/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DDEBUG -DCMWX1ZZABZ0XX -DUSE_HAL_DRIVER -DSTM32L082xx -c -I../Core/Inc -I../Middlewares/SubGHz_Phy/ -I../Middlewares/LoRaWAN/Mac/Region -I../Drivers/BSP/CMWX1ZZABZ_0xx/ -I../Drivers/BSP/B-L072Z-LRWAN1 -I../Middlewares/LoRaWAN/Mac -I../Middlewares/LoRaWAN/Crypto -I../Middlewares/LoRaWAN/LmHandler -I../Middlewares/LoRaWAN/LmHandler/Packages -I../Middlewares/LoRaWAN/Utilities -I../LoRaWAN/App -I../LoRaWAN/Target -I../Drivers/STM32L0xx_HAL_Driver/Inc -I../Drivers/STM32L0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L0xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"Drivers/BSP/B-L072Z-LRWAN1/b-l072z-lrwan1.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Drivers-2f-BSP-2f-B-2d-L072Z-2d-LRWAN1

clean-Drivers-2f-BSP-2f-B-2d-L072Z-2d-LRWAN1:
	-$(RM) ./Drivers/BSP/B-L072Z-LRWAN1/b-l072z-lrwan1.cyclo ./Drivers/BSP/B-L072Z-LRWAN1/b-l072z-lrwan1.d ./Drivers/BSP/B-L072Z-LRWAN1/b-l072z-lrwan1.o ./Drivers/BSP/B-L072Z-LRWAN1/b-l072z-lrwan1.su

.PHONY: clean-Drivers-2f-BSP-2f-B-2d-L072Z-2d-LRWAN1

