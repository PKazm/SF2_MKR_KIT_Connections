open_project -project {C:\Users\Phoenix136\Dropbox\FPGA\Microsemi\SF2_MKR_KIT_Connection_Test\designer\Connection_Test/Connection_Test_prbi/Connection_Test_fp/Connection_Test.pro}
load_programming_data \
    -name {M2S010} \
    -fpga {C:\Users\Phoenix136\Dropbox\FPGA\Microsemi\SF2_MKR_KIT_Connection_Test\designer\Connection_Test/Connection_Test_prbi/Connection_Test.map} \
    -dca {C:\Users\Phoenix136\Dropbox\FPGA\Microsemi\SF2_MKR_KIT_Connection_Test\designer\Connection_Test/Connection_Test_prbi/Connection_Test.dca} \
    -header {C:\Users\Phoenix136\Dropbox\FPGA\Microsemi\SF2_MKR_KIT_Connection_Test\designer\Connection_Test/Connection_Test_prbi/Connection_Test.hdr} \
    -spm {C:\Users\Phoenix136\Dropbox\FPGA\Microsemi\SF2_MKR_KIT_Connection_Test\designer\Connection_Test/Connection_Test_prbi/Connection_Test.spm}  \
    -gen_bitstream
set_programming_file -name {M2S010} -no_file
save_project
close_project
