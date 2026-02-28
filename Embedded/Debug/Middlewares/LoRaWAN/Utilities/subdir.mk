################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Middlewares/LoRaWAN/Utilities/stm32_adv_trace.c \
../Middlewares/LoRaWAN/Utilities/stm32_lpm.c \
../Middlewares/LoRaWAN/Utilities/stm32_mem.c \
../Middlewares/LoRaWAN/Utilities/stm32_seq.c \
../Middlewares/LoRaWAN/Utilities/stm32_systime.c \
../Middlewares/LoRaWAN/Utilities/stm32_timer.c \
../Middlewares/LoRaWAN/Utilities/stm32_tiny_vsnprintf.c \
C:/Users/user1/Downloads/i-cube_lrwan/STM32CubeExpansion_LRWAN_V2.1.0/Middlewares/Third_Party/LoRaWAN/Utilities/utilities.c 

OBJS += \
./Middlewares/LoRaWAN/Utilities/stm32_adv_trace.o \
./Middlewares/LoRaWAN/Utilities/stm32_lpm.o \
./Middlewares/LoRaWAN/Utilities/stm32_mem.o \
./Middlewares/LoRaWAN/Utilities/stm32_seq.o \
./Middlewares/LoRaWAN/Utilities/stm32_systime.o \
./Middlewares/LoRaWAN/Utilities/stm32_timer.o \
./Middlewares/LoRaWAN/Utilities/stm32_tiny_vsnprintf.o \
./Middlewares/LoRaWAN/Utilities/utilities.o 

C_DEPS += \
./Middlewares/LoRaWAN/Utilities/stm32_adv_trace.d \
./Middlewares/LoRaWAN/Utilities/stm32_lpm.d \
./Middlewares/LoRaWAN/Utilities/stm32_mem.d \
./Middlewares/LoRaWAN/Utilities/stm32_seq.d \
./Middlewares/LoRaWAN/Utilities/stm32_systime.d \
./Middlewares/LoRaWAN/Utilities/stm32_timer.d \
./Middlewares/LoRaWAN/Utilities/stm32_tiny_vsnprintf.d \
./Middlewares/LoRaWAN/Utilities/utilities.d 


# Each subdirectory must supply rules for building sources it contributes
Middlewares/LoRaWAN/Utilities/%.o Middlewares/LoRaWAN/Utilities/%.su Middlewares/LoRaWAN/Utilities/%.cyclo: ../Middlewares/LoRaWAN/Utilities/%.c Middlewares/LoRaWAN/Utilities/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DDEBUG -DCMWX1ZZABZ0XX -DUSE_HAL_DRIVER -DSTM32L082xx -c -I../Core/Inc -I../Middlewares/SubGHz_Phy/ -I../Middlewares/LoRaWAN/Mac/Region -I../Drivers/BSP/CMWX1ZZABZ_0xx/ -I../Drivers/BSP/B-L072Z-LRWAN1 -I../Middlewares/LoRaWAN/Mac -I../Middlewares/LoRaWAN/Crypto -I../Middlewares/LoRaWAN/LmHandler -I../Middlewares/LoRaWAN/LmHandler/Packages -I../Middlewares/LoRaWAN/Utilities -I../LoRaWAN/App -I../LoRaWAN/Target -I../Drivers/STM32L0xx_HAL_Driver/Inc -I../Drivers/STM32L0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L0xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Middlewares/LoRaWAN/Utilities/utilities.o: C:/Users/user1/Downloads/i-cube_lrwan/STM32CubeExpansion_LRWAN_V2.1.0/Middlewares/Third_Party/LoRaWAN/Utilities/utilities.c Middlewares/LoRaWAN/Utilities/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DDEBUG -DCMWX1ZZABZ0XX -DUSE_HAL_DRIVER -DSTM32L082xx -c -I../Core/Inc -I../Middlewares/SubGHz_Phy/ -I../Middlewares/LoRaWAN/Mac/Region -I../Drivers/BSP/CMWX1ZZABZ_0xx/ -I../Drivers/BSP/B-L072Z-LRWAN1 -I../Middlewares/LoRaWAN/Mac -I../Middlewares/LoRaWAN/Crypto -I../Middlewares/LoRaWAN/LmHandler -I../Middlewares/LoRaWAN/LmHandler/Packages -I../Middlewares/LoRaWAN/Utilities -I../LoRaWAN/App -I../LoRaWAN/Target -I../Drivers/STM32L0xx_HAL_Driver/Inc -I../Drivers/STM32L0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L0xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"Middlewares/LoRaWAN/Utilities/utilities.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Middlewares-2f-LoRaWAN-2f-Utilities

clean-Middlewares-2f-LoRaWAN-2f-Utilities:
	-$(RM) ./Middlewares/LoRaWAN/Utilities/stm32_adv_trace.cyclo ./Middlewares/LoRaWAN/Utilities/stm32_adv_trace.d ./Middlewares/LoRaWAN/Utilities/stm32_adv_trace.o ./Middlewares/LoRaWAN/Utilities/stm32_adv_trace.su ./Middlewares/LoRaWAN/Utilities/stm32_lpm.cyclo ./Middlewares/LoRaWAN/Utilities/stm32_lpm.d ./Middlewares/LoRaWAN/Utilities/stm32_lpm.o ./Middlewares/LoRaWAN/Utilities/stm32_lpm.su ./Middlewares/LoRaWAN/Utilities/stm32_mem.cyclo ./Middlewares/LoRaWAN/Utilities/stm32_mem.d ./Middlewares/LoRaWAN/Utilities/stm32_mem.o ./Middlewares/LoRaWAN/Utilities/stm32_mem.su ./Middlewares/LoRaWAN/Utilities/stm32_seq.cyclo ./Middlewares/LoRaWAN/Utilities/stm32_seq.d ./Middlewares/LoRaWAN/Utilities/stm32_seq.o ./Middlewares/LoRaWAN/Utilities/stm32_seq.su ./Middlewares/LoRaWAN/Utilities/stm32_systime.cyclo ./Middlewares/LoRaWAN/Utilities/stm32_systime.d ./Middlewares/LoRaWAN/Utilities/stm32_systime.o ./Middlewares/LoRaWAN/Utilities/stm32_systime.su ./Middlewares/LoRaWAN/Utilities/stm32_timer.cyclo ./Middlewares/LoRaWAN/Utilities/stm32_timer.d ./Middlewares/LoRaWAN/Utilities/stm32_timer.o ./Middlewares/LoRaWAN/Utilities/stm32_timer.su ./Middlewares/LoRaWAN/Utilities/stm32_tiny_vsnprintf.cyclo ./Middlewares/LoRaWAN/Utilities/stm32_tiny_vsnprintf.d ./Middlewares/LoRaWAN/Utilities/stm32_tiny_vsnprintf.o ./Middlewares/LoRaWAN/Utilities/stm32_tiny_vsnprintf.su ./Middlewares/LoRaWAN/Utilities/utilities.cyclo ./Middlewares/LoRaWAN/Utilities/utilities.d ./Middlewares/LoRaWAN/Utilities/utilities.o ./Middlewares/LoRaWAN/Utilities/utilities.su

.PHONY: clean-Middlewares-2f-LoRaWAN-2f-Utilities

