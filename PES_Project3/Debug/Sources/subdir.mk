################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Sources/cirbuf.c \
../Sources/conversion.c \
../Sources/dma.c \
../Sources/logger.c \
../Sources/main.c \
../Sources/nordic.c \
../Sources/project2.c \
../Sources/spi.c \
../Sources/uart.c 

OBJS += \
./Sources/cirbuf.o \
./Sources/conversion.o \
./Sources/dma.o \
./Sources/logger.o \
./Sources/main.o \
./Sources/nordic.o \
./Sources/project2.o \
./Sources/spi.o \
./Sources/uart.o 

C_DEPS += \
./Sources/cirbuf.d \
./Sources/conversion.d \
./Sources/dma.d \
./Sources/logger.d \
./Sources/main.d \
./Sources/nordic.d \
./Sources/project2.d \
./Sources/spi.d \
./Sources/uart.d 


# Each subdirectory must supply rules for building sources it contributes
Sources/%.o: ../Sources/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m0plus -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -I"../Sources" -I"../Includes" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


