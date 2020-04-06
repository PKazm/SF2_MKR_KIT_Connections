----------------------------------------------------------------------
-- Created by SmartDesign Mon Apr  6 00:30:27 2020
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
-- Connection_system entity declaration
----------------------------------------------------------------------
entity Connection_system is
    -- Port list
    port(
        -- Inputs
        Board_Buttons    : in    std_logic_vector(1 downto 0);
        DEVRST_N         : in    std_logic;
        FLASH_MEM_SDI    : in    std_logic;
        GMII_COL         : in    std_logic;
        GMII_CRS         : in    std_logic;
        GMII_RXD         : in    std_logic_vector(7 downto 0);
        GMII_RX_CLK      : in    std_logic;
        GMII_RX_DV       : in    std_logic;
        GMII_RX_ER       : in    std_logic;
        GMII_TX_CLK      : in    std_logic;
        MDINT            : in    std_logic;
        USB_UART_TXD     : in    std_logic;
        -- Outputs
        Board_J10        : out   std_logic;
        Board_J11        : out   std_logic;
        Board_J7         : out   std_logic_vector(4 downto 0);
        Board_J8         : out   std_logic;
        Board_J9         : out   std_logic;
        Board_LEDs       : out   std_logic_vector(7 downto 0);
        Board_MOD1       : out   std_logic_vector(5 downto 0);
        COMA_MODE        : out   std_logic;
        ETH_NRESET       : out   std_logic;
        FLASH_MEM_CLK    : out   std_logic;
        FLASH_MEM_HOLD_N : out   std_logic;
        FLASH_MEM_SDO    : out   std_logic;
        FLASH_MEM_SSO    : out   std_logic;
        FLASH_MEM_WP_N   : out   std_logic;
        GMII_GTX_CLK     : out   std_logic;
        GMII_MDC         : out   std_logic;
        GMII_TXD         : out   std_logic_vector(7 downto 0);
        GMII_TX_EN       : out   std_logic;
        GMII_TX_ER       : out   std_logic;
        REFCLK_SEL       : out   std_logic_vector(1 downto 0);
        USB_UART_RXD     : out   std_logic;
        -- Inouts
        GMII_MDIO        : inout std_logic;
        Light_SCL        : inout std_logic;
        Light_SDA        : inout std_logic
        );
end Connection_system;
----------------------------------------------------------------------
-- Connection_system architecture body
----------------------------------------------------------------------
architecture RTL of Connection_system is
----------------------------------------------------------------------
-- Component declarations
----------------------------------------------------------------------
-- BIBUF
component BIBUF
    generic( 
        IOSTD : string := "" 
        );
    -- Port list
    port(
        -- Inputs
        D   : in    std_logic;
        E   : in    std_logic;
        -- Outputs
        Y   : out   std_logic;
        -- Inouts
        PAD : inout std_logic
        );
end component;
-- Connection_system_sb
component Connection_system_sb
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
end component;
-- CoreAPB3_C0
component CoreAPB3_C0
    -- Port list
    port(
        -- Inputs
        PADDR     : in  std_logic_vector(31 downto 0);
        PENABLE   : in  std_logic;
        PRDATAS0  : in  std_logic_vector(31 downto 0);
        PRDATAS1  : in  std_logic_vector(31 downto 0);
        PREADYS0  : in  std_logic;
        PREADYS1  : in  std_logic;
        PSEL      : in  std_logic;
        PSLVERRS0 : in  std_logic;
        PSLVERRS1 : in  std_logic;
        PWDATA    : in  std_logic_vector(31 downto 0);
        PWRITE    : in  std_logic;
        -- Outputs
        PADDRS    : out std_logic_vector(31 downto 0);
        PENABLES  : out std_logic;
        PRDATA    : out std_logic_vector(31 downto 0);
        PREADY    : out std_logic;
        PSELS0    : out std_logic;
        PSELS1    : out std_logic;
        PSLVERR   : out std_logic;
        PWDATAS   : out std_logic_vector(31 downto 0);
        PWRITES   : out std_logic
        );
end component;
-- corepwm_C0
component corepwm_C0
    -- Port list
    port(
        -- Inputs
        PADDR   : in  std_logic_vector(7 downto 0);
        PCLK    : in  std_logic;
        PENABLE : in  std_logic;
        PRESETN : in  std_logic;
        PSEL    : in  std_logic;
        PWDATA  : in  std_logic_vector(31 downto 0);
        PWRITE  : in  std_logic;
        -- Outputs
        PRDATA  : out std_logic_vector(31 downto 0);
        PREADY  : out std_logic;
        PSLVERR : out std_logic;
        PWM     : out std_logic_vector(1 downto 0)
        );
end component;
-- LED_inverter_dimmer
component LED_inverter_dimmer
    -- Port list
    port(
        -- Inputs
        CLK         : in  std_logic;
        LED_toggles : in  std_logic_vector(7 downto 0);
        -- Outputs
        Board_LEDs  : out std_logic_vector(7 downto 0)
        );
end component;
-- Nokia5110_Driver
-- using entity instantiation for component Nokia5110_Driver
----------------------------------------------------------------------
-- Signal declarations
----------------------------------------------------------------------
signal BIBUF_0_Y                                        : std_logic;
signal BIBUF_1_Y                                        : std_logic;
signal BIBUF_2_Y                                        : std_logic;
signal Board_Buttons_slice_0                            : std_logic_vector(1 to 1);
signal Board_Buttons_slice_1                            : std_logic_vector(0 to 0);
signal Board_J7_net_0                                   : std_logic;
signal Board_J7_0                                       : std_logic;
signal Board_J7_1                                       : std_logic;
signal Board_J7_2                                       : std_logic;
signal Board_J7_3                                       : std_logic;
signal Board_J8_net_0                                   : std_logic_vector(1 to 1);
signal Board_J10_net_0                                  : std_logic;
signal Board_LEDs_net_0                                 : std_logic_vector(7 downto 0);
signal Connection_system_sb_0_FIC_0_AMBA_MASTER_PADDR   : std_logic_vector(31 downto 0);
signal Connection_system_sb_0_FIC_0_AMBA_MASTER_PENABLE : std_logic;
signal Connection_system_sb_0_FIC_0_AMBA_MASTER_PRDATA  : std_logic_vector(31 downto 0);
signal Connection_system_sb_0_FIC_0_AMBA_MASTER_PREADY  : std_logic;
signal Connection_system_sb_0_FIC_0_AMBA_MASTER_PSELx   : std_logic;
signal Connection_system_sb_0_FIC_0_AMBA_MASTER_PSLVERR : std_logic;
signal Connection_system_sb_0_FIC_0_AMBA_MASTER_PWDATA  : std_logic_vector(31 downto 0);
signal Connection_system_sb_0_FIC_0_AMBA_MASTER_PWRITE  : std_logic;
signal Connection_system_sb_0_FIC_0_CLK                 : std_logic;
signal Connection_system_sb_0_GPIO_0_M2F                : std_logic;
signal Connection_system_sb_0_GPIO_1_M2F                : std_logic;
signal Connection_system_sb_0_GPIO_2_M2F                : std_logic;
signal Connection_system_sb_0_GPIO_3_M2F                : std_logic;
signal Connection_system_sb_0_GPIO_4_M2F                : std_logic;
signal Connection_system_sb_0_GPIO_5_M2F                : std_logic;
signal Connection_system_sb_0_GPIO_6_M2F                : std_logic;
signal Connection_system_sb_0_GPIO_7_M2F                : std_logic;
signal Connection_system_sb_0_I2C_0_SCL_M2F             : std_logic;
signal Connection_system_sb_0_I2C_0_SCL_M2F_OE          : std_logic;
signal Connection_system_sb_0_I2C_0_SDA_M2F             : std_logic;
signal Connection_system_sb_0_I2C_0_SDA_M2F_OE          : std_logic;
signal Connection_system_sb_0_MAC_GMII_MDO              : std_logic;
signal Connection_system_sb_0_MAC_GMII_MDO_EN           : std_logic;
signal CoreAPB3_C0_0_APBmslave0_PENABLE                 : std_logic;
signal CoreAPB3_C0_0_APBmslave0_PRDATA                  : std_logic_vector(31 downto 0);
signal CoreAPB3_C0_0_APBmslave0_PREADY                  : std_logic;
signal CoreAPB3_C0_0_APBmslave0_PSELx                   : std_logic;
signal CoreAPB3_C0_0_APBmslave0_PSLVERR                 : std_logic;
signal CoreAPB3_C0_0_APBmslave0_PWRITE                  : std_logic;
signal CoreAPB3_C0_0_APBmslave1_PREADY                  : std_logic;
signal CoreAPB3_C0_0_APBmslave1_PSELx                   : std_logic;
signal CoreAPB3_C0_0_APBmslave1_PSLVERR                 : std_logic;
signal corepwm_C0_0_PWM0to0                             : std_logic_vector(0 to 0);
signal ETH_NRESET_net_0                                 : std_logic;
signal FLASH_MEM_CLK_net_0                              : std_logic;
signal FLASH_MEM_SSO_net_0                              : std_logic;
signal GMII_GTX_CLK_net_0                               : std_logic;
signal GMII_MDC_net_0                                   : std_logic;
signal GMII_TX_EN_net_0                                 : std_logic;
signal GMII_TX_ER_net_0                                 : std_logic;
signal GMII_TXD_net_0                                   : std_logic_vector(7 downto 0);
signal Nokia5110_Driver_0_driver_busy                   : std_logic;
signal USB_UART_RXD_net_0                               : std_logic;
signal Board_J8_net_1                                   : std_logic;
signal GMII_GTX_CLK_net_1                               : std_logic;
signal FLASH_MEM_SSO_net_1                              : std_logic;
signal Board_J10_net_1                                  : std_logic;
signal FLASH_MEM_CLK_net_1                              : std_logic;
signal FLASH_MEM_CLK_net_2                              : std_logic;
signal Board_J10_net_2                                  : std_logic;
signal USB_UART_RXD_net_1                               : std_logic;
signal GMII_MDC_net_1                                   : std_logic;
signal FLASH_MEM_SSO_net_2                              : std_logic;
signal GMII_TX_ER_net_1                                 : std_logic;
signal GMII_TX_EN_net_1                                 : std_logic;
signal ETH_NRESET_net_1                                 : std_logic;
signal Board_LEDs_net_1                                 : std_logic_vector(7 downto 0);
signal GMII_TXD_net_1                                   : std_logic_vector(7 downto 0);
signal Board_J7_3_net_0                                 : std_logic_vector(0 to 0);
signal Board_J7_2_net_0                                 : std_logic_vector(1 to 1);
signal Board_J7_1_net_0                                 : std_logic_vector(2 to 2);
signal Board_J7_net_1                                   : std_logic_vector(3 to 3);
signal Board_J7_0_net_0                                 : std_logic_vector(4 to 4);
signal FLASH_MEM_SDI_net_0                              : std_logic_vector(0 to 0);
signal MSS_INT_F2M_net_0                                : std_logic_vector(15 downto 0);
signal PWM_net_0                                        : std_logic_vector(1 downto 0);
signal LED_toggles_net_0                                : std_logic_vector(7 downto 0);
----------------------------------------------------------------------
-- TiedOff Signals
----------------------------------------------------------------------
signal VCC_net                                          : std_logic;
signal GND_net                                          : std_logic;
signal REFCLK_SEL_const_net_0                           : std_logic_vector(1 downto 0);
signal MSS_INT_F2M_const_net_0                          : std_logic_vector(15 downto 1);
----------------------------------------------------------------------
-- Bus Interface Nets Declarations - Unequal Pin Widths
----------------------------------------------------------------------
signal CoreAPB3_C0_0_APBmslave0_PADDR                   : std_logic_vector(31 downto 0);
signal CoreAPB3_C0_0_APBmslave0_PADDR_0_7to0            : std_logic_vector(7 downto 0);
signal CoreAPB3_C0_0_APBmslave0_PADDR_0                 : std_logic_vector(7 downto 0);
signal CoreAPB3_C0_0_APBmslave0_PADDR_1_7to0            : std_logic_vector(7 downto 0);
signal CoreAPB3_C0_0_APBmslave0_PADDR_1                 : std_logic_vector(7 downto 0);

signal CoreAPB3_C0_0_APBmslave0_PWDATA                  : std_logic_vector(31 downto 0);
signal CoreAPB3_C0_0_APBmslave0_PWDATA_0_7to0           : std_logic_vector(7 downto 0);
signal CoreAPB3_C0_0_APBmslave0_PWDATA_0                : std_logic_vector(7 downto 0);

signal CoreAPB3_C0_0_APBmslave1_PRDATA_0_31to8          : std_logic_vector(31 downto 8);
signal CoreAPB3_C0_0_APBmslave1_PRDATA_0_7to0           : std_logic_vector(7 downto 0);
signal CoreAPB3_C0_0_APBmslave1_PRDATA_0                : std_logic_vector(31 downto 0);
signal CoreAPB3_C0_0_APBmslave1_PRDATA                  : std_logic_vector(7 downto 0);


begin
----------------------------------------------------------------------
-- Constant assignments
----------------------------------------------------------------------
 VCC_net                 <= '1';
 GND_net                 <= '0';
 REFCLK_SEL_const_net_0  <= B"10";
 MSS_INT_F2M_const_net_0 <= B"000000000000000";
----------------------------------------------------------------------
-- TieOff assignments
----------------------------------------------------------------------
 FLASH_MEM_WP_N         <= '1';
 FLASH_MEM_HOLD_N       <= '1';
 COMA_MODE              <= '0';
 REFCLK_SEL(1 downto 0) <= B"10";
 Board_MOD1(1)          <= '0';
 Board_MOD1(2)          <= '0';
 Board_MOD1(3)          <= '0';
 Board_MOD1(4)          <= '0';
 Board_MOD1(5)          <= '0';
----------------------------------------------------------------------
-- Top level output port assignments
----------------------------------------------------------------------
 Board_J8_net_1         <= Board_J8_net_0(1);
 Board_J8               <= Board_J8_net_1;
 GMII_GTX_CLK_net_1     <= GMII_GTX_CLK_net_0;
 GMII_GTX_CLK           <= GMII_GTX_CLK_net_1;
 FLASH_MEM_SSO_net_1    <= FLASH_MEM_SSO_net_0;
 Board_J9               <= FLASH_MEM_SSO_net_1;
 Board_J10_net_1        <= Board_J10_net_0;
 Board_J10              <= Board_J10_net_1;
 FLASH_MEM_CLK_net_1    <= FLASH_MEM_CLK_net_0;
 Board_J11              <= FLASH_MEM_CLK_net_1;
 FLASH_MEM_CLK_net_2    <= FLASH_MEM_CLK_net_0;
 FLASH_MEM_CLK          <= FLASH_MEM_CLK_net_2;
 Board_J10_net_2        <= Board_J10_net_0;
 FLASH_MEM_SDO          <= Board_J10_net_2;
 USB_UART_RXD_net_1     <= USB_UART_RXD_net_0;
 USB_UART_RXD           <= USB_UART_RXD_net_1;
 GMII_MDC_net_1         <= GMII_MDC_net_0;
 GMII_MDC               <= GMII_MDC_net_1;
 FLASH_MEM_SSO_net_2    <= FLASH_MEM_SSO_net_0;
 FLASH_MEM_SSO          <= FLASH_MEM_SSO_net_2;
 GMII_TX_ER_net_1       <= GMII_TX_ER_net_0;
 GMII_TX_ER             <= GMII_TX_ER_net_1;
 GMII_TX_EN_net_1       <= GMII_TX_EN_net_0;
 GMII_TX_EN             <= GMII_TX_EN_net_1;
 ETH_NRESET_net_1       <= ETH_NRESET_net_0;
 ETH_NRESET             <= ETH_NRESET_net_1;
 Board_LEDs_net_1       <= Board_LEDs_net_0;
 Board_LEDs(7 downto 0) <= Board_LEDs_net_1;
 GMII_TXD_net_1         <= GMII_TXD_net_0;
 GMII_TXD(7 downto 0)   <= GMII_TXD_net_1;
 Board_J7_3_net_0(0)    <= Board_J7_3;
 Board_J7(0)            <= Board_J7_3_net_0(0);
 Board_J7_2_net_0(1)    <= Board_J7_2;
 Board_J7(1)            <= Board_J7_2_net_0(1);
 Board_J7_1_net_0(2)    <= Board_J7_1;
 Board_J7(2)            <= Board_J7_1_net_0(2);
 Board_J7_net_1(3)      <= Board_J7_net_0;
 Board_J7(3)            <= Board_J7_net_1(3);
 Board_J7_0_net_0(4)    <= Board_J7_0;
 Board_J7(4)            <= Board_J7_0_net_0(4);
 FLASH_MEM_SDI_net_0(0) <= FLASH_MEM_SDI;
 Board_MOD1(0)          <= FLASH_MEM_SDI_net_0(0);
----------------------------------------------------------------------
-- Slices assignments
----------------------------------------------------------------------
 Board_Buttons_slice_0(1) <= Board_Buttons(1);
 Board_Buttons_slice_1(0) <= Board_Buttons(0);
 Board_J8_net_0(1)        <= PWM_net_0(1);
 corepwm_C0_0_PWM0to0(0)  <= PWM_net_0(0);
----------------------------------------------------------------------
-- Concatenation assignments
----------------------------------------------------------------------
 MSS_INT_F2M_net_0 <= ( B"000000000000000" & MDINT );
 LED_toggles_net_0 <= ( Connection_system_sb_0_GPIO_7_M2F & Connection_system_sb_0_GPIO_6_M2F & Connection_system_sb_0_GPIO_5_M2F & Connection_system_sb_0_GPIO_4_M2F & Connection_system_sb_0_GPIO_3_M2F & Connection_system_sb_0_GPIO_2_M2F & Connection_system_sb_0_GPIO_1_M2F & Connection_system_sb_0_GPIO_0_M2F );
----------------------------------------------------------------------
-- Bus Interface Nets Assignments - Unequal Pin Widths
----------------------------------------------------------------------
 CoreAPB3_C0_0_APBmslave0_PADDR_0_7to0(7 downto 0) <= CoreAPB3_C0_0_APBmslave0_PADDR(7 downto 0);
 CoreAPB3_C0_0_APBmslave0_PADDR_0 <= ( CoreAPB3_C0_0_APBmslave0_PADDR_0_7to0(7 downto 0) );
 CoreAPB3_C0_0_APBmslave0_PADDR_1_7to0(7 downto 0) <= CoreAPB3_C0_0_APBmslave0_PADDR(7 downto 0);
 CoreAPB3_C0_0_APBmslave0_PADDR_1 <= ( CoreAPB3_C0_0_APBmslave0_PADDR_1_7to0(7 downto 0) );

 CoreAPB3_C0_0_APBmslave0_PWDATA_0_7to0(7 downto 0) <= CoreAPB3_C0_0_APBmslave0_PWDATA(7 downto 0);
 CoreAPB3_C0_0_APBmslave0_PWDATA_0 <= ( CoreAPB3_C0_0_APBmslave0_PWDATA_0_7to0(7 downto 0) );

 CoreAPB3_C0_0_APBmslave1_PRDATA_0_31to8(31 downto 8) <= B"000000000000000000000000";
 CoreAPB3_C0_0_APBmslave1_PRDATA_0_7to0(7 downto 0) <= CoreAPB3_C0_0_APBmslave1_PRDATA(7 downto 0);
 CoreAPB3_C0_0_APBmslave1_PRDATA_0 <= ( CoreAPB3_C0_0_APBmslave1_PRDATA_0_31to8(31 downto 8) & CoreAPB3_C0_0_APBmslave1_PRDATA_0_7to0(7 downto 0) );

----------------------------------------------------------------------
-- Component instances
----------------------------------------------------------------------
-- BIBUF_0
BIBUF_0 : BIBUF
    port map( 
        -- Inputs
        D   => Connection_system_sb_0_I2C_0_SDA_M2F,
        E   => Connection_system_sb_0_I2C_0_SDA_M2F_OE,
        -- Outputs
        Y   => BIBUF_0_Y,
        -- Inouts
        PAD => Light_SDA 
        );
-- BIBUF_1
BIBUF_1 : BIBUF
    port map( 
        -- Inputs
        D   => Connection_system_sb_0_I2C_0_SCL_M2F,
        E   => Connection_system_sb_0_I2C_0_SCL_M2F_OE,
        -- Outputs
        Y   => BIBUF_1_Y,
        -- Inouts
        PAD => Light_SCL 
        );
-- BIBUF_2
BIBUF_2 : BIBUF
    port map( 
        -- Inputs
        D   => Connection_system_sb_0_MAC_GMII_MDO,
        E   => Connection_system_sb_0_MAC_GMII_MDO_EN,
        -- Outputs
        Y   => BIBUF_2_Y,
        -- Inouts
        PAD => GMII_MDIO 
        );
-- Connection_system_sb_0
Connection_system_sb_0 : Connection_system_sb
    port map( 
        -- Inputs
        FAB_RESET_N         => VCC_net,
        DEVRST_N            => DEVRST_N,
        FIC_0_APB_M_PREADY  => Connection_system_sb_0_FIC_0_AMBA_MASTER_PREADY,
        FIC_0_APB_M_PSLVERR => Connection_system_sb_0_FIC_0_AMBA_MASTER_PSLVERR,
        SPI_1_DI_F2M        => FLASH_MEM_SDI,
        SPI_1_CLK_F2M       => GND_net,
        SPI_1_SS0_F2M       => GND_net,
        MMUART_0_RXD_F2M    => USB_UART_TXD,
        I2C_0_SDA_F2M       => BIBUF_0_Y,
        I2C_0_SCL_F2M       => BIBUF_1_Y,
        GPIO_8_F2M          => Board_Buttons_slice_1(0),
        GPIO_9_F2M          => Board_Buttons_slice_0(1),
        GPIO_10_F2M         => Nokia5110_Driver_0_driver_busy,
        MAC_GMII_RX_ER      => GMII_RX_ER,
        MAC_GMII_RX_DV      => GMII_RX_DV,
        MAC_GMII_CRS        => GMII_CRS,
        MAC_GMII_COL        => GMII_COL,
        MAC_GMII_RX_CLK     => GMII_RX_CLK,
        MAC_GMII_TX_CLK     => GMII_TX_CLK,
        MAC_GMII_GTX_CLK    => GMII_GTX_CLK_net_0,
        MAC_GMII_MDI        => BIBUF_2_Y,
        MSS_INT_F2M         => MSS_INT_F2M_net_0,
        FIC_0_APB_M_PRDATA  => Connection_system_sb_0_FIC_0_AMBA_MASTER_PRDATA,
        MAC_GMII_RXD        => GMII_RXD,
        -- Outputs
        POWER_ON_RESET_N    => OPEN,
        INIT_DONE           => OPEN,
        FIC_0_CLK           => Connection_system_sb_0_FIC_0_CLK,
        FIC_0_LOCK          => OPEN,
        FAB_CCC_GL1         => GMII_GTX_CLK_net_0,
        FAB_CCC_LOCK        => OPEN,
        MSS_READY           => ETH_NRESET_net_0,
        FIC_0_APB_M_PSEL    => Connection_system_sb_0_FIC_0_AMBA_MASTER_PSELx,
        FIC_0_APB_M_PENABLE => Connection_system_sb_0_FIC_0_AMBA_MASTER_PENABLE,
        FIC_0_APB_M_PWRITE  => Connection_system_sb_0_FIC_0_AMBA_MASTER_PWRITE,
        SPI_1_DO_M2F        => Board_J10_net_0,
        SPI_1_CLK_M2F       => FLASH_MEM_CLK_net_0,
        SPI_1_SS0_M2F       => FLASH_MEM_SSO_net_0,
        SPI_1_SS0_M2F_OE    => OPEN,
        MMUART_0_TXD_M2F    => USB_UART_RXD_net_0,
        I2C_0_SDA_M2F       => Connection_system_sb_0_I2C_0_SDA_M2F,
        I2C_0_SDA_M2F_OE    => Connection_system_sb_0_I2C_0_SDA_M2F_OE,
        I2C_0_SCL_M2F       => Connection_system_sb_0_I2C_0_SCL_M2F,
        I2C_0_SCL_M2F_OE    => Connection_system_sb_0_I2C_0_SCL_M2F_OE,
        GPIO_0_M2F          => Connection_system_sb_0_GPIO_0_M2F,
        GPIO_1_M2F          => Connection_system_sb_0_GPIO_1_M2F,
        GPIO_2_M2F          => Connection_system_sb_0_GPIO_2_M2F,
        GPIO_3_M2F          => Connection_system_sb_0_GPIO_3_M2F,
        GPIO_4_M2F          => Connection_system_sb_0_GPIO_4_M2F,
        GPIO_5_M2F          => Connection_system_sb_0_GPIO_5_M2F,
        GPIO_6_M2F          => Connection_system_sb_0_GPIO_6_M2F,
        GPIO_7_M2F          => Connection_system_sb_0_GPIO_7_M2F,
        MAC_GMII_TX_EN      => GMII_TX_EN_net_0,
        MAC_GMII_TX_ER      => GMII_TX_ER_net_0,
        MAC_GMII_MDC        => GMII_MDC_net_0,
        MAC_GMII_MDO_EN     => Connection_system_sb_0_MAC_GMII_MDO_EN,
        MAC_GMII_MDO        => Connection_system_sb_0_MAC_GMII_MDO,
        FIC_0_APB_M_PADDR   => Connection_system_sb_0_FIC_0_AMBA_MASTER_PADDR,
        FIC_0_APB_M_PWDATA  => Connection_system_sb_0_FIC_0_AMBA_MASTER_PWDATA,
        MAC_GMII_TXD        => GMII_TXD_net_0 
        );
-- CoreAPB3_C0_0
CoreAPB3_C0_0 : CoreAPB3_C0
    port map( 
        -- Inputs
        PSEL      => Connection_system_sb_0_FIC_0_AMBA_MASTER_PSELx,
        PENABLE   => Connection_system_sb_0_FIC_0_AMBA_MASTER_PENABLE,
        PWRITE    => Connection_system_sb_0_FIC_0_AMBA_MASTER_PWRITE,
        PREADYS0  => CoreAPB3_C0_0_APBmslave0_PREADY,
        PSLVERRS0 => CoreAPB3_C0_0_APBmslave0_PSLVERR,
        PREADYS1  => CoreAPB3_C0_0_APBmslave1_PREADY,
        PSLVERRS1 => CoreAPB3_C0_0_APBmslave1_PSLVERR,
        PADDR     => Connection_system_sb_0_FIC_0_AMBA_MASTER_PADDR,
        PWDATA    => Connection_system_sb_0_FIC_0_AMBA_MASTER_PWDATA,
        PRDATAS0  => CoreAPB3_C0_0_APBmslave0_PRDATA,
        PRDATAS1  => CoreAPB3_C0_0_APBmslave1_PRDATA_0,
        -- Outputs
        PREADY    => Connection_system_sb_0_FIC_0_AMBA_MASTER_PREADY,
        PSLVERR   => Connection_system_sb_0_FIC_0_AMBA_MASTER_PSLVERR,
        PSELS0    => CoreAPB3_C0_0_APBmslave0_PSELx,
        PENABLES  => CoreAPB3_C0_0_APBmslave0_PENABLE,
        PWRITES   => CoreAPB3_C0_0_APBmslave0_PWRITE,
        PSELS1    => CoreAPB3_C0_0_APBmslave1_PSELx,
        PRDATA    => Connection_system_sb_0_FIC_0_AMBA_MASTER_PRDATA,
        PADDRS    => CoreAPB3_C0_0_APBmslave0_PADDR,
        PWDATAS   => CoreAPB3_C0_0_APBmslave0_PWDATA 
        );
-- corepwm_C0_0
corepwm_C0_0 : corepwm_C0
    port map( 
        -- Inputs
        PCLK    => Connection_system_sb_0_FIC_0_CLK,
        PRESETN => ETH_NRESET_net_0,
        PENABLE => CoreAPB3_C0_0_APBmslave0_PENABLE,
        PSEL    => CoreAPB3_C0_0_APBmslave0_PSELx,
        PWRITE  => CoreAPB3_C0_0_APBmslave0_PWRITE,
        PADDR   => CoreAPB3_C0_0_APBmslave0_PADDR_0,
        PWDATA  => CoreAPB3_C0_0_APBmslave0_PWDATA,
        -- Outputs
        PREADY  => CoreAPB3_C0_0_APBmslave0_PREADY,
        PSLVERR => CoreAPB3_C0_0_APBmslave0_PSLVERR,
        PRDATA  => CoreAPB3_C0_0_APBmslave0_PRDATA,
        PWM     => PWM_net_0 
        );
-- LED_inverter_dimmer_0
LED_inverter_dimmer_0 : LED_inverter_dimmer
    port map( 
        -- Inputs
        CLK         => corepwm_C0_0_PWM0to0(0),
        LED_toggles => LED_toggles_net_0,
        -- Outputs
        Board_LEDs  => Board_LEDs_net_0 
        );
-- Nokia5110_Driver_0
Nokia5110_Driver_0 : entity work.Nokia5110_Driver
    generic map( 
        g_clk_period   => ( 10 ),
        g_clk_spi_div  => ( 50 ),
        g_frame_buffer => ( 0 ),
        g_frame_size   => ( 8 ),
        g_update_rate  => ( 4 )
        )
    port map( 
        -- Inputs
        CLK          => Connection_system_sb_0_FIC_0_CLK,
        RSTn         => ETH_NRESET_net_0,
        PSEL         => CoreAPB3_C0_0_APBmslave1_PSELx,
        PENABLE      => CoreAPB3_C0_0_APBmslave0_PENABLE,
        PWRITE       => CoreAPB3_C0_0_APBmslave0_PWRITE,
        PADDR        => CoreAPB3_C0_0_APBmslave0_PADDR_1,
        PWDATA       => CoreAPB3_C0_0_APBmslave0_PWDATA_0,
        -- Outputs
        driver_busy  => Nokia5110_Driver_0_driver_busy,
        SPIDO        => Board_J7_2,
        SPICLK       => Board_J7_3,
        data_command => Board_J7_1,
        chip_enable  => Board_J7_0,
        RSTout       => Board_J7_net_0,
        PREADY       => CoreAPB3_C0_0_APBmslave1_PREADY,
        PSLVERR      => CoreAPB3_C0_0_APBmslave1_PSLVERR,
        PRDATA       => CoreAPB3_C0_0_APBmslave1_PRDATA 
        );

end RTL;
