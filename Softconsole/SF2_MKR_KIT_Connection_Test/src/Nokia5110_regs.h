/*
 * Nokia5110_regs.h
 *
 *  Created on: Mar 25, 2020
 *      Author: Phoenix136
 */

#ifndef NOKIA5110_REGS_H_
#define NOKIA5110_REGS_H_

#ifdef __cplusplus
extern "C" {
#endif

/*******************************************************************************
 * CONTROL register:
 *------------------------------------------------------------------------------
 * bit 0 enables the LCD driver (default on = 1)
 * bit 1 enables an indicator in the top left to show the screen updating (default on = 1)
 * bit 2 sets the frame buffer A or B to be displayed on the LCD
 * bit 3 sets data write to both frames
 */
#define CONTROL_REG_OFFSET 0x00u

/*******************************************************************************
 * Function Set register:
 *------------------------------------------------------------------------------
 * This register is written directly into the Nokia5110 IC
 * The bit functions are defined by the IC datasheet/user guide
 */
#define func_set_REG_OFFSET 0x04u

/*******************************************************************************
 * Display Control register:
 *------------------------------------------------------------------------------
 * This register is written directly into the Nokia5110 IC
 * The bit functions are defined by the IC datasheet/user guide
 */
#define disp_ctrl_REG_OFFSET 0x08u

/*******************************************************************************
 * Temp Control register:
 *------------------------------------------------------------------------------
 * This register is written directly into the Nokia5110 IC
 * The bit functions are defined by the IC datasheet/user guide
 */
#define temp_ctrl_REG_OFFSET 0x0Cu

/*******************************************************************************
 * Bias System register:
 *------------------------------------------------------------------------------
 * This register is written directly into the Nokia5110 IC
 * The bit functions are defined by the IC datasheet/user guide
 */
#define bias_sys_REG_OFFSET 0x10u

/*******************************************************************************
 * V op Set register:
 *------------------------------------------------------------------------------
 * This register is written directly into the Nokia5110 IC
 * The bit functions are defined by the IC datasheet/user guide
 */
#define Vop_set_REG_OFFSET 0x14u

/*******************************************************************************
 * Data register:
 *------------------------------------------------------------------------------
 * This register allows read and write access to the pixel register set by mem_x and mem_y
 */
#define mem_data_REG_OFFSET 0x18u

/*******************************************************************************
 * Mem X register:
 *------------------------------------------------------------------------------
 * This register sets the X register position for accessing pixel data
 */
#define mem_x_REG_OFFSET 0x1Cu

/*******************************************************************************
 * Mem Y register:
 *------------------------------------------------------------------------------
 * This register sets the Y register position for accessing pixel data
 */
#define mem_y_REG_OFFSET 0x20u

#ifdef __cplusplus
}
#endif

#endif /* SRC_NOKIA5110_REGS_H_ */
