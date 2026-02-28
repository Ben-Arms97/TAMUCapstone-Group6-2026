################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Users/user1/Downloads/i-cube_lrwan/STM32CubeExpansion_LRWAN_V2.1.0/Middlewares/Third_Party/LoRaWAN/LmHandler/LmHandler.c \
C:/Users/user1/Downloads/i-cube_lrwan/STM32CubeExpansion_LRWAN_V2.1.0/Middlewares/Third_Party/LoRaWAN/LmHandler/Packages/LmhpCompliance.c \
C:/Users/user1/Downloads/i-cube_lrwan/STM32CubeExpansion_LRWAN_V2.1.0/Middlewares/Third_Party/LoRaWAN/LmHandler/NvmDataMgmt.c \
../Middlewares/LoRaWAN/LmHandler/lora_info.c 

OBJS += \
./Middlewares/LoRaWAN/LmHandler/LmHandler.o \
./Middlewares/LoRaWAN/LmHandler/LmhpCompliance.o \
./Middlewares/LoRaWAN/LmHandler/NvmDataMgmt.o \
./Middlewares/LoRaWAN/LmHandler/lora_info.o 

C_DEPS += \
./Middlewares/LoRaWAN/LmHandler/LmHandler.d \
./Middlewares/LoRaWAN/LmHandler/LmhpCompliance.d \
./Middlewares/LoRaWAN/LmHandler/NvmDataMgmt.d \
./Middlewares/LoRaWAN/LmHandler/lora_info.d 


# Each subdirectory must supply rules for building sources it contributes
Middlewares/LoRaWAN/LmHandler/LmHandler.o: C:/Users/user1/Downloads/i-cube_lrwan/STM32CubeExpansion_LRWAN_V2.1.0/Middlewares/Third_Party/LoRaWAN/LmHandler/LmHandler.c Middlewares/LoRaWAN/LmHandler/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DDEBUG -DCMWX1ZZABZ0XX -DUSE_HAL_DRIVER -DSTM32L082xx -c -I../Core/Inc -I../Middlewares/SubGHz_Phy/ -I../Middlewares/LoRaWAN/Mac/Region -I../Drivers/BSP/CMWX1ZZABZ_0xx/ -I../Drivers/BSP/B-L072Z-LRWAN1 -I../Middlewares/LoRaWAN/Mac -I../Middlewares/LoRaWAN/Crypto -I../Middlewares/LoRaWAN/LmHandler -I../Middlewares/LoRaWAN/LmHandler/Packages -I../Middlewares/LoRaWAN/Utilities -I../LoRaWAN/App -I../LoRaWAN/Target -I../Drivers/STM32L0xx_HAL_Driver/Inc -I../Drivers/STM32L0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L0xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"Middlewares/LoRaWAN/LmHandler/LmHandler.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Middlewares/LoRaWAN/LmHandler/LmhpCompliance.o: C:/Users/user1/Downloads/i-cube_lrwan/STM32CubeExpansion_LRWAN_V2.1.0/Middlewares/Third_Party/LoRaWAN/LmHandler/Packages/LmhpCompliance.c Middlewares/LoRaWAN/LmHandler/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DDEBUG -DCMWX1ZZABZ0XX -DUSE_HAL_DRIVER -DSTM32L082xx -c -I../Core/Inc -I../Middlewares/SubGHz_Phy/ -I../Middlewares/LoRaWAN/Mac/Region -I../Drivers/BSP/CMWX1ZZABZ_0xx/ -I../Drivers/BSP/B-L072Z-LRWAN1 -I../Middlewares/LoRaWAN/Mac -I../Middlewares/LoRaWAN/Crypto -I../Middlewares/LoRaWAN/LmHandler -I../Middlewares/LoRaWAN/LmHandler/Packages -I../Middlewares/LoRaWAN/Utilities -I../LoRaWAN/App -I../LoRaWAN/Target -I../Drivers/STM32L0xx_HAL_Driver/Inc -I../Drivers/STM32L0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L0xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"Middlewares/LoRaWAN/LmHandler/LmhpCompliance.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Middlewares/LoRaWAN/LmHandler/NvmDataMgmt.o: C:/Users/user1/Downloads/i-cube_lrwan/STM32CubeExpansion_LRWAN_V2.1.0/Middlewares/Third_Party/LoRaWAN/LmHandler/NvmDataMgmt.c Middlewares/LoRaWAN/LmHandler/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DDEBUG -DCMWX1ZZABZ0XX -DUSE_HAL_DRIVER -DSTM32L082xx -c -I../Core/Inc -I../Middlewares/SubGHz_Phy/ -I../Middlewares/LoRaWAN/Mac/Region -I../Drivers/BSP/CMWX1ZZABZ_0xx/ -I../Drivers/BSP/B-L072Z-LRWAN1 -I../Middlewares/LoRaWAN/Mac -I../Middlewares/LoRaWAN/Crypto -I../Middlewares/LoRaWAN/LmHandler -I../Middlewares/LoRaWAN/LmHandler/Packages -I../Middlewares/LoRaWAN/Utilities -I../LoRaWAN/App -I../LoRaWAN/Target -I../Drivers/STM32L0xx_HAL_Driver/Inc -I../Drivers/STM32L0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L0xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"Middlewares/LoRaWAN/LmHandler/NvmDataMgmt.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Middlewares/LoRaWAN/LmHandler/%.o Middlewares/LoRaWAN/LmHandler/%.su Middlewares/LoRaWAN/LmHandler/%.cyclo: ../Middlewares/LoRaWAN/LmHandler/%.c Middlewares/LoRaWAN/LmHandler/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DDEBUG -DCMWX1ZZABZ0XX -DUSE_HAL_DRIVER -DSTM32L082xx -c -I../Core/Inc -I../Middlewares/SubGHz_Phy/ -I../Middlewares/LoRaWAN/Mac/Region -I../Drivers/BSP/CMWX1ZZABZ_0xx/ -I../Drivers/BSP/B-L072Z-LRWAN1 -I../Middlewares/LoRaWAN/Mac -I../Middlewares/LoRaWAN/Crypto -I../Middlewares/LoRaWAN/LmHandler -I../Middlewares/LoRaWAN/LmHandler/Packages -I../Middlewares/LoRaWAN/Utilities -I../LoRaWAN/App -I../LoRaWAN/Target -I../Drivers/STM32L0xx_HAL_Driver/Inc -I../Drivers/STM32L0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L0xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Middlewares-2f-LoRaWAN-2f-LmHandler

clean-Middlewares-2f-LoRaWAN-2f-LmHandler:
	-$(RM) ./Middlewares/LoRaWAN/LmHandler/LmHandler.cyclo ./Middlewares/LoRaWAN/LmHandler/LmHandler.d ./Middlewares/LoRaWAN/LmHandler/LmHandler.o ./Middlewares/LoRaWAN/LmHandler/LmHandler.su ./Middlewares/LoRaWAN/LmHandler/LmhpCompliance.cyclo ./Middlewares/LoRaWAN/LmHandler/LmhpCompliance.d ./Middlewares/LoRaWAN/LmHandler/LmhpCompliance.o ./Middlewares/LoRaWAN/LmHandler/LmhpCompliance.su ./Middlewares/LoRaWAN/LmHandler/NvmDataMgmt.cyclo ./Middlewares/LoRaWAN/LmHandler/NvmDataMgmt.d ./Middlewares/LoRaWAN/LmHandler/NvmDataMgmt.o ./Middlewares/LoRaWAN/LmHandler/NvmDataMgmt.su ./Middlewares/LoRaWAN/LmHandler/lora_info.cyclo ./Middlewares/LoRaWAN/LmHandler/lora_info.d ./Middlewares/LoRaWAN/LmHandler/lora_info.o ./Middlewares/LoRaWAN/LmHandler/lora_info.su

.PHONY: clean-Middlewares-2f-LoRaWAN-2f-LmHandler

