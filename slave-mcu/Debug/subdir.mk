################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ADC_Driver.c \
../DIO_Program.c \
../LED_Program.c \
../SPI.c \
../Servo.c \
../Timer_PRG.c \
../s.c 

OBJS += \
./ADC_Driver.o \
./DIO_Program.o \
./LED_Program.o \
./SPI.o \
./Servo.o \
./Timer_PRG.o \
./s.o 

C_DEPS += \
./ADC_Driver.d \
./DIO_Program.d \
./LED_Program.d \
./SPI.d \
./Servo.d \
./Timer_PRG.d \
./s.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega16 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


