----------------------------------------------------------------------------------
-- Compteur 4 bits : 0 à 15
----------------------------------------------------------------------------------

library ieee;
use ieee.std_logic_1164.all;
use ieee.std_numeric_std.all;

entity compteur_4b is
    Port ( 
        -- Inputs
        clk             : in std_logic;     -- Horloge
        rst             : in std_logic;     -- Reset
        en              : in std_logic;     -- Enable (activation du compteur)
        inc             : in std_logic;     -- Incrément (+ si 1, - si 0)
        -- Outputs
        s               : out std_logic_vector(3 downto 0)
    );
end entity;

architecture rtl of compteur_4b is
    signal compteur : unsigned(3 downto 0) := (others=>'0'); -- Signal intermédiaire
begin

    process(clk,rst)
    begin
        -- Remise à zéro
        if rst = '1' then
            compteur <= (others=>'0');
        -- Front montant d'horloge
        elsif rising_edge(clk) then
            -- Activation compteur/décompteur
            if en = '1' then
                -- Incrémente le compteur
                if inc = '1' then
                    if compteur = 15 then
                        compteur <= (others=>'0');
                    else
                        compteur <= compteur + 1;
                    end if;
                -- Décrémente le compteur
                elsif inc = '0' then
                    if compteur = 0 then
                        compteur <= 15;
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