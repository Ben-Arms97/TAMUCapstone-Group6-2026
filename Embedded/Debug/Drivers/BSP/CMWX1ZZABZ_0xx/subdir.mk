################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Users/user1/Downloads/i-cube_lrwan2/STM32CubeExpansion_LRWAN_V2.1.0/Drivers/BSP/CMWX1ZZABZ_0xx/cmwx1zzabz_0xx.c 

OBJS += \
./Drivers/BSP/CMWX1ZZABZ_0xx/cmwx1zzabz_0xx.o 

C_DEPS += \
./Drivers/BSP/CMWX1ZZABZ_0xx/cmwx1zzabz_0xx.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/BSP/CMWX1ZZABZ_0xx/cmwx1zzabz_0xx.o: C:/Users/user1/Downloads/i-cube_lrwan2/STM32CubeExpansion_LRWAN_V2.1.0/Drivers/BSP/CMWX1ZZABZ_0xx/cmwx1zzabz_0xx.c Drivers/BSP/CMWX1ZZABZ_0xx/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DDEBUG -DCMWX1ZZABZ0XX -DUSE_HAL_DRIVER -DSTM32L082xx -c -I../Core/Inc -I../Middlewares/SubGHz_Phy/ -I../Middlewares/LoRaWAN/Mac/Region -I../Drivers/BSP/CMWX1ZZABZ_0xx/ -I../Drivers/BSP/B-L072Z-LRWAN1 -I../Middlewares/LoRaWAN/Mac -I../Middlewares/LoRaWAN/Crypto -I../Middlewares/LoRaWAN/LmHandler -I../Middlewares/LoRaWAN/LmHandler/Packages -I../Middlewares/LoRaWAN/Utilities -I../LoRaWAN/App -I../LoRaWAN/Target -I../Drivers/STM32L0xx_HAL_Driver/Inc -I../Drivers/STM32L0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L0xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"Drivers/BSP/CMWX1ZZABZ_0xx/cmwx1zzabz_0xx.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Drivers-2f-BSP-2f-CMWX1ZZABZ_0xx

clean-Drivers-2f-BSP-2f-CMWX1ZZABZ_0xx:
	-$(RM) ./Drivers/BSP/CMWX1ZZABZ_0xx/cmwx1zzabz_0xx.cyclo ./Drivers/BSP/CMWX1ZZABZ_0xx/cmwx1zzabz_0xx.d ./Drivers/BSP/CMWX1ZZABZ_0xx/cmwx1zzabz_0xx.o ./Drivers/BSP/CMWX1ZZABZ_0xx/cmwx1zzabz_0xx.su

.PHONY: clean-Drivers-2f-BSP-2f-CMWX1ZZABZ_0xx

