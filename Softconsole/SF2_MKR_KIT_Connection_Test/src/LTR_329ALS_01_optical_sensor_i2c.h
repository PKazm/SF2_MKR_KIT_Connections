#include "cpu_types.h"

#define BIT0        0x0001u
#define BIT1        0x0002u
#define BIT2        0x0004u
#define BIT3        0x0008u
#define BIT4        0x0010u
#define BIT5        0x0020u
#define BIT6        0x0040u
#define BIT7        0x0080u



#define OPT_SENS_ADDRESS            0x29
#define OPT_SENS_ADDRESS_W          (I2C_ADDRESS << 1u) | 0x00u
#define OPT_SENS_ADDRESS_R          (I2C_ADDRESS << 1u) | 0x01u


/***************************************************************************//**
 * LTR_329ALS_01 Optical Sensor register offsets and bit definitions
 */

#define OPT_SENS_ALS_CONTR          0x80u
#define OPT_SENS_ALS_MEAS_RATE      0x85u
#define OPT_SENS_PART_ID            0x86u
#define OPT_SENS_MANUFAC_ID         0x87u
#define OPT_SENS_ALS_DATA_CH1_0     0x88u
#define OPT_SENS_ALS_DATA_CH1_1     0x89u
#define OPT_SENS_ALS_DATA_CH0_0     0x8Au
#define OPT_SENS_ALS_DATA_CH0_1     0x8Bu
#define OPT_SENS_ALS_STATUS         0x8Cu

/*
 * OPT_SENS_ALS_CONTR
 * ALS_CONTR Register
 * [7:5] reserved
 */
#define ALS_GAIN                    BIT4 | BIT3 | BIT2
#define SW_RESET                    BIT1
#define ALS_MODE                    BIT0

#define ALS_GAIN_1X                 0x00u       // default
#define ALS_GAIN_2X                 BIT2
#define ALS_GAIN_4X                 BIT3
#define ALS_GAIN_8X                 BIT3 | BIT2
#define ALS_GAIN_48X                BIT4 | BIT3
#define ALS_GAIN_96X                BIT4 | BIT3 | BIT2


/*
 * OPT_SENS_ALS_MEAS_RATE
 * ALS_MEAS_RATE Register
 * [7:6]
 */
#define ALS_INTGR_TIME              BIT5 | BIT4 | BIT3
#define ALS_MEAS_RATE               BIT2 | BIT1 | BIT0

#define ALS_INTGR_TIME_100ms        0x00u       // default
#define ALS_INTGR_TIME_50ms         BIT3
#define ALS_INTGR_TIME_200ms        BIT4
#define ALS_INTGR_TIME_400ms        BIT4 | BIT3
#define ALS_INTGR_TIME_150ms        BIT5
#define ALS_INTGR_TIME_250ms        BIT5 | BIT3
#define ALS_INTGR_TIME_300ms        BIT5 | BIT4
#define ALS_INTGR_TIME_350ms        BIT5 | BIT4 | BIT3

#define ALS_MEAS_RATE_50ms          0x00u
#define ALS_MEAS_RATE_100ms         BIT0
#define ALS_MEAS_RATE_200ms         BIT1
#define ALS_MEAS_RATE_500ms         BIT1 | BIT0 // default
#define ALS_MEAS_RATE_1000ms        BIT2
#define ALS_MEAS_RATE_2000ms        BIT2 | BIT1 | BIT0



/*
 * OPT_SENS_ALS_STATUS
 * ALS_STATUS Register
 * [3] reserved
 * [1:0] reserved
 */
#define ALS_DATA_VALID              BIT7
#define ALS_DATA_GAIN_RNG           BIT6 | BIT5 | BIT4
#define ALS_DATA_STATUS             BIT2




void osens_i2c_init(mss_i2c_instance_t * this_i2c);
void osens_i2c_cfg
(
    mss_i2c_instance_t * this_i2c,
    uint8_t als_gain,
    uint8_t als_intgr_time,
    uint8_t als_meas_time
);

uint8_t * osens_i2c_get_channel_data(mss_i2c_instance_t * this_i2c);