LIBRARY IEEE;
USE IEEE.STD_LOGIC_1164.ALL;

ENTITY trans7seg IS
PORT (
    bin                     : IN STD_LOGIC_VECTOR(3 DOWNTO 0);  -- Codage du caractère à afficher de 0 à 15 (10=a,11=b,...)
    a, b, c, d, e, f, g     : OUT STD_LOGIC -- Commande des 7 segments
);
END ENTITY trans7seg;

ARCHITECTURE behavioral OF trans7seg IS
    signal aff7seg : STD_LOGIC_VECTOR (6 DOWNTO 0); -- signal intermédiaire
BEGIN
    (a, b, c, d, e, f, g) <= aff7seg;   -- signal intermédiaire connecté à la sortie
    
    -- Commande des segments à partir du codage du caractère 
    -- Par exemple : 
    --      pour afficher 0 le code est "0000"
    --      cela correspond à tous les semgents allumés sauf g
    --      la sortie doit donc être "0000001"
    --                               "abcdefg"
    with bin select
    aff7seg <=  
                --"abcdefg"
                "0000001" when "0000",  -- 0
                "1001111" when "0001",  -- 1
                "0010010" when "0010",  -- 2
                "0000110" when "0011",  -- 3
                "1001100" when "0100",  -- 4
                "0100100" when "0101",  -- 5
                "0100000" when "0110",  -- 6
                "0001111" when "0111",  -- 7
                "0000000" when "1000",  -- 8
                "0000100" when "1001",  -- 9
                "0001000" when "1010",  -- 10 (A)
                "1100000" when "1011",  -- 11 (b)
                "0110001" when "1100",  -- 12 (C)
                "1000010" when "1101",  -- 13 (d)
                "0110000" when "1110",  -- 14 (E)
                "0111000" when "1111",  -- 15 (F)
                "1111111" when OTHERS;  -- autres cas non gérés (tous les segments éteints)

END ARCHITECTURE behavioral;