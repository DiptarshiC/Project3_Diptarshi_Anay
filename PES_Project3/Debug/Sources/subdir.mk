################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Sources/cirbuf.c \
../Sources/cirbuf2.c \
../Sources/conversion.c \
../Sources/dma.c \
../Sources/logger.c \
../Sources/logger_queue.c \
../Sources/main.c \
../Sources/nordic.c \
../Sources/project3.c \
../Sources/spi.c \
../Sources/uart.c 

OBJS += \
./Sources/cirbuf.o \
./Sources/cirbuf2.o \
./Sources/conversion.o \
./Sources/dma.o \
./Sources/logger.o \
./Sources/logger_queue.o \
./Sources/main.o \
./Sources/nordic.o \
./Sources/project3.o \
./Sources/spi.o \
./Sources/uart.o 

C_DEPS += \
./Sources/cirbuf.d \
./Sources/cirbuf2.d \
./Sources/conversion.d \
./Sources/dma.d \
./Sources/logger.d \
./Sources/logger_queue.d \
./Sources/main.d \
./Sources/nordic.d \
./Sources/project3.d \
./Sources/spi.d \
./Sources/uart.d 


# Each subdirectory must supply rules for building sources it contributes
Sources/%.o: ../Sources/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m0plus -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -I"../Sources" -I"../Includes" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


