set_family {SmartFusion2}
read_vhdl -mode vhdl_2008 {C:\Users\Phoenix136\Dropbox\FPGA\Microsemi\SF2_MKR_KIT_Connection_Test\component\work\Connection_Test_sb\CCC_0\Connection_Test_sb_CCC_0_FCCC.vhd}
read_vhdl -mode vhdl_2008 {C:\Users\Phoenix136\Dropbox\FPGA\Microsemi\SF2_MKR_KIT_Connection_Test\component\work\Connection_Test_sb\FABOSC_0\Connection_Test_sb_FABOSC_0_OSC.vhd}
read_vhdl -mode vhdl_2008 {C:\Users\Phoenix136\Dropbox\FPGA\Microsemi\SF2_MKR_KIT_Connection_Test\component\work\Connection_Test_sb_MSS\Connection_Test_sb_MSS.vhd}
read_vhdl -mode vhdl_2008 {C:\Users\Phoenix136\Dropbox\FPGA\Microsemi\SF2_MKR_KIT_Connection_Test\component\Actel\DirectCore\CoreResetP\7.1.100\rtl\vhdl\core\coreresetp_pcie_hotreset.vhd}
read_vhdl -mode vhdl_2008 {C:\Users\Phoenix136\Dropbox\FPGA\Microsemi\SF2_MKR_KIT_Connection_Test\component\Actel\DirectCore\CoreResetP\7.1.100\rtl\vhdl\core\coreresetp.vhd}
read_vhdl -mode vhdl_2008 {C:\Users\Phoenix136\Dropbox\FPGA\Microsemi\SF2_MKR_KIT_Connection_Test\component\work\Connection_Test_sb\Connection_Test_sb.vhd}
read_vhdl -mode vhdl_2008 -lib COREAPB3_LIB {C:\Users\Phoenix136\Dropbox\FPGA\Microsemi\SF2_MKR_KIT_Connection_Test\component\Actel\DirectCore\CoreAPB3\4.1.100\rtl\vhdl\core\coreapb3_muxptob3.vhd}
read_vhdl -mode vhdl_2008 -lib COREAPB3_LIB {C:\Users\Phoenix136\Dropbox\FPGA\Microsemi\SF2_MKR_KIT_Connection_Test\component\Actel\DirectCore\CoreAPB3\4.1.100\rtl\vhdl\core\coreapb3_iaddr_reg.vhd}
read_vhdl -mode vhdl_2008 -lib COREAPB3_LIB {C:\Users\Phoenix136\Dropbox\FPGA\Microsemi\SF2_MKR_KIT_Connection_Test\component\Actel\DirectCore\CoreAPB3\4.1.100\rtl\vhdl\core\coreapb3.vhd}
read_vhdl -mode vhdl_2008 -lib COREAPB3_LIB {C:\Users\Phoenix136\Dropbox\FPGA\Microsemi\SF2_MKR_KIT_Connection_Test\component\Actel\DirectCore\CoreAPB3\4.1.100\rtl\vhdl\core\components.vhd}
read_vhdl -mode vhdl_2008 {C:\Users\Phoenix136\Dropbox\FPGA\Microsemi\SF2_MKR_KIT_Connection_Test\component\work\CoreAPB3_C0\CoreAPB3_C0.vhd}
read_vhdl -mode vhdl_2008 {C:\Users\Phoenix136\Dropbox\FPGA\My_Stuff\Standalone Files\LED_inverter_dimmer.vhd}
read_vhdl -mode vhdl_2008 -lib COREPWM_LIB {C:\Users\Phoenix136\Dropbox\FPGA\Microsemi\SF2_MKR_KIT_Connection_Test\component\Actel\DirectCore\corepwm\4.3.101\rtl\vhdl\core\tach_if.vhd}
read_vhdl -mode vhdl_2008 -lib COREPWM_LIB {C:\Users\Phoenix136\Dropbox\FPGA\Microsemi\SF2_MKR_KIT_Connection_Test\component\Actel\DirectCore\corepwm\4.3.101\rtl\vhdl\core\pwm_gen.vhd}
read_vhdl -mode vhdl_2008 -lib COREPWM_LIB {C:\Users\Phoenix136\Dropbox\FPGA\Microsemi\SF2_MKR_KIT_Connection_Test\component\Actel\DirectCore\corepwm\4.3.101\rtl\vhdl\core\reg_if.vhd}
read_vhdl -mode vhdl_2008 -lib COREPWM_LIB {C:\Users\Phoenix136\Dropbox\FPGA\Microsemi\SF2_MKR_KIT_Connection_Test\component\Actel\DirectCore\corepwm\4.3.101\rtl\vhdl\core\timebase.vhd}
read_vhdl -mode vhdl_2008 -lib COREPWM_LIB {C:\Users\Phoenix136\Dropbox\FPGA\Microsemi\SF2_MKR_KIT_Connection_Test\component\Actel\DirectCore\corepwm\4.3.101\rtl\vhdl\core\t_corepwm_pkg.vhd}
read_vhdl -mode vhdl_2008 -lib COREPWM_LIB {C:\Users\Phoenix136\Dropbox\FPGA\Microsemi\SF2_MKR_KIT_Connection_Test\component\Actel\DirectCore\corepwm\4.3.101\rtl\vhdl\core\corepwm.vhd}
read_vhdl -mode vhdl_2008 -lib COREPWM_LIB {C:\Users\Phoenix136\Dropbox\FPGA\Microsemi\SF2_MKR_KIT_Connection_Test\component\Actel\DirectCore\corepwm\4.3.101\rtl\vhdl\core\components.vhd}
read_vhdl -mode vhdl_2008 {C:\Users\Phoenix136\Dropbox\FPGA\Microsemi\SF2_MKR_KIT_Connection_Test\component\work\corepwm_C0\corepwm_C0.vhd}
read_vhdl -mode vhdl_2008 {C:\Users\Phoenix136\Dropbox\FPGA\My_Stuff\Standalone Files\timer.vhd}
read_vhdl -mode vhdl_2008 {C:\Users\Phoenix136\Dropbox\FPGA\Microsemi\SF2_MKR_KIT_Connection_Test\hdl\Nokia5110_Driver.vhd}
read_vhdl -mode vhdl_2008 {C:\Users\Phoenix136\Dropbox\FPGA\Microsemi\SF2_MKR_KIT_Connection_Test\component\work\Connection_Test\Connection_Test.vhd}
set_top_level {Connection_Test}
map_netlist
check_constraints {C:\Users\Phoenix136\Dropbox\FPGA\Microsemi\SF2_MKR_KIT_Connection_Test\constraint\synthesis_sdc_errors.log}
write_fdc {C:\Users\Phoenix136\Dropbox\FPGA\Microsemi\SF2_MKR_KIT_Connection_Test\designer\Connection_Test\synthesis.fdc}
