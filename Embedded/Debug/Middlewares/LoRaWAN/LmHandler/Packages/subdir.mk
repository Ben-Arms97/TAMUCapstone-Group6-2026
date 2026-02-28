################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Middlewares/LoRaWAN/LmHandler/Packages/FragDecoder.c \
../Middlewares/LoRaWAN/LmHandler/Packages/LmhpClockSync.c \
../Middlewares/LoRaWAN/LmHandler/Packages/LmhpFirmwareManagement.c \
../Middlewares/LoRaWAN/LmHandler/Packages/LmhpFragmentation.c \
../Middlewares/LoRaWAN/LmHandler/Packages/LmhpPackagesRegistration.c \
../Middlewares/LoRaWAN/LmHandler/Packages/LmhpRemoteMcastSetup.c 

OBJS += \
./Middlewares/LoRaWAN/LmHandler/Packages/FragDecoder.o \
./Middlewares/LoRaWAN/LmHandler/Packages/LmhpClockSync.o \
./Middlewares/LoRaWAN/LmHandler/Packages/LmhpFirmwareManagement.o \
./Middlewares/LoRaWAN/LmHandler/Packages/LmhpFragmentation.o \
./Middlewares/LoRaWAN/LmHandler/Packages/LmhpPackagesRegistration.o \
./Middlewares/LoRaWAN/LmHandler/Packages/LmhpRemoteMcastSetup.o 

C_DEPS += \
./Middlewares/LoRaWAN/LmHandler/Packages/FragDecoder.d \
./Middlewares/LoRaWAN/LmHandler/Packages/LmhpClockSync.d \
./Middlewares/LoRaWAN/LmHandler/Packages/LmhpFirmwareManagement.d \
./Middlewares/LoRaWAN/LmHandler/Packages/LmhpFragmentation.d \
./Middlewares/LoRaWAN/LmHandler/Packages/LmhpPackagesRegistration.d \
./Middlewares/LoRaWAN/LmHandler/Packages/LmhpRemoteMcastSetup.d 


# Each subdirectory must supply rules for building sources it contributes
Middlewares/LoRaWAN/LmHandler/Packages/%.o Middlewares/LoRaWAN/LmHandler/Packages/%.su Middlewares/LoRaWAN/LmHandler/Packages/%.cyclo: ../Middlewares/LoRaWAN/LmHandler/Packages/%.c Middlewares/LoRaWAN/LmHandler/Packages/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DDEBUG -DCMWX1ZZABZ0XX -DUSE_HAL_DRIVER -DSTM32L082xx -c -I../Core/Inc -I../Middlewares/SubGHz_Phy/ -I../Middlewares/LoRaWAN/Mac/Region -I../Drivers/BSP/CMWX1ZZABZ_0xx/ -I../Drivers/BSP/B-L072Z-LRWAN1 -I../Middlewares/LoRaWAN/Mac -I../Middlewares/LoRaWAN/Crypto -I../Middlewares/LoRaWAN/LmHandler -I../Middlewares/LoRaWAN/LmHandler/Packages -I../Middlewares/LoRaWAN/Utilities -I../LoRaWAN/App -I../LoRaWAN/Target -I../Drivers/STM32L0xx_HAL_Driver/Inc -I../Drivers/STM32L0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L0xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Middlewares-2f-LoRaWAN-2f-LmHandler-2f-Packages

clean-Middlewares-2f-LoRaWAN-2f-LmHandler-2f-Packages:
	-$(RM) ./Middlewares/LoRaWAN/LmHandler/Packages/FragDecoder.cyclo ./Middlewares/LoRaWAN/LmHandler/Packages/FragDecoder.d ./Middlewares/LoRaWAN/LmHandler/Packages/FragDecoder.o ./Middlewares/LoRaWAN/LmHandler/Packages/FragDecoder.su ./Middlewares/LoRaWAN/LmHandler/Packages/LmhpClockSync.cyclo ./Middlewares/LoRaWAN/LmHandler/Packages/LmhpClockSync.d ./Middlewares/LoRaWAN/LmHandler/Packages/LmhpClockSync.o ./Middlewares/LoRaWAN/LmHandler/Packages/LmhpClockSync.su ./Middlewares/LoRaWAN/LmHandler/Packages/LmhpFirmwareManagement.cyclo ./Middlewares/LoRaWAN/LmHandler/Packages/LmhpFirmwareManagement.d ./Middlewares/LoRaWAN/LmHandler/Packages/LmhpFirmwareManagement.o ./Middlewares/LoRaWAN/LmHandler/Packages/LmhpFirmwareManagement.su ./Middlewares/LoRaWAN/LmHandler/Packages/LmhpFragmentation.cyclo ./Middlewares/LoRaWAN/LmHandler/Packages/LmhpFragmentation.d ./Middlewares/LoRaWAN/LmHandler/Packages/LmhpFragmentation.o ./Middlewares/LoRaWAN/LmHandler/Packages/LmhpFragmentation.su ./Middlewares/LoRaWAN/LmHandler/Packages/LmhpPackagesRegistration.cyclo ./Middlewares/LoRaWAN/LmHandler/Packages/LmhpPackagesRegistration.d ./Middlewares/LoRaWAN/LmHandler/Packages/LmhpPackagesRegistration.o ./Middlewares/LoRaWAN/LmHandler/Packages/LmhpPackagesRegistration.su ./Middlewares/LoRaWAN/LmHandler/Packages/LmhpRemoteMcastSetup.cyclo ./Middlewares/LoRaWAN/LmHandler/Packages/LmhpRemoteMcastSetup.d ./Middlewares/LoRaWAN/LmHandler/Packages/LmhpRemoteMcastSetup.o ./Middlewares/LoRaWAN/LmHandler/Packages/LmhpRemoteMcastSetup.su

.PHONY: clean-Middlewares-2f-LoRaWAN-2f-LmHandler-2f-Packages

