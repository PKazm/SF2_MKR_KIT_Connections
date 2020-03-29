set_component Connection_Test_sb_MSS
# Microsemi Corp.
# Date: 2020-Mar-26 00:14:16
#

create_clock -period 40 [ get_pins { MSS_ADLIB_INST/CLK_CONFIG_APB } ]
set_false_path -ignore_errors -through [ get_pins { MSS_ADLIB_INST/CONFIG_PRESET_N } ]
