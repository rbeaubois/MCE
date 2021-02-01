----------------------------------------------------------------------------------
-- Check when statement behavior
----------------------------------------------------------------------------------

library ieee;
use ieee.std_logic_1164.all;


entity mux41 is
    Port ( 
		-- Inputs
        a               :	in  std_logic_vector(1 downto 0);
        en              :   in std_logic;

        -- Outputs
        s3,s2,s1,s0     :   out std_logic
    );
end mux41;


architecture ar of mux41 is
signal s : std_logic_vector(3 downto 0);
begin

    process(en,s)
    begin
    if en = '1' then
        (s3,s2,s1,s0) <= s;
    else
        s3 <= '0';
        s2 <= '0';
        s1 <= '0';
        s0 <= '0';
    end if;
    end process;
    
    -- With/select
    with a select s <=
	    "0001" when "00",
	    "0010" when "01",
	    "0100" when "10",
        "1000" when "11",
        "XXXX" when others;
            
end ar;