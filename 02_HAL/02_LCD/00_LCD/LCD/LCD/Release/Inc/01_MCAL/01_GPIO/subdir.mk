################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Inc/01_MCAL/01_GPIO/GPIO_program.c 

OBJS += \
./Inc/01_MCAL/01_GPIO/GPIO_program.o 

C_DEPS += \
./Inc/01_MCAL/01_GPIO/GPIO_program.d 


# Each subdirectory must supply rules for building sources it contributes
Inc/01_MCAL/01_GPIO/%.o: ../Inc/01_MCAL/01_GPIO/%.c Inc/01_MCAL/01_GPIO/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -DSTM32 -DSTM32F4 -DSTM32F401VETx -c -I../Inc -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Inc-2f-01_MCAL-2f-01_GPIO

clean-Inc-2f-01_MCAL-2f-01_GPIO:
	-$(RM) ./Inc/01_MCAL/01_GPIO/GPIO_program.d ./Inc/01_MCAL/01_GPIO/GPIO_program.o

.PHONY: clean-Inc-2f-01_MCAL-2f-01_GPIO

