set_component Connection_system_sb_MSS
# Microsemi Corp.
# Date: 2020-Mar-29 03:20:59
#

create_clock -period 40 [ get_pins { MSS_ADLIB_INST/CLK_CONFIG_APB } ]
set_false_path -ignore_errors -through [ get_pins { MSS_ADLIB_INST/CONFIG_PRESET_N } ]
