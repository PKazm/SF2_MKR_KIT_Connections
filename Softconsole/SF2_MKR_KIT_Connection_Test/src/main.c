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

#include "fab_Nokia5110.h"
#include "Nokia5110_regs.h"
#include "lcd_characters.h"


#include "hw_reg_access.h"
#include "../firmware/drivers/CorePWM/corepwm_regs.h"


/*-------------------------------------------------------------------------*//**
 * main definitions
 */
void periph_init(void);
void mss_uart_init(uint32_t);
void fab_pwm_init(void);
void mss_gpio_init(void);
void fab_nokia_init(void);
void fab_nokia_test(void);

void uart0_rx_int_handler(mss_uart_instance_t *);
void uart_rx_to_nokia_raw(uint8_t *, size_t);
void uart_rx_to_nokia_char(uint8_t *, size_t);
void uart_rx_to_spi_mem(uint8_t *, size_t);

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

/*-------------------------------------------------------------------------*//**
 * main globals
 */

int sample_pos = 0;

/*------------------------------------------------------------------------------
 * MSS UART instance for UART0
 */
mss_uart_instance_t * const gp_my_uart = &g_mss_uart0;

pwm_instance_t fab_corepwm_c0_0;
pwm_id_t LCD_bklt;
pwm_id_t LED_row;

nokia_instance_t fab_Nokia5110_Driver_0;




/*-------------------------------------------------------------------------*//**
 * main main
 */
int main(void){

	periph_init();
	
	fab_nokia_test();

	while(1);
}

/*-------------------------------------------------------------------------*//**
 * peripheral initialization functions
 */
void periph_init(void){

	/*-------------------------------------------------------------------------*//**
	* MSS_UART
	*/
	mss_uart_init(MSS_UART_921600_BAUD);//MSS_UART_115200_BAUD
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
	mss_gpio_init();

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
	LED_row = PWM_1;
	LCD_bklt = PWM_2;
	fab_pwm_init();

	/*-------------------------------------------------------------------------*//**
	* FAB_Nokia5110
	*/
	fab_nokia_init();

	/*-------------------------------------------------------------------------*//**
	* MSS_SPI
	*/
	MSS_SPI_init(&g_mss_spi1);
	MSS_SPI_configure_master_mode(
			&g_mss_spi1,
			MSS_SPI_SLAVE_0,
			MSS_SPI_MODE0,
			4u,
			MSS_SPI_BLOCK_TRANSFER_FRAME_SIZE
		);

}

void mss_uart_init(uint32_t baudrate){
	MSS_UART_init(
			gp_my_uart,
	        baudrate,
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
}

void fab_pwm_init(void){

	PWM_set_duty_cycle(&fab_corepwm_c0_0, LED_row, 70);	// LED row is active low
	PWM_set_duty_cycle(&fab_corepwm_c0_0, LCD_bklt, 40);
	//PWM_enable(&fab_corepwm_c0_0, LCD_bklt);
	//PWM_disable(&fab_corepwm_c0_0, LCD_bklt);
}

void mss_gpio_init(void){

	MSS_GPIO_set_outputs(0x5F);
}

void fab_nokia_init(void){


	fab_Nokia5110_Driver_0.address = NOKIA5110_DRIVER_0;


	nokia_clear_disp(&fab_Nokia5110_Driver_0, 0x01);

	nokia_set_driver_ctrl
		(
			&fab_Nokia5110_Driver_0,
			0b00000011
		);


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
	}
	MSS_GPIO_clear_irq(MSS_GPIO_8);
}

/*-------------------------------------------------------------------------*//**
 * GPIO9_IRQHandler() clears the Nokia 5110 Screen to all 1
 * until I find something more interesting
 * (send memory block to computer over UART?)
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
