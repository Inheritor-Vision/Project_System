%{
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include "src/symboltable.h"
	#include "src/tvartable.h"
	
	int yydebug = 1;
	int yyerror(char *s);
	int yylex();
	void addVarray(char*);
	void freeAllVarray();
	char * strdup( const char * source );

	typedef struct {
    	char** tab;
    	int size;
	} Varray;
	Varray *RepVars;
    
%}


%token tInt tMain tReturn tPrintf tConst tVoid tAdd tSub tMul 
%token tEqu tSC tDiv tOCB tCCB tORB tCRB tComma tCR tVar 
%token tValInt tDecVal tExpVal tIf tElse tEquEqu tSupEqu tInfEqu
%token tSup tInf 

%left tAdd tSub
%left tMul tDiv
%start S
%union
{
    int integerValue;
    char *stringValue;
};
%%
S: Main Body ;


Main:
	tMain tORB tVoid tCRB {}
	| tMain tORB tCRB {}
	| {fprintf(stderr,"Error: No main detected, maybe ( or ) missing\n");exit(3);};


Body: 
	tOCB Instructions tReturn tValInt tSC tCRB {}
	| tOCB Instructions tCCB {}
	| {fprintf(stderr,"Error: No body detected, maybe  { or } missing\n");exit(3);};

Instructions: 
	Instruction Instructions {}
	| {};

Instruction: 
	Assign {}
	| Initialize {}
	| Declare {}
	| tPrintf tORB tVar tCRB tSC {}
	| ConditionnalJump;

ConditionnalJump:
	tIf tORB Expression ComparaisonOperator Expression tCRB tOCB Instructions tCCB {printf("if\n");}
	| tIf tORB Expression ComparaisonOperator Expression tCRB tOCB Instructions tCCB tElse tOCB Instructions tCCB{printf("if/else\n");};

ComparaisonOperator:
	tSup
	|tInf
	|tSupEqu
	|tInfEqu
	|tEquEqu;

	
Assign:
	tVar tEqu Expression tSC {
		fprintf(f,"%%Assignation var: %s\n",$<stringValue>1);
		write_ligne();write_int(7);write_int(0);write_int($<integerValue>3);write_endl();
		write_ligne();write_int(8); write_int(assign_var_to_local_int($<stringValue>1, 0)); write_int(0);write_endl();
		delLastVal();};
		


RepInitialize:
	tVar {addVarray($<stringValue>1);}
	| tVar tComma RepInitialize {addVarray($<stringValue>1);};

Initialize:
	  tInt RepInitialize tEqu Expression tSC {
		  for(int i = 0; i < RepVars->size; i++){
			  fprintf(f,"%%Initialize var: %s\n",RepVars->tab[i]);
			  write_ligne();write_int(7);write_int(0);write_int($<integerValue>4);write_endl();
			  write_ligne();write_int(8); write_int(initialize_var_to_local_int(RepVars->tab[i], false, true, 0)); write_int(0);write_endl();
			}
			freeAllVarray();
			delLastVal();
		}
	| tInt tConst RepInitialize tEqu Expression tSC {
		for(int i = 0; i < RepVars->size; i++){
				fprintf(f,"%%Initialize var: %s\n",RepVars->tab[i]);
				write_ligne();write_int(7);write_int(0);write_int($<integerValue>5);write_endl();
			  	write_ligne();write_int(8); write_int(initialize_var_to_local_int(RepVars->tab[i], true, true, 0)); write_int(0);write_endl();
			}
			freeAllVarray();
			delLastVal();
	};

 

Repdeclare: 
	  tVar tComma Repdeclare {addVarray($<stringValue>1);}
	| tVar tSC {addVarray($<stringValue>1);};

Declare:
	tInt Repdeclare {
		for(int i = 0; i < RepVars->size; i++){
			initialize_var_to_local_int(RepVars->tab[i], false, false, 0);
		}
		freeAllVarray();
	}
	| tInt tConst Repdeclare {
		for(int i = 0; i < RepVars->size; i++){
			initialize_var_to_local_int(RepVars->tab[i], false, false, 0);
		}
		freeAllVarray();
	};

IntegerValue:
	  tValInt {$<integerValue>$ = $<integerValue>1;}
	| tDecVal {}
	| tExpVal {};
Expression:
	  IntegerValue {
		  	$<integerValue>$ = addTVarFromVal($<integerValue>1);
	  }
	| tVar {

			$<integerValue>$ = addTVarfromLVar(get_local_var_addr($<stringValue>1));
	}
	| Expression tAdd Expression {
		$<integerValue>$ = addTVarFromOperation(add,$<integerValue>1, $<integerValue>3);
	}
	| Expression tSub Expression {
		$<integerValue>$ = addTVarFromOperation(sub,$<integerValue>1, $<integerValue>3);}
	| Expression tMul Expression {
		$<integerValue>$ = addTVarFromOperation(mul,$<integerValue>1, $<integerValue>3);}
	| Expression tDiv Expression {
		$<integerValue>$ = addTVarFromOperation(divi,$<integerValue>1, $<integerValue>3);}
	| tSub Expression %prec tMul {}
	| tAdd Expression %prec tMul {}
	| tORB Expression tCRB {$<integerValue>$ = $<integerValue>1;};

%%


void addVarray(char* a){
    RepVars->size++;
    RepVars->tab = (char**)realloc(RepVars->tab,RepVars->size * sizeof(char*));
	
	RepVars->tab[RepVars->size-1] = strdup(a);
}

void freeAllVarray(){
	for(int i = 0; i<RepVars->size; i++){
		free(RepVars->tab[i]);
	}
    free(RepVars->tab);
    free(RepVars);
	RepVars = malloc(sizeof(Varray));
    RepVars->size = 0;
    RepVars->tab = malloc(sizeof(char**));
}





int yyerror(char *s){
	printf("Default Error:  \"%s\"\n",s);
	exit(1);
}
int main(void){

	printf("\nDebut de l'analyse syntaxique\n");

	//init vars locals
	init();
	//init RepVars
	RepVars = (Varray*) malloc(sizeof(Varray));
    RepVars->size = 0;
    RepVars->tab = (char**) malloc(sizeof(char*));


	
	yyparse();
	
	fclose(f);

	printf("\nFin de l'analyse syntaxique\n\n");
}


