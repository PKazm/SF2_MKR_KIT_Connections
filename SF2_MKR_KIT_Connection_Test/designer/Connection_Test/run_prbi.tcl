add_prb \
         -net    {iPSELS_raw[0]} \
         -port   {Probe_Insert0} \
         -pkgpin {83} \
         -fam    {PA4M}
add_prb \
         -net    {CoreAPB3_C0_0/CoreAPB3_C0_0/CoreAPB3_C0_0_APBmslave0_PSELx_i_2} \
         -port   {Probe_Insert1} \
         -pkgpin {4} \
         -fam    {PA4M}
prbi \
         -desdir {C:\Users\Phoenix136\Dropbox\FPGA\Microsemi\SF2_MKR_KIT_Connection_Test\designer\Connection_Test} \
         -design {Connection_Test} \
         -fam {PA4M} \
         -die {PA4M1000_N} \
         -pkg {tq144} \
         -use_debug {0} \
         -init_lock_file {}
