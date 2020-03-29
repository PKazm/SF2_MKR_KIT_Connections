/*
 * main.c
 *
 *  Created on: Mar 23, 2020
 *      Author: Phoenix136
 */

/*-------------------------------------------------------------------------*//**
 * main includes
 */
#include "../firmware/drivers/mss_uart/mss_uart.h"
#include "../firmware/drivers/mss_gpio/mss_gpio.h"
#include "../firmware/drivers/mss_i2c/mss_i2c.h"
#include "../firmware/drivers/CorePWM/core_pwm.h"
#include "../firmware/CMSIS/system_m2sxxx.h"

#include "../firmware/Connection_Test_hw_platform.h"

#include "fab_Nokia5110.h"
#include "Nokia5110_regs.h"


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

/*-------------------------------------------------------------------------*//**
 * main defines
 */
#define pwm_dat_width 2^32-1

/*-------------------------------------------------------------------------*//**
 * main globals
 */

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
	mss_uart_init(MSS_UART_921600_BAUD);
	MSS_UART_polled_tx_string(gp_my_uart, (const uint8_t *)"uart initialized!\n\r");
	fab_pwm_init();
	mss_gpio_init();

	fab_nokia_init();

	fab_nokia_test();





	//for(;;){

	//}
	while(1);
}

/*-------------------------------------------------------------------------*//**
 * peripheral initialization functions
 */
void periph_init(void){

	MSS_GPIO_init();
	MSS_GPIO_enable_irq(MSS_GPIO_8);
	MSS_GPIO_enable_irq(MSS_GPIO_9);

	PWM_init
		(
			&fab_corepwm_c0_0,
			COREPWM_C0_0,
			1000,
			100
		);
	LED_row = PWM_1;
	LCD_bklt = PWM_2;


}

void mss_uart_init(uint32_t baudrate){
	MSS_UART_init(gp_my_uart,
	                   baudrate,
	                   MSS_UART_DATA_8_BITS | MSS_UART_NO_PARITY | MSS_UART_ONE_STOP_BIT);
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

	for(int k = 0; k < LCD_MAX_Y; k++){
		nokia_set_y(&fab_Nokia5110_Driver_0, k);
		for(int i = 0; i < LCD_MAX_X; i++){
			nokia_set_x(&fab_Nokia5110_Driver_0, i);
			nokia_set_data(&fab_Nokia5110_Driver_0, 0xFF);
		}
	}

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
	uint8_t temp;



	MSS_UART_polled_tx_string(gp_my_uart, (const uint8_t *)"Nokia test started!\n\r");

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
			28, 2,
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

	MSS_UART_polled_tx_string(gp_my_uart, (const uint8_t *)"Nokia test finished!\n\r");
}