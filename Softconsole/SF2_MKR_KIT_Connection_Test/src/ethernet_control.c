
#include "../firmware/drivers/mss_ethernet_mac/mss_ethernet_mac_types.h"
#include "../firmware/drivers/mss_ethernet_mac/mss_ethernet_mac.h"
#include "../firmware/drivers/mss_ethernet_mac/phy.h"

#include "ethernet_control.h"

void report_eth_stat_over_uart(void){
	uint8_t link_status;
    mss_mac_speed_t speed;
    uint8_t fullduplex;

	link_status = MSS_MAC_phy_get_link_status(&speed, &fullduplex);
	MSS_UART_polled_tx_string(gp_my_uart, (const uint8_t *)"Link is: ");
	if(link_status == MSS_MAC_LINK_UP){
		MSS_UART_polled_tx_string(gp_my_uart, (const uint8_t *)"UP!\r\n");
		switch(speed)
		{
			case MSS_MAC_10MBPS:
				MSS_UART_polled_tx_string(gp_my_uart, (const uint8_t*)"    10Mbps ");
			break;

			case MSS_MAC_100MBPS:
				MSS_UART_polled_tx_string(gp_my_uart, (const uint8_t*)"    100Mbps ");
			break;
			case MSS_MAC_1000MBPS:
				MSS_UART_polled_tx_string(gp_my_uart, (const uint8_t*)"    1000Mbps ");
			default:
			break;
		}
		if(1u == fullduplex)
		{
			MSS_UART_polled_tx_string(gp_my_uart, (const uint8_t*)"Full Duplex\r\n");
		}
		else
		{
			MSS_UART_polled_tx_string(gp_my_uart, (const uint8_t*)"Half Duplex\r\n");
		}
	}
	else{
		MSS_UART_polled_tx_string(gp_my_uart, (const uint8_t *)"DOWN!\r\n");
	}


}