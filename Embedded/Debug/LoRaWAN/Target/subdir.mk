################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../LoRaWAN/Target/b_l072z_lrwan1_bus.c 

OBJS += \
./LoRaWAN/Target/b_l072z_lrwan1_bus.o 

C_DEPS += \
./LoRaWAN/Target/b_l072z_lrwan1_bus.d 


# Each subdirectory must supply rules for building sources it contributes
LoRaWAN/Target/%.o LoRaWAN/Target/%.su LoRaWAN/Target/%.cyclo: ../LoRaWAN/Target/%.c LoRaWAN/Target/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DDEBUG -DCMWX1ZZABZ0XX -DUSE_HAL_DRIVER -DSTM32L082xx -c -I../Core/Inc -I../Middlewares/SubGHz_Phy/ -I../Middlewares/LoRaWAN/Mac/Region -I../Drivers/BSP/CMWX1ZZABZ_0xx/ -I../Drivers/BSP/B-L072Z-LRWAN1 -I../Middlewares/LoRaWAN/Mac -I../Middlewares/LoRaWAN/Crypto -I../Middlewares/LoRaWAN/LmHandler -I../Middlewares/LoRaWAN/LmHandler/Packages -I../Middlewares/LoRaWAN/Utilities -I../LoRaWAN/App -I../LoRaWAN/Target -I../Drivers/STM32L0xx_HAL_Driver/Inc -I../Drivers/STM32L0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L0xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-LoRaWAN-2f-Target

clean-LoRaWAN-2f-Target:
	-$(RM) ./LoRaWAN/Target/b_l072z_lrwan1_bus.cyclo ./LoRaWAN/Target/b_l072z_lrwan1_bus.d ./LoRaWAN/Target/b_l072z_lrwan1_bus.o ./LoRaWAN/Target/b_l072z_lrwan1_bus.su

.PHONY: clean-LoRaWAN-2f-Target

