/*
 * fab_Nokia5110.c
 *
 *  Created on: Mar 23, 2020
 *      Author: Phoenix136
 */

#include "fab_Nokia5110.h"
#include "Nokia5110_regs.h"
#include "hal.h"
#include "hal_assert.h"
//#include "hw_reg_access.h"

#ifdef __cplusplus
extern "C" {
#endif

void nokia_init
(
    nokia_instance_t * nokia_inst,
    addr_t base_addr,
    uint8_t func_set,
    uint8_t disp_ctrl,
    uint8_t temp_ctrl,
    uint8_t bias_sys,
    uint8_t Vop_set
)
{
    nokia_inst->address = base_addr;
    nokia_set_reg
        (
            nokia_inst,
			func_set_REG_OFFSET,
            func_set
        );
    nokia_set_reg
        (
            nokia_inst,
			disp_ctrl_REG_OFFSET,
            disp_ctrl
        );
    nokia_set_reg
        (
            nokia_inst,
			temp_ctrl_REG_OFFSET,
            temp_ctrl
        );
    nokia_set_reg
        (
            nokia_inst,
			bias_sys_REG_OFFSET,
            bias_sys
        );
    nokia_set_reg
        (
            nokia_inst,
			Vop_set_REG_OFFSET,
            Vop_set
        );
}

uint8_t nokia_get_reg(
    nokia_instance_t * nokia_inst,
    addr_t reg_adr
)
{
    return HW_get_8bit_reg(nokia_inst->address + reg_adr);
}

void nokia_set_reg(
    nokia_instance_t * nokia_inst,
    addr_t reg_adr,
    uint8_t reg_val
)
{
    HW_set_8bit_reg(nokia_inst->address + reg_adr, reg_val);
}


uint8_t nokia_get_x
(
    nokia_instance_t * nokia_inst
)
{
    return HW_get_8bit_reg(nokia_inst->address + mem_x_REG_OFFSET);
}


void nokia_set_x
(
    nokia_instance_t * nokia_inst,
    uint8_t reg_val
)
{
    HW_set_8bit_reg( nokia_inst->address + mem_x_REG_OFFSET, reg_val );
}

uint8_t nokia_get_y
(
    nokia_instance_t * nokia_inst
)
{
    return HW_get_8bit_reg(nokia_inst->address + mem_y_REG_OFFSET);
}

void nokia_set_y
(
    nokia_instance_t * nokia_inst,
    uint8_t reg_val
)
{
    HW_set_8bit_reg( nokia_inst->address + mem_y_REG_OFFSET, reg_val );
}

uint8_t nokia_get_data
(
    nokia_instance_t * nokia_inst
)
{
    return HW_get_8bit_reg(nokia_inst->address + mem_data_REG_OFFSET);
}

void nokia_set_data
(
    nokia_instance_t * nokia_inst,
    uint8_t reg_val
)
{
    HW_set_8bit_reg( nokia_inst->address + mem_data_REG_OFFSET, reg_val );
}

uint8_t nokia_get_data_reg
(
	nokia_instance_t * nokia_inst,
	uint8_t reg_x,
	uint8_t reg_y
)
{
    HW_set_8bit_reg( nokia_inst->address + mem_x_REG_OFFSET, reg_x );
    HW_set_8bit_reg( nokia_inst->address + mem_y_REG_OFFSET, reg_y );
    return HW_get_8bit_reg( nokia_inst->address + mem_data_REG_OFFSET );
}

void nokia_set_data_reg
(
    nokia_instance_t * nokia_inst,
    uint8_t reg_x,
    uint8_t reg_y,
    uint8_t reg_data
)
{
    HW_set_8bit_reg( nokia_inst->address + mem_x_REG_OFFSET, reg_x );
    HW_set_8bit_reg( nokia_inst->address + mem_y_REG_OFFSET, reg_y );
    HW_set_8bit_reg( nokia_inst->address + mem_data_REG_OFFSET, reg_data );
}

uint8_t nokia_get_driver_ctrl
(
    nokia_instance_t * nokia_inst
)
{
    return HW_get_8bit_reg(nokia_inst->address + CONTROL_REG_OFFSET);
}

void nokia_set_driver_ctrl
(
    nokia_instance_t * nokia_inst,
    uint8_t reg_val
)
{
    HW_set_8bit_reg( nokia_inst->address + CONTROL_REG_OFFSET, reg_val );
}

uint8_t nokia_get_func_set
(
    nokia_instance_t * nokia_inst
)
{
    return HW_get_8bit_reg(nokia_inst->address + func_set_REG_OFFSET);
}

void nokia_set_func_set
(
    nokia_instance_t * nokia_inst,
    uint8_t reg_val
)
{
    HW_set_8bit_reg( nokia_inst->address + func_set_REG_OFFSET, reg_val );
}

uint8_t nokia_get_disp_ctrl
(
    nokia_instance_t * nokia_inst
)
{
    return HW_get_8bit_reg(nokia_inst->address + disp_ctrl_REG_OFFSET);
}

void nokia_set_disp_ctrl
(
    nokia_instance_t * nokia_inst,
    uint8_t reg_val
)
{
    HW_set_8bit_reg( nokia_inst->address + disp_ctrl_REG_OFFSET, reg_val );
}

uint8_t nokia_get_temp_ctrl
(
    nokia_instance_t * nokia_inst
)
{
    return HW_get_8bit_reg(nokia_inst->address + temp_ctrl_REG_OFFSET);
}

void nokia_set_temp_ctrl
(
    nokia_instance_t * nokia_inst,
    uint8_t reg_val
)
{
    HW_set_8bit_reg( nokia_inst->address + temp_ctrl_REG_OFFSET, reg_val );
}

uint8_t nokia_get_bias_sys
(
    nokia_instance_t * nokia_inst
)
{
    return HW_get_8bit_reg(nokia_inst->address + bias_sys_REG_OFFSET);
}

void nokia_set_bias_sys
(
    nokia_instance_t * nokia_inst,
    uint8_t reg_val
)
{
    HW_set_8bit_reg( nokia_inst->address + bias_sys_REG_OFFSET, reg_val );
}

uint8_t nokia_get_Vop_set
(
    nokia_instance_t * nokia_inst
)
{
    return HW_get_8bit_reg(nokia_inst->address + Vop_set_REG_OFFSET);
}

void nokia_set_Vop_set
(
    nokia_instance_t * nokia_inst,
    uint8_t reg_val
)
{
    HW_set_8bit_reg( nokia_inst->address + Vop_set_REG_OFFSET, reg_val );
}

/*
uint8_t* nokia_get_pixel_reg_block
(
    nokia_instance_t * nokia_inst,
    uint8_t x_left,
    uint8_t y_top,
    uint8_t x_right,
    uint8_t y_bot
)
{
    uint8_t* pixel_regs;
    int x_delta, y_delta;
    int n = 0;
    x_delta = (x_right - x_left);
    y_delta = (y_bot - y_top);
    pixel_regs = malloc(x_delta * y_delta);

    for(int i = x_right; i < x_left + 1; i++){
        nokia_set_x(nokia_inst, i);
        for(int k = y_top; k < y_bot + 1; k ++){
            nokia_set_y(nokia_inst, k);
            pixel_regs[n++] = nokia_get_data(nokia_inst);
        }
    }
}
*/

void nokia_set_pixel_reg_block
(
    nokia_instance_t * nokia_inst,
    uint8_t x_left,
    uint8_t y_top,
    uint8_t x_len,
    uint8_t y_len,
    uint8_t * pixel_regs
)
{
    int n = 0;

    for(int k = y_top; k < y_top + y_len; k ++){
        HW_set_8bit_reg( nokia_inst->address + mem_y_REG_OFFSET, k );
        for(int i = x_left; i < x_left + x_len; i++){
            HW_set_8bit_reg( nokia_inst->address + mem_x_REG_OFFSET, i );
            HW_set_8bit_reg( nokia_inst->address + mem_data_REG_OFFSET, pixel_regs[n++] );
        }
    }
}

uint8_t nokia_get_pixel
(
    nokia_instance_t * nokia_inst,
    uint8_t x,
    uint8_t y
)
{
    uint8_t x_reg, y_reg, y_pos, pixel_mask;
    uint8_t pixel_data;
    x_reg = x;
    y_reg = y / 8;
    y_pos = y % 8;


    HW_set_8bit_reg( nokia_inst->address + mem_x_REG_OFFSET, x_reg );
    HW_set_8bit_reg( nokia_inst->address + mem_y_REG_OFFSET, y_reg );
    pixel_data = HW_get_8bit_reg( nokia_inst->address + mem_data_REG_OFFSET );
    return (pixel_data >> y_pos) & 1u;
}

void nokia_set_pixel
(
    nokia_instance_t * nokia_inst,
    uint8_t x,
    uint8_t y,
    uint8_t val
)
{
    uint8_t x_reg, y_reg, y_pos, pixel_mask;
    uint8_t pixel_data;
    x_reg = x;
    y_reg = y / 8;
    y_pos = y % 8;

    pixel_mask = 1 << y_pos;


    HW_set_8bit_reg( nokia_inst->address + mem_x_REG_OFFSET, x_reg );
    HW_set_8bit_reg( nokia_inst->address + mem_y_REG_OFFSET, y_reg );
    pixel_data = HW_get_8bit_reg( nokia_inst->address + mem_data_REG_OFFSET );
    if(val == 0){
        pixel_data = pixel_data & ~pixel_mask;
    }
    else{
        pixel_data |= pixel_mask;
    }
    HW_set_8bit_reg( nokia_inst->address + mem_data_REG_OFFSET, pixel_data );

}

#ifdef __cplusplus
}
#endif