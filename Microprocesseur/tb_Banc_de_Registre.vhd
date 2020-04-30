--------------------------------------------------------------------------------
-- Company: 
-- Engineer:
--
-- Create Date:   16:05:55 04/22/2020
-- Design Name:   
-- Module Name:   /home/vison/Bureau/INSA/4A/Projet-Systeme/Microprocesseur/tb_Banc_de_Registre.vhd
-- Project Name:  Microprocesseur
-- Target Device:  
-- Tool versions:  
-- Description:   
-- 
-- VHDL Test Bench Created by ISE for module: Banc_de_Registre
-- 
-- Dependencies:
-- 
-- Revision:
-- Revision 0.01 - File Created
-- Additional Comments:
--
-- Notes: 
-- This testbench has been automatically generated using types std_logic and
-- std_logic_vector for the ports of the unit under test.  Xilinx recommends
-- that these types always be used for the top-level I/O of a design in order
-- to guarantee that the testbench will bind correctly to the post-implementation 
-- simulation model.
--------------------------------------------------------------------------------
LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
 
-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--USE ieee.numeric_std.ALL;
 
ENTITY tb_Banc_de_Registre IS
END tb_Banc_de_Registre;
 
ARCHITECTURE behavior OF tb_Banc_de_Registre IS 
 
    -- Component Declaration for the Unit Under Test (UUT)
 
    COMPONENT Banc_de_Registre
    PORT(
         addrA : IN  std_logic_vector(3 downto 0);
         addrB : IN  std_logic_vector(3 downto 0);
         addrW : IN  std_logic_vector(3 downto 0);
         DATA : IN  std_logic_vector(7 downto 0);
         RST : IN  std_logic;
         CLK : IN  std_logic;
         QA : OUT  std_logic_vector(7 downto 0);
         QB : OUT  std_logic_vector(7 downto 0);
         W : IN  std_logic
        );
    END COMPONENT;
    

   --Inputs
   signal addrA : std_logic_vector(3 downto 0) := (others => '0');
   signal addrB : std_logic_vector(3 downto 0) := (others => '0');
   signal addrW : std_logic_vector(3 downto 0) := (others => '0');
   signal DATA : std_logic_vector(7 downto 0) := (others => '0');
   signal RST : std_logic := '0';
   signal CLK : std_logic := '0';
   signal W : std_logic := '0';

 	--Outputs
   signal QA : std_logic_vector(7 downto 0);
   signal QB : std_logic_vector(7 downto 0);

   -- Clock period definitions
   constant CLK_period : time := 10 ns;
 
BEGIN
 
	-- Instantiate the Unit Under Test (UUT)
   uut: Banc_de_Registre PORT MAP (
          addrA => addrA,
          addrB => addrB,
          addrW => addrW,
          DATA => DATA,
          RST => RST,
          CLK => CLK,
          QA => QA,
          QB => QB,
          W => W
        );

   -- Clock process definitions
   CLK_process :process
   begin
		CLK <= '0';
		wait for CLK_period/2;
		CLK <= '1';
		wait for CLK_period/2;
   end process;
 

   -- Stimulus process
   stim_proc: process
   begin		
      -- hold reset state for 100 ns.
      wait for 100 ns;	

      wait for CLK_period*10;
		
		RST <= '0';
		addrA <= "0000";
		addrB <= "0001";
		addrW <= "0011";
		W <= '1';
		DATA <= "11111111";
		
		wait for CLK_period*10;
		
		RST <= '1';
		addrA <= "0000";
		addrB <= "0001";
		addrW <= "0010";
		W <= '1';
		DATA <= "11011111";
		
		wait for CLK_period*10;
		
		RST <= '1';
		addrA <= "0010";
		addrB <= "0001";
		addrW <= "0011";
		W <= '0';
		DATA <= "11111111";
		
		wait for CLK_period*10;
		
		RST <= '1';
		addrA <= "0000";
		addrB <= "0001";
		addrW <= "0001";
		W <= '1';
		DATA <= "11111110";
		
		wait for CLK_period*10;
		
		RST <= '1';
		addrA <= "0000";
		addrB <= "0001";
		addrW <= "0010";
		W <= '1';
		DATA <= "11111100";
		
		wait for CLK_period*10;
		
		RST <= '0';
		addrA <= "0000";
		addrB <= "0001";
		addrW <= "0010";
		W <= '1';
		DATA <= "11111100";
		
		wait for CLK_period*10;
		
		RST <= '1';
		addrA <= "0000";
		addrB <= "0001";
		addrW <= "0000";
		W <= '0';
		DATA <= "11111100";
		
		

      -- insert stimulus here 

      wait;
   end process;

END;
