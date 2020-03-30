/*
 * fab_Nokia5110.h
 *
 *  Created on: Mar 23, 2020
 *      Author: Phoenix136
 */

#ifndef FAB_NOKIA5110_H_
#define FAB_NOKIA5110_H_

#include "cpu_types.h"

#ifdef __cplusplus
extern "C" {
#endif

/*-------------------------------------------------------------------------*//**

 */
//#define Driver_reg_ctrl_ADDR		0x0000000000uL
//#define LCD_reg_func_set_ADDR		0x0000000001uL
//#define LCD_reg_disp_ctrl_ADDR		0x0000000002uL
//#define LCD_reg_temp_ctrl_ADDR		0x0000000003uL
//#define LCD_reg_bias_sys_ADDR		0x0000000004uL
//#define LCD_reg_Vop_set_ADDR		0x0000000005uL
//#define LCD_reg_mem_data_ADDR		0x0000000010uL
//#define LCD_reg_mem_X_ADDR			0x0000000011uL
//#define LCD_reg_mem_Y_ADDR			0x0000000012uL

#define LCD_MAX_X 84
#define LCD_MAX_Y 6



typedef struct nokia_instance
{
    addr_t address;
} nokia_instance_t;

/***************************************************************************//**
  The MSS_UART_irda_init() function is used to initialize the MSS UART instance 
  referenced by the parameter this_uart  for IrDA mode of operation. This 
  function must be called before calling any other IrDA functionality specific 
  functions.

  @param nokia_inst

  @param base_addr

  @param func_set

  @param disp_ctrl

  @param temp_ctrl

  @param bias_sys

  @param Vop_set

  @return
    This function does not return a value.

  Example:
  @code

    #define NOKIA5110_DRIVER_0              0x50000100U

    nokia_instance_t fab_Nokia5110_Driver_0;

    nokia_init(&fab_Nokia5110_Driver_0,
                NOKIA5110_DRIVER_0,
                0b00100000,
                0b00001100,
                0b00000100,
                0b00010011,
                0b10111001);
  @endcode
 */
void nokia_init
(
    nokia_instance_t * nokia_inst,
    addr_t base_addr,
    uint8_t func_set,
    uint8_t disp_ctrl,
    uint8_t temp_ctrl,
    uint8_t bias_sys,
    uint8_t Vop_set
);


uint8_t nokia_get_reg
(
    nokia_instance_t * nokia_inst,
    addr_t reg_adr
);

void nokia_set_reg
(
    nokia_instance_t * nokia_inst,
    addr_t reg_adr,
    uint8_t reg_val
);

uint8_t nokia_get_x
(
    nokia_instance_t * nokia_inst
);

void nokia_set_x
(
    nokia_instance_t * nokia_inst,
    uint8_t reg_val
);

uint8_t nokia_get_y
(
    nokia_instance_t * nokia_inst
);

void nokia_set_y
(
    nokia_instance_t * nokia_inst,
    uint8_t reg_val
);

uint8_t nokia_get_data
(
    nokia_instance_t * nokia_inst
);

void nokia_set_data
(
    nokia_instance_t * nokia_inst,
    uint8_t reg_val
);

uint8_t nokia_get_data_reg
(
	nokia_instance_t * nokia_inst,
	uint8_t reg_x,
	uint8_t reg_y
);

void nokia_set_data_reg
(
    nokia_instance_t * nokia_inst,
    uint8_t reg_x,
    uint8_t reg_y,
    uint8_t reg_data
);

uint8_t nokia_get_driver_ctrl
(
    nokia_instance_t * nokia_inst
);

void nokia_set_driver_ctrl
(
    nokia_instance_t * nokia_inst,
    uint8_t reg_val
);

uint8_t nokia_get_func_set
(
    nokia_instance_t * nokia_inst
);

void nokia_set_func_set
(
    nokia_instance_t * nokia_inst,
    uint8_t reg_val
);

uint8_t nokia_get_disp_ctrl
(
    nokia_instance_t * nokia_inst
);

void nokia_set_disp_ctrl
(
    nokia_instance_t * nokia_inst,
    uint8_t reg_val
);

uint8_t nokia_get_temp_ctrl
(
    nokia_instance_t * nokia_inst
);

void nokia_set_temp_ctrl
(
    nokia_instance_t * nokia_inst,
    uint8_t reg_val
);

uint8_t nokia_get_bias_sys
(
    nokia_instance_t * nokia_inst
);

void nokia_set_bias_sys
(
    nokia_instance_t * nokia_inst,
    uint8_t reg_val
);

uint8_t nokia_get_Vop_set
(
    nokia_instance_t * nokia_inst
);

void nokia_set_Vop_set
(
    nokia_instance_t * nokia_inst,
    uint8_t reg_val
);

void nokia_set_disp_0
(
    nokia_instance_t * nokia_inst
);

void nokia_set_disp_1
(
    nokia_instance_t * nokia_inst
);

uint8_t* nokia_get_pixel_reg_block
(
    nokia_instance_t * nokia_inst,
    uint8_t x_left,
    uint8_t y_top,
    uint8_t x_right,
    uint8_t y_bot
);

void nokia_set_pixel_reg_block
(
    nokia_instance_t * nokia_inst,
    uint8_t x_left,
    uint8_t y_top,
    uint8_t x_len,
    uint8_t y_len,
    uint8_t * pixel_regs
);

uint8_t nokia_get_pixel
(
    nokia_instance_t * nokia_inst,
    uint8_t x,
    uint8_t y
);

void nokia_set_pixel
(
    nokia_instance_t * nokia_inst,
    uint8_t x,
    uint8_t y,
    uint8_t val
);

uint8_t* nokia_get_pixel_block
(
    nokia_instance_t * nokia_inst,
    uint8_t x_left,
    uint8_t y_top,
    uint8_t x_len,
    uint8_t y_len,
);

/***************************************************************************//**
  The nokia_set_pixel_block() function is used to initialize the MSS UART instance 
  referenced by the parameter this_uart  for IrDA mode of operation. This 
  function must be called before calling any other IrDA functionality specific 
  functions.

  @param nokia_inst

  @param x_left

  @param y_top

  @param x_len

  @param y_len

  @param pixel_array
    

  @return
    This function does not return a value.

  Example:
  @code

    #define NOKIA5110_DRIVER_0              0x50000100U

    nokia_instance_t fab_Nokia5110_Driver_0;

    // pixel_array will store 90 bits representing pixels
    uint pixel_array[] = 

    nokia_init(&fab_Nokia5110_Driver_0,
                NOKIA5110_DRIVER_0,
                5, 10,
                10, 9,
                pixel_array);
  @endcode
 */
void nokia_set_pixel_block
(
    nokia_instance_t * nokia_inst,
    uint8_t x_left,
    uint8_t y_top,
    uint8_t x_len,
    uint8_t y_len,
    uint8_t * pixel_array
);

void nokia_set_pixel_block_alpha
(
    nokia_instance_t * nokia_inst,
    uint8_t x_left,
    uint8_t y_top,
    uint8_t x_len,
    uint8_t y_len,
    uint8_t * pixel_array,
    uint8_t * pixel_array_alpha
);

#ifdef __cplusplus
}
#endif

#endif /* SRC_FAB_NOKIA5110_H_ */
