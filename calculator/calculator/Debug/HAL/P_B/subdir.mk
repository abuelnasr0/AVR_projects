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
	avr-gcc -I"D:\eclipse_projects\calculator\MCAL\DIO" -I"D:\eclipse_projects\calculator\MCAL" -I"D:\eclipse_projects\calculator\APP\LIB" -I"D:\eclipse_projects\calculator\MCAL\INT" -I"D:\eclipse_projects\calculator\HAL\KEY_PAD" -I"D:\eclipse_projects\calculator\HAL\LCD" -I"D:\eclipse_projects\calculator\HAL\LED" -I"D:\eclipse_projects\calculator\HAL\P_B" -I"D:\eclipse_projects\calculator\HAL\S_SEG" -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


