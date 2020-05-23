----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    15:21:55 04/22/2020 
-- Design Name: 
-- Module Name:    Banc_de_Registre - Behavioral 
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

entity Banc_de_Registre is
    Port ( addrA : in  STD_LOGIC_VECTOR (3 downto 0);
           addrB : in  STD_LOGIC_VECTOR (3 downto 0);
           addrW : in  STD_LOGIC_VECTOR (3 downto 0);
           DATA : in  STD_LOGIC_VECTOR (7 downto 0);
           RST : in  STD_LOGIC;
           CLK : in  STD_LOGIC;
           QA : out  STD_LOGIC_VECTOR (7 downto 0);
           QB : out  STD_LOGIC_VECTOR (7 downto 0);
           W : in  STD_LOGIC);
end Banc_de_Registre;

architecture Behavioral of Banc_de_Registre is
	type register_table is array (0 to 15) of std_logic_vector(7 downto 0);
	signal registers : register_table;
begin

      
QA <= (others =>'0') when RST = '0' else
		 DATA when addrA = addrW else
		registers(to_integer(unsigned(addrA)));
QB <= (others =>'0') when RST = '0' else
		DATA when addrB = addrW else
		registers(to_integer(unsigned(addrB)));

	process (CLK) is


	begin

		if(rising_edge(CLK)) then 
			if (RST = '0') then
				registers <= (others=>(others=>'0'));
			else
				if ( W = '1' ) then
					registers(to_integer(unsigned(addrW))) <= DATA;						
				end if;
			end if;
		end if;
		 
	end process;



end Behavioral;

