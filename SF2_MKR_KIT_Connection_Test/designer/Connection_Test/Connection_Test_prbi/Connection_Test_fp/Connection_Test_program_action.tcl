open_project -project {C:\Users\Phoenix136\Dropbox\FPGA\Microsemi\SF2_MKR_KIT_Connection_Test\designer\Connection_Test/Connection_Test_prbi/Connection_Test_fp/Connection_Test.pro}
set_programming_file \
    -name {M2S010} \
    -file {C:\Users\Phoenix136\Dropbox\FPGA\Microsemi\SF2_MKR_KIT_Connection_Test\designer\Connection_Test/Connection_Test_prbi/Connection_Test.ipd} 
enable_device \
    -name {M2S010} \
    -enable {1} 
set_programming_action \
    -name {M2S010} \
    -action {PROGRAM} 
catch {run_selected_actions} return_val
set_programming_file \
    -name {M2S010} \
    -no_file
save_project
close_project
if {$return_val != 0} {exit 1}
