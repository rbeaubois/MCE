-- Bibliothèques
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

-- Entité du module
entity dec24 is
port(   
    a                   : in std_logic_vector(1 downto 0);  -- Entrée décodeur
    en                  : in std_Logic;                     -- Signal enable (activation)
    s0, s1, s2, s3      : out std_Logic                     -- Sorties décodeur
);
end entity;

-- Architecture module
architecture behavioral of dec24 IS
    signal s : std_logic_vector(3 DOWNTO 0);    -- Signal intermédiaire
begin

-- Activation décodeur
with en select
    (s3, s2, s1, s0) <=     s when '1',                     -- Activation : signal du décodeur sur la sortie du module
                            (others=>'0') when '0',         -- Désactivation : sorties du module à 0
                            (others=>'X') when others;      -- Autres cas : liberté au compilateur pour les sorties du module

-- Décodeur 2 entrée 4 sorties
with a select 
    s <=    "0001" when "00",
            "0010" when "01",
            "0100" when "10",
            "1000" when "11",
            "XXXX" when others;

end architecture behavioral;