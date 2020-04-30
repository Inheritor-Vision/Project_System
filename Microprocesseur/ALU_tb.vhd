--------------------------------------------------------------------------------
-- Company: 
-- Engineer:
--
-- Create Date:   09:56:12 04/21/2020
-- Design Name:   
-- Module Name:   /home/vison/Bureau/INSA/4A/Projet-Systeme/Microprocesseur/ALU_tb.vhd
-- Project Name:  Microprocesseur
-- Target Device:  
-- Tool versions:  
-- Description:   
-- 
-- VHDL Test Bench Created by ISE for module: ALU
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
 
ENTITY ALU_tb IS
END ALU_tb;
 
ARCHITECTURE behavior OF ALU_tb IS 
 
    -- Component Declaration for the Unit Under Test (UUT)
 
    COMPONENT ALU
    PORT(
         A : IN  std_logic_vector(7 downto 0);
         B : IN  std_logic_vector(7 downto 0);
         S : OUT  std_logic_vector(7 downto 0);
         N : OUT  std_logic;
         O : OUT  std_logic;
         Z : OUT  std_logic;
         C : OUT  std_logic;
         Ctrl_Alu : IN  std_logic_vector(2 downto 0)
        );
    END COMPONENT;
    

   --Inputs
   signal A : std_logic_vector(7 downto 0) := (others => '0');
   signal B : std_logic_vector(7 downto 0) := (others => '0');
   signal Ctrl_Alu : std_logic_vector(2 downto 0) := (others => '0');
 --  signal CLK : std_logic := '0';

 	--Outputs
   signal S : std_logic_vector(7 downto 0);
   signal N : std_logic;
   signal O : std_logic;
   signal Z : std_logic;
   signal C : std_logic;

   -- Clock period definitions
 constant simu_period : time := 10 ns;
 
BEGIN
 
	-- Instantiate the Unit Under Test (UUT)
   uut: ALU PORT MAP (
          A => A,
          B => B,
          S => S,
          N => N,
          O => O,
          Z => Z,
          C => C,
          Ctrl_Alu => Ctrl_Alu
           --CLK => CLK
        );

--   -- Clock process definitions
--   CLK_process :process
--   begin
--		CLK <= '0';
--		wait for CLK_period/2;
--		CLK <= '1';
--		wait for CLK_period/2;
--   end process;
 

   -- Stimulus process
   stim_proc: process
   begin		
      -- hold reset state for 100 ns.
      wait for 100 ns;	

      wait for simu_period*10;
		
		-- RST
		A <= "00000000";
		B <= "00000000";
		Ctrl_Alu <= "000";
		
		wait for simu_period*10;
		
		-- 0 + 15
		A <= "00000000";
		B <= "00001111";
		Ctrl_Alu <= "000";
		
		wait for simu_period*10;
		
		-- 1 + 15
		A <= "00000001";
		B <= "00001111";
		Ctrl_Alu <= "000";
		
		wait for simu_period*10;
		-- 255 + 1 Carry
		A <= "00000001";
		B <= "11111111";
		Ctrl_Alu <= "000";
		
		wait for simu_period*10;
		
		--
		A <= "00000001";
		B <= "11111111";
		Ctrl_Alu <= "000";
		
		wait for simu_period*10;
		
		A <= "00000111";
		B <= "00000011";
		Ctrl_Alu <= "001";
		wait for simu_period*10;
		
		A <= "00000111";
		B <= "00000011";
		Ctrl_Alu <= "010";
		
		wait for simu_period*10;
		
		A <= "00000111";
		B <= "00001111";
		Ctrl_Alu <= "010";

      -- insert stimulus here 
		

      wait;
   end process;

END;
