----------------------------------------------------------------------------------
-- Test du compteur sur la carte avec afficheur 7 semgents et les boutons
----------------------------------------------------------------------------------

library ieee;
use ieee.std_logic_1164.all;

entity test_carte is
    Port ( 
        -- Entrees
        clk             : in std_logic;     -- Horloge
        rst             : in std_logic;     -- Reset
        en              : in std_logic;     -- Enable (activation du compteur)
        inc             : in std_logic;     -- Increment (+ si 1, - si 0)
        -- Sorties
        a,b,c,d,e,f,g   : out std_logic     -- Commande des afficheurs 7 semgents
    );
end entity;

architecture rtl of test_carte is
    signal codage_7seg : std_logic_vector(3 downto 0);
begin

    -- Instanciation du compteur
    compteur_4b_map : entity work.compteur_4b
        Port map( 
        -- Entrees
        clk             => clk, -- Horloge
        rst             => rst, -- Reset
        en              => en,  -- Enable (activation)
        inc             => inc, -- Increment/Decrement
        -- Sorties
        s               => codage_7seg  -- Sortie du compteur
    );

    -- Instanciation du transcodeur 7 segments
    trans7seg_map : entity work.trans7seg
    port map(
        -- Entrees
        bin     => codage_7seg, -- Entree du transcodeur 7 segments
        -- Sorties
        a       => a,
        b       => b,
        c       => c,
        d       => d,
        e       => e,
        f       => f,
        g       => g
    );
    
end rtl;