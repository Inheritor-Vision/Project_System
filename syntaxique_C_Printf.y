%{
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>

	int yydebug = 1;
	int yyerror(char *s);
	int yylex();
	FILE * f;
    
%}


%token tInt tMain tReturn tPrintf tConst tVoid tAdd tSub tMul 
%token tEqu tSC tDiv tOCB tCCB tORB tCRB tComma tCR tVar 
%token tValInt tDecVal tExpVal

%left tAdd tSub
%left tMul tDiv
%start S
%union
{
    int integerValue;
    char *stringValue;
};
%%
S: Main Body;


Main:
	tMain tORB tVoid tCRB {printf("Main\n");}
	| tMain tORB tCRB {printf("Main\n");};


Body: 
	tOCB Instructions tReturn tValInt tSC tCRB {printf("Body\n");}
	| tOCB Instructions tCCB {printf("Body\n");};

Instructions: 
	Instruction Instructions {printf("Instructions\n");}
	| {};

Instruction: 
	Assign {printf("Instruction\n");}
	| Initialize {printf("Instruction\n");}
	| Declare {printf("Instruction\n");}
	| tPrintf tORB tVar tCRB tSC {printf("Instruction\n");};

	
Assign:
	tVar tEqu Expression tSC {printf("Assign\n");};


RepInitialize:
	tVar {printf("RepInitialize\n");}
	| tVar tComma RepInitialize {printf("RepInitialize\n");};

Initialize:
	  tInt RepInitialize tEqu Expression tSC {printf("Initialize\n");}
	| tInt tConst RepInitialize tEqu Expression tSC {printf("Initialize\n");};

 

Repdeclare: 
	  tVar tComma Repdeclare {printf("Repdeclare + %s\n", $<stringValue>1);}
	| tVar tSC {printf("Repdeclare + %s\n", $<stringValue>1);};

Declare:
	tInt Repdeclare {printf("Declare\n");}
	| tInt tConst Repdeclare {printf("Declare\n");};

IntegerValue:
	  tValInt {printf("IntegerValue\n");}
	| tDecVal {printf("IntegerValue\n");}
	| tExpVal {printf("IntegerValue\n");};
Expression:
	  IntegerValue {printf("Expression IntegerValue\n");}
	| tVar {printf("Expression tVar\n");}
	| Expression tAdd Expression {printf("tAdd\n");}
	| Expression tSub Expression {printf("tSub\n");}
	| Expression tMul Expression {printf("tMul\n");}
	| Expression tDiv Expression {printf("tDiv\n");}
	| tSub Expression %prec tMul {printf("tSub Expression\n");}
	| tAdd Expression %prec tMul {printf("tAdd Expression\n");}
	| tORB Expression tCRB {printf("tORB Expression tCRB\n");};

%%






int yyerror(char *s){
	printf("%s\n",s);
	exit(1);
}
int main(void){
	printf("\nDebut de l'analyse syntaxique\n");
	
	yyparse();
	printf("\n\nFin de l'analyse syntaxique\n");
}


