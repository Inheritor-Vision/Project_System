----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    16:18:23 04/22/2020 
-- Design Name: 
-- Module Name:    Memoire_des_Donnees - Behavioral 
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

entity Memoire_des_Donnees is
    Port ( addr : in  STD_LOGIC_VECTOR (7 downto 0);
           entree : in  STD_LOGIC_VECTOR (7 downto 0);
           RW : in  STD_LOGIC;
           RST : in  STD_LOGIC;
           CLK : in  STD_LOGIC;
           sortie : out  STD_LOGIC_VECTOR (7 downto 0));
end Memoire_des_Donnees;

architecture Behavioral of Memoire_des_Donnees is
type data_table is array (0 to 255) of std_logic_vector(7 downto 0);
signal datas : data_table;
begin

	process (CLK) is

	begin
		if(rising_edge(CLK)) then 
			if (RST = '0') then 
				sortie <= "00000000";
				datas <= (others=>(others=>'0'));
			else
				if(RW = '1') then
					sortie <= datas(to_integer(unsigned(addr)));
				else
					datas(to_integer(unsigned(addr))) <= entree;
				end if;
		
			end if;
		end if;
		
		
	end process;

end Behavioral;

