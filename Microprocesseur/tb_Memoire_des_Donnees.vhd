--------------------------------------------------------------------------------
-- Company: 
-- Engineer:
--
-- Create Date:   16:30:19 04/22/2020
-- Design Name:   
-- Module Name:   /home/vison/Bureau/INSA/4A/Projet-Systeme/Microprocesseur/tb_Memoire_des_Donnees.vhd
-- Project Name:  Microprocesseur
-- Target Device:  
-- Tool versions:  
-- Description:   
-- 
-- VHDL Test Bench Created by ISE for module: Memoire_des_Donnees
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
 
ENTITY tb_Memoire_des_Donnees IS
END tb_Memoire_des_Donnees;
 
ARCHITECTURE behavior OF tb_Memoire_des_Donnees IS 
 
    -- Component Declaration for the Unit Under Test (UUT)
 
    COMPONENT Memoire_des_Donnees
    PORT(
         addr : IN  std_logic_vector(7 downto 0);
         entree : IN  std_logic_vector(7 downto 0);
         RW : IN  std_logic;
         RST : IN  std_logic;
         CLK : IN  std_logic;
         sortie : OUT  std_logic_vector(7 downto 0)
        );
    END COMPONENT;
    

   --Inputs
   signal addr : std_logic_vector(7 downto 0) := (others => '0');
   signal entree : std_logic_vector(7 downto 0) := (others => '0');
   signal RW : std_logic := '0';
   signal RST : std_logic := '0';
   signal CLK : std_logic := '0';

 	--Outputs
   signal sortie : std_logic_vector(7 downto 0);

   -- Clock period definitions
   constant CLK_period : time := 10 ns;
 
BEGIN
 
	-- Instantiate the Unit Under Test (UUT)
   uut: Memoire_des_Donnees PORT MAP (
          addr => addr,
          entree => entree,
          RW => RW,
          RST => RST,
          CLK => CLK,
          sortie => sortie
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
		--RESET
		RST <= '0';
		addr <= "00000000";
		entree <= "00000001";
		RW <= '0';
		
		wait for CLK_period*10;
		--WRITE 1 dans 0
		RST <= '1';
		addr <= "00000000";
		entree <= "00000001";
		RW <= '0';
		
		wait for CLK_period*10;
		--READ 0
		RST <= '1';
		addr <= "00000000";
		entree <= "00000001";
		RW <= '1';
		
		wait for CLK_period*10;
		--WRITE 255 dans 1
		RST <= '1';
		addr <= "00000001";
		entree <= "11111111";
		RW <= '0';
		
		wait for CLK_period*10;
		--READ 1
		RST <= '1';
		addr <= "00000001";
		entree <= "11111111";
		RW <= '1';
		
		wait for CLK_period*10;
		-- RESET
		RST <= '0';
		addr <= "00000001";
		entree <= "11111111";
		RW <= '1';
		
		wait for CLK_period*10;
		--READ 1
		RST <= '1';
		addr <= "00000001";
		entree <= "11111111";
		RW <= '1';
		
		
		
		
		

      -- insert stimulus here 

      wait;
   end process;

END;
