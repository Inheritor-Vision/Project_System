----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    08:44:17 04/21/2020 
-- Design Name: 
-- Module Name:    ALU - Behavioral 
-- Project Name: 
-- Target Devices: 
-- Tool versions: 
-- Description: 
--
-- Dependencies: 
--
-- Revision: 
-- Revision 0.01 - File Created
-- Additional Comments: 
--
----------------------------------------------------------------------------------
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.STD_LOGIC_ARITH.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;

-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx primitives in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity ALU is
    Port ( A : in  STD_LOGIC_VECTOR (7 downto 0);
           B : in  STD_LOGIC_VECTOR (7 downto 0);
			  Ctrl_Alu : in  STD_LOGIC_VECTOR (2 downto 0);
           S : out  STD_LOGIC_VECTOR (7 downto 0);
           N : out  STD_LOGIC;
           O : out  STD_LOGIC;
           Z : out  STD_LOGIC;
           C : out  STD_LOGIC
            ) ;
			
end ALU;

-- 8bits int
-- CLK 
-- 3bits control
architecture Behavioral of ALU is
signal S_aux: STD_LOGIC_VECTOR (8 downto 0);
signal S_aux2: STD_LOGIC_VECTOR (15 downto 0);

begin
	--Addition
	S_aux <= (B"0"&A)+(B"0"&B) when Ctrl_Alu = "000" else
	--Soustraction
		(B"0"&A)-(B"0"&B) when Ctrl_Alu = "001" else
	--AND 
		A AND B when Ctrl_Alu = "100" else
	--OR
		A OR B when Ctrl_Alu = "101" else
	-- Reset	
		"000000000";

	--Multiplication
	S_aux2 <=	A*B when Ctrl_Alu = "010" else
	--Division
		--(A/B) when Ctrl_Alu = "011" else
	
		"0000000000000000";


		

	S <= S_aux2(7 downto 0) when Ctrl_Alu = "010" or Ctrl_Alu = "011" else
		S_aux(7 downto 0);

		
	N <= '0' when S_aux(7) = '0' else
		'1';



	O <= '1' when (S_aux2(8) = '1' or S_aux2(9) = '1' or S_aux2(10) = '1' or S_aux2(11) = '1' or S_aux2(12) = '1' 
				or S_aux2(13) = '1' or S_aux2(14) = '1'  or S_aux2(15) = '1') and Ctrl_Alu = "010" else
		'0';

	Z <= '1' when S_aux(7 downto 0) = "00000000" else 
		'0';
		
	C <= S_aux(8) when Ctrl_Alu = "000" or Ctrl_Alu = "001" else
		'0';

end Behavioral;

