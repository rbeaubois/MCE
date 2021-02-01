----------------------------------------------------------------------------------
-- A gauche ou à droite
--
-- Description : 
--    > sur 8 bits avec bascules D-edge (Flip-flop)
--
--    > signal d'activation : décalage des bits uniquement si le signal enable (activation)
--      est à 1
--
--    > sens de décalage avec rev pour reverse : 
--          - si rev = '0', le registre se décale dans ce sens
--              [0]  [1]  [2]  [3]  [4]  [5]  [6]  [7]   : LSB to MSB (bit de poids faible à bit de poids fort)
--              (1)->(0)->(0)->(0)->(0)->(0)->(0)->(0)
--              (0)->(1)->(0)->(0)->(0)->(0)->(0)->(0)
--          - si rev = '1', le registre se décale dans l'autre sens
--              [0]  [1]  [2]  [3]  [4]  [5]  [6]  [7]   : LSB to MSB (bit de poids faible à bit de poids fort)
--              (0)<-(1)<-(0)<-(0)<-(0)<-(0)<-(0)<-(0)
--              (1)<-(0)<-(0)<-(0)<-(0)<-(0)<-(0)<-(0)
-- Version 6 : huit bascules avec reset asynchrone, enable, sens de décalage et notions plus avancés
----------------------------------------------------------------------------------
-- RAPPEL : 
-- /!\ La boucle for VHDL peut-être utilisée mais elle différente du C/python
-- puisqu'elle génère de l'architecture donc ici bien 8 bascules D-Edge
--
-- La boucle for n'est pas au programme, c'est juste pour votre culture 

-- Bibliothèques
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

-- Entité du module
entity shift8b_v6 is
port(   
    clock   : in std_Logic;                     -- Horloge
    reset   : in std_Logic;                     -- Reset
    en      : in std_logic;                     -- Enable (activation)
    rev     : in std_logic;                     -- Reverse (inverse le sens de décalage des bits)
    d       : in std_Logic;                     -- Donnée
    s       : out std_logic_vector(7 downto 0)  -- Sortie
);
end entity;

-- Architecture module
architecture behavioral of shift8b_v6 IS
    signal reg : std_logic_vector(7 DOWNTO 0);    -- Signal intermédiaire entre les différentes bascules
begin

process(clock, reset)
begin
    -- Remise à zéro des signaux sur niveau haut du reset
    if reset ='1' then
        reg <= (others=>'0'); -- tous les bits du bus à 0
    -- Détection d'un front montant de l'horloge
    elsif rising_edge(clock) then
        -- Signal d'activation à l'état haut
        if en = '1' then
            -- Sens de décalage initial
            if rev = '0' then
                reg(0) <= d;
                for i in 7 downto 1 loop
                    reg(i) <= reg(i-1);
                end loop ;
            -- Sens de décalage inversé
            elsif rev = '1' then
                reg(7) <= d;
                for i in 7 downto 1 loop
                    reg(i-1) <= reg(i);
                end loop ;
            end if;
        end if;
    end if;
end process;

-- Assignation du signal intermédiaire à la sortie
s <= reg;

end architecture behavioral;