new_project \
         -name {Connection_system} \
         -location {E:\Github_Repos\SF2_MKR_KIT_Connections\SF2_MKR_KIT_Connections\designer\Connection_system\Connection_system_fp} \
         -mode {chain} \
         -connect_programmers {FALSE}
add_actel_device \
         -device {M2S010} \
         -name {M2S010}
enable_device \
         -name {M2S010} \
         -enable {TRUE}
save_project
close_project
