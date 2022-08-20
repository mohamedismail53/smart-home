################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL := cmd.exe
RM := rm -rf

USER_OBJS :=

LIBS := 
PROJ := 

O_SRCS := 
C_SRCS := 
S_SRCS := 
S_UPPER_SRCS := 
OBJ_SRCS := 
ASM_SRCS := 
PREPROCESSING_SRCS := 
OBJS := 
OBJS_AS_ARGS := 
C_DEPS := 
C_DEPS_AS_ARGS := 
EXECUTABLES := 
OUTPUT_FILE_PATH :=
OUTPUT_FILE_PATH_AS_ARGS :=
AVR_APP_PATH :=$$$AVR_APP_PATH$$$
QUOTE := "
ADDITIONAL_DEPENDENCIES:=
OUTPUT_FILE_DEP:=
LIB_DEP:=
LINKER_SCRIPT_DEP:=

# Every subdirectory with source files must be described here
SUBDIRS := 


# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS +=  \
../DIO_Program.c \
../keypad.c \
../LCD_PRG.c \
../m.c \
../SPI.c \
../timer.c \
../ultrasonic.c


PREPROCESSING_SRCS += 


ASM_SRCS += 


OBJS +=  \
DIO_Program.o \
keypad.o \
LCD_PRG.o \
m.o \
SPI.o \
timer.o \
ultrasonic.o

OBJS_AS_ARGS +=  \
DIO_Program.o \
keypad.o \
LCD_PRG.o \
m.o \
SPI.o \
timer.o \
ultrasonic.o

C_DEPS +=  \
DIO_Program.d \
keypad.d \
LCD_PRG.d \
m.d \
SPI.d \
timer.d \
ultrasonic.d

C_DEPS_AS_ARGS +=  \
DIO_Program.d \
keypad.d \
LCD_PRG.d \
m.d \
SPI.d \
timer.d \
ultrasonic.d

OUTPUT_FILE_PATH +=master.elf

OUTPUT_FILE_PATH_AS_ARGS +=master.elf

ADDITIONAL_DEPENDENCIES:=

OUTPUT_FILE_DEP:= ./makedep.mk

LIB_DEP+= 

LINKER_SCRIPT_DEP+= 


# AVR32/GNU C Compiler















./%.o: .././%.c
	@echo Building file: $<
	@echo Invoking: AVR/GNU C Compiler : 4.9.2
	$(QUOTE)D:\programs\AVR\ATmel studio 7\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-gcc.exe$(QUOTE)  -x c -funsigned-char -funsigned-bitfields -DDEBUG  -I"D:\programs\AVR\ATmel studio 7\7.0\Packs\atmel\ATmega_DFP\1.0.106\include"  -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -g2 -Wall -mmcu=atmega32 -B "D:\programs\AVR\ATmel studio 7\7.0\Packs\atmel\ATmega_DFP\1.0.106\gcc\dev\atmega32" -c -std=gnu99 -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)"   -o "$@" "$<" 
	@echo Finished building: $<
	



# AVR32/GNU Preprocessing Assembler



# AVR32/GNU Assembler




ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: $(OUTPUT_FILE_PATH) $(ADDITIONAL_DEPENDENCIES)

$(OUTPUT_FILE_PATH): $(OBJS) $(USER_OBJS) $(OUTPUT_FILE_DEP) $(LIB_DEP) $(LINKER_SCRIPT_DEP)
	@echo Building target: $@
	@echo Invoking: AVR/GNU Linker : 4.9.2
	$(QUOTE)D:\programs\AVR\ATmel studio 7\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-gcc.exe$(QUOTE) -o$(OUTPUT_FILE_PATH_AS_ARGS) $(OBJS_AS_ARGS) $(USER_OBJS) $(LIBS) -Wl,-Map="master.map" -Wl,--start-group -Wl,-lm  -Wl,--end-group -Wl,--gc-sections -mmcu=atmega32 -B "D:\programs\AVR\ATmel studio 7\7.0\Packs\atmel\ATmega_DFP\1.0.106\gcc\dev\atmega32"  
	@echo Finished building target: $@
	"D:\programs\AVR\ATmel studio 7\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-objcopy.exe" -O ihex -R .eeprom -R .fuse -R .lock -R .signature -R .user_signatures  "master.elf" "master.hex"
	"D:\programs\AVR\ATmel studio 7\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-objcopy.exe" -j .eeprom  --set-section-flags=.eeprom=alloc,load --change-section-lma .eeprom=0  --no-change-warnings -O ihex "master.elf" "master.eep" || exit 0
	"D:\programs\AVR\ATmel studio 7\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-objdump.exe" -h -S "master.elf" > "master.lss"
	"D:\programs\AVR\ATmel studio 7\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-objcopy.exe" -O srec -R .eeprom -R .fuse -R .lock -R .signature -R .user_signatures "master.elf" "master.srec"
	"D:\programs\AVR\ATmel studio 7\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-size.exe" "master.elf"
	
	





# Other Targets
clean:
	-$(RM) $(OBJS_AS_ARGS) $(EXECUTABLES)  
	-$(RM) $(C_DEPS_AS_ARGS)   
	rm -rf "master.elf" "master.a" "master.hex" "master.lss" "master.eep" "master.map" "master.srec" "master.usersignatures"
	