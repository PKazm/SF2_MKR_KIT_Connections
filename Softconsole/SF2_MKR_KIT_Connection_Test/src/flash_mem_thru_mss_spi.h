
#include "cpu_types.h"

#include "../firmware/drivers/mss_spi/mss_spi.h"

/*
void flash_mem_write_block
(
    mss_spi_instance_t * mss_spi,
    uint8_t * rx_buff,
    size_t rx_size
)
{
    uint32_t mem_adr = 0;
    uint8_t spi_page_program_start_buf = {  0x02,
                                            (mem_adr >> 16) & 0xFF,
                                            (mem_adr >> 8) & 0xFF,
                                            mem_adr & 0xFF,
                                            rx_buff[0]
                                        };

    MSS_SPI_transfer_frame(&mss_spi, 0x06);      // cmd: flash mem write enable
    MSS_SPI_transfer_block(
            &mss_spi,
            spi_page_program_start_buf,
            sizeof(spi_page_program_start_buf),
            0, 0
        );

    for(int i = 1; i < rx_size; i++){
        MSS_SPI_transfer_frame(&mss_spi, rx_buff[i]);
        while(0){
            
        }
    }


    MSS_SPI_transfer_frame(&mss_spi, 0x04);      // cmd: flash mem write disable
}
*/
