


#define BIT0        0x0001u
#define BIT1        0x0002u
#define BIT2        0x0004u
#define BIT3        0x0008u
#define BIT4        0x0010u
#define BIT5        0x0020u
#define BIT6        0x0040u
#define BIT7        0x0080u
#define BIT8        0x0100u
#define BIT9        0x0200u
#define BIT10       0x0400u
#define BIT11       0x0800u
#define BIT12       0x1000u
#define BIT13       0x2000u
#define BIT14       0x4000u
#define BIT15       0x8000u


/***************************************************************************//**
 * VSC8541_01 PHY specific register offsets and bit definitions
 */

#define VSC8541_EXT_ADDR_PAGE_CR            0x1Fu
#define PAGE_0                              0x00u
#define PAGE_1                              0x01u
#define PAGE_2                              0x02u

/* Page 0 Main Registers */
#define VSC8541_STAT_EXT_100BASE_TX         0x10u
#define VSC8541_STAT_EXT_1000BASE_T         0x11u
#define VSC8541_BYPASS_CONTROL              0x12u
#define VSC8541_ERR_CNT_1                   0x13u
#define VSC8541_ERR_CNT_2                   0x14u
#define VSC8541_ERR_CNT_3                   0x15u
#define VSC8541_EXT_CTRL_STATUS             0x16u
#define VSC8541_EXT_PHY_CTRL_1              0x17u
#define VSC8541_EXT_PHY_CTRL_2              0x18u
#define VSC8541_INT_MASK                    0x19u
#define VSC8541_INT_STATUS                  0x1Au
//#define VSC8541_                          0x1Bu   //reserved
#define VSC8541_AUX_CTRL_STATUS             0x1Cu
#define VSC8541_LED_MODE_SEL                0x1Du
#define VSC8541_LED_BEHAV                   0x1Eu

/* Page 1 Extended Registers */
#define VSC8541_VERIPHY_STAT_R1             0x10u
#define VSC8541_VERIPHY_STAT_R2             0x11u
#define VSC8541_Cu_MEDIA_CRC_GOOD_CNT       0x12u
#define VSC8541_EXT_MODE_CTRL               0x13u
#define VSC8541_EXT_PHY_CTRL_3              0x14u
//#define VSC8541_                          0x15u   //reserved
//#define VSC8541_                          0x16u   //reserved
#define VSC8541_EXT_PHY_CTRL_4              0x17u
#define VSC8541_VERIPHY_CTRL_1              0x18u
#define VSC8541_VERIPHY_CTRL_2              0x19u
#define VSC8541_VERIPHY_CTRL_3              0x1Au
//#define VSC8541_                          0x1Bu   //reserved
//#define VSC8541_                          0x1Cu   //reserved
#define VSC8541_ETH_PCKT_GEN_1              0x1Du
#define VSC8541_ETH_PCKT_GEN_2              0x1Eu

/* Page 2 Extended Registers */
#define VSC8541_Cu_PMD_TX_CTRL              0x10u
#define VSC8541_EEE_CTRL                    0x11u
//#define VSC8541_                          0x12u   //reserved
//#define VSC8541_                          0x13u   //reserved
#define VSC8541_RGMII_CTRL                  0x14u
#define VSC8541_WOLAN_MAC_ADR_15_0          0x15u
#define VSC8541_WOLAN_MAC_ADR_31_16         0x16u
#define VSC8541_WOLAN_MAC_ADR_47_32         0x17u
#define VSC8541_SEC_ON_PW_15_0              0x18u
#define VSC8541_SEC_ON_PW_31_16             0x19u
#define VSC8541_SEC_ON_PW_47_32             0x1Au
#define VSC8541_WOLAN_MAC_INTF_CTRL         0x1Bu
#define VSC8541_EXT_INT_MASK                0x1Cu
#define VSC8541_EXT_INT_STATUS              0x1Du
#define VSC8541_RING_RES_CTRL               0x1Eu


/*
 * VSC8541_STAT_EXT_100BASE_TX register bits
 * 100BASE-TX Status Extension
 * [7:0] reserved
 */
#define SE_100BASE_TX_ESD_ERR               BIT8
#define SE_100BASE_TX_SSD_ERR               BIT9
#define SE_100BASE_TX_TX_ERR                BIT10
#define SE_100BASE_TX_RX_ERR                BIT11
#define SE_100BASE_TX_CUR_LNK_STAT          BIT12
#define SE_100BASE_TX_DISC_STATE            BIT13
#define SE_100BASE_TX_LOCK_ERR              BIT14
#define SE_100BASE_TX_DESCRAMBLER           BIT15


/*
 * VSC8541_STAT_EXT_1000BASE_T register bits
 * 1000BASE-T Status Extension 2
 * [4:0] reserved
 */
#define SE_1000BASE_T_MDI_CRS_ERR           BIT5
#define SE_1000BASE_T_NON_CMPLNT_BCM5400    BIT6
#define SE_1000BASE_T_CARRIER_EXT_ERR       BIT7
#define SE_1000BASE_T_ESD_ERR               BIT8
#define SE_1000BASE_T_SSD_ERR               BIT9
#define SE_1000BASE_T_TX_ERR                BIT10
#define SE_1000BASE_T_RX_ERR                BIT11
#define SE_1000BASE_T_CUR_LNK_STAT          BIT12
#define SE_1000BASE_T_DISC_STATE            BIT13
#define SE_1000BASE_T_LOCK_ERR              BIT14
#define SE_1000BASE_T_DESCRAMBLER           BIT15

/*
 * VSC8541_EXT_CTRL_STATUS register bits
 * Device Auxiliary Control and Status
 * [5:1] reserved
 */
#define EXT_CTRL_STAT_SMI_BRDCST_W          BIT0
#define EXT_CTRL_STAT_10BASE_LNK_STAT       BIT6
#define EXT_CTRL_STAT_10BASE_DC_STATE       BIT7
#define EXT_CTRL_STAT_EOF_ERR               BIT8
#define EXT_CTRL_STAT_STICKY_RST_EN         BIT9
#define EXT_CTRL_STAT_10BASE_SQLCH_CTRL     BIT11 | BIT10
#define EXT_CTRL_STAT_DSBL_SQE_MODE         BIT12
#define EXT_CTRL_STAT_DSBL_10BASE_ECHO      BIT13
#define EXT_CTRL_STAT_JBR_DTCT_DSBL         BIT14
#define EXT_CTRL_STAT_FRCE_10BASE_LNK       BIT15



/*
 * VSC8541_AUX_CTRL_STATUS register bits
 */
#define AUX_CS_MEDIA_MODE_STAT              BIT1 | BIT0
#define AUX_CS_APHY_LNK_STAT_TMOUT_0        BIT2
#define AUX_CS_SPEED_STATUS                 BIT4 | BIT3
#define AUX_CS_FDX_STATUS                   BIT5
#define AUX_CS_APHY_MODE_EN                 BIT6
#define AUX_CS_APHY_LNK_STAT_TMOUT_1        BIT7
#define AUX_CS_D_POL_INV                    BIT8
#define AUX_CS_C_POL_INV                    BIT9
#define AUX_CS_B_POL_INV                    BIT10
#define AUX_CS_A_POL_INV                    BIT11
#define AUX_CS_CD_SWAP                      BIT12
#define AUX_CS_AUTO_MDIX_CRSOVR             BIT13
#define AUX_CS_ANEG_DIS                     BIT14
#define AUX_CS_ANEG_CMPLT                   BIT15


#define AUX_CS_SPEED_STATUS_10              0x0000u
#define AUX_CS_SPEED_STATUS_100             BIT3
#define AUX_CS_SPEED_STATUS_1000            BIT4