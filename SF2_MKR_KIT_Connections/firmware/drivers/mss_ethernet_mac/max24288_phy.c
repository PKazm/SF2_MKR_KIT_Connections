/*******************************************************************************
 * (c) Copyright 2011-2015 Microsemi SoC Products Group.  All rights reserved.
 *
 * Microsemi MAX24288 PHY interface driver implementation.
 *
 * SVN $Revision: 7574 $
 * SVN $Date: 2015-07-22 12:08:12 +0530 (Wed, 22 Jul 2015) $
 */
#include "phy.h"
#include "mss_ethernet_mac_types.h"
#include "mss_ethernet_mac.h"
#include "mss_gpio.h"

#ifdef __cplusplus
extern "C" {
#endif
/***************************************************************************//**
 * Address of the PHY on the MII management interface.
 */
static uint8_t g_phy_addr = 0u;

/*******************************************************************************
    MAX24288 registers
 ******************************************************************************/
#define MAX24288_BMCR_REG       0x00
#define MAX24288_BMSR_REG       0x01
#define MAX24288_ID1_REG        0x02
#define MAX24288_ID2_REG        0x03
#define MAX24288_AN_ADV_REG     0x04
#define MAX24288_AN_RX_REG      0x05
#define MAX24288_AN_EXP_REG     0x06
#define MAX24288_EXT_STAT_REG   0x0F
#define MAX24288_JIT_DIAG_REG   0x10
#define MAX24288_PCSCR_REG      0x11
#define MAX24288_GMIICR_REG     0x12
#define MAX24288_CR_REG         0x13
#define MAX24288_IR_REG         0x14
#define MAX24288_PAGESEL_REG    0x1F

#define MAX24288_PTPCR1_REG             16u

/*
 * MAX24288 BMCR register bits:
 */
#define MAX24288_BMCR_DP_RST_MASK       0x8000u
#define MAX24288_BMCR_DLB_MASK  0x4000u

/*
 * MAX24288 GMIICR register bits:
 */
#define GMIICR_SPD_MASK         0xC000u
#define GMIICR_DDR_MASK         0x0800u

#define GMIICR_SPD_GMII_MODE    0x8000u

/*
 * MAX24288 PCSCR register bits:
 */
#define PCSCR_BASEX_MASK        0x0010u

/*
 * MAX24288 PTPCR1 register bits:
 */
#define MAX24288_PTPCR1_RX_PWDN_MASK    0x0004u

/**************************************************************************/
/* Private Function definitions                                           */
/**************************************************************************/
static void startup_max24288(void);
static void wait_100us(void);
static void wait_1ms(void);


/**************************************************************************/
/* Public Function definitions                                            */
/**************************************************************************/


/**************************************************************************//**
 * 
 */
void MSS_MAC_phy_init(uint8_t phy_addr)
{
    g_phy_addr = phy_addr;
    
    startup_max24288();
}

/**************************************************************************//**
 * 
 */
void MSS_MAC_phy_set_link_speed(uint32_t speed_duplex_select)
{
}

/**************************************************************************//**
 * 
 */
void MSS_MAC_phy_autonegotiate(void)
{
}

/**************************************************************************//**
 * 
 */
uint8_t MSS_MAC_phy_get_link_status
(
    mss_mac_speed_t * speed,
    uint8_t *     fullduplex
)
{
    *fullduplex = MSS_MAC_HALF_DUPLEX;
    *speed = MSS_MAC_1000MBPS;
    
    return 1u;
}

/*******************************************************************************
 *
 */
static void startup_max24288(void)
{
    volatile uint32_t phy_reg;
    
    MSS_GPIO_init();
    MSS_GPIO_config(MSS_GPIO_0, MSS_GPIO_OUTPUT_MODE);
    
    /* Assert RST_N. */
    MSS_GPIO_set_output(MSS_GPIO_0, 0u);
    
    wait_100us();
    
    /* De-assaert RST_N */
    MSS_GPIO_set_output(MSS_GPIO_0, 1u);
    
    /* Disable SPI interface and select page 2. */
    MSS_MAC_write_phy_reg(g_phy_addr, MAX24288_PAGESEL_REG, 0x0012u);
    
    /* Power down receive CDR. */
    phy_reg = MSS_MAC_read_phy_reg(g_phy_addr, MAX24288_PTPCR1_REG);
    phy_reg |= MAX24288_PTPCR1_RX_PWDN_MASK;
    MSS_MAC_write_phy_reg(g_phy_addr, MAX24288_PTPCR1_REG, phy_reg);
    
    wait_1ms();
    
    /* Power up receive CDR. */
    phy_reg &= ~MAX24288_PTPCR1_RX_PWDN_MASK;
    MSS_MAC_write_phy_reg(g_phy_addr, MAX24288_PTPCR1_REG, phy_reg);
    
    /* Reset data path. */
    phy_reg = MSS_MAC_read_phy_reg(g_phy_addr, MAX24288_BMCR_REG);
    phy_reg |= MAX24288_BMCR_DP_RST_MASK;
    MSS_MAC_write_phy_reg(g_phy_addr, MAX24288_BMCR_REG, phy_reg);

    /* Enable SPI interface and select page 0. */
    MSS_MAC_write_phy_reg(g_phy_addr, MAX24288_PAGESEL_REG, 0x0000u);
    
}

/*******************************************************************************
 * This assumes that the Cortex-M3 SysTick timer is configured for 10ms
 * interrupts.
 */
static void wait_100us(void)
{
    uint32_t sys_tick_load;
    uint32_t sys_tick_100us;
    uint32_t start_value;
    uint32_t upper_limit;
    uint32_t sys_tick_current;
    
    start_value = SysTick->VAL;
    sys_tick_load = SysTick->LOAD;
    sys_tick_100us = sys_tick_load / 100u;
    upper_limit = start_value + sys_tick_100us;
    
    if(upper_limit >= sys_tick_load)
    {
        upper_limit = upper_limit - sys_tick_load;
        do {
            sys_tick_current = SysTick->VAL;
        } while((sys_tick_current < upper_limit) || (sys_tick_current > start_value));
    }
    else
    {
        do {
            sys_tick_current = SysTick->VAL;
        } while((sys_tick_current < upper_limit) && (sys_tick_current > start_value));
    }
}

/*******************************************************************************
 * This assumes that the Cortex-M3 SysTick timer is configured for 10ms
 * interrupts.
 */
static void wait_1ms(void)
{
    uint32_t sys_tick_load;
    uint32_t sys_tick_1ms;
    uint32_t start_value;
    uint32_t upper_limit;
    uint32_t sys_tick_current;
    
    start_value = SysTick->VAL;
    sys_tick_load = SysTick->LOAD;
    sys_tick_1ms = sys_tick_load / 10u;
    upper_limit = start_value + sys_tick_1ms;
    
    if(upper_limit >= sys_tick_load)
    {
        upper_limit = upper_limit - sys_tick_load;
        do {
            sys_tick_current = SysTick->VAL;
        } while((sys_tick_current < upper_limit) || (sys_tick_current > start_value));
    }
    else
    {
        do {
            sys_tick_current = SysTick->VAL;
        } while((sys_tick_current < upper_limit) && (sys_tick_current > start_value));
    }
}


#ifdef __cplusplus
}
#endif

/******************************** END OF FILE ******************************/






