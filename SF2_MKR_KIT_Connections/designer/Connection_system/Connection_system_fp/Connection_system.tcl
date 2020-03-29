open_project -project {E:\Github_Repos\SF2_MKR_KIT_Connections\SF2_MKR_KIT_Connections\designer\Connection_system\Connection_system_fp\Connection_system.pro}
enable_device -name {M2S010} -enable 1
set_programming_file -name {M2S010} -file {E:\Github_Repos\SF2_MKR_KIT_Connections\SF2_MKR_KIT_Connections\designer\Connection_system\Connection_system.ppd}
set_programming_action -action {PROGRAM} -name {M2S010} 
run_selected_actions
set_programming_file -name {M2S010} -no_file
save_project
close_project
