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
			-- AFC 1 15 : 
			-- 0000 0000:C | 0000 1111:B | 0000 0001:A | 0000 0110:OP
			instructions(0) <= "00000000000011110000000100000110";
			-- NOP
			-- 0000 0000:C | 0000 0000:B | 0000 0000:A | 0000 0000:OP
			instructions(1) <= (others=>'0');
			-- NOP
			-- 0000 0000:C | 0000 0000:B | 0000 0000:A | 0000 0000:OP
			instructions(2) <= (others=>'0');	
			-- NOP
			-- 0000 0000:C | 0000 0000:B | 0000 0000:A | 0000 0000:OP
			instructions(3) <= (others=>'0');
			-- NOP
			-- 0000 0000:C | 0000 0000:B | 0000 0000:A | 0000 0000:OP
			instructions(4) <= (others=>'0');
			-- COP 2 1 : 
			-- 0000 0000:C | 0000 0001:B | 0000 0010:A | 0000 0101:OP
			instructions(5) <= "00000000000000010000001000000101";
			-- NOP
			-- 0000 0000:C | 0000 0000:B | 0000 0000:A | 0000 0000:OP
			instructions(6) <= (others=>'0');
			-- NOP
			-- 0000 0000:C | 0000 0000:B | 0000 0000:A | 0000 0000:OP
			instructions(7) <= (others=>'0');	
			-- NOP
			-- 0000 0000:C | 0000 0000:B | 0000 0000:A | 0000 0000:OP
			instructions(8) <= (others=>'0');
			-- NOP
			-- 0000 0000:C | 0000 0000:B | 0000 0000:A | 0000 0000:OP
			instructions(9) <= (others=>'0');
			-- AFC 3 3 : 
			-- 0000 0000:C | 0000 0011:B | 0000 0011:A | 0000 0110:OP
			instructions(10) <= "00000000000000110000001100000110";
			-- NOP
			-- 0000 0000:C | 0000 0000:B | 0000 0000:A | 0000 0000:OP
			instructions(11) <= (others=>'0');
			-- NOP
			-- 0000 0000:C | 0000 0000:B | 0000 0000:A | 0000 0000:OP
			instructions(12) <= (others=>'0');	
			-- NOP
			-- 0000 0000:C | 0000 0000:B | 0000 0000:A | 0000 0000:OP
			instructions(13) <= (others=>'0');
			-- NOP
			-- 0000 0000:C | 0000 0000:B | 0000 0000:A | 0000 0000:OP
			instructions(14) <= (others=>'0');
			-- COP 4 3 : 
			-- 0000 0000:C | 0000 0011:B | 0000 0100:A | 0000 0101:OP
			instructions(15) <= "00000000000000110000010000000101";
			-- NOP
			-- 0000 0000:C | 0000 0000:B | 0000 0000:A | 0000 0000:OP
			instructions(16) <= (others=>'0');
			-- NOP
			-- 0000 0000:C | 0000 0000:B | 0000 0000:A | 0000 0000:OP
			instructions(17) <= (others=>'0');	
			-- NOP
			-- 0000 0000:C | 0000 0000:B | 0000 0000:A | 0000 0000:OP
			instructions(18) <= (others=>'0');
			-- NOP
			-- 0000 0000:C | 0000 0000:B | 0000 0000:A | 0000 0000:OP
			instructions(19) <= (others=>'0');
			-- COP 5 4 : 
			-- 0000 0000:C | 0000 0100:B | 0000 0101:A | 0000 0101:OP
			instructions(20) <= "00000000000001000000010100000101";
			-- NOP
			-- 0000 0000:C | 0000 0000:B | 0000 0000:A | 0000 0000:OP
			instructions(21) <= (others=>'0');
			-- NOP
			-- 0000 0000:C | 0000 0000:B | 0000 0000:A | 0000 0000:OP
			instructions(22) <= (others=>'0');	
			-- NOP
			-- 0000 0000:C | 0000 0000:B | 0000 0000:A | 0000 0000:OP
			instructions(23) <= (others=>'0');
			-- NOP
			-- 0000 0000:C | 0000 0000:B | 0000 0000:A | 0000 0000:OP
			instructions(24) <= (others=>'0');
			-- ADD 6 5 5 : 
			-- 0000 0101:C | 0000 0101:B | 0000 0110:A | 0000 0001:OP
			instructions(25) <= "00000101000001010000011000000001";
			-- NOP
			-- 0000 0000:C | 0000 0000:B | 0000 0000:A | 0000 0000:OP
			instructions(26) <= (others=>'0');
			-- NOP
			-- 0000 0000:C | 0000 0000:B | 0000 0000:A | 0000 0000:OP
			instructions(27) <= (others=>'0');	
			-- NOP
			-- 0000 0000:C | 0000 0000:B | 0000 0000:A | 0000 0000:OP
			instructions(28) <= (others=>'0');
			-- NOP
			-- 0000 0000:C | 0000 0000:B | 0000 0000:A | 0000 0000:OP
			instructions(29) <= (others=>'0');
			-- SUB 7 1 5 : 
			-- 0000 0101:C | 0000 0001:B | 0000 0111:A | 0000 0011:OP
			instructions(30) <= "00000101000000010000011100000011";
			-- NOP
			-- 0000 0000:C | 0000 0000:B | 0000 0000:A | 0000 0000:OP
			instructions(31) <= (others=>'0');
			-- NOP
			-- 0000 0000:C | 0000 0000:B | 0000 0000:A | 0000 0000:OP
			instructions(32) <= (others=>'0');	
			-- NOP
			-- 0000 0000:C | 0000 0000:B | 0000 0000:A | 0000 0000:OP
			instructions(33) <= (others=>'0');
			-- NOP
			-- 0000 0000:C | 0000 0000:B | 0000 0000:A | 0000 0000:OP
			instructions(34) <= (others=>'0');
			-- MUL 8 5 5 : 
			-- 0000 0101:C | 0000 0101:B | 0000 1000:A | 0000 0010:OP
			instructions(35) <= "00000101000001010000100000000010";
			-- NOP
			-- 0000 0000:C | 0000 0000:B | 0000 0000:A | 0000 0000:OP
			instructions(36) <= (others=>'0');
			-- NOP
			-- 0000 0000:C | 0000 0000:B | 0000 0000:A | 0000 0000:OP
			instructions(37) <= (others=>'0');	
			-- NOP
			-- 0000 0000:C | 0000 0000:B | 0000 0000:A | 0000 0000:OP
			instructions(38) <= (others=>'0');
			-- NOP
			-- 0000 0000:C | 0000 0000:B | 0000 0000:A | 0000 0000:OP
			instructions(39) <= (others=>'0');
			-- LOAD 9 1 : 
			-- 0000 0000:C | 0000 0001:B | 0000 1001:A | 0000 0111:OP
			instructions(40) <= "00000000000000010000100100000111";
			-- NOP
			-- 0000 0000:C | 0000 0000:B | 0000 0000:A | 0000 0000:OP
			instructions(41) <= (others=>'0');
			-- NOP
			-- 0000 0000:C | 0000 0000:B | 0000 0000:A | 0000 0000:OP
			instructions(42) <= (others=>'0');	
			-- NOP
			-- 0000 0000:C | 0000 0000:B | 0000 0000:A | 0000 0000:OP
			instructions(43) <= (others=>'0');
			-- NOP
			-- 0000 0000:C | 0000 0000:B | 0000 0000:A | 0000 0000:OP
			instructions(44) <= (others=>'0');
			-- STR 2 1 : 
			-- 0000 0000:C | 0000 0001:B | 0000 0010:A | 0000 1000:OP
			instructions(45) <= "00000000000000010000001000001000";

			sortie <= instructions(to_integer(unsigned(addr)));
		end if;
		
	end process;


end Behavioral;

