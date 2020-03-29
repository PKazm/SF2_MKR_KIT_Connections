new_project \
         -name {Connection_Test} \
         -location {C:\Users\Phoenix136\Dropbox\FPGA\Microsemi\SF2_MKR_KIT_Connection_Test\designer\Connection_Test/Connection_Test_prbi/Connection_Test_fp} \
         -mode {chain}
add_actel_device \
         -device {M2S010} \
         -name {M2S010}
enable_device \
         -name {M2S010} \
         -enable {TRUE}
save_project
