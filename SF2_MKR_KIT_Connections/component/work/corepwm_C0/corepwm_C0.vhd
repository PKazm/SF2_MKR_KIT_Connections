----------------------------------------------------------------------
-- Created by SmartDesign Sun Mar 29 03:23:21 2020
-- Version: v12.1 12.600.0.14
----------------------------------------------------------------------

----------------------------------------------------------------------
-- Libraries
----------------------------------------------------------------------
library ieee;
use ieee.std_logic_1164.all;

library smartfusion2;
use smartfusion2.all;
library COREPWM_LIB;
use COREPWM_LIB.all;
use COREPWM_LIB.components.all;
----------------------------------------------------------------------
-- corepwm_C0 entity declaration
----------------------------------------------------------------------
entity corepwm_C0 is
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
end corepwm_C0;
----------------------------------------------------------------------
-- corepwm_C0 architecture body
----------------------------------------------------------------------
architecture RTL of corepwm_C0 is
----------------------------------------------------------------------
-- Component declarations
----------------------------------------------------------------------
-- corepwm   -   Actel:DirectCore:corepwm:4.3.101
-- using entity instantiation for component corepwm
----------------------------------------------------------------------
-- Signal declarations
----------------------------------------------------------------------
signal APBslave_PRDATA        : std_logic_vector(31 downto 0);
signal APBslave_PREADY        : std_logic;
signal APBslave_PSLVERR       : std_logic;
signal PWM_0                  : std_logic_vector(1 downto 0);
signal APBslave_PRDATA_net_0  : std_logic_vector(31 downto 0);
signal APBslave_PREADY_net_0  : std_logic;
signal APBslave_PSLVERR_net_0 : std_logic;
signal PWM_0_net_0            : std_logic_vector(1 downto 0);
----------------------------------------------------------------------
-- TiedOff Signals
----------------------------------------------------------------------
signal GND_net                : std_logic;

begin
----------------------------------------------------------------------
-- Constant assignments
----------------------------------------------------------------------
 GND_net    <= '0';
----------------------------------------------------------------------
-- Top level output port assignments
----------------------------------------------------------------------
 APBslave_PRDATA_net_0  <= APBslave_PRDATA;
 PRDATA(31 downto 0)    <= APBslave_PRDATA_net_0;
 APBslave_PREADY_net_0  <= APBslave_PREADY;
 PREADY                 <= APBslave_PREADY_net_0;
 APBslave_PSLVERR_net_0 <= APBslave_PSLVERR;
 PSLVERR                <= APBslave_PSLVERR_net_0;
 PWM_0_net_0            <= PWM_0;
 PWM(1 downto 0)        <= PWM_0_net_0;
----------------------------------------------------------------------
-- Component instances
----------------------------------------------------------------------
-- corepwm_C0_0   -   Actel:DirectCore:corepwm:4.3.101
corepwm_C0_0 : entity COREPWM_LIB.corepwm
    generic map( 
        APB_DWIDTH          => ( 32 ),
        CONFIG_MODE         => ( 0 ),
        DAC_MODE1           => ( 0 ),
        DAC_MODE2           => ( 0 ),
        DAC_MODE3           => ( 0 ),
        DAC_MODE4           => ( 0 ),
        DAC_MODE5           => ( 0 ),
        DAC_MODE6           => ( 0 ),
        DAC_MODE7           => ( 0 ),
        DAC_MODE8           => ( 0 ),
        DAC_MODE9           => ( 0 ),
        DAC_MODE10          => ( 0 ),
        DAC_MODE11          => ( 0 ),
        DAC_MODE12          => ( 0 ),
        DAC_MODE13          => ( 0 ),
        DAC_MODE14          => ( 0 ),
        DAC_MODE15          => ( 0 ),
        DAC_MODE16          => ( 0 ),
        FAMILY              => ( 19 ),
        FIXED_PERIOD        => ( 1 ),
        FIXED_PERIOD_EN     => ( 0 ),
        FIXED_PRESCALE      => ( 0 ),
        FIXED_PRESCALE_EN   => ( 0 ),
        FIXED_PWM_NEG_EN1   => ( 0 ),
        FIXED_PWM_NEG_EN2   => ( 0 ),
        FIXED_PWM_NEG_EN3   => ( 0 ),
        FIXED_PWM_NEG_EN4   => ( 0 ),
        FIXED_PWM_NEG_EN5   => ( 0 ),
        FIXED_PWM_NEG_EN6   => ( 0 ),
        FIXED_PWM_NEG_EN7   => ( 0 ),
        FIXED_PWM_NEG_EN8   => ( 0 ),
        FIXED_PWM_NEG_EN9   => ( 0 ),
        FIXED_PWM_NEG_EN10  => ( 0 ),
        FIXED_PWM_NEG_EN11  => ( 0 ),
        FIXED_PWM_NEG_EN12  => ( 0 ),
        FIXED_PWM_NEG_EN13  => ( 0 ),
        FIXED_PWM_NEG_EN14  => ( 0 ),
        FIXED_PWM_NEG_EN15  => ( 0 ),
        FIXED_PWM_NEG_EN16  => ( 0 ),
        FIXED_PWM_NEGEDGE1  => ( 0 ),
        FIXED_PWM_NEGEDGE2  => ( 0 ),
        FIXED_PWM_NEGEDGE3  => ( 0 ),
        FIXED_PWM_NEGEDGE4  => ( 0 ),
        FIXED_PWM_NEGEDGE5  => ( 0 ),
        FIXED_PWM_NEGEDGE6  => ( 0 ),
        FIXED_PWM_NEGEDGE7  => ( 0 ),
        FIXED_PWM_NEGEDGE8  => ( 0 ),
        FIXED_PWM_NEGEDGE9  => ( 0 ),
        FIXED_PWM_NEGEDGE10 => ( 0 ),
        FIXED_PWM_NEGEDGE11 => ( 0 ),
        FIXED_PWM_NEGEDGE12 => ( 0 ),
        FIXED_PWM_NEGEDGE13 => ( 0 ),
        FIXED_PWM_NEGEDGE14 => ( 0 ),
        FIXED_PWM_NEGEDGE15 => ( 0 ),
        FIXED_PWM_NEGEDGE16 => ( 0 ),
        FIXED_PWM_POS_EN1   => ( 1 ),
        FIXED_PWM_POS_EN2   => ( 1 ),
        FIXED_PWM_POS_EN3   => ( 1 ),
        FIXED_PWM_POS_EN4   => ( 1 ),
        FIXED_PWM_POS_EN5   => ( 1 ),
        FIXED_PWM_POS_EN6   => ( 1 ),
        FIXED_PWM_POS_EN7   => ( 1 ),
        FIXED_PWM_POS_EN8   => ( 1 ),
        FIXED_PWM_POS_EN9   => ( 1 ),
        FIXED_PWM_POS_EN10  => ( 1 ),
        FIXED_PWM_POS_EN11  => ( 1 ),
        FIXED_PWM_POS_EN12  => ( 1 ),
        FIXED_PWM_POS_EN13  => ( 1 ),
        FIXED_PWM_POS_EN14  => ( 1 ),
        FIXED_PWM_POS_EN15  => ( 1 ),
        FIXED_PWM_POS_EN16  => ( 1 ),
        FIXED_PWM_POSEDGE1  => ( 0 ),
        FIXED_PWM_POSEDGE2  => ( 0 ),
        FIXED_PWM_POSEDGE3  => ( 0 ),
        FIXED_PWM_POSEDGE4  => ( 0 ),
        FIXED_PWM_POSEDGE5  => ( 0 ),
        FIXED_PWM_POSEDGE6  => ( 0 ),
        FIXED_PWM_POSEDGE7  => ( 0 ),
        FIXED_PWM_POSEDGE8  => ( 0 ),
        FIXED_PWM_POSEDGE9  => ( 0 ),
        FIXED_PWM_POSEDGE10 => ( 0 ),
        FIXED_PWM_POSEDGE11 => ( 0 ),
        FIXED_PWM_POSEDGE12 => ( 0 ),
        FIXED_PWM_POSEDGE13 => ( 0 ),
        FIXED_PWM_POSEDGE14 => ( 0 ),
        FIXED_PWM_POSEDGE15 => ( 0 ),
        FIXED_PWM_POSEDGE16 => ( 0 ),
        PWM_NUM             => ( 2 ),
        PWM_STRETCH_VALUE1  => ( 0 ),
        PWM_STRETCH_VALUE2  => ( 0 ),
        PWM_STRETCH_VALUE3  => ( 0 ),
        PWM_STRETCH_VALUE4  => ( 0 ),
        PWM_STRETCH_VALUE5  => ( 0 ),
        PWM_STRETCH_VALUE6  => ( 0 ),
        PWM_STRETCH_VALUE7  => ( 0 ),
        PWM_STRETCH_VALUE8  => ( 0 ),
        PWM_STRETCH_VALUE9  => ( 0 ),
        PWM_STRETCH_VALUE10 => ( 0 ),
        PWM_STRETCH_VALUE11 => ( 0 ),
        PWM_STRETCH_VALUE12 => ( 0 ),
        PWM_STRETCH_VALUE13 => ( 0 ),
        PWM_STRETCH_VALUE14 => ( 0 ),
        PWM_STRETCH_VALUE15 => ( 0 ),
        PWM_STRETCH_VALUE16 => ( 0 ),
        SEPARATE_PWM_CLK    => ( 0 ),
        SHADOW_REG_EN1      => ( 0 ),
        SHADOW_REG_EN2      => ( 0 ),
        SHADOW_REG_EN3      => ( 0 ),
        SHADOW_REG_EN4      => ( 0 ),
        SHADOW_REG_EN5      => ( 0 ),
        SHADOW_REG_EN6      => ( 0 ),
        SHADOW_REG_EN7      => ( 0 ),
        SHADOW_REG_EN8      => ( 0 ),
        SHADOW_REG_EN9      => ( 0 ),
        SHADOW_REG_EN10     => ( 0 ),
        SHADOW_REG_EN11     => ( 0 ),
        SHADOW_REG_EN12     => ( 0 ),
        SHADOW_REG_EN13     => ( 0 ),
        SHADOW_REG_EN14     => ( 0 ),
        SHADOW_REG_EN15     => ( 0 ),
        SHADOW_REG_EN16     => ( 0 ),
        TACH_EDGE1          => ( 0 ),
        TACH_EDGE2          => ( 0 ),
        TACH_EDGE3          => ( 0 ),
        TACH_EDGE4          => ( 0 ),
        TACH_EDGE5          => ( 0 ),
        TACH_EDGE6          => ( 0 ),
        TACH_EDGE7          => ( 0 ),
        TACH_EDGE8          => ( 0 ),
        TACH_EDGE9          => ( 0 ),
        TACH_EDGE10         => ( 0 ),
        TACH_EDGE11         => ( 0 ),
        TACH_EDGE12         => ( 0 ),
        TACH_EDGE13         => ( 0 ),
        TACH_EDGE14         => ( 0 ),
        TACH_EDGE15         => ( 0 ),
        TACH_EDGE16         => ( 0 ),
        TACH_NUM            => ( 1 ),
        TACHINT_ACT_LEVEL   => ( 0 )
        )
    port map( 
        -- Inputs
        PADDR     => PADDR,
        PCLK      => PCLK,
        PENABLE   => PENABLE,
        PRESETN   => PRESETN,
        PSEL      => PSEL,
        PWDATA    => PWDATA,
        TACHIN(0) => GND_net, -- tied to '0' from definition
        PWRITE    => PWRITE,
        PWM_CLK   => GND_net, -- tied to '0' from definition
        -- Outputs
        PRDATA    => APBslave_PRDATA,
        PREADY    => APBslave_PREADY,
        PSLVERR   => APBslave_PSLVERR,
        TACHINT   => OPEN,
        PWM       => PWM_0 
        );

end RTL;
