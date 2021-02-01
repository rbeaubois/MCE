----------------------------------------------------------------------------------
-- Check concat order
----------------------------------------------------------------------------------

library ieee;
use ieee.std_logic_1164.all;


entity concat is
    Port ( 
		-- Inputs
        a,b,c,d,e,f,g   :	in  std_logic;
        -- Outputs
        s               :   out std_logic_vector(6 downto 0)
    );
end concat;


architecture ar of concat is
begin

    s <= (a,b,c,d,e,f,g);
--  s <= (6,5,4,3,2,1,0);
    
end ar;