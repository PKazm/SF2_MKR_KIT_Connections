################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include src/subdir.mk
-include firmware/hal/CortexM3/GNU/subdir.mk
-include firmware/hal/CortexM3/subdir.mk
-include firmware/drivers_config/sys_config/subdir.mk
-include firmware/drivers/mss_uart/subdir.mk
-include firmware/drivers/mss_sys_services/subdir.mk
-include firmware/drivers/mss_spi/subdir.mk
-include firmware/drivers/mss_nvm/subdir.mk
-include firmware/drivers/mss_i2c/subdir.mk
-include firmware/drivers/mss_hpdma/subdir.mk
-include firmware/drivers/mss_gpio/subdir.mk
-include firmware/drivers/mss_ethernet_mac/subdir.mk
-include firmware/drivers/CorePWM/subdir.mk
-include firmware/CMSIS/startup_gcc/subdir.mk
-include firmware/CMSIS/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
SECONDARY_FLASH += \
SF2_MKR_KIT_Connection_Test.hex \

SECONDARY_SIZE += \
SF2_MKR_KIT_Connection_Test.siz \


# All Target
all: SF2_MKR_KIT_Connection_Test.elf secondary-outputs

# Tool invocations
SF2_MKR_KIT_Connection_Test.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: GNU ARM Cross C Linker'
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -T ../firmware/CMSIS/startup_gcc/debug-in-microsemi-smartfusion2-esram.ld -Xlinker --gc-sections -Wl,-Map,"SF2_MKR_KIT_Connection_Test.map" --specs=nano.specs -o "SF2_MKR_KIT_Connection_Test.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

SF2_MKR_KIT_Connection_Test.hex: SF2_MKR_KIT_Connection_Test.elf
	@echo 'Invoking: GNU ARM Cross Create Flash Image'
	arm-none-eabi-objcopy -O ihex "SF2_MKR_KIT_Connection_Test.elf"  "SF2_MKR_KIT_Connection_Test.hex"
	@echo 'Finished building: $@'
	@echo ' '

SF2_MKR_KIT_Connection_Test.siz: SF2_MKR_KIT_Connection_Test.elf
	@echo 'Invoking: GNU ARM Cross Print Size'
	arm-none-eabi-size --format=berkeley "SF2_MKR_KIT_Connection_Test.elf"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(OBJS)$(SECONDARY_FLASH)$(SECONDARY_SIZE)$(ASM_DEPS)$(S_UPPER_DEPS)$(C_DEPS) SF2_MKR_KIT_Connection_Test.elf
	-@echo ' '

secondary-outputs: $(SECONDARY_FLASH) $(SECONDARY_SIZE)

.PHONY: all clean dependents

-include ../makefile.targets
