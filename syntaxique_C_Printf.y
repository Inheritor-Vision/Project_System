%{
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	extern int mylineno;
	int yydebug = 1;
	int yyerror(char *s);
	int yylex();
	FILE * f;
    
%}


%token tInt tMain tReturn tPrintf tConst tVoid tAdd tSub tMul 
%token tEqu tSC tDiv tOCB tCCB tORB tCRB tComma tCR tVar 
%token tValInt tDecVal tExpVal tIf tElse tEquEqu tSupEqu tInfEqu
%token tSup tInf tWhile tEt

%left tAdd tSub
%left tMul tDiv
%start S
%union
{
    int integerValue;
    char *stringValue;
};
%%
S:  Functions ;



Functions:
	Function Functions {printf("Functions\n");}
	| {};


RepFunction:
	tComma tInt tVar {printf("RepFunction1 ");}
	| tInt tVar Repdeclare {printf("RepFunction2 ");}
	| {};

Funct:
	tMain tORB Vide tCRB Body {printf("Funct1 ");}
	| tVar tORB RepFunction tCRB Body {printf("Funct2 ");};
FunctReturn: 
	tMain tORB Vide tCRB BodyReturn {printf("FunctReturn1 ");}
	| tORB RepFunction tCRB BodyReturn {printf("FunctReturn2 ");};
Function:
	tVoid Funct {printf("Function1 ");}
	| Funct  {printf("Function2 ");}
	| tInt FunctReturn  {printf("Function3 ");};

Vide:
	tVoid
	| ;
InitFunc:
	tOCB {printf("InitFunc ");};


Body: 
	InitFunc Instructions tCCB {printf("Body1 ");}
	| {fprintf(stderr,"Error l%d: No body detected, maybe  { or } missing\n",mylineno);exit(EXIT_FAILURE);};

Return:
	tReturn Expression tSC {printf("Return1 ");} 
	| {fprintf(stderr,"Error l%d: No return detected\n",mylineno);exit(EXIT_FAILURE);};

BodyReturn:
	InitFunc Instructions Return tCCB {printf("BodyReturn1 ");}
	| {fprintf(stderr,"Error l%d: No body detected, maybe  { or } missing\n",mylineno);exit(EXIT_FAILURE);};




Instructions: 
	Instruction Instructions {printf("Instructions1 ");}
	| ;

Instruction: 
	Assign {printf("Instruction1 \n");}
	| Initialize {printf("Instruction2 \n");}
	| Declare {printf("Instruction3 \n");}
	| tPrintf tORB tVar tCRB tSC {printf("Instruction4 \n");}
	| ConditionnalJump {printf("Instruction5 \n");};

ConditionnalJump:
	tIf tORB Expression tCRB InitIf Instructions EndIf {printf("ConditionnalJump1 ");}
	| tIf tORB Expression tCRB InitIf Instructions EndIf InitElse Instructions EndIf{printf("ConditionnalJump2 ");}
	| tWhile WhileORB Expression tCRB InitWhile Instructions EndWhile {printf("ConditionnalJump3 ");};

InitIf:
	tOCB {printf("InitIf ");};
InitElse:
	tElse tOCB {printf("InitElse ");};

EndIf:
	tCCB {printf("EndIf ");};

InitWhile:
	tOCB {printf("InitWhile ");};

EndWhile:
	tCCB {printf("EndWhile ");};

WhileORB:
	tORB{printf("WhileORB ");};



	
Assign:
	tVar tEqu Expression tSC {printf("Assign ");};
		


RepInitialize:
	tVar {printf("RepInitialize1 ");}
	| tVar tComma RepInitialize {printf("RepInitialize2 ");};

Initialize:
	  tInt RepInitialize tEqu Expression tSC {printf("Initialize1 ");}
	| tInt tConst RepInitialize tEqu Expression tSC {printf("Initialize2 ");}
	| tInt tMul RepInitialize tEqu Expression tSC {printf("Initialize3 ");}
	| tInt tMul tConst  RepInitialize tEqu Expression tSC {printf("Initialize4 ");};

 

Repdeclare: 
	  tVar tComma Repdeclare {printf("Repdeclare1 ");}
	| tVar tSC {printf("Repdeclare2 ");};

Declare:
	tInt Repdeclare {printf("Declare1");}
	| tInt tConst Repdeclare {printf("Declare2 ");}
	| tInt tMul Repdeclare {printf("Declare3 ");}
	| tInt tMul tConst Repdeclare {printf("Declare4 ");};

IntegerValue:
	  tValInt {printf("IntegerValue ");}
	| tDecVal {}
	| tExpVal {};
Expression:
	  IntegerValue {printf("");}
	| tVar {printf("");}
	| tEt tVar {printf("");}
	| Expression tAdd Expression {printf("");}
	| Expression tSub Expression {printf("");}
	| Expression tMul Expression {printf("");}
	| Expression tDiv Expression {printf("");}
	| tSub Expression %prec tMul {}
	| tAdd Expression %prec tMul {}
	| tORB Expression tCRB {printf("");};

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


