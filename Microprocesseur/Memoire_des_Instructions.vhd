----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    16:39:58 04/22/2020 
-- Design Name: 
-- Module Name:    Memoire_des_Instructions - Behavioral 
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

-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
use IEEE.NUMERIC_STD.ALL;


-- Uncomment the following library declaration if instantiating
-- any Xilinx primitives in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity Memoire_des_Instructions is
    Port ( addr : in  STD_LOGIC_VECTOR (7 downto 0);
           CLK : in  STD_LOGIC;
           sortie : out  STD_LOGIC_VECTOR (31 downto 0));
end Memoire_des_Instructions;

architecture Behavioral of Memoire_des_Instructions is
type instruction_table is array (0 to 255) of std_logic_vector(31 downto 0);
signal instructions: instruction_table := (others=>(others=>'0'));
begin

	process (CLK) is

	begin
		if(rising_edge(CLK)) then
			-- 0000 0000:C | 0000 1111:B | 0000 0001:A | 0000 0110:OP
			instructions(0) <= "00000000000011110000000100000110";
			-- 0000 0000:C | 0000 0001:B | 0000 0010:A | 0000 0101:OP
			instructions(1) <= "00000000000000010000001000000101";
			-- 0000 0000:C | 0000 0011:B | 0000 0011:A | 0000 0110:OP
			instructions(2) <= "00000000000000110000001100000110";
			-- 0000 0000:C | 0000 0011:B | 0000 0100:A | 0000 0101:OP
			instructions(3) <= "00000000000000110000010000000101";
			-- 0000 0000:C | 0000 0100:B | 0000 0101:A | 0000 0101:OP
			instructions(4) <= "00000000000001000000010100000101";
			sortie <= instructions(to_integer(unsigned(addr)));
		end if;
		
	end process;


end Behavioral;

