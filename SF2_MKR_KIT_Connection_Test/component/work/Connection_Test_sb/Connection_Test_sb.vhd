----------------------------------------------------------------------
-- Created by SmartDesign Thu Mar 26 00:14:21 2020
-- Version: v12.1 12.600.0.14
----------------------------------------------------------------------

----------------------------------------------------------------------
-- Libraries
----------------------------------------------------------------------
library ieee;
use ieee.std_logic_1164.all;

library smartfusion2;
use smartfusion2.all;
----------------------------------------------------------------------
-- Connection_Test_sb entity declaration
----------------------------------------------------------------------
entity Connection_Test_sb is
    -- Port list
    port(
        -- Inputs
        DEVRST_N            : in  std_logic;
        FAB_RESET_N         : in  std_logic;
        FIC_0_APB_M_PRDATA  : in  std_logic_vector(31 downto 0);
        FIC_0_APB_M_PREADY  : in  std_logic;
        FIC_0_APB_M_PSLVERR : in  std_logic;
        GPIO_10_F2M         : in  std_logic;
        GPIO_8_F2M          : in  std_logic;
        GPIO_9_F2M          : in  std_logic;
        I2C_0_SCL_F2M       : in  std_logic;
        I2C_0_SDA_F2M       : in  std_logic;
        MAC_GMII_COL        : in  std_logic;
        MAC_GMII_CRS        : in  std_logic;
        MAC_GMII_GTX_CLK    : in  std_logic;
        MAC_GMII_MDI        : in  std_logic;
        MAC_GMII_RXD        : in  std_logic_vector(7 downto 0);
        MAC_GMII_RX_CLK     : in  std_logic;
        MAC_GMII_RX_DV      : in  std_logic;
        MAC_GMII_RX_ER      : in  std_logic;
        MAC_GMII_TX_CLK     : in  std_logic;
        MMUART_0_RXD_F2M    : in  std_logic;
        MSS_INT_F2M         : in  std_logic_vector(15 downto 0);
        SPI_1_CLK_F2M       : in  std_logic;
        SPI_1_DI_F2M        : in  std_logic;
        SPI_1_SS0_F2M       : in  std_logic;
        -- Outputs
        FAB_CCC_GL1         : out std_logic;
        FAB_CCC_LOCK        : out std_logic;
        FIC_0_APB_M_PADDR   : out std_logic_vector(31 downto 0);
        FIC_0_APB_M_PENABLE : out std_logic;
        FIC_0_APB_M_PSEL    : out std_logic;
        FIC_0_APB_M_PWDATA  : out std_logic_vector(31 downto 0);
        FIC_0_APB_M_PWRITE  : out std_logic;
        FIC_0_CLK           : out std_logic;
        FIC_0_LOCK          : out std_logic;
        GPIO_0_M2F          : out std_logic;
        GPIO_1_M2F          : out std_logic;
        GPIO_2_M2F          : out std_logic;
        GPIO_3_M2F          : out std_logic;
        GPIO_4_M2F          : out std_logic;
        GPIO_5_M2F          : out std_logic;
        GPIO_6_M2F          : out std_logic;
        GPIO_7_M2F          : out std_logic;
        I2C_0_SCL_M2F       : out std_logic;
        I2C_0_SCL_M2F_OE    : out std_logic;
        I2C_0_SDA_M2F       : out std_logic;
        I2C_0_SDA_M2F_OE    : out std_logic;
        INIT_DONE           : out std_logic;
        MAC_GMII_MDC        : out std_logic;
        MAC_GMII_MDO        : out std_logic;
        MAC_GMII_MDO_EN     : out std_logic;
        MAC_GMII_TXD        : out std_logic_vector(7 downto 0);
        MAC_GMII_TX_EN      : out std_logic;
        MAC_GMII_TX_ER      : out std_logic;
        MMUART_0_TXD_M2F    : out std_logic;
        MSS_READY           : out std_logic;
        POWER_ON_RESET_N    : out std_logic;
        SPI_1_CLK_M2F       : out std_logic;
        SPI_1_DO_M2F        : out std_logic;
        SPI_1_SS0_M2F       : out std_logic;
        SPI_1_SS0_M2F_OE    : out std_logic
        );
end Connection_Test_sb;
----------------------------------------------------------------------
-- Connection_Test_sb architecture body
----------------------------------------------------------------------
architecture RTL of Connection_Test_sb is
----------------------------------------------------------------------
-- Component declarations
----------------------------------------------------------------------
-- Connection_Test_sb_CCC_0_FCCC   -   Actel:SgCore:FCCC:2.0.201
component Connection_Test_sb_CCC_0_FCCC
    -- Port list
    port(
        -- Inputs
        RCOSC_25_50MHZ : in  std_logic;
        -- Outputs
        GL0            : out std_logic;
        GL1            : out std_logic;
        LOCK           : out std_logic
        );
end component;
-- Connection_Test_sb_MSS
component Connection_Test_sb_MSS
    -- Port list
    port(
        -- Inputs
        FIC_0_APB_M_PRDATA     : in  std_logic_vector(31 downto 0);
        FIC_0_APB_M_PREADY     : in  std_logic;
        FIC_0_APB_M_PSLVERR    : in  std_logic;
        FIC_2_APB_M_PRDATA     : in  std_logic_vector(31 downto 0);
        FIC_2_APB_M_PREADY     : in  std_logic;
        FIC_2_APB_M_PSLVERR    : in  std_logic;
        GPIO_10_F2M            : in  std_logic;
        GPIO_8_F2M             : in  std_logic;
        GPIO_9_F2M             : in  std_logic;
        I2C_0_SCL_F2M          : in  std_logic;
        I2C_0_SDA_F2M          : in  std_logic;
        MAC_GMII_COL           : in  std_logic;
        MAC_GMII_CRS           : in  std_logic;
        MAC_GMII_GTX_CLK       : in  std_logic;
        MAC_GMII_MDI           : in  std_logic;
        MAC_GMII_RXD           : in  std_logic_vector(7 downto 0);
        MAC_GMII_RX_CLK        : in  std_logic;
        MAC_GMII_RX_DV         : in  std_logic;
        MAC_GMII_RX_ER         : in  std_logic;
        MAC_GMII_TX_CLK        : in  std_logic;
        MCCC_CLK_BASE          : in  std_logic;
        MCCC_CLK_BASE_PLL_LOCK : in  std_logic;
        MMUART_0_RXD_F2M       : in  std_logic;
        MSS_INT_F2M            : in  std_logic_vector(15 downto 0);
        MSS_RESET_N_F2M        : in  std_logic;
        SPI_1_CLK_F2M          : in  std_logic;
        SPI_1_DI_F2M           : in  std_logic;
        SPI_1_SS0_F2M          : in  std_logic;
        -- Outputs
        FIC_0_APB_M_PADDR      : out std_logic_vector(31 downto 0);
        FIC_0_APB_M_PENABLE    : out std_logic;
        FIC_0_APB_M_PSEL       : out std_logic;
        FIC_0_APB_M_PWDATA     : out std_logic_vector(31 downto 0);
        FIC_0_APB_M_PWRITE     : out std_logic;
        FIC_2_APB_M_PADDR      : out std_logic_vector(15 downto 2);
        FIC_2_APB_M_PCLK       : out std_logic;
        FIC_2_APB_M_PENABLE    : out std_logic;
        FIC_2_APB_M_PRESET_N   : out std_logic;
        FIC_2_APB_M_PSEL       : out std_logic;
        FIC_2_APB_M_PWDATA     : out std_logic_vector(31 downto 0);
        FIC_2_APB_M_PWRITE     : out std_logic;
        GPIO_0_M2F             : out std_logic;
        GPIO_1_M2F             : out std_logic;
        GPIO_2_M2F             : out std_logic;
        GPIO_3_M2F             : out std_logic;
        GPIO_4_M2F             : out std_logic;
        GPIO_5_M2F             : out std_logic;
        GPIO_6_M2F             : out std_logic;
        GPIO_7_M2F             : out std_logic;
        I2C_0_SCL_M2F          : out std_logic;
        I2C_0_SCL_M2F_OE       : out std_logic;
        I2C_0_SDA_M2F          : out std_logic;
        I2C_0_SDA_M2F_OE       : out std_logic;
        MAC_GMII_MDC           : out std_logic;
        MAC_GMII_MDO           : out std_logic;
        MAC_GMII_MDO_EN        : out std_logic;
        MAC_GMII_TXD           : out std_logic_vector(7 downto 0);
        MAC_GMII_TX_EN         : out std_logic;
        MAC_GMII_TX_ER         : out std_logic;
        MMUART_0_TXD_M2F       : out std_logic;
        MSS_RESET_N_M2F        : out std_logic;
        SPI_1_CLK_M2F          : out std_logic;
        SPI_1_DO_M2F           : out std_logic;
        SPI_1_SS0_M2F          : out std_logic;
        SPI_1_SS0_M2F_OE       : out std_logic
        );
end component;
-- CoreResetP   -   Actel:DirectCore:CoreResetP:7.1.100
component CoreResetP
    generic( 
        DDR_WAIT            : integer := 200 ;
        DEVICE_090          : integer := 0 ;
        DEVICE_VOLTAGE      : integer := 2 ;
        ENABLE_SOFT_RESETS  : integer := 0 ;
        EXT_RESET_CFG       : integer := 0 ;
        FDDR_IN_USE         : integer := 0 ;
        MDDR_IN_USE         : integer := 0 ;
        SDIF0_IN_USE        : integer := 0 ;
        SDIF0_PCIE          : integer := 0 ;
        SDIF0_PCIE_HOTRESET : integer := 1 ;
        SDIF0_PCIE_L2P2     : integer := 1 ;
        SDIF1_IN_USE        : integer := 0 ;
        SDIF1_PCIE          : integer := 0 ;
        SDIF1_PCIE_HOTRESET : integer := 1 ;
        SDIF1_PCIE_L2P2     : integer := 1 ;
        SDIF2_IN_USE        : integer := 0 ;
        SDIF2_PCIE          : integer := 0 ;
        SDIF2_PCIE_HOTRESET : integer := 1 ;
        SDIF2_PCIE_L2P2     : integer := 1 ;
        SDIF3_IN_USE        : integer := 0 ;
        SDIF3_PCIE          : integer := 0 ;
        SDIF3_PCIE_HOTRESET : integer := 1 ;
        SDIF3_PCIE_L2P2     : integer := 1 
        );
    -- Port list
    port(
        -- Inputs
        CLK_BASE                       : in  std_logic;
        CLK_LTSSM                      : in  std_logic;
        CONFIG1_DONE                   : in  std_logic;
        CONFIG2_DONE                   : in  std_logic;
        FAB_RESET_N                    : in  std_logic;
        FIC_2_APB_M_PRESET_N           : in  std_logic;
        FPLL_LOCK                      : in  std_logic;
        POWER_ON_RESET_N               : in  std_logic;
        RCOSC_25_50MHZ                 : in  std_logic;
        RESET_N_M2F                    : in  std_logic;
        SDIF0_PERST_N                  : in  std_logic;
        SDIF0_PRDATA                   : in  std_logic_vector(31 downto 0);
        SDIF0_PSEL                     : in  std_logic;
        SDIF0_PWRITE                   : in  std_logic;
        SDIF0_SPLL_LOCK                : in  std_logic;
        SDIF1_PERST_N                  : in  std_logic;
        SDIF1_PRDATA                   : in  std_logic_vector(31 downto 0);
        SDIF1_PSEL                     : in  std_logic;
        SDIF1_PWRITE                   : in  std_logic;
        SDIF1_SPLL_LOCK                : in  std_logic;
        SDIF2_PERST_N                  : in  std_logic;
        SDIF2_PRDATA                   : in  std_logic_vector(31 downto 0);
        SDIF2_PSEL                     : in  std_logic;
        SDIF2_PWRITE                   : in  std_logic;
        SDIF2_SPLL_LOCK                : in  std_logic;
        SDIF3_PERST_N                  : in  std_logic;
        SDIF3_PRDATA                   : in  std_logic_vector(31 downto 0);
        SDIF3_PSEL                     : in  std_logic;
        SDIF3_PWRITE                   : in  std_logic;
        SDIF3_SPLL_LOCK                : in  std_logic;
        SOFT_EXT_RESET_OUT             : in  std_logic;
        SOFT_FDDR_CORE_RESET           : in  std_logic;
        SOFT_M3_RESET                  : in  std_logic;
        SOFT_MDDR_DDR_AXI_S_CORE_RESET : in  std_logic;
        SOFT_RESET_F2M                 : in  std_logic;
        SOFT_SDIF0_0_CORE_RESET        : in  std_logic;
        SOFT_SDIF0_1_CORE_RESET        : in  std_logic;
        SOFT_SDIF0_CORE_RESET          : in  std_logic;
        SOFT_SDIF0_PHY_RESET           : in  std_logic;
        SOFT_SDIF1_CORE_RESET          : in  std_logic;
        SOFT_SDIF1_PHY_RESET           : in  std_logic;
        SOFT_SDIF2_CORE_RESET          : in  std_logic;
        SOFT_SDIF2_PHY_RESET           : in  std_logic;
        SOFT_SDIF3_CORE_RESET          : in  std_logic;
        SOFT_SDIF3_PHY_RESET           : in  std_logic;
        -- Outputs
        DDR_READY                      : out std_logic;
        EXT_RESET_OUT                  : out std_logic;
        FDDR_CORE_RESET_N              : out std_logic;
        INIT_DONE                      : out std_logic;
        M3_RESET_N                     : out std_logic;
        MDDR_DDR_AXI_S_CORE_RESET_N    : out std_logic;
        MSS_HPMS_READY                 : out std_logic;
        RESET_N_F2M                    : out std_logic;
        SDIF0_0_CORE_RESET_N           : out std_logic;
        SDIF0_1_CORE_RESET_N           : out std_logic;
        SDIF0_CORE_RESET_N             : out std_logic;
        SDIF0_PHY_RESET_N              : out std_logic;
        SDIF1_CORE_RESET_N             : out std_logic;
        SDIF1_PHY_RESET_N              : out std_logic;
        SDIF2_CORE_RESET_N             : out std_logic;
        SDIF2_PHY_RESET_N              : out std_logic;
        SDIF3_CORE_RESET_N             : out std_logic;
        SDIF3_PHY_RESET_N              : out std_logic;
        SDIF_READY                     : out std_logic;
        SDIF_RELEASED                  : out std_logic
        );
end component;
-- Connection_Test_sb_FABOSC_0_OSC   -   Actel:SgCore:OSC:2.0.101
component Connection_Test_sb_FABOSC_0_OSC
    -- Port list
    port(
        -- Inputs
        XTL                : in  std_logic;
        -- Outputs
        RCOSC_1MHZ_CCC     : out std_logic;
        RCOSC_1MHZ_O2F     : out std_logic;
        RCOSC_25_50MHZ_CCC : out std_logic;
        RCOSC_25_50MHZ_O2F : out std_logic;
        XTLOSC_CCC         : out std_logic;
        XTLOSC_O2F         : out std_logic
        );
end component;
-- SYSRESET
component SYSRESET
    -- Port list
    port(
        -- Inputs
        DEVRST_N         : in  std_logic;
        -- Outputs
        POWER_ON_RESET_N : out std_logic
        );
end component;
----------------------------------------------------------------------
-- Signal declarations
----------------------------------------------------------------------
signal Connection_Test_sb_MSS_TMP_0_FIC_2_APB_M_PRESET_N  : std_logic;
signal Connection_Test_sb_MSS_TMP_0_MSS_RESET_N_M2F       : std_logic;
signal CORERESETP_0_RESET_N_F2M                           : std_logic;
signal FAB_CCC_GL1_net_0                                  : std_logic;
signal FAB_CCC_LOCK_net_0                                 : std_logic;
signal FABOSC_0_RCOSC_25_50MHZ_CCC_OUT_RCOSC_25_50MHZ_CCC : std_logic;
signal FABOSC_0_RCOSC_25_50MHZ_O2F                        : std_logic;
signal FIC_0_APB_MASTER_3_PADDR                           : std_logic_vector(31 downto 0);
signal FIC_0_APB_MASTER_3_PENABLE                         : std_logic;
signal FIC_0_APB_MASTER_3_PSELx                           : std_logic;
signal FIC_0_APB_MASTER_3_PWDATA                          : std_logic_vector(31 downto 0);
signal FIC_0_APB_MASTER_3_PWRITE                          : std_logic;
signal FIC_0_CLK_net_0                                    : std_logic;
signal GPIO_0_M2F_net_0                                   : std_logic;
signal GPIO_1_M2F_net_0                                   : std_logic;
signal GPIO_2_M2F_net_0                                   : std_logic;
signal GPIO_3_M2F_net_0                                   : std_logic;
signal GPIO_4_M2F_net_0                                   : std_logic;
signal GPIO_5_M2F_net_0                                   : std_logic;
signal GPIO_6_M2F_net_0                                   : std_logic;
signal GPIO_7_M2F_net_0                                   : std_logic;
signal I2C_0_SCL_M2F_net_0                                : std_logic;
signal I2C_0_SCL_M2F_OE_net_0                             : std_logic;
signal I2C_0_SDA_M2F_net_0                                : std_logic;
signal I2C_0_SDA_M2F_OE_net_0                             : std_logic;
signal INIT_DONE_net_0                                    : std_logic;
signal MAC_GMII_MDC_net_0                                 : std_logic;
signal MAC_GMII_MDO_net_0                                 : std_logic;
signal MAC_GMII_MDO_EN_net_0                              : std_logic;
signal MAC_GMII_TX_EN_net_0                               : std_logic;
signal MAC_GMII_TX_ER_net_0                               : std_logic;
signal MAC_GMII_TXD_net_0                                 : std_logic_vector(7 downto 0);
signal MMUART_0_TXD_M2F_net_0                             : std_logic;
signal MSS_READY_net_0                                    : std_logic;
signal POWER_ON_RESET_N_net_0                             : std_logic;
signal SPI_1_CLK_M2F_net_0                                : std_logic;
signal SPI_1_DO_M2F_net_0                                 : std_logic;
signal SPI_1_SS0_M2F_net_0                                : std_logic;
signal SPI_1_SS0_M2F_OE_net_0                             : std_logic;
signal POWER_ON_RESET_N_net_1                             : std_logic;
signal INIT_DONE_net_1                                    : std_logic;
signal FIC_0_CLK_net_1                                    : std_logic;
signal FAB_CCC_LOCK_net_1                                 : std_logic;
signal FAB_CCC_GL1_net_1                                  : std_logic;
signal FAB_CCC_LOCK_net_2                                 : std_logic;
signal MSS_READY_net_1                                    : std_logic;
signal FIC_0_APB_MASTER_3_PADDR_net_0                     : std_logic_vector(31 downto 0);
signal FIC_0_APB_MASTER_3_PSELx_net_0                     : std_logic;
signal FIC_0_APB_MASTER_3_PENABLE_net_0                   : std_logic;
signal FIC_0_APB_MASTER_3_PWRITE_net_0                    : std_logic;
signal FIC_0_APB_MASTER_3_PWDATA_net_0                    : std_logic_vector(31 downto 0);
signal SPI_1_DO_M2F_net_1                                 : std_logic;
signal SPI_1_CLK_M2F_net_1                                : std_logic;
signal SPI_1_SS0_M2F_net_1                                : std_logic;
signal SPI_1_SS0_M2F_OE_net_1                             : std_logic;
signal MMUART_0_TXD_M2F_net_1                             : std_logic;
signal I2C_0_SDA_M2F_net_1                                : std_logic;
signal I2C_0_SDA_M2F_OE_net_1                             : std_logic;
signal I2C_0_SCL_M2F_net_1                                : std_logic;
signal I2C_0_SCL_M2F_OE_net_1                             : std_logic;
signal GPIO_0_M2F_net_1                                   : std_logic;
signal GPIO_1_M2F_net_1                                   : std_logic;
signal GPIO_2_M2F_net_1                                   : std_logic;
signal GPIO_3_M2F_net_1                                   : std_logic;
signal GPIO_4_M2F_net_1                                   : std_logic;
signal GPIO_5_M2F_net_1                                   : std_logic;
signal GPIO_6_M2F_net_1                                   : std_logic;
signal GPIO_7_M2F_net_1                                   : std_logic;
signal MAC_GMII_TX_EN_net_1                               : std_logic;
signal MAC_GMII_TX_ER_net_1                               : std_logic;
signal MAC_GMII_MDC_net_1                                 : std_logic;
signal MAC_GMII_MDO_EN_net_1                              : std_logic;
signal MAC_GMII_MDO_net_1                                 : std_logic;
signal MAC_GMII_TXD_net_1                                 : std_logic_vector(7 downto 0);
----------------------------------------------------------------------
-- TiedOff Signals
----------------------------------------------------------------------
signal VCC_net                                            : std_logic;
signal GND_net                                            : std_logic;
signal PADDR_const_net_0                                  : std_logic_vector(7 downto 2);
signal PWDATA_const_net_0                                 : std_logic_vector(7 downto 0);
signal SDIF0_PRDATA_const_net_0                           : std_logic_vector(31 downto 0);
signal SDIF1_PRDATA_const_net_0                           : std_logic_vector(31 downto 0);
signal SDIF2_PRDATA_const_net_0                           : std_logic_vector(31 downto 0);
signal SDIF3_PRDATA_const_net_0                           : std_logic_vector(31 downto 0);
signal FIC_2_APB_M_PRDATA_const_net_0                     : std_logic_vector(31 downto 0);

begin
----------------------------------------------------------------------
-- Constant assignments
----------------------------------------------------------------------
 VCC_net                        <= '1';
 GND_net                        <= '0';
 PADDR_const_net_0              <= B"000000";
 PWDATA_const_net_0             <= B"00000000";
 SDIF0_PRDATA_const_net_0       <= B"00000000000000000000000000000000";
 SDIF1_PRDATA_const_net_0       <= B"00000000000000000000000000000000";
 SDIF2_PRDATA_const_net_0       <= B"00000000000000000000000000000000";
 SDIF3_PRDATA_const_net_0       <= B"00000000000000000000000000000000";
 FIC_2_APB_M_PRDATA_const_net_0 <= B"00000000000000000000000000000000";
----------------------------------------------------------------------
-- Top level output port assignments
----------------------------------------------------------------------
 POWER_ON_RESET_N_net_1           <= POWER_ON_RESET_N_net_0;
 POWER_ON_RESET_N                 <= POWER_ON_RESET_N_net_1;
 INIT_DONE_net_1                  <= INIT_DONE_net_0;
 INIT_DONE                        <= INIT_DONE_net_1;
 FIC_0_CLK_net_1                  <= FIC_0_CLK_net_0;
 FIC_0_CLK                        <= FIC_0_CLK_net_1;
 FAB_CCC_LOCK_net_1               <= FAB_CCC_LOCK_net_0;
 FIC_0_LOCK                       <= FAB_CCC_LOCK_net_1;
 FAB_CCC_GL1_net_1                <= FAB_CCC_GL1_net_0;
 FAB_CCC_GL1                      <= FAB_CCC_GL1_net_1;
 FAB_CCC_LOCK_net_2               <= FAB_CCC_LOCK_net_0;
 FAB_CCC_LOCK                     <= FAB_CCC_LOCK_net_2;
 MSS_READY_net_1                  <= MSS_READY_net_0;
 MSS_READY                        <= MSS_READY_net_1;
 FIC_0_APB_MASTER_3_PADDR_net_0   <= FIC_0_APB_MASTER_3_PADDR;
 FIC_0_APB_M_PADDR(31 downto 0)   <= FIC_0_APB_MASTER_3_PADDR_net_0;
 FIC_0_APB_MASTER_3_PSELx_net_0   <= FIC_0_APB_MASTER_3_PSELx;
 FIC_0_APB_M_PSEL                 <= FIC_0_APB_MASTER_3_PSELx_net_0;
 FIC_0_APB_MASTER_3_PENABLE_net_0 <= FIC_0_APB_MASTER_3_PENABLE;
 FIC_0_APB_M_PENABLE              <= FIC_0_APB_MASTER_3_PENABLE_net_0;
 FIC_0_APB_MASTER_3_PWRITE_net_0  <= FIC_0_APB_MASTER_3_PWRITE;
 FIC_0_APB_M_PWRITE               <= FIC_0_APB_MASTER_3_PWRITE_net_0;
 FIC_0_APB_MASTER_3_PWDATA_net_0  <= FIC_0_APB_MASTER_3_PWDATA;
 FIC_0_APB_M_PWDATA(31 downto 0)  <= FIC_0_APB_MASTER_3_PWDATA_net_0;
 SPI_1_DO_M2F_net_1               <= SPI_1_DO_M2F_net_0;
 SPI_1_DO_M2F                     <= SPI_1_DO_M2F_net_1;
 SPI_1_CLK_M2F_net_1              <= SPI_1_CLK_M2F_net_0;
 SPI_1_CLK_M2F                    <= SPI_1_CLK_M2F_net_1;
 SPI_1_SS0_M2F_net_1              <= SPI_1_SS0_M2F_net_0;
 SPI_1_SS0_M2F                    <= SPI_1_SS0_M2F_net_1;
 SPI_1_SS0_M2F_OE_net_1           <= SPI_1_SS0_M2F_OE_net_0;
 SPI_1_SS0_M2F_OE                 <= SPI_1_SS0_M2F_OE_net_1;
 MMUART_0_TXD_M2F_net_1           <= MMUART_0_TXD_M2F_net_0;
 MMUART_0_TXD_M2F                 <= MMUART_0_TXD_M2F_net_1;
 I2C_0_SDA_M2F_net_1              <= I2C_0_SDA_M2F_net_0;
 I2C_0_SDA_M2F                    <= I2C_0_SDA_M2F_net_1;
 I2C_0_SDA_M2F_OE_net_1           <= I2C_0_SDA_M2F_OE_net_0;
 I2C_0_SDA_M2F_OE                 <= I2C_0_SDA_M2F_OE_net_1;
 I2C_0_SCL_M2F_net_1              <= I2C_0_SCL_M2F_net_0;
 I2C_0_SCL_M2F                    <= I2C_0_SCL_M2F_net_1;
 I2C_0_SCL_M2F_OE_net_1           <= I2C_0_SCL_M2F_OE_net_0;
 I2C_0_SCL_M2F_OE                 <= I2C_0_SCL_M2F_OE_net_1;
 GPIO_0_M2F_net_1                 <= GPIO_0_M2F_net_0;
 GPIO_0_M2F                       <= GPIO_0_M2F_net_1;
 GPIO_1_M2F_net_1                 <= GPIO_1_M2F_net_0;
 GPIO_1_M2F                       <= GPIO_1_M2F_net_1;
 GPIO_2_M2F_net_1                 <= GPIO_2_M2F_net_0;
 GPIO_2_M2F                       <= GPIO_2_M2F_net_1;
 GPIO_3_M2F_net_1                 <= GPIO_3_M2F_net_0;
 GPIO_3_M2F                       <= GPIO_3_M2F_net_1;
 GPIO_4_M2F_net_1                 <= GPIO_4_M2F_net_0;
 GPIO_4_M2F                       <= GPIO_4_M2F_net_1;
 GPIO_5_M2F_net_1                 <= GPIO_5_M2F_net_0;
 GPIO_5_M2F                       <= GPIO_5_M2F_net_1;
 GPIO_6_M2F_net_1                 <= GPIO_6_M2F_net_0;
 GPIO_6_M2F                       <= GPIO_6_M2F_net_1;
 GPIO_7_M2F_net_1                 <= GPIO_7_M2F_net_0;
 GPIO_7_M2F                       <= GPIO_7_M2F_net_1;
 MAC_GMII_TX_EN_net_1             <= MAC_GMII_TX_EN_net_0;
 MAC_GMII_TX_EN                   <= MAC_GMII_TX_EN_net_1;
 MAC_GMII_TX_ER_net_1             <= MAC_GMII_TX_ER_net_0;
 MAC_GMII_TX_ER                   <= MAC_GMII_TX_ER_net_1;
 MAC_GMII_MDC_net_1               <= MAC_GMII_MDC_net_0;
 MAC_GMII_MDC                     <= MAC_GMII_MDC_net_1;
 MAC_GMII_MDO_EN_net_1            <= MAC_GMII_MDO_EN_net_0;
 MAC_GMII_MDO_EN                  <= MAC_GMII_MDO_EN_net_1;
 MAC_GMII_MDO_net_1               <= MAC_GMII_MDO_net_0;
 MAC_GMII_MDO                     <= MAC_GMII_MDO_net_1;
 MAC_GMII_TXD_net_1               <= MAC_GMII_TXD_net_0;
 MAC_GMII_TXD(7 downto 0)         <= MAC_GMII_TXD_net_1;
----------------------------------------------------------------------
-- Component instances
----------------------------------------------------------------------
-- CCC_0   -   Actel:SgCore:FCCC:2.0.201
CCC_0 : Connection_Test_sb_CCC_0_FCCC
    port map( 
        -- Inputs
        RCOSC_25_50MHZ => FABOSC_0_RCOSC_25_50MHZ_CCC_OUT_RCOSC_25_50MHZ_CCC,
        -- Outputs
        GL0            => FIC_0_CLK_net_0,
        GL1            => FAB_CCC_GL1_net_0,
        LOCK           => FAB_CCC_LOCK_net_0 
        );
-- Connection_Test_sb_MSS_0
Connection_Test_sb_MSS_0 : Connection_Test_sb_MSS
    port map( 
        -- Inputs
        MCCC_CLK_BASE          => FIC_0_CLK_net_0,
        SPI_1_DI_F2M           => SPI_1_DI_F2M,
        SPI_1_CLK_F2M          => SPI_1_CLK_F2M,
        SPI_1_SS0_F2M          => SPI_1_SS0_F2M,
        MMUART_0_RXD_F2M       => MMUART_0_RXD_F2M,
        I2C_0_SDA_F2M          => I2C_0_SDA_F2M,
        I2C_0_SCL_F2M          => I2C_0_SCL_F2M,
        MCCC_CLK_BASE_PLL_LOCK => FAB_CCC_LOCK_net_0,
        MSS_RESET_N_F2M        => CORERESETP_0_RESET_N_F2M,
        GPIO_8_F2M             => GPIO_8_F2M,
        GPIO_9_F2M             => GPIO_9_F2M,
        GPIO_10_F2M            => GPIO_10_F2M,
        MAC_GMII_RX_ER         => MAC_GMII_RX_ER,
        MAC_GMII_RX_DV         => MAC_GMII_RX_DV,
        MAC_GMII_CRS           => MAC_GMII_CRS,
        MAC_GMII_COL           => MAC_GMII_COL,
        MAC_GMII_RX_CLK        => MAC_GMII_RX_CLK,
        MAC_GMII_TX_CLK        => MAC_GMII_TX_CLK,
        MAC_GMII_GTX_CLK       => MAC_GMII_GTX_CLK,
        MAC_GMII_MDI           => MAC_GMII_MDI,
        FIC_0_APB_M_PREADY     => FIC_0_APB_M_PREADY,
        FIC_0_APB_M_PSLVERR    => FIC_0_APB_M_PSLVERR,
        FIC_2_APB_M_PREADY     => VCC_net, -- tied to '1' from definition
        FIC_2_APB_M_PSLVERR    => GND_net, -- tied to '0' from definition
        MAC_GMII_RXD           => MAC_GMII_RXD,
        FIC_0_APB_M_PRDATA     => FIC_0_APB_M_PRDATA,
        FIC_2_APB_M_PRDATA     => FIC_2_APB_M_PRDATA_const_net_0, -- tied to X"0" from definition
        MSS_INT_F2M            => MSS_INT_F2M,
        -- Outputs
        SPI_1_DO_M2F           => SPI_1_DO_M2F_net_0,
        SPI_1_CLK_M2F          => SPI_1_CLK_M2F_net_0,
        SPI_1_SS0_M2F          => SPI_1_SS0_M2F_net_0,
        SPI_1_SS0_M2F_OE       => SPI_1_SS0_M2F_OE_net_0,
        MMUART_0_TXD_M2F       => MMUART_0_TXD_M2F_net_0,
        I2C_0_SDA_M2F          => I2C_0_SDA_M2F_net_0,
        I2C_0_SDA_M2F_OE       => I2C_0_SDA_M2F_OE_net_0,
        I2C_0_SCL_M2F          => I2C_0_SCL_M2F_net_0,
        I2C_0_SCL_M2F_OE       => I2C_0_SCL_M2F_OE_net_0,
        MSS_RESET_N_M2F        => Connection_Test_sb_MSS_TMP_0_MSS_RESET_N_M2F,
        GPIO_0_M2F             => GPIO_0_M2F_net_0,
        GPIO_1_M2F             => GPIO_1_M2F_net_0,
        GPIO_2_M2F             => GPIO_2_M2F_net_0,
        GPIO_3_M2F             => GPIO_3_M2F_net_0,
        GPIO_4_M2F             => GPIO_4_M2F_net_0,
        GPIO_5_M2F             => GPIO_5_M2F_net_0,
        GPIO_6_M2F             => GPIO_6_M2F_net_0,
        GPIO_7_M2F             => GPIO_7_M2F_net_0,
        MAC_GMII_TX_EN         => MAC_GMII_TX_EN_net_0,
        MAC_GMII_TX_ER         => MAC_GMII_TX_ER_net_0,
        MAC_GMII_MDC           => MAC_GMII_MDC_net_0,
        MAC_GMII_MDO_EN        => MAC_GMII_MDO_EN_net_0,
        MAC_GMII_MDO           => MAC_GMII_MDO_net_0,
        FIC_0_APB_M_PSEL       => FIC_0_APB_MASTER_3_PSELx,
        FIC_0_APB_M_PWRITE     => FIC_0_APB_MASTER_3_PWRITE,
        FIC_0_APB_M_PENABLE    => FIC_0_APB_MASTER_3_PENABLE,
        FIC_2_APB_M_PRESET_N   => Connection_Test_sb_MSS_TMP_0_FIC_2_APB_M_PRESET_N,
        FIC_2_APB_M_PCLK       => OPEN,
        FIC_2_APB_M_PWRITE     => OPEN,
        FIC_2_APB_M_PENABLE    => OPEN,
        FIC_2_APB_M_PSEL       => OPEN,
        MAC_GMII_TXD           => MAC_GMII_TXD_net_0,
        FIC_0_APB_M_PADDR      => FIC_0_APB_MASTER_3_PADDR,
        FIC_0_APB_M_PWDATA     => FIC_0_APB_MASTER_3_PWDATA,
        FIC_2_APB_M_PADDR      => OPEN,
        FIC_2_APB_M_PWDATA     => OPEN 
        );
-- CORERESETP_0   -   Actel:DirectCore:CoreResetP:7.1.100
CORERESETP_0 : CoreResetP
    generic map( 
        DDR_WAIT            => ( 200 ),
        DEVICE_090          => ( 0 ),
        DEVICE_VOLTAGE      => ( 2 ),
        ENABLE_SOFT_RESETS  => ( 0 ),
        EXT_RESET_CFG       => ( 0 ),
        FDDR_IN_USE         => ( 0 ),
        MDDR_IN_USE         => ( 0 ),
        SDIF0_IN_USE        => ( 0 ),
        SDIF0_PCIE          => ( 0 ),
        SDIF0_PCIE_HOTRESET => ( 1 ),
        SDIF0_PCIE_L2P2     => ( 1 ),
        SDIF1_IN_USE        => ( 0 ),
        SDIF1_PCIE          => ( 0 ),
        SDIF1_PCIE_HOTRESET => ( 1 ),
        SDIF1_PCIE_L2P2     => ( 1 ),
        SDIF2_IN_USE        => ( 0 ),
        SDIF2_PCIE          => ( 0 ),
        SDIF2_PCIE_HOTRESET => ( 1 ),
        SDIF2_PCIE_L2P2     => ( 1 ),
        SDIF3_IN_USE        => ( 0 ),
        SDIF3_PCIE          => ( 0 ),
        SDIF3_PCIE_HOTRESET => ( 1 ),
        SDIF3_PCIE_L2P2     => ( 1 )
        )
    port map( 
        -- Inputs
        RESET_N_M2F                    => Connection_Test_sb_MSS_TMP_0_MSS_RESET_N_M2F,
        FIC_2_APB_M_PRESET_N           => Connection_Test_sb_MSS_TMP_0_FIC_2_APB_M_PRESET_N,
        POWER_ON_RESET_N               => POWER_ON_RESET_N_net_0,
        FAB_RESET_N                    => FAB_RESET_N,
        RCOSC_25_50MHZ                 => FABOSC_0_RCOSC_25_50MHZ_O2F,
        CLK_BASE                       => FIC_0_CLK_net_0,
        CLK_LTSSM                      => GND_net, -- tied to '0' from definition
        FPLL_LOCK                      => VCC_net, -- tied to '1' from definition
        SDIF0_SPLL_LOCK                => VCC_net, -- tied to '1' from definition
        SDIF1_SPLL_LOCK                => VCC_net, -- tied to '1' from definition
        SDIF2_SPLL_LOCK                => VCC_net, -- tied to '1' from definition
        SDIF3_SPLL_LOCK                => VCC_net, -- tied to '1' from definition
        CONFIG1_DONE                   => VCC_net,
        CONFIG2_DONE                   => VCC_net,
        SDIF0_PERST_N                  => VCC_net, -- tied to '1' from definition
        SDIF1_PERST_N                  => VCC_net, -- tied to '1' from definition
        SDIF2_PERST_N                  => VCC_net, -- tied to '1' from definition
        SDIF3_PERST_N                  => VCC_net, -- tied to '1' from definition
        SDIF0_PSEL                     => GND_net, -- tied to '0' from definition
        SDIF0_PWRITE                   => VCC_net, -- tied to '1' from definition
        SDIF0_PRDATA                   => SDIF0_PRDATA_const_net_0, -- tied to X"0" from definition
        SDIF1_PSEL                     => GND_net, -- tied to '0' from definition
        SDIF1_PWRITE                   => VCC_net, -- tied to '1' from definition
        SDIF1_PRDATA                   => SDIF1_PRDATA_const_net_0, -- tied to X"0" from definition
        SDIF2_PSEL                     => GND_net, -- tied to '0' from definition
        SDIF2_PWRITE                   => VCC_net, -- tied to '1' from definition
        SDIF2_PRDATA                   => SDIF2_PRDATA_const_net_0, -- tied to X"0" from definition
        SDIF3_PSEL                     => GND_net, -- tied to '0' from definition
        SDIF3_PWRITE                   => VCC_net, -- tied to '1' from definition
        SDIF3_PRDATA                   => SDIF3_PRDATA_const_net_0, -- tied to X"0" from definition
        SOFT_EXT_RESET_OUT             => GND_net, -- tied to '0' from definition
        SOFT_RESET_F2M                 => GND_net, -- tied to '0' from definition
        SOFT_M3_RESET                  => GND_net, -- tied to '0' from definition
        SOFT_MDDR_DDR_AXI_S_CORE_RESET => GND_net, -- tied to '0' from definition
        SOFT_FDDR_CORE_RESET           => GND_net, -- tied to '0' from definition
        SOFT_SDIF0_PHY_RESET           => GND_net, -- tied to '0' from definition
        SOFT_SDIF0_CORE_RESET          => GND_net, -- tied to '0' from definition
        SOFT_SDIF0_0_CORE_RESET        => GND_net, -- tied to '0' from definition
        SOFT_SDIF0_1_CORE_RESET        => GND_net, -- tied to '0' from definition
        SOFT_SDIF1_PHY_RESET           => GND_net, -- tied to '0' from definition
        SOFT_SDIF1_CORE_RESET          => GND_net, -- tied to '0' from definition
        SOFT_SDIF2_PHY_RESET           => GND_net, -- tied to '0' from definition
        SOFT_SDIF2_CORE_RESET          => GND_net, -- tied to '0' from definition
        SOFT_SDIF3_PHY_RESET           => GND_net, -- tied to '0' from definition
        SOFT_SDIF3_CORE_RESET          => GND_net, -- tied to '0' from definition
        -- Outputs
        MSS_HPMS_READY                 => MSS_READY_net_0,
        DDR_READY                      => OPEN,
        SDIF_READY                     => OPEN,
        RESET_N_F2M                    => CORERESETP_0_RESET_N_F2M,
        M3_RESET_N                     => OPEN,
        EXT_RESET_OUT                  => OPEN,
        MDDR_DDR_AXI_S_CORE_RESET_N    => OPEN,
        FDDR_CORE_RESET_N              => OPEN,
        SDIF0_CORE_RESET_N             => OPEN,
        SDIF0_0_CORE_RESET_N           => OPEN,
        SDIF0_1_CORE_RESET_N           => OPEN,
        SDIF0_PHY_RESET_N              => OPEN,
        SDIF1_CORE_RESET_N             => OPEN,
        SDIF1_PHY_RESET_N              => OPEN,
        SDIF2_CORE_RESET_N             => OPEN,
        SDIF2_PHY_RESET_N              => OPEN,
        SDIF3_CORE_RESET_N             => OPEN,
        SDIF3_PHY_RESET_N              => OPEN,
        SDIF_RELEASED                  => OPEN,
        INIT_DONE                      => INIT_DONE_net_0 
        );
-- FABOSC_0   -   Actel:SgCore:OSC:2.0.101
FABOSC_0 : Connection_Test_sb_FABOSC_0_OSC
    port map( 
        -- Inputs
        XTL                => GND_net, -- tied to '0' from definition
        -- Outputs
        RCOSC_25_50MHZ_CCC => FABOSC_0_RCOSC_25_50MHZ_CCC_OUT_RCOSC_25_50MHZ_CCC,
        RCOSC_25_50MHZ_O2F => FABOSC_0_RCOSC_25_50MHZ_O2F,
        RCOSC_1MHZ_CCC     => OPEN,
        RCOSC_1MHZ_O2F     => OPEN,
        XTLOSC_CCC         => OPEN,
        XTLOSC_O2F         => OPEN 
        );
-- SYSRESET_POR
SYSRESET_POR : SYSRESET
    port map( 
        -- Inputs
        DEVRST_N         => DEVRST_N,
        -- Outputs
        POWER_ON_RESET_N => POWER_ON_RESET_N_net_0 
        );

end RTL;
