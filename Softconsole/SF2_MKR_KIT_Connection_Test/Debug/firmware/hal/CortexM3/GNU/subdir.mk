################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_UPPER_SRCS += \
../firmware/hal/CortexM3/GNU/hal.S \
../firmware/hal/CortexM3/GNU/hw_reg_access.S 

OBJS += \
./firmware/hal/CortexM3/GNU/hal.o \
./firmware/hal/CortexM3/GNU/hw_reg_access.o 

S_UPPER_DEPS += \
./firmware/hal/CortexM3/GNU/hal.d \
./firmware/hal/CortexM3/GNU/hw_reg_access.d 


# Each subdirectory must supply rules for building sources it contributes
firmware/hal/CortexM3/GNU/%.o: ../firmware/hal/CortexM3/GNU/%.S
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM Cross Assembler'
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -x assembler-with-cpp -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


