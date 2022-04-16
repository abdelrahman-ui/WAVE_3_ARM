################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Inc/02_HAL/01_LCD/LCD_prog.c 

OBJS += \
./Inc/02_HAL/01_LCD/LCD_prog.o 

C_DEPS += \
./Inc/02_HAL/01_LCD/LCD_prog.d 


# Each subdirectory must supply rules for building sources it contributes
Inc/02_HAL/01_LCD/%.o: ../Inc/02_HAL/01_LCD/%.c Inc/02_HAL/01_LCD/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -DSTM32 -DSTM32F4 -DSTM32F401VETx -c -I../Inc -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Inc-2f-02_HAL-2f-01_LCD

clean-Inc-2f-02_HAL-2f-01_LCD:
	-$(RM) ./Inc/02_HAL/01_LCD/LCD_prog.d ./Inc/02_HAL/01_LCD/LCD_prog.o

.PHONY: clean-Inc-2f-02_HAL-2f-01_LCD

