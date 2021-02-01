----------------------------------------------------------------------------------
-- Huit bascules : un registre à décalage (encore)
--
-- Description : 
--    > sur 8 bits avec bascules D-edge (Flip-flop)
--
--    > évolution du signal <reg>
--      [0]  [1]  [2]  [3]  [4]  [5]  [6]  [7]   : LSB to MSB (bit de poids faible à bit de poids fort)
--      (0)->(0)->(0)->(0)->(0)->(0)->(0)->(0)   : initialisation
--      (1)->(0)->(0)->(0)->(0)->(0)->(0)->(0)   : rising edge(clock) et d='1'
--      (0)->(1)->(0)->(0)->(0)->(0)->(0)->(0)   : rising edge(clock) suivant et d='0'
--      (0)->(0)->(1)->(0)->(0)->(0)->(0)->(0)   : rising edge(clock) suivant et d='0'
--      (0)->(0)->(0)->(1)->(0)->(0)->(0)->(0)   : rising edge(clock) suivant et d='0'
--
-- Version 2 : huit bascules avec reset asynchrone avec notions plus avancés
----------------------------------------------------------------------------------

-- Bibliothèques
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

-- Entité du module
entity shift8b_v2 is
port(   
    clock   : in std_Logic;                     -- Horloge
    reset   : in std_Logic;                     -- Reset
    d       : in std_Logic;                     -- Donnée
    s       : out std_logic_vector(7 downto 0)  -- Sortie
);
end entity;

-- Architecture module
architecture behavioral of shift8b_v2 IS
    signal reg : std_logic_vector(7 DOWNTO 0);    -- Signal intermédiaire entre les différentes bascules
begin

process(clock, reset)
begin
    -- Remise à zéro des signaux sur niveau haut du reset
    if reset ='1' then
        reg <= (others=>'0'); -- tous les bits du bus à 0
    -- Décalage des bits à la détection d'un front montant sur l'horloge
    elsif rising_edge(clock) then
        reg(0) <= d;
        shifting_loop : for i in 7 downto 1 loop
            reg(i) <= reg(i-1);
        end loop ; -- shifting_loop
        -- /!\ La boucle for VHDL peut-être utilisée mais elle différente du C/python
        -- puisqu'elle génère de l'architecture donc ici bien 8 bascules D-Edge
    end if;
end process;

-- Assignation du signal intermédiaire à la sortie
s <= reg;

end architecture behavioral;