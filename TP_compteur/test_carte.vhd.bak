----------------------------------------------------------------------------------
-- Test du compteur sur la carte avec l'afficheur 7 semgents et les boutons
----------------------------------------------------------------------------------

library ieee;
use ieee.std_logic_1164.all;

entity test_carte is
    Port ( 
        -- Inputs
        clk             : in std_logic;     -- Horloge
        rst             : in std_logic;     -- Reset
        en              : in std_logic;     -- Enable (activation du compteur)
        inc             : in std_logic;     -- Incrément (+ si 1, - si 0)
        -- Outputs
        a,b,c,d,e,f,g   : out std_logic     -- Commande des afficheurs 7 semgents
    );
end entity;

architecture rtl of test_carte is
    signal codage_7seg : std_logic_vector(6 downto 0);
begin

    -- Instanciation du compteur
    compteur_4b_map : entity work.compteur_4b
        Port map( 
        -- Inputs
        clk             => clk, -- Horloge
        rst             => rst, -- Reset
        en              => en,  -- Enable (activation)
        inc             => inc, -- Incrément/Décrément
        -- Outputs
        s               => codage_7seg  -- Sortie du compteur
    );

    -- Instanciation du transcodeur 7 segments
    trans7seg_map : entity work.trans7seg
    port map(
        -- Input
        bin     => codage_7seg, -- Entrée du transcodeur 7 segments
        -- Outputs
        a       => a,
        b       => b,
        c       => c,
        d       => d,
        e       => e,
        f       => f,
        g       => g
    );
    
end rtl;