open_project -project {C:\Users\Phoenix136\Dropbox\FPGA\Microsemi\SF2_MKR_KIT_Connection_Test\designer\Connection_Test\Connection_Test_fp\Connection_Test.pro}
enable_device -name {M2S010} -enable 1
set_programming_file -name {M2S010} -file {C:\Users\Phoenix136\Dropbox\FPGA\Microsemi\SF2_MKR_KIT_Connection_Test\designer\Connection_Test\Connection_Test.ppd}
set_programming_action -action {PROGRAM} -name {M2S010} 
run_selected_actions
set_programming_file -name {M2S010} -no_file
save_project
close_project
