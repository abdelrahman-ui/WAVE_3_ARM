################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Inc/01_MCAL/00_RCC/RCC_program.c 

OBJS += \
./Inc/01_MCAL/00_RCC/RCC_program.o 

C_DEPS += \
./Inc/01_MCAL/00_RCC/RCC_program.d 


# Each subdirectory must supply rules for building sources it contributes
Inc/01_MCAL/00_RCC/%.o: ../Inc/01_MCAL/00_RCC/%.c Inc/01_MCAL/00_RCC/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F4 -DSTM32F401VETx -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Inc-2f-01_MCAL-2f-00_RCC

clean-Inc-2f-01_MCAL-2f-00_RCC:
	-$(RM) ./Inc/01_MCAL/00_RCC/RCC_program.d ./Inc/01_MCAL/00_RCC/RCC_program.o

.PHONY: clean-Inc-2f-01_MCAL-2f-00_RCC

