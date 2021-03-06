


#include "../firmware/drivers/mss_i2c/mss_i2c.h"
#include "LTR_329ALS_01_optical_sensor_i2c.h"




void osens_i2c_init(mss_i2c_instance_t * this_i2c)
{
    uint8_t osens_tx[2] = {OPT_SENS_ALS_CONTR, 0x00};
    uint8_t osens_rx[1];
    mss_i2c_status_t status;
    char uart_buffer[128];

    MSS_I2C_write_read
    (
        this_i2c,
        OPT_SENS_ADDRESS,
        osens_tx,
        1,
        osens_rx,
        1,
        MSS_I2C_RELEASE_BUS
    );

    status = MSS_I2C_wait_complete(this_i2c, MSS_I2C_NO_TIMEOUT);
    // check status here to handle errors,
    // omitted because of maximum confidence

    osens_tx[1] = osens_rx[0] | ~SW_RESET | ALS_MODE;    //These are always set '1' to enable the device

    MSS_I2C_write
    (
        this_i2c,
		OPT_SENS_ADDRESS,
        osens_tx,      // light sensor defaults, but turned on
        2,
        MSS_I2C_RELEASE_BUS
    );

    status = MSS_I2C_wait_complete(this_i2c, MSS_I2C_NO_TIMEOUT);
    // check status here to handle errors,
    // omitted because of maximum confidence
}


void osens_i2c_cfg
(
    mss_i2c_instance_t * this_i2c,
    uint8_t als_gain,
    uint8_t als_intgr_time,
    uint8_t als_meas_time
)
{
    uint8_t osens_tx[2] = {OPT_SENS_ALS_CONTR, 0x00};
    uint8_t osens_rx[1];
    mss_i2c_status_t status;

    MSS_I2C_write_read
    (
        this_i2c,
        OPT_SENS_ADDRESS,
        osens_tx,
        1,
        osens_rx,
        1,
        MSS_I2C_HOLD_BUS
    );

    status = MSS_I2C_wait_complete(this_i2c, MSS_I2C_NO_TIMEOUT);
    // check status here to handle errors,
    // omitted because of maximum confidence

    /* ensure reserved MSBs are set to '0', ALS_GAIN doesn't seem to work correctly otherwise */
    osens_rx[0] &= ~(ALS_GAIN | 0b11100000);
    osens_tx[1] = osens_rx[0] | als_gain;

    MSS_I2C_write
    (
        this_i2c,
        OPT_SENS_ADDRESS,
        osens_tx,
        2,
        MSS_I2C_HOLD_BUS
    );

    status = MSS_I2C_wait_complete(this_i2c, MSS_I2C_NO_TIMEOUT);
    // check status here to handle errors,
    // omitted because of maximum confidence

    osens_tx[0] = OPT_SENS_ALS_MEAS_RATE;
    osens_tx[1] = als_intgr_time | als_meas_time;

    MSS_I2C_write
    (
        this_i2c,
        OPT_SENS_ADDRESS,
        osens_tx,
        2,
        MSS_I2C_RELEASE_BUS
    );

    status = MSS_I2C_wait_complete(this_i2c, MSS_I2C_NO_TIMEOUT);
    // check status here to handle errors,
    // omitted because of maximum confidence
}


uint8_t * osens_i2c_get_channel_data(mss_i2c_instance_t * this_i2c)
{
    uint8_t osens_tx[1];
    uint8_t osens_rx[1];
    static uint8_t channel_data[4];
    mss_i2c_status_t status;

    /* read first data register CH1_0 @ 0x88 */
    osens_tx[0] = OPT_SENS_ALS_DATA_CH1_0;
    MSS_I2C_write_read
    (
        this_i2c,
        OPT_SENS_ADDRESS,
        osens_tx,
        1,
        osens_rx,
        1,
        MSS_I2C_HOLD_BUS
    );

    status = MSS_I2C_wait_complete(this_i2c, MSS_I2C_NO_TIMEOUT);
    // check status here to handle errors,
    // omitted because of maximum confidence

    channel_data[0] = osens_rx[0];

    /* read second data register CH1_1 @ 0x89 */
    osens_tx[0] = OPT_SENS_ALS_DATA_CH1_1;
    MSS_I2C_write_read
    (
        this_i2c,
        OPT_SENS_ADDRESS,
        osens_tx,
        1,
        osens_rx,
        1,
        MSS_I2C_HOLD_BUS
    );

    status = MSS_I2C_wait_complete(this_i2c, MSS_I2C_NO_TIMEOUT);
    // check status here to handle errors,
    // omitted because of maximum confidence

    channel_data[1] = osens_rx[0];

    /* read second data register CH0_0 @ 0x8A */
    osens_tx[0] = OPT_SENS_ALS_DATA_CH0_0;
    MSS_I2C_write_read
    (
        this_i2c,
        OPT_SENS_ADDRESS,
        osens_tx,
        1,
        osens_rx,
        1,
        MSS_I2C_HOLD_BUS
    );

    status = MSS_I2C_wait_complete(this_i2c, MSS_I2C_NO_TIMEOUT);
    // check status here to handle errors,
    // omitted because of maximum confidence
    
    channel_data[2] = osens_rx[0];

    /* read second data register CH0_1 @ 0x8B */
    osens_tx[0] = OPT_SENS_ALS_DATA_CH0_1;
    MSS_I2C_write_read
    (
        this_i2c,
        OPT_SENS_ADDRESS,
        osens_tx,
        1,
        osens_rx,
        1,
        MSS_I2C_RELEASE_BUS
    );

    status = MSS_I2C_wait_complete(this_i2c, MSS_I2C_NO_TIMEOUT);
    // check status here to handle errors,
    // omitted because of maximum confidence

    channel_data[3] = osens_rx[0];

    return channel_data;
}
