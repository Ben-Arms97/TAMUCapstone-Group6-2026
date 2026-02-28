################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Users/user1/Downloads/i-cube_lrwan/STM32CubeExpansion_LRWAN_V2.1.0/Middlewares/Third_Party/LoRaWAN/Mac/LoRaMac.c \
C:/Users/user1/Downloads/i-cube_lrwan/STM32CubeExpansion_LRWAN_V2.1.0/Middlewares/Third_Party/LoRaWAN/Mac/LoRaMacAdr.c \
C:/Users/user1/Downloads/i-cube_lrwan/STM32CubeExpansion_LRWAN_V2.1.0/Middlewares/Third_Party/LoRaWAN/Mac/LoRaMacClassB.c \
C:/Users/user1/Downloads/i-cube_lrwan/STM32CubeExpansion_LRWAN_V2.1.0/Middlewares/Third_Party/LoRaWAN/Mac/LoRaMacCommands.c \
C:/Users/user1/Downloads/i-cube_lrwan/STM32CubeExpansion_LRWAN_V2.1.0/Middlewares/Third_Party/LoRaWAN/Mac/LoRaMacConfirmQueue.c \
C:/Users/user1/Downloads/i-cube_lrwan/STM32CubeExpansion_LRWAN_V2.1.0/Middlewares/Third_Party/LoRaWAN/Mac/LoRaMacCrypto.c \
C:/Users/user1/Downloads/i-cube_lrwan/STM32CubeExpansion_LRWAN_V2.1.0/Middlewares/Third_Party/LoRaWAN/Mac/LoRaMacParser.c \
C:/Users/user1/Downloads/i-cube_lrwan/STM32CubeExpansion_LRWAN_V2.1.0/Middlewares/Third_Party/LoRaWAN/Mac/LoRaMacSerializer.c 

OBJS += \
./Middlewares/LoRaWAN/Mac/LoRaMac.o \
./Middlewares/LoRaWAN/Mac/LoRaMacAdr.o \
./Middlewares/LoRaWAN/Mac/LoRaMacClassB.o \
./Middlewares/LoRaWAN/Mac/LoRaMacCommands.o \
./Middlewares/LoRaWAN/Mac/LoRaMacConfirmQueue.o \
./Middlewares/LoRaWAN/Mac/LoRaMacCrypto.o \
./Middlewares/LoRaWAN/Mac/LoRaMacParser.o \
./Middlewares/LoRaWAN/Mac/LoRaMacSerializer.o 

C_DEPS += \
./Middlewares/LoRaWAN/Mac/LoRaMac.d \
./Middlewares/LoRaWAN/Mac/LoRaMacAdr.d \
./Middlewares/LoRaWAN/Mac/LoRaMacClassB.d \
./Middlewares/LoRaWAN/Mac/LoRaMacCommands.d \
./Middlewares/LoRaWAN/Mac/LoRaMacConfirmQueue.d \
./Middlewares/LoRaWAN/Mac/LoRaMacCrypto.d \
./Middlewares/LoRaWAN/Mac/LoRaMacParser.d \
./Middlewares/LoRaWAN/Mac/LoRaMacSerializer.d 


# Each subdirectory must supply rules for building sources it contributes
Middlewares/LoRaWAN/Mac/LoRaMac.o: C:/Users/user1/Downloads/i-cube_lrwan/STM32CubeExpansion_LRWAN_V2.1.0/Middlewares/Third_Party/LoRaWAN/Mac/LoRaMac.c Middlewares/LoRaWAN/Mac/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DDEBUG -DCMWX1ZZABZ0XX -DUSE_HAL_DRIVER -DSTM32L082xx -c -I../Core/Inc -I../Middlewares/SubGHz_Phy/ -I../Middlewares/LoRaWAN/Mac/Region -I../Drivers/BSP/CMWX1ZZABZ_0xx/ -I../Drivers/BSP/B-L072Z-LRWAN1 -I../Middlewares/LoRaWAN/Mac -I../Middlewares/LoRaWAN/Crypto -I../Middlewares/LoRaWAN/LmHandler -I../Middlewares/LoRaWAN/LmHandler/Packages -I../Middlewares/LoRaWAN/Utilities -I../LoRaWAN/App -I../LoRaWAN/Target -I../Drivers/STM32L0xx_HAL_Driver/Inc -I../Drivers/STM32L0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L0xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"Middlewares/LoRaWAN/Mac/LoRaMac.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Middlewares/LoRaWAN/Mac/LoRaMacAdr.o: C:/Users/user1/Downloads/i-cube_lrwan/STM32CubeExpansion_LRWAN_V2.1.0/Middlewares/Third_Party/LoRaWAN/Mac/LoRaMacAdr.c Middlewares/LoRaWAN/Mac/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DDEBUG -DCMWX1ZZABZ0XX -DUSE_HAL_DRIVER -DSTM32L082xx -c -I../Core/Inc -I../Middlewares/SubGHz_Phy/ -I../Middlewares/LoRaWAN/Mac/Region -I../Drivers/BSP/CMWX1ZZABZ_0xx/ -I../Drivers/BSP/B-L072Z-LRWAN1 -I../Middlewares/LoRaWAN/Mac -I../Middlewares/LoRaWAN/Crypto -I../Middlewares/LoRaWAN/LmHandler -I../Middlewares/LoRaWAN/LmHandler/Packages -I../Middlewares/LoRaWAN/Utilities -I../LoRaWAN/App -I../LoRaWAN/Target -I../Drivers/STM32L0xx_HAL_Driver/Inc -I../Drivers/STM32L0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L0xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"Middlewares/LoRaWAN/Mac/LoRaMacAdr.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Middlewares/LoRaWAN/Mac/LoRaMacClassB.o: C:/Users/user1/Downloads/i-cube_lrwan/STM32CubeExpansion_LRWAN_V2.1.0/Middlewares/Third_Party/LoRaWAN/Mac/LoRaMacClassB.c Middlewares/LoRaWAN/Mac/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DDEBUG -DCMWX1ZZABZ0XX -DUSE_HAL_DRIVER -DSTM32L082xx -c -I../Core/Inc -I../Middlewares/SubGHz_Phy/ -I../Middlewares/LoRaWAN/Mac/Region -I../Drivers/BSP/CMWX1ZZABZ_0xx/ -I../Drivers/BSP/B-L072Z-LRWAN1 -I../Middlewares/LoRaWAN/Mac -I../Middlewares/LoRaWAN/Crypto -I../Middlewares/LoRaWAN/LmHandler -I../Middlewares/LoRaWAN/LmHandler/Packages -I../Middlewares/LoRaWAN/Utilities -I../LoRaWAN/App -I../LoRaWAN/Target -I../Drivers/STM32L0xx_HAL_Driver/Inc -I../Drivers/STM32L0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L0xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"Middlewares/LoRaWAN/Mac/LoRaMacClassB.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Middlewares/LoRaWAN/Mac/LoRaMacCommands.o: C:/Users/user1/Downloads/i-cube_lrwan/STM32CubeExpansion_LRWAN_V2.1.0/Middlewares/Third_Party/LoRaWAN/Mac/LoRaMacCommands.c Middlewares/LoRaWAN/Mac/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DDEBUG -DCMWX1ZZABZ0XX -DUSE_HAL_DRIVER -DSTM32L082xx -c -I../Core/Inc -I../Middlewares/SubGHz_Phy/ -I../Middlewares/LoRaWAN/Mac/Region -I../Drivers/BSP/CMWX1ZZABZ_0xx/ -I../Drivers/BSP/B-L072Z-LRWAN1 -I../Middlewares/LoRaWAN/Mac -I../Middlewares/LoRaWAN/Crypto -I../Middlewares/LoRaWAN/LmHandler -I../Middlewares/LoRaWAN/LmHandler/Packages -I../Middlewares/LoRaWAN/Utilities -I../LoRaWAN/App -I../LoRaWAN/Target -I../Drivers/STM32L0xx_HAL_Driver/Inc -I../Drivers/STM32L0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L0xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"Middlewares/LoRaWAN/Mac/LoRaMacCommands.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Middlewares/LoRaWAN/Mac/LoRaMacConfirmQueue.o: C:/Users/user1/Downloads/i-cube_lrwan/STM32CubeExpansion_LRWAN_V2.1.0/Middlewares/Third_Party/LoRaWAN/Mac/LoRaMacConfirmQueue.c Middlewares/LoRaWAN/Mac/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DDEBUG -DCMWX1ZZABZ0XX -DUSE_HAL_DRIVER -DSTM32L082xx -c -I../Core/Inc -I../Middlewares/SubGHz_Phy/ -I../Middlewares/LoRaWAN/Mac/Region -I../Drivers/BSP/CMWX1ZZABZ_0xx/ -I../Drivers/BSP/B-L072Z-LRWAN1 -I../Middlewares/LoRaWAN/Mac -I../Middlewares/LoRaWAN/Crypto -I../Middlewares/LoRaWAN/LmHandler -I../Middlewares/LoRaWAN/LmHandler/Packages -I../Middlewares/LoRaWAN/Utilities -I../LoRaWAN/App -I../LoRaWAN/Target -I../Drivers/STM32L0xx_HAL_Driver/Inc -I../Drivers/STM32L0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L0xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"Middlewares/LoRaWAN/Mac/LoRaMacConfirmQueue.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Middlewares/LoRaWAN/Mac/LoRaMacCrypto.o: C:/Users/user1/Downloads/i-cube_lrwan/STM32CubeExpansion_LRWAN_V2.1.0/Middlewares/Third_Party/LoRaWAN/Mac/LoRaMacCrypto.c Middlewares/LoRaWAN/Mac/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DDEBUG -DCMWX1ZZABZ0XX -DUSE_HAL_DRIVER -DSTM32L082xx -c -I../Core/Inc -I../Middlewares/SubGHz_Phy/ -I../Middlewares/LoRaWAN/Mac/Region -I../Drivers/BSP/CMWX1ZZABZ_0xx/ -I../Drivers/BSP/B-L072Z-LRWAN1 -I../Middlewares/LoRaWAN/Mac -I../Middlewares/LoRaWAN/Crypto -I../Middlewares/LoRaWAN/LmHandler -I../Middlewares/LoRaWAN/LmHandler/Packages -I../Middlewares/LoRaWAN/Utilities -I../LoRaWAN/App -I../LoRaWAN/Target -I../Drivers/STM32L0xx_HAL_Driver/Inc -I../Drivers/STM32L0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L0xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"Middlewares/LoRaWAN/Mac/LoRaMacCrypto.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Middlewares/LoRaWAN/Mac/LoRaMacParser.o: C:/Users/user1/Downloads/i-cube_lrwan/STM32CubeExpansion_LRWAN_V2.1.0/Middlewares/Third_Party/LoRaWAN/Mac/LoRaMacParser.c Middlewares/LoRaWAN/Mac/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DDEBUG -DCMWX1ZZABZ0XX -DUSE_HAL_DRIVER -DSTM32L082xx -c -I../Core/Inc -I../Middlewares/SubGHz_Phy/ -I../Middlewares/LoRaWAN/Mac/Region -I../Drivers/BSP/CMWX1ZZABZ_0xx/ -I../Drivers/BSP/B-L072Z-LRWAN1 -I../Middlewares/LoRaWAN/Mac -I../Middlewares/LoRaWAN/Crypto -I../Middlewares/LoRaWAN/LmHandler -I../Middlewares/LoRaWAN/LmHandler/Packages -I../Middlewares/LoRaWAN/Utilities -I../LoRaWAN/App -I../LoRaWAN/Target -I../Drivers/STM32L0xx_HAL_Driver/Inc -I../Drivers/STM32L0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L0xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"Middlewares/LoRaWAN/Mac/LoRaMacParser.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Middlewares/LoRaWAN/Mac/LoRaMacSerializer.o: C:/Users/user1/Downloads/i-cube_lrwan/STM32CubeExpansion_LRWAN_V2.1.0/Middlewares/Third_Party/LoRaWAN/Mac/LoRaMacSerializer.c Middlewares/LoRaWAN/Mac/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DDEBUG -DCMWX1ZZABZ0XX -DUSE_HAL_DRIVER -DSTM32L082xx -c -I../Core/Inc -I../Middlewares/SubGHz_Phy/ -I../Middlewares/LoRaWAN/Mac/Region -I../Drivers/BSP/CMWX1ZZABZ_0xx/ -I../Drivers/BSP/B-L072Z-LRWAN1 -I../Middlewares/LoRaWAN/Mac -I../Middlewares/LoRaWAN/Crypto -I../Middlewares/LoRaWAN/LmHandler -I../Middlewares/LoRaWAN/LmHandler/Packages -I../Middlewares/LoRaWAN/Utilities -I../LoRaWAN/App -I../LoRaWAN/Target -I../Drivers/STM32L0xx_HAL_Driver/Inc -I../Drivers/STM32L0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L0xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"Middlewares/LoRaWAN/Mac/LoRaMacSerializer.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Middlewares-2f-LoRaWAN-2f-Mac

clean-Middlewares-2f-LoRaWAN-2f-Mac:
	-$(RM) ./Middlewares/LoRaWAN/Mac/LoRaMac.cyclo ./Middlewares/LoRaWAN/Mac/LoRaMac.d ./Middlewares/LoRaWAN/Mac/LoRaMac.o ./Middlewares/LoRaWAN/Mac/LoRaMac.su ./Middlewares/LoRaWAN/Mac/LoRaMacAdr.cyclo ./Middlewares/LoRaWAN/Mac/LoRaMacAdr.d ./Middlewares/LoRaWAN/Mac/LoRaMacAdr.o ./Middlewares/LoRaWAN/Mac/LoRaMacAdr.su ./Middlewares/LoRaWAN/Mac/LoRaMacClassB.cyclo ./Middlewares/LoRaWAN/Mac/LoRaMacClassB.d ./Middlewares/LoRaWAN/Mac/LoRaMacClassB.o ./Middlewares/LoRaWAN/Mac/LoRaMacClassB.su ./Middlewares/LoRaWAN/Mac/LoRaMacCommands.cyclo ./Middlewares/LoRaWAN/Mac/LoRaMacCommands.d ./Middlewares/LoRaWAN/Mac/LoRaMacCommands.o ./Middlewares/LoRaWAN/Mac/LoRaMacCommands.su ./Middlewares/LoRaWAN/Mac/LoRaMacConfirmQueue.cyclo ./Middlewares/LoRaWAN/Mac/LoRaMacConfirmQueue.d ./Middlewares/LoRaWAN/Mac/LoRaMacConfirmQueue.o ./Middlewares/LoRaWAN/Mac/LoRaMacConfirmQueue.su ./Middlewares/LoRaWAN/Mac/LoRaMacCrypto.cyclo ./Middlewares/LoRaWAN/Mac/LoRaMacCrypto.d ./Middlewares/LoRaWAN/Mac/LoRaMacCrypto.o ./Middlewares/LoRaWAN/Mac/LoRaMacCrypto.su ./Middlewares/LoRaWAN/Mac/LoRaMacParser.cyclo ./Middlewares/LoRaWAN/Mac/LoRaMacParser.d ./Middlewares/LoRaWAN/Mac/LoRaMacParser.o ./Middlewares/LoRaWAN/Mac/LoRaMacParser.su ./Middlewares/LoRaWAN/Mac/LoRaMacSerializer.cyclo ./Middlewares/LoRaWAN/Mac/LoRaMacSerializer.d ./Middlewares/LoRaWAN/Mac/LoRaMacSerializer.o ./Middlewares/LoRaWAN/Mac/LoRaMacSerializer.su

.PHONY: clean-Middlewares-2f-LoRaWAN-2f-Mac

