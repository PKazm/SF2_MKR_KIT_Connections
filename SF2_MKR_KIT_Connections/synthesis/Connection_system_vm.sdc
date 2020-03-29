# Written by Synplify Pro version mapact, Build 2461R. Synopsys Run ID: sid1585468192 
# Top Level Design Parameters 

# Clocks 
create_clock -period 10.000 -waveform {0.000 5.000} -name {Connection_system_sb_CCC_0_FCCC|GL0_net_inferred_clock} [get_pins {Connection_system_sb_0/CCC_0/CCC_INST/GL0}] 
create_clock -period 10.000 -waveform {0.000 5.000} -name {timerZ1|timer_clock_out_sig_inferred_clock} [get_pins {Nokia5110_Driver_0/SPI_timer/timer_clock_out_sig/Q}] 
create_clock -period 10.000 -waveform {0.000 5.000} -name {Connection_system|GMII_RX_CLK} [get_ports {GMII_RX_CLK}] 
create_clock -period 10.000 -waveform {0.000 5.000} -name {Connection_system_sb_CCC_0_FCCC|GL1_net_inferred_clock} [get_pins {Connection_system_sb_0/CCC_0/CCC_INST/GL1}] 
create_clock -period 10.000 -waveform {0.000 5.000} -name {Connection_system|BIBUF_1_Y_inferred_clock} [get_pins {BIBUF_1/Y}] 

# Virtual Clocks 

# Generated Clocks 

# Paths Between Clocks 

# Multicycle Constraints 

# Point-to-point Delay Constraints 

# False Path Constraints 

# Output Load Constraints 

# Driving Cell Constraints 

# Input Delay Constraints 

# Output Delay Constraints 

# Wire Loads 

# Other Constraints 

# syn_hier Attributes 

# set_case Attributes 

# Clock Delay Constraints 
set Inferred_clkgroup_0 [list Connection_system_sb_CCC_0_FCCC|GL0_net_inferred_clock]
set Inferred_clkgroup_1 [list timerZ1|timer_clock_out_sig_inferred_clock]
set Inferred_clkgroup_2 [list Connection_system|GMII_RX_CLK]
set Inferred_clkgroup_3 [list Connection_system_sb_CCC_0_FCCC|GL1_net_inferred_clock]
set Inferred_clkgroup_4 [list Connection_system|BIBUF_1_Y_inferred_clock]
set_clock_groups -asynchronous -group $Inferred_clkgroup_0
set_clock_groups -asynchronous -group $Inferred_clkgroup_1
set_clock_groups -asynchronous -group $Inferred_clkgroup_2
set_clock_groups -asynchronous -group $Inferred_clkgroup_3
set_clock_groups -asynchronous -group $Inferred_clkgroup_4


# syn_mode Attributes 

# Cells 

# Port DRC Rules 

# Input Transition Constraints 

# Unused constraints (intentionally commented out) 

# Non-forward-annotatable constraints (intentionally commented out) 

# Block Path constraints 
