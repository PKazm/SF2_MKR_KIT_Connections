/*
 * main.c
 *
 *  Created on: Mar 23, 2020
 *      Author: Phoenix136
 */

/*-------------------------------------------------------------------------*//**
 * main includes
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../firmware/drivers/mss_uart/mss_uart.h"
#include "../firmware/drivers/mss_gpio/mss_gpio.h"
#include "../firmware/drivers/mss_i2c/mss_i2c.h"
#include "../firmware/drivers/CorePWM/core_pwm.h"
#include "../firmware/drivers/mss_spi/mss_spi.h"
#include "../firmware/CMSIS/system_m2sxxx.h"

#include "../firmware/Connection_Test_hw_platform.h"

// VSC8541_01 functions are declared in the following headers and defined in VSC8541_01_phy.c
#include "../firmware/drivers/mss_ethernet_mac/mss_ethernet_mac_types.h"
#include "../firmware/drivers/mss_ethernet_mac/mss_ethernet_mac.h"
#include "../firmware/drivers/mss_ethernet_mac/phy.h"
//#include "VSC8541_01_phy_regs.h"

#include "fab_Nokia5110.h"
#include "Nokia5110_regs.h"
#include "lcd_characters.h"

#include "LTR_329ALS_01_optical_sensor_i2c.h"

#include "hw_reg_access.h"
#include "../firmware/drivers/CorePWM/corepwm_regs.h"


/*-------------------------------------------------------------------------*//**
 * main definitions
 */
void periph_init(void);
void fab_nokia_test(void);
void report_eth_stat_over_uart(void);

void uart0_rx_int_handler(mss_uart_instance_t *);
void uart_rx_to_nokia_raw(uint8_t *, size_t);
void uart_rx_to_nokia_char(uint8_t *, size_t);
void uart_rx_to_spi_mem(uint8_t *, size_t);

void eth_tx_callback(void * caller_info);
void eth_rx_callback(uint8_t * p_rx_packet, uint32_t pckt_length, void * p_user_data);
char eth_check_address(uint8_t *);

void osense_report_channels(void);

void GPIO8_IRQHandler(void);
void GPIO9_IRQHandler(void);
void GPIO10_IRQHandler(void);


/*-------------------------------------------------------------------------*//**
 * main defines
 */
#define pwm_dat_width 2^32-1

#define RX_BUFF_SIZE    64

#define BUTTON_0_GPIO	MSS_GPIO_8
#define BUTTON_1_GPIO	MSS_GPIO_9

#define BUTTON_0_GPIO_MASK	MSS_GPIO_8_MASK
#define BUTTON_1_GPIO_MASK	MSS_GPIO_9_MASK

#define NOKIA_BUSY_GPIO		MSS_GPIO_10
#define NOKIA_BUSY_GPIO_MASK	MSS_GPIO_10_MASK

#define ETH_PACKET_SIZE                  1514u

#define I2C_0_SLAVE_SER_ADDR   0x10u

/*-------------------------------------------------------------------------*//**
 * main globals
 */

int sample_pos = 0;

int do_light_sensor = 0;


/*------------------------------------------------------------------------------
 * MSS UART instance for UART0
 */
mss_uart_instance_t * const gp_my_uart = &g_mss_uart0;

/*------------------------------------------------------------------------------
 * Fab PWM core
 */
pwm_instance_t fab_corepwm_c0_0;
const pwm_id_t LED_row = PWM_1;
const pwm_id_t LCD_bklt = PWM_2;

/*------------------------------------------------------------------------------
 * Fab Nokia 5110 core
 */
nokia_instance_t fab_Nokia5110_Driver_0;

/*------------------------------------------------------------------------------
 * MSS MAC, Ethernet
 */
mss_mac_cfg_t mac_config;
const static uint8_t mac_address[6] = {0x22, 0x22, 0x22, 0x22, 0x22, 0x22};
volatile uint32_t g_pckt_rcvd_len = 0;

static uint8_t g_mac_tx_buffer[ETH_PACKET_SIZE] = \
      {0x10,0x10,0x10,0x10,0x10,0x10, 0xDE,0xAD,0xBE,0xEF,0xAA,0xAA};
static uint8_t g_mac_rx_buffer[ETH_PACKET_SIZE];

static volatile uint32_t g_mac_tx_buffer_used = 1u;



/*-------------------------------------------------------------------------*//**
 * main main
 */
int main(void){

	periph_init();
	
	fab_nokia_test();

	for(;;){
		if(do_light_sensor == 1){
			/* if you trace back to where do_light_sensor is set to 1
			 * you might wonder why not call osense_report_channels() from inside the GPIO irq
			 * or call it on the rising edge (button press). Well there seems to be a conflict
			 * with interrupts that causes everything to break. Worth investigating for future
			 * projects but I'm proving the I2C bus not interrupt priorities here
			 */
			osense_report_channels();
		}
	}
}

/*-------------------------------------------------------------------------*//**
 * peripheral initialization functions
 */
void periph_init(void){

	/*-------------------------------------------------------------------------*//**
	* MSS_UART
	*/
	MSS_UART_init(
			gp_my_uart,
	        MSS_UART_921600_BAUD,//MSS_UART_115200_BAUD
	        MSS_UART_DATA_8_BITS | MSS_UART_NO_PARITY | MSS_UART_ONE_STOP_BIT
		);
	MSS_UART_enable_irq(
			gp_my_uart,
			MSS_UART_RBF_IRQ
		);
	MSS_UART_set_rx_handler(
			gp_my_uart,
			uart0_rx_int_handler,
			MSS_UART_FIFO_SINGLE_BYTE
		);
	MSS_UART_polled_tx_string(gp_my_uart, (const uint8_t *)"uart initialized!\n\r");

	/*-------------------------------------------------------------------------*//**
	* MSS_GPIO
	*/
	MSS_GPIO_init();
	MSS_GPIO_config(BUTTON_0_GPIO, MSS_GPIO_INPUT_MODE | MSS_GPIO_IRQ_EDGE_POSITIVE);
	MSS_GPIO_config(BUTTON_1_GPIO, MSS_GPIO_INPUT_MODE | MSS_GPIO_IRQ_EDGE_POSITIVE);
	MSS_GPIO_enable_irq(BUTTON_0_GPIO);
	MSS_GPIO_enable_irq(BUTTON_1_GPIO);
	//MSS_GPIO_enable_irq(NOKIA_BUSY_GPIO);
	MSS_GPIO_set_outputs(0x5F);

	MSS_UART_polled_tx_string(gp_my_uart, (const uint8_t *)"gpio initialized!\n\r");

	/*-------------------------------------------------------------------------*//**
	* FAB_PWM
	*/
	PWM_init
		(
			&fab_corepwm_c0_0,
			COREPWM_C0_0,
			1000,
			100
		);
	PWM_set_duty_cycle(&fab_corepwm_c0_0, LED_row, 70);	// LED row is active low
	PWM_set_duty_cycle(&fab_corepwm_c0_0, LCD_bklt, 40);
	//PWM_enable(&fab_corepwm_c0_0, LCD_bklt);
	//PWM_disable(&fab_corepwm_c0_0, LCD_bklt);

	MSS_UART_polled_tx_string(gp_my_uart, (const uint8_t *)"pwm initialized!\n\r");

	/*-------------------------------------------------------------------------*//**
	* FAB_Nokia5110
	*/
	fab_Nokia5110_Driver_0.address = NOKIA5110_DRIVER_0;

	nokia_clear_disp(&fab_Nokia5110_Driver_0, 0x01);

	nokia_set_driver_ctrl
		(
			&fab_Nokia5110_Driver_0,
			0b00000011
		);

	MSS_UART_polled_tx_string(gp_my_uart, (const uint8_t *)"nokia initialized!\n\r");

	/*-------------------------------------------------------------------------*//**
	* MSS_SPI
	*/

	/* SPI clk div of 2 seemed to give accurate data writes but not accurate data reads
	 * SPI clk div of 4 is next lowest valid divider that gives correct data on both
	 * possibly a timing issue with the flash mem read array command but it should be
	 * in range: 100Mhz / 2 = 50Mhz; 50Mhz < 85Mhz for command 0x0B
	 */
	MSS_SPI_init(&g_mss_spi1);
	MSS_SPI_configure_master_mode(
			&g_mss_spi1,
			MSS_SPI_SLAVE_0,
			MSS_SPI_MODE0,
			4u,
			MSS_SPI_BLOCK_TRANSFER_FRAME_SIZE
		);

	MSS_UART_polled_tx_string(gp_my_uart, (const uint8_t *)"spi initialized!\n\r");

	/*-------------------------------------------------------------------------*//**
	* MSS_MAC, VSC8541 PHY, Ethernet stuff
	*/

	/* 100Mhz with 256 divider gives 390.6kHz */
	MSS_I2C_init(&g_mss_i2c0, I2C_0_SLAVE_SER_ADDR, MSS_I2C_PCLK_DIV_256);

	MSS_UART_polled_tx_string(gp_my_uart, (const uint8_t *)"i2c initialized!\n\r");

	osens_i2c_init(&g_mss_i2c0);

	/* gain of 96x almost maxes out CH0 with my phone light pointed directly at it
	 * integration time and measure rate to taste (default is fine for this)
	 */
	osens_i2c_cfg
	(
		&g_mss_i2c0,
		ALS_GAIN_96X,
		ALS_INTGR_TIME_100ms,
		ALS_MEAS_RATE_500ms
	);


	MSS_UART_polled_tx_string(gp_my_uart, (const uint8_t *)"i2c light sens initialized!\n\r");

	/*-------------------------------------------------------------------------*//**
	* MSS_MAC, VSC8541 PHY, Ethernet stuff
	*/
	MSS_MAC_cfg_struct_def_init(&mac_config);
	mac_config.mac_addr[0] = mac_address[0];
    mac_config.mac_addr[1] = mac_address[1];
    mac_config.mac_addr[2] = mac_address[2];
    mac_config.mac_addr[3] = mac_address[3];
    mac_config.mac_addr[4] = mac_address[4];
    mac_config.mac_addr[5] = mac_address[5];
	mac_config.speed_duplex_select = MSS_MAC_ANEG_100M_FD;
	mac_config.phy_addr = 0x00;


	MSS_MAC_init(&mac_config);
    MSS_MAC_receive_pkt(g_mac_rx_buffer, 0);
	MSS_MAC_set_tx_callback(eth_tx_callback);
	MSS_MAC_set_rx_callback(eth_rx_callback);

	MSS_UART_polled_tx_string(gp_my_uart, (const uint8_t *)"mac initialized!\n\r");


	MSS_UART_polled_tx_string(gp_my_uart, (const uint8_t *)"== everything is set up! ==\n\r");



}

void fab_nokia_test(void){
	uint8_t pixel_regs[] = {0x00, 0x7C, 0x12, 0x12, 0x7C, 0x00};
	uint8_t pixel_b_regs[] = {0x00, 0b01111110, 0b01010010, 0b01010010, 0b00101100, 0x00};
	uint8_t pixel_test[] = {
			0x00, 0x88, 0x04, 0xfa, 0xfa, 0x04, 0x88, 0x00,
			0x00, 0x60, 0x11, 0x4a, 0x4a, 0x11, 0x60, 0x00
	};
	uint8_t pixel_b_alpha[] = {0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0};

	uint8_t small_letter_alpha[] = {0b1111111, 0b1111111, 0b1111111, 0b1111111};
	uint8_t small_a[] = {0b011100, 0b001010, 0b011100};
	uint8_t small_b[] = {0b111110, 0b101010, 0b010100};


	uint8_t * temp_pix_ar;

	uint8_t temp;



	MSS_UART_polled_tx_string(gp_my_uart, (const uint8_t *)"Nokia test started!\n\r");


	/*
	* Pixel block tests with data aligned with LCD memory
	*/
	nokia_set_pixel_reg_block
		(
			&fab_Nokia5110_Driver_0,
			19, 1,
			6, 1,
			pixel_regs
		);

	nokia_set_pixel_reg_block
		(
			&fab_Nokia5110_Driver_0,
			19, 3,
			6, 1,
			pixel_b_regs
		);

	nokia_set_pixel_reg_block
		(
			&fab_Nokia5110_Driver_0,
			70, 2,
			8, 2,
			pixel_test
		);

	temp = nokia_get_data_reg
		(
			&fab_Nokia5110_Driver_0,
			20, 3
		);

	/*
	* Pixel setting tests
	*/
	nokia_set_pixel
		(
			&fab_Nokia5110_Driver_0,
			1, 0,
			0
		);
	nokia_set_pixel
		(
			&fab_Nokia5110_Driver_0,
			83, 45,
			0
		);
	nokia_set_pixel
		(
			&fab_Nokia5110_Driver_0,
			26, 26,
			0
		);
	nokia_set_pixel
		(
			&fab_Nokia5110_Driver_0,
			26, 28,
			0
		);
	nokia_set_pixel
		(
			&fab_Nokia5110_Driver_0,
			29, 26,
			1
		);
	temp = nokia_get_pixel
		(
			&fab_Nokia5110_Driver_0,
			1, 1
		);
	temp = nokia_get_pixel
		(
			&fab_Nokia5110_Driver_0,
			1, 0
		);

	/*
	* Pixel block tests with data NOT aligned with LCD memory
	*/
	nokia_set_pixel_block
		(
			&fab_Nokia5110_Driver_0,
			26, 10,
			6, 1,
			pixel_regs
		);

	nokia_set_pixel_block_alpha
		(
			&fab_Nokia5110_Driver_0,
			29, 14,
			6, 1,
			pixel_b_regs,
			pixel_b_alpha
		);

	nokia_set_pixel_block_alpha
		(
			&fab_Nokia5110_Driver_0,
			40, 14,
			3, 1,
			small_a,
			small_letter_alpha
		);
	nokia_set_pixel_block_alpha
		(
			&fab_Nokia5110_Driver_0,
			44, 14,
			3, 1,
			small_b,
			small_letter_alpha
		);

	/*
	* write all characters in my 3x5 library to screen
	*/
	int x_3x5 = 0, y_3x5 = 47-14;
	for(int i = 0; i < ASCII_3x5_SIZE; i++){
		temp_pix_ar = ascii_3x5_with_border(i);
		nokia_set_pixel_block_alpha
		(
			&fab_Nokia5110_Driver_0,
			x_3x5, y_3x5,
			5, 1,
			temp_pix_ar,
			ascii_3x5_get_alpha_border()
		);
		x_3x5 += 4;
		if(x_3x5 + 4 > LCD_MAX_X){
			x_3x5 = 0;
			y_3x5 += 6;
		}
	}

	MSS_UART_polled_tx_string(gp_my_uart, (const uint8_t *)"Nokia test finished!\n\r");
}

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
			break;
			default:
				MSS_UART_polled_tx_string(gp_my_uart, (const uint8_t*)"    nope ");
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

void uart0_rx_int_handler(mss_uart_instance_t * this_uart){
	uint8_t rx_buff[RX_BUFF_SIZE];
	uint32_t rx_idx  = 0;
	size_t rx_size;
	rx_size = MSS_UART_get_rx(this_uart, rx_buff, sizeof(rx_buff));
	//uart_rx_to_nokia_raw(rx_buff, rx_size);
	//uart_rx_to_nokia_char(rx_buff, rx_size);
	uart_rx_to_spi_mem(rx_buff, rx_size);
}

void uart_rx_to_nokia_raw(uint8_t * rx_buff, size_t rx_size){

	int x, y;

	nokia_set_driver_ctrl
		(
			&fab_Nokia5110_Driver_0,
			0b00000001
		);

	for(int i = 0; i < rx_size; i++){
		while(sample_pos >= LCD_MAX_PIXELS){
			sample_pos -= LCD_MAX_PIXELS;
		}
		y = sample_pos / LCD_MAX_X;
		x = sample_pos % LCD_MAX_X;
		nokia_set_data_reg(&fab_Nokia5110_Driver_0, x, y, rx_buff[i]);
		sample_pos++;
	}
	
}

void uart_rx_to_nokia_char(uint8_t * rx_buff, size_t rx_size){
	int x, y, char_index;
	char char_buf[3];
	uint8_t * alpha_num;
	int char_width = 5;
	int char_height = 7;
	int x_slots = (LCD_MAX_X) / (char_width - 1);
	int y_slots = (LCD_MAX_Y * 8) / (char_height - 1);

	nokia_set_driver_ctrl
		(
			&fab_Nokia5110_Driver_0,
			0b00000001
		);

	for(int i = 0; i < rx_size; i++){
		
		itoa(rx_buff[i], char_buf, 10);
		for(int k = 0; k < 3; k++){
			
			y = (sample_pos / x_slots) * (char_height - 1);
			x = (sample_pos % x_slots) * (char_width - 1);
			char_index = ASCII_to_index_3x5(char_buf[k]);
			if(char_index != -1){
				alpha_num = ascii_3x5_with_border(char_index);
				nokia_set_pixel_block_alpha
					(
						&fab_Nokia5110_Driver_0,
						x, y,
						5, 1,
						alpha_num,
						ascii_3x5_get_alpha_border()
					);
			}
			
			sample_pos++;
			if(sample_pos >= x_slots * y_slots){
				sample_pos = 0;
			}
		}
	}
}

void uart_rx_to_spi_mem(uint8_t * rx_buff, size_t rx_size){
	static uint32_t mem_adr = 0;
	const int ovhd_cmd = 4;
	int buf_size = rx_size + ovhd_cmd;

	uint8_t spi_tx_buffer[buf_size];
	spi_tx_buffer[0] = 0x02;			// cmd byte/page program
	spi_tx_buffer[1] = (mem_adr >> 16) & 0xFF;	// upper byte of address24 in flash mem
	spi_tx_buffer[2] = (mem_adr >> 8) & 0xFF;	// middle byte of address24 in flash mem
	spi_tx_buffer[3] = mem_adr & 0xFF;			// lower byte of address24 in flash mem
	for(int i = 0; i < rx_size; i++){
		spi_tx_buffer[i + ovhd_cmd] = rx_buff[i];
	}

	MSS_SPI_set_slave_select( &g_mss_spi1, MSS_SPI_SLAVE_0 );
	MSS_SPI_transfer_frame(&g_mss_spi1, 0x06);      // cmd: flash mem write enable
	MSS_SPI_transfer_block(
				&g_mss_spi1,
				spi_tx_buffer,
				sizeof(spi_tx_buffer),
				0, 0
			);

	//MSS_SPI_transfer_frame(&g_mss_spi1, 0x04);      // cmd: flash mem write disable

	mem_adr += rx_size;
	
	MSS_SPI_clear_slave_select( &g_mss_spi1, MSS_SPI_SLAVE_0 );
}

void eth_tx_callback(void * caller_info){
	*((uint32_t *)caller_info) = 0;
}

void eth_rx_callback(
	uint8_t * p_rx_packet,
	uint32_t pckt_length,
	void * p_user_data
)
{
	if(1 == eth_check_address(p_rx_packet)){
		
		char buffer[128];
		snprintf(buffer, sizeof(buffer), "\n\rRX pkt size = %d\r\n", (int)pckt_length);
		MSS_UART_polled_tx_string(gp_my_uart, (const uint8_t *)"========================\n\r");
		MSS_UART_polled_tx_string(gp_my_uart, (const uint8_t *)"Ethernet packet received\n\r");
		MSS_UART_polled_tx_string(gp_my_uart, (const uint8_t *)buffer);

		
		//MSS_MAC_send_pkt(g_mac_tx_buffer, 64u, (void *)&g_mac_tx_buffer_used);
		/*
		for(int i = 0; i < pckt_length; i++){
			snprintf(buffer, sizeof(buffer), "%i", p_rx_packet[i]);
			MSS_UART_polled_tx_string(gp_my_uart, (const uint8_t *)buffer);
		}
		*/
		
		MSS_UART_polled_tx_string(gp_my_uart, (const uint8_t *)"\n\rDATA DONE\n\r");
		MSS_UART_polled_tx_string(gp_my_uart, (const uint8_t *)"========================\n\r");

		
	}
	MSS_MAC_receive_pkt(g_mac_rx_buffer, 0);

}

char eth_check_address(uint8_t * packet_data){
	/* Check Destination address */
	if(packet_data[30] == 169 && packet_data[31] == 254 && packet_data[32] == 255 && packet_data[33] == 255){
		/* Check Destination port */
		if(packet_data[36] == 0xBE && packet_data[37] == 0xEF){
			return 1;
		}
	}
	return 0;
}

void osense_report_channels(void){

	uint8_t * i2c_osens_ch_buf;
	char buffer[128];
	uint16_t cmb_ch;

	i2c_osens_ch_buf = osens_i2c_get_channel_data(&g_mss_i2c0);

	cmb_ch = i2c_osens_ch_buf[3] << 8 | i2c_osens_ch_buf[2];
	snprintf(buffer, sizeof(buffer), "====\n\rosens CH0 = %d\r\n", (int)cmb_ch);
	MSS_UART_polled_tx_string(gp_my_uart, (const uint8_t *)buffer);
	
	cmb_ch = i2c_osens_ch_buf[1] << 8 | i2c_osens_ch_buf[0];
	snprintf(buffer, sizeof(buffer), "====\n\rosens CH1 = %d\r\n", (int)cmb_ch);
	MSS_UART_polled_tx_string(gp_my_uart, (const uint8_t *)buffer);

	do_light_sensor = 0;
}

/*-------------------------------------------------------------------------*//**
 * GPIO8_IRQHandler() clears the Nokia 5110 Screen
 * toggles between setting display all 0 or all 1
 */
void GPIO8_IRQHandler(void){
	static char disp_value = 0;

	// MSS_GPIO_IRQ_EDGE_POSITIVE DOES NOTHING! check if input is high (button currently down)
	uint32_t gpio_inputs;
	gpio_inputs = MSS_GPIO_get_inputs();
	gpio_inputs &= MSS_GPIO_8_MASK;

	if(gpio_inputs != 0){
		nokia_clear_disp(&fab_Nokia5110_Driver_0, disp_value);
		disp_value = ~disp_value;
		sample_pos = 0;

		MSS_SPI_set_slave_select( &g_mss_spi1, MSS_SPI_SLAVE_0 );
		uint8_t erase_cmd_buf[] = {0x20, 0x00, 0x00, 0x00};
		MSS_SPI_transfer_frame(&g_mss_spi1, 0x06);      // cmd: flash mem write enable
		MSS_SPI_transfer_block(
				&g_mss_spi1,
				erase_cmd_buf,
				sizeof(erase_cmd_buf),
				0, 0
			);
		MSS_SPI_clear_slave_select( &g_mss_spi1, MSS_SPI_SLAVE_0 );

		report_eth_stat_over_uart();
	}

	MSS_GPIO_clear_irq(MSS_GPIO_8);
}

/*-------------------------------------------------------------------------*//**
 * GPIO9_IRQHandler()
 * reads data out of SPI flash mem and transmits over uart
 * also reads optical sensor channels and transmits over uart
 */
void GPIO9_IRQHandler(void){
	uint32_t gpio_inputs;
	static uint8_t count = 0;
	char count_str[3];

	uint8_t spi_tx_buffer[5];
	spi_tx_buffer[0] = 0x0B;	// cmd flash mem read array
	spi_tx_buffer[1] = 0x00;	// upper byte of address24 in flash mem
	spi_tx_buffer[2] = 0x00;	// middle byte of address24 in flash mem
	spi_tx_buffer[3] = 0x00;	// lower byte of address24 in flash mem
	spi_tx_buffer[4] = 0x00;	// cmd dummy byte required by 0x0B

	uint8_t spi_rx_buffer[16];

	// tracks how many times interrupt is triggered
	itoa(count++, count_str, 10);
	MSS_UART_polled_tx_string(gp_my_uart, count_str);

	gpio_inputs = MSS_GPIO_get_inputs();
	gpio_inputs &= MSS_GPIO_9_MASK;

	if(gpio_inputs == 0){
		MSS_UART_polled_tx_string(gp_my_uart, (const uint8_t *)" Pin 9 is low\n\r");
		
		do_light_sensor = 1;
	}
	else{
		MSS_UART_polled_tx_string(gp_my_uart, (const uint8_t *)" Pin 9 is high\n\r");
		// if pressed, export Flash Mem SPI data
		MSS_SPI_set_slave_select( &g_mss_spi1, MSS_SPI_SLAVE_0 );
		MSS_SPI_transfer_block(
				&g_mss_spi1,
				spi_tx_buffer,
				sizeof(spi_tx_buffer),
				spi_rx_buffer,
				sizeof(spi_rx_buffer)
			);

		for(int i = 0; i < sizeof(spi_rx_buffer); i++){
			MSS_UART_polled_tx_string(gp_my_uart, (const uint8_t *)"adr: ");
			itoa(i, count_str, 10);
			MSS_UART_polled_tx_string(gp_my_uart, count_str);
			MSS_UART_polled_tx_string(gp_my_uart, (const uint8_t *)" = ");
			itoa(spi_rx_buffer[i], count_str, 10);
			MSS_UART_polled_tx_string(gp_my_uart, count_str);
			MSS_UART_polled_tx_string(gp_my_uart, (const uint8_t *)"\n\r");
		}
		MSS_SPI_clear_slave_select( &g_mss_spi1, MSS_SPI_SLAVE_0 );
	}
	MSS_GPIO_clear_irq(MSS_GPIO_9);
}

/*-------------------------------------------------------------------------*//**
 * GPIO10_IRQHandler() responds to Nokia 5110 Busy signal
 * Probably not going to do anything.
 */
void GPIO10_IRQHandler(void){
	MSS_GPIO_clear_irq(MSS_GPIO_10);
}
