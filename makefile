all:  Compilator.exe Comprintlator.exe clean 

Comprintlator.exe: Comprintlator.y.tab.c Compilator.lex.yy.c 
	gcc Comprintlator.y.tab.c Compilator.lex.yy.c -o Comprintlator.exe -std=c11 -Wall -Wextra -g

Compilator.exe: Compilator.y.tab.c Compilator.lex.yy.c 
	gcc Compilator.y.tab.c Compilator.lex.yy.c src/symboltable.c src/tvartable.c -o Compilator.exe -std=c11 -Wall -Wextra -g

Comprintlator.y.tab.c: syntaxique_C_Printf.y 
	yacc -d syntaxique_C_Printf.y -o Comprintlator.y.tab.c

Compilator.lex.yy.c:lexical_C_Return.l
	lex  -o Compilator.lex.yy.c lexical_C_Return.l

Compilator.y.tab.c: syntaxique_C_Return.y
	yacc -d syntaxique_C_Return.y -o Compilator.y.tab.c


clean:
	rm -f ./make/Comprintlator.lex.yy.c
	rm -f ./make/Comprintlator.y.tab.c
	rm -f ./make/Comprintlator.y.tab.h
	rm -f ./make/Compilator.y.tab.c
	rm -f ./make/Compilator.y.tab.h

	mv -f Compilator.lex.yy.c ./make/Compilator.lex.yy.c 2>/dev/null
	mv -f Comprintlator.y.tab.c ./make/Comprintlator.y.tab.c 2>/dev/null
	mv -f Comprintlator.y.tab.h ./make/Comprintlator.y.tab.h 2>/dev/null
	mv -f Compilator.y.tab.c ./make/Compilator.y.tab.c 2>/dev/null
	mv -f Compilator.y.tab.h ./make/Compilator.y.tab.h 2>/dev/null
