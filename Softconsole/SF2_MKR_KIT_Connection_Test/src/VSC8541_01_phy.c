#include "../firmware/drivers/mss_ethernet_mac/phy.h"
#include "../firmware/drivers/mss_ethernet_mac/mss_ethernet_mac_types.h"
#include "../firmware/drivers/mss_ethernet_mac/mss_ethernet_mac.h"
#include "../firmware/CMSIS/m2sxxx.h"
#include "../firmware/CMSIS/mss_assert.h"
#include "../firmware/CMSIS/system_m2sxxx.h"
#include "../firmware/drivers/mss_ethernet_mac/mss_ethernet_mac_regs.h"
#include "VSC8541_01_phy_regs.h"

#ifdef __cplusplus
extern "C" {
#endif



/***************************************************************************//**
 * VSC8541_01 PHY specific register offsets and bit definitions
 */

// see VSC8541_01_phy_regs.h



/***************************************************************************//**
 * Address of the PHY on the MII management interface.
 */
static uint8_t g_phy_addr = 0u;

/***************************************************************************//**
 * 
 */
void MSS_MAC_phy_init(uint8_t phy_addr)
{
    uint16_t phy_reg;
    
    g_phy_addr = phy_addr;
    
    /* Reset the PHY. */
    phy_reg = MSS_MAC_read_phy_reg(g_phy_addr, MII_BMCR);
    phy_reg |= BMCR_RESET;
    MSS_MAC_write_phy_reg(g_phy_addr, MII_BMCR, phy_reg);

    /* Power up the PHY. */
    phy_reg = MSS_MAC_read_phy_reg(g_phy_addr, MII_BMCR);
    phy_reg &= ~BMCR_PDOWN;
    MSS_MAC_write_phy_reg(g_phy_addr, MII_BMCR, phy_reg);
}


/***************************************************************************//**
 * 
 */
void MSS_MAC_phy_set_link_speed(uint32_t speed_duplex_select)
{
    uint16_t phy_reg;
    uint32_t inc;
    uint32_t speed_select;
    const uint16_t mii_advertise_bits[4] = {ADVERTISE_10FULL, ADVERTISE_10HALF, ADVERTISE_100FULL, ADVERTISE_100HALF};
    
    /* Set auto-negotiation advertisement. */
    
    /* Set 10Mbps and 100Mbps advertisement. */
    phy_reg = MSS_MAC_read_phy_reg(g_phy_addr, MII_ADVERTISE);
    phy_reg &= ~(ADVERTISE_10HALF | ADVERTISE_10FULL |
                 ADVERTISE_100HALF | ADVERTISE_100FULL);
                 
    speed_select = speed_duplex_select;
    for(inc = 0u; inc < 4u; ++inc)
    {
        uint32_t advertise;
        advertise = speed_select & 0x00000001u;
        if(advertise != 0u)
        {
            phy_reg |= mii_advertise_bits[inc];
        }
        speed_select = speed_select >> 1u;
    }
    
    MSS_MAC_write_phy_reg(g_phy_addr, MII_ADVERTISE, phy_reg);
    
    /* Set 1000Mbps advertisement. */
    phy_reg = MSS_MAC_read_phy_reg(g_phy_addr, MII_CTRL1000);
    phy_reg &= ~(ADVERTISE_1000FULL | ADVERTISE_1000HALF);
    
    if((speed_duplex_select & MSS_MAC_ANEG_1000M_FD) != 0u)
    {
        phy_reg |= ADVERTISE_1000FULL;
    }
    
    if((speed_duplex_select & MSS_MAC_ANEG_1000M_HD) != 0u)
    {
        phy_reg |= ADVERTISE_1000HALF;
    }
    
    MSS_MAC_write_phy_reg(g_phy_addr, MII_CTRL1000, phy_reg);
}


/***************************************************************************//**
 * 
 */
void MSS_MAC_phy_autonegotiate(void)
{
    uint16_t phy_reg;
    uint16_t autoneg_complete;
    volatile uint32_t copper_aneg_timeout = 1000000u;
    
    /* Enable auto-negotiation. */
    MSS_MAC_write_phy_reg(g_phy_addr, VSC8541_EXT_ADDR_PAGE_CR, PAGE_0);
    
    phy_reg = MSS_MAC_read_phy_reg(g_phy_addr, MII_BMCR);
    phy_reg |= (BMCR_ANENABLE | BMCR_ANRESTART);
    MSS_MAC_write_phy_reg(g_phy_addr, MII_BMCR, phy_reg);
    
    /* Wait for copper auto-negotiation to complete. */
    do {
        phy_reg = MSS_MAC_read_phy_reg(g_phy_addr, MII_BMSR);
        autoneg_complete = phy_reg & BMSR_ANEGCOMPLETE;
        --copper_aneg_timeout;
    } while((!autoneg_complete && (copper_aneg_timeout != 0u)) || (0xFFFF == phy_reg));
  
}


/***************************************************************************//**
 * 
 */
uint8_t MSS_MAC_phy_get_link_status
(
    mss_mac_speed_t * speed,
    uint8_t *     fullduplex
)
{
    uint16_t phy_reg;
    uint16_t copper_link_up;
    uint8_t link_status;

    /*
     * Find out if link is up between VSC8541_01 PHY and remote device.
     */
    phy_reg = MSS_MAC_read_phy_reg(g_phy_addr, MII_BMSR);
    copper_link_up = phy_reg & BMSR_LSTATUS;
    
    if(copper_link_up != MSS_MAC_LINK_DOWN)
    {
        uint16_t duplex;
        uint16_t phy_speed;
        
        /* Link is up. */
        link_status = MSS_MAC_LINK_UP;


        MSS_MAC_write_phy_reg(g_phy_addr, VSC8541_EXT_ADDR_PAGE_CR, PAGE_0);
        /* check 10MBPS */
        phy_reg = MSS_MAC_read_phy_reg(g_phy_addr, VSC8541_AUX_CTRL_STATUS);
        duplex = phy_reg & AUX_CS_FDX_STATUS;
        phy_speed = phy_reg & AUX_CS_SPEED_STATUS;
        
        if(MSS_MAC_HALF_DUPLEX == duplex)
        {
            *fullduplex = MSS_MAC_HALF_DUPLEX;
        }
        else
        {
            *fullduplex = MSS_MAC_FULL_DUPLEX;
        }
        
        switch(phy_speed) 
        {
            case AUX_CS_SPEED_STATUS_1000:
                *speed = MSS_MAC_1000MBPS;
                break;
    
            case AUX_CS_SPEED_STATUS_100:
                *speed = MSS_MAC_100MBPS;
                break;
    
            case AUX_CS_SPEED_STATUS_10:
                *speed = MSS_MAC_10MBPS;
                break;
            default:
                *speed = INVALID_SPEED;
                break;
        }
    }
    else
    {
        /* Link is down. */
        link_status = MSS_MAC_LINK_DOWN;
    }
    
    return link_status;
}

#ifdef __cplusplus
}
#endif
