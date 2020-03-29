save
set st_prbi {C:\Users\Phoenix136\Dropbox\FPGA\Microsemi\SF2_MKR_KIT_Connection_Test\designer\Connection_Test/Connection_Test_prbi/Connection_Test_st_prbi.rpt}
set fp [open $st_prbi w]
puts $fp [list_paths -from { CoreAPB3_C0_0/CoreAPB3_C0_0/iPSELS_raw[0]:Y } -to { Probe_Insert0 }]
puts $fp [list_paths -from { CoreAPB3_C0_0/CoreAPB3_C0_0/iPSELS_raw_RNO[0]:Y } -to { Probe_Insert1 }]
close $fp
