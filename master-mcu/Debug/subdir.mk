################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../DIO_Program.c \
../LCD_PRG.c \
../SPI.c \
../keypad.c \
../m.c \
../timer.c \
../ultrasonic.c 

OBJS += \
./DIO_Program.o \
./LCD_PRG.o \
./SPI.o \
./keypad.o \
./m.o \
./timer.o \
./ultrasonic.o 

C_DEPS += \
./DIO_Program.d \
./LCD_PRG.d \
./SPI.d \
./keypad.d \
./m.d \
./timer.d \
./ultrasonic.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega16 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


