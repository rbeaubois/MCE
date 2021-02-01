----------------------------------------------------------------------------------
-- Compteur 4 bits
----------------------------------------------------------------------------------

library ieee;
use ieee.std_logic_1164.all;
use ieee.std_numeric_std.all;   -- Used for unsigned type

entity compteur_4b is
    Port ( 
        -- Inputs
        -- ...
        -- Outputs
        -- ...
    );
end entity;

architecture rtl of compteur_4b is
    -- Signaux intermédiaires
    -- ...
begin

    -- Fonctionnement du compteur synchrone
    gestion_compteur : process(...)
    begin
        if ... then
            -- ...
        elsif ... then
            -- ...
        end if;
    end process;

    -- Assignation du signal de sortie
    -- ...

    
end rtl;