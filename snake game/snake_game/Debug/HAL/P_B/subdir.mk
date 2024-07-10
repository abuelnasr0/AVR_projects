################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/P_B/P_B.c 

OBJS += \
./HAL/P_B/P_B.o 

C_DEPS += \
./HAL/P_B/P_B.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/P_B/%.o: ../HAL/P_B/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"D:\snake_game\HAL\LCD" -I"D:\snake_game\HAL\LED" -I"D:\snake_game\HAL\P_B" -I"D:\snake_game\MCAL\DIO" -I"D:\snake_game\MCAL" -I"D:\snake_game\APP\LIB" -I"D:\snake_game\APP" -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega16 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


