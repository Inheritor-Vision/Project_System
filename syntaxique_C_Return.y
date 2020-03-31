%{
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include "src/symboltable.h"
	#include "src/tvartable.h"
	#include "src/write.h"
	#include "src/conditionaljump.h"
	#include "src/operation.h"
	
	int yydebug = 1;
	int yyerror(char *s);
	int yylex();
	void addVarray(char*);
	void freeAllVarray();
	char * strdup( const char * source );
	extern FILE * f;


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
	tIf tORB Expression ComparaisonOperator Expression tCRB InitIf Instructions EndIf {
		modifyLast($<integerValue>7,$<integerValue>9);
		printAllCondJump();}
	| tIf tORB Expression ComparaisonOperator Expression tCRB InitIf Instructions EndIf InitIf Instructions EndIf{
		modifyLast($<integerValue>7,$<integerValue>9+1);
		modifyLast($<integerValue>10,$<integerValue>12);
		printAllCondJump();};

InitIf:
	tOCB {
		incrementeDepth();
		$<integerValue>$ = pushCondJump(JMF,ligneCom,ligne);write_endl();}
	| tElse tOCB {
		incrementeDepth();
		$<integerValue>$ = pushCondJump(JMP,ligneCom,ligne);write_endl();
	};

EndIf:
	tCCB {decrementeDepth();$<integerValue>$ = ligneCom;};

ComparaisonOperator:
	tSup
	|tInf
	|tSupEqu
	|tInfEqu
	|tEquEqu;

	
Assign:
	tVar tEqu Expression tSC {
		write_str("%%Assignation var: %s\n",$<stringValue>1);
		write_ligne();write_char(LOD);write_int(0);write_int($<integerValue>3);write_endl();
		write_ligne();write_char(STR); write_int(assign_var_to_local_int($<stringValue>1)); write_int(0);write_endl();
		delLastVal();};
		


RepInitialize:
	tVar {addVarray($<stringValue>1);}
	| tVar tComma RepInitialize {addVarray($<stringValue>1);};

Initialize:
	  tInt RepInitialize tEqu Expression tSC {
		  for(int i = 0; i < RepVars->size; i++){
			  write_str("%%Initialize var: %s\n",RepVars->tab[i]);
			  write_ligne();write_char(LOD);write_int(0);write_int($<integerValue>4);write_endl();
			  write_ligne();write_char(STR); write_int(initialize_var_to_local_int(RepVars->tab[i], false, true, 0)); write_int(0);write_endl();
			}
			freeAllVarray();
			delLastVal();
		}
	| tInt tConst RepInitialize tEqu Expression tSC {
		for(int i = 0; i < RepVars->size; i++){
				write_str("%%Initialize var: %s\n",RepVars->tab[i]);
				write_ligne();write_char(LOD);write_int(0);write_int($<integerValue>5);write_endl();
			  	write_ligne();write_char(STR); write_int(initialize_var_to_local_int(RepVars->tab[i], true, true, 0)); write_int(0);write_endl();
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
	f = fopen("compil.asm","r");
	FILE * ftemp = fopen("temp.tmp","w");
	if(ftemp == NULL || f == NULL){
		 printf("\nUnable to open file temp.tmp or compil.asm for patching.\n");
		 exit(EXIT_FAILURE);
	}
	int count = 0;
	int indexPatch = 0;
	char* laligne;
	size_t len = 0;
	while((getline(&laligne,&len, f)) != -1){
		if(count == CondJumpList->liste[indexPatch].from){
			char yo[254];
			sprintf(yo,"%-9d %-9s %-9d", CondJumpList->liste[indexPatch].pos,CondJumpList->liste[indexPatch].op,CondJumpList->liste[indexPatch].to);
			fprintf(ftemp,"%s\n",yo);
			if(indexPatch+1 != CondJumpList->size){
				indexPatch++;
			}
		}else{
			fprintf(ftemp,"%s",laligne);
		}
		
		count++;
	}
	fclose(f);
	fclose(ftemp);
	remove("compil.asm");
	rename("temp.tmp", "compil.asm");
	printf("\nFin de l'analyse syntaxique\n\n");
}


