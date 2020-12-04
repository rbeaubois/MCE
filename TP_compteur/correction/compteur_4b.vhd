----------------------------------------------------------------------------------
-- Compteur 4 bits : 0 a 15
----------------------------------------------------------------------------------

library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity compteur_4b is
    Port ( 
        -- Entrees
        clk             : in std_logic;     -- Horloge
        rst             : in std_logic;     -- Reset
        en              : in std_logic;     -- Enable (activation du compteur)
        inc             : in std_logic;     -- Increment (+ si 1, - si 0)
        -- Sorties
        s               : out std_logic_vector(3 downto 0)
    );
end entity;

architecture rtl of compteur_4b is
    signal compteur : unsigned(3 downto 0) := to_unsigned(0,4); -- Signal intermediaire
begin

    process(clk,rst)
    begin
        -- Remise a zero
        if rst = '1' then
            compteur <= (others=>'0');
        -- Front montant d'horloge
        elsif rising_edge(clk) then
            -- Activation compteur/decompteur
            if en = '1' then
                -- Incremente le compteur
                if inc = '1' then
                    if compteur = to_unsigned(15,4) then
                        compteur <= to_unsigned(0,4);
                    else
                        compteur <= compteur + 1;
                    end if;
                -- Decremente le compteur
                elsif inc = '0' then
                    if compteur = to_unsigned(0,4) then
                        compteur <= to_unsigned(15,4);
                    else
                        compteur <= compteur - 1;
                    end if;
                end if;
            end if;
        end if;
    end process;

    --
    s <= std_logic_vector(compteur);
    
end rtl;