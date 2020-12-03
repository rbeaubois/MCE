----------------------------------------------------------------------------------
-- Compteur 4 bits
----------------------------------------------------------------------------------

library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;       -- Used for unsigned

entity compteur_4b is
    Port ( 
        -- Entrees
        -- ...
        -- Sorties
        -- ...
    );
end entity;

architecture rtl of compteur_4b is
    -- Signaux intermediaires
    signal compteur : unsigned(3 downto 0) := to_unsigned(0,4); -- Signal intermediaire
    -- "to_unsigned(valeur, nombre de bits)" sert a affecter une valeur a un signal de type unsigned
    -- il faut également l'utiliser comme syntaxe pour les comparaisons (condition if, elsif, ...)
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