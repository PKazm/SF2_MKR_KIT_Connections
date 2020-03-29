################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../firmware/CMSIS/startup_gcc/newlib_stubs.c 

S_UPPER_SRCS += \
../firmware/CMSIS/startup_gcc/startup_m2sxxx.S 

OBJS += \
./firmware/CMSIS/startup_gcc/newlib_stubs.o \
./firmware/CMSIS/startup_gcc/startup_m2sxxx.o 

S_UPPER_DEPS += \
./firmware/CMSIS/startup_gcc/startup_m2sxxx.d 

C_DEPS += \
./firmware/CMSIS/startup_gcc/newlib_stubs.d 


# Each subdirectory must supply rules for building sources it contributes
firmware/CMSIS/startup_gcc/%.o: ../firmware/CMSIS/startup_gcc/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM Cross C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -I"E:\Github_Repos\SF2_MKR_KIT_Connections\Softconsole\SF2_MKR_KIT_Connection_Test\firmware\hal\CortexM3\GNU" -I"E:\Github_Repos\SF2_MKR_KIT_Connections\Softconsole\SF2_MKR_KIT_Connection_Test\firmware\hal" -std=gnu11 --specs=cmsis.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

firmware/CMSIS/startup_gcc/%.o: ../firmware/CMSIS/startup_gcc/%.S
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM Cross Assembler'
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -x assembler-with-cpp -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


