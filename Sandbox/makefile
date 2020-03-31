all: Sandbox.exe
Sandbox.exe: ../src/conditionaljump.c ../src/symboltable.c ../src/tvartable.c C_Sandbox.c ../src/write.c
	gcc C_Sandbox.c ../src/conditionaljump.c ../src/symboltable.c ../src/tvartable.c ../src/write.c -o Sandbox.exe