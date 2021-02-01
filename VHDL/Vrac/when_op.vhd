----------------------------------------------------------------------------------
-- Check when statement behavior
----------------------------------------------------------------------------------

library ieee;
use ieee.std_logic_1164.all;


entity when_op is
    Port ( 
		-- Inputs
        a       :	in  std_logic_vector(2 downto 0);
        -- Outputs
        s       :   out std_logic_vector(1 downto 0)
    );
end when_op;


architecture ar of when_op is
-- Signals -------------------------------------------------------------------------------------------------------------
    signal 		clk_96M     		: std_logic		:= '0';		-- Main clock (calculation and main fsm)
begin

    -- With/select
    with a select s <=
	"1000" when "00",
	"0100" when "01",
	"0010" when "10",
    "0001" when "11";
    
    -- When/else
    s <=    "1000" when a = "00" else 
            "0100" when a = "01" else 
            "0010" when a = "10" else 
            "0001" when a = "11";

    -- Process + case statement
    process(a)
    begin
        case a is
            when "00" => s <= "1000";
            when "01" => s <= "0100";
            when "10" => s <= "0010";
            when "11" => s <= "0001";
            when others => report "unreachable" severity failure; -- or void
        end case;
    end process;
            
end ar;