%{
	#define _GNU_SOURCE
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include "src/symboltable.h"
	#include "src/tvartable.h"
	#include "src/write.h"
	#include "src/conditionaljump.h"
	#include "src/operation.h"
	#include "src/functable.h"

	
	int yydebug = 1;
	int yyerror(char *s);
	int yylex();
	void addVarray(char*);
	void addTVars(int a);
	void freeAllTVars();
	void freeAllVarray();
	char * strdup( const char * source );
	extern FILE * f;
	extern int mylineno;
	int deb[50] = {0};
	int debIndex = 0;
	int arg = 0;
	int wile = 0;
	char ** argt = NULL;
	char* nameFct;

	typedef struct {
		int* tab;
		int size;
	} argsArray;
	argsArray  *RepTVars;

	typedef struct {
    	char** tab;
    	int size;
	} Varray;
	Varray *RepVars;

    
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
	Function Functions {}
	| {};


RepFunction:
	tComma tInt tVar {
		arg++;
		argt = realloc(argt, sizeof(char*) * arg);
		argt[arg-1] = strdup($<stringValue>3);}
	| tInt tVar Repdeclare {
		arg++;
		argt = realloc(argt, sizeof(char*) * arg);
		argt[arg-1] = strdup($<stringValue>3);}
	| {};

Funct:
	Princ tORB Vide tCRB Body
	| Var tORB RepFunction tCRB Body{ };
FunctReturn: 
	Princ tORB Vide tCRB BodyReturn
	| Var tORB RepFunction tCRB BodyReturn {};
Function:
	tVoid Funct {}
	| Funct  {}
	| tInt FunctReturn  {};

Princ: 
	tMain {
		addFunc("main",ligne, 0, NULL);};

Var:
	tVar {
		addFunc($<stringValue>1,ligne, 0, argt);
		argt = NULL;};

Vide:
	tVoid
	| ;
	
InitFunc:
	tOCB {
		modifyLastArgc(arg);
		arg = 0;
		write_str("%%Début de la fonction %s\n", getLastName());
		$<stringValue>$ = getLastName();
	};

Body: 
	InitFunc Instructions tCCB {
		write_str("%%Fin de la fonction %s\n", $<stringValue>1);
		decrementeDepth(deb[debIndex]);
		debIndex--;
		write_str("%%Récupération de l'addresse de retour\n");
		write_ligne();write_char(LODR);write_int(0);write_int(SP);write_endl();
		write_ligne();write_char(SOU);write_int(SP);write_int(SP);write_int(4);write_endl();
		write_ligne();write_char(JMP[0]);write_int(0);write_endl();
		}
	| {fprintf(stderr,"Error l%d: No body detected1, maybe  { or } missing\n",mylineno);exit(EXIT_FAILURE);};

Return:
	tReturn Expression tSC {
	delLastVal();
	$<integerValue>$ = $<integerValue>2;
	} 
	| {fprintf(stderr,"Error l%d: No return detected\n",mylineno);exit(EXIT_FAILURE);};

BodyReturn:
	InitFunc Instructions Return tCCB {
		write_str("%%Fin de la fonction %s\n", $<stringValue>1);
		decrementeDepth(deb[debIndex]);
		debIndex--;
		write_str("%%Récupération de l'addresse de retour et return ds r0\n");
		write_ligne();write_char(AFC);write_int(0);write_int($<integerValue>3);write_endl();
		write_ligne();write_char(LODR);write_int(1);write_int(SP);write_endl();
		write_ligne();write_char(SOU);write_int(SP);write_int(SP);write_int(4);write_endl();
		write_ligne();write_char(JMP[0]);write_int(1);write_endl();
		}
	| {fprintf(stderr,"Error l%d: No body detected2, maybe  { or } missing\n",mylineno);exit(EXIT_FAILURE);};



Instructions: 
	Instruction Instructions {}
	|;

Instruction: 
	Assign {}
	| Initialize {}
	| Declare {}
	| tPrintf tORB tVar tCRB tSC {}
	| ConditionnalJump {};

ConditionnalJump:
	 InitIf Instructions EndIf {
		modifyLast($<integerValue>1,$<integerValue>3);
		}
	| InitIf Instructions EndIf InitElse Instructions EndIf{
		modifyLast($<integerValue>1,$<integerValue>3+1);
		modifyLast($<integerValue>4,$<integerValue>6);
		}
	| InitWhile Instructions EndWhile {
		modifyLast($<integerValue>1,$<integerValue>3+1);
		write_ligne();write_char(JMP[0]);write_int(wile);write_endl();
	};

InitIf:
	tIf Expression tOCB{
		delLastVal();
		incrementeDepth(deb[debIndex]);
		write_ligne();write_char(LOD);write_int(0);write_int($<integerValue>2);write_endl();
		$<integerValue>$ = pushCondJump(JMF,ligneCom,ligne);write_endl();
	};
InitElse:
	tElse tOCB {
		incrementeDepth(deb[debIndex]);
		$<integerValue>$ = pushCondJump(JMP,ligneCom,ligne);write_endl();
	};

EndIf:
	tCCB {decrementeDepth(deb[debIndex]);$<integerValue>$ = ligne;};

InitWhile:
	tWhile WhileORB Expression tCRB tOCB {
		delLastVal();
		incrementeDepth(deb[debIndex]);
		write_ligne();write_char(LOD);write_int(0);write_int($<integerValue>3);write_endl();
		$<integerValue>$ = pushCondJump(JMF,ligneCom,ligne);write_endl();
		wile = $<integerValue>2;
	};

EndWhile:
	tCCB {decrementeDepth(deb[debIndex]);$<integerValue>$ = ligne;};

WhileORB:
	tORB{$<integerValue>$ = ligne;};



	
Assign:
	tVar tEqu Expression tSC {
		write_str("%%Assignation var: %s\n",$<stringValue>1);
		write_ligne();write_char(LOD);write_int(0);write_int($<integerValue>3);write_endl();
		write_ligne();write_char(STR); write_int(assign_var_to_local_int(deb[debIndex],$<stringValue>1)); write_int(0);write_endl();
		delLastVal();};
		


RepInitialize:
	tVar {addVarray($<stringValue>1);}
	| tVar tComma RepInitialize {addVarray($<stringValue>1);};

Initialize:
	  tInt RepInitialize tEqu Expression tSC {
		  for(int i = 0; i < RepVars->size; i++){
			  write_str("%%Initialize var : %s\n",RepVars->tab[i]);
			  write_ligne();write_char(LOD);write_int(0);write_int($<integerValue>4);write_endl();
			  write_ligne();write_char(STR); write_int(initialize_var_to_local_int(deb[debIndex],RepVars->tab[i], false, true, 0)); write_int(0);write_endl();
			}
			freeAllVarray();
			delLastVal();
		}
	| tInt tConst RepInitialize tEqu Expression tSC {
		for(int i = 0; i < RepVars->size; i++){
			write_str("%%Initialize var : %s\n",RepVars->tab[i]);
			write_ligne();write_char(LOD);write_int(0);write_int($<integerValue>5);write_endl();
			write_ligne();write_char(STR); write_int(initialize_var_to_local_int(deb[debIndex],RepVars->tab[i], true, true, 0)); write_int(0);write_endl();
		}
		freeAllVarray();
		delLastVal();
	}
	| tInt tMul RepInitialize tEqu Expression tSC {
		for(int i = 0; i < RepVars->size; i++){
			write_str("%%Initialize var : %s\n",RepVars->tab[i]);
			write_ligne();write_char(LOD);write_int(0);write_int($<integerValue>5);write_endl();
			write_ligne();write_char(STR); write_int(initialize_var_to_local_int(deb[debIndex],RepVars->tab[i], false, true, 0)); write_int(0);write_endl();
		}
		freeAllVarray();
		delLastVal();
	}
	| tInt tMul tConst  RepInitialize tEqu Expression tSC {
		for(int i = 0; i < RepVars->size; i++){
			write_str("%%Initialize var : %s\n",RepVars->tab[i]);
			write_ligne();write_char(LOD);write_int(0);write_int($<integerValue>6);write_endl();
			write_ligne();write_char(STR); write_int(initialize_var_to_local_int(deb[debIndex],RepVars->tab[i], true, true, 0)); write_int(0);write_endl();
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
			initialize_var_to_local_int(deb[debIndex],RepVars->tab[i], false, false, 0);
		}
		freeAllVarray();
		
	}
	| tInt tConst Repdeclare {
		for(int i = 0; i < RepVars->size; i++){
			initialize_var_to_local_int(deb[debIndex],RepVars->tab[i], true, false, 0);
		}
		freeAllVarray();
	}
	| tInt tMul Repdeclare {
		for(int i = 0; i < RepVars->size; i++){
			initialize_var_to_local_int(deb[debIndex],RepVars->tab[i], false, false, 0);
		}
		freeAllVarray();
	}
	| tInt tMul tConst Repdeclare {
		for(int i = 0; i < RepVars->size; i++){
			initialize_var_to_local_int(deb[debIndex],RepVars->tab[i], true, false, 0);
		}
		freeAllVarray();
	};
RepArgs:
	tComma Expression RepArgs {
		delLastVal();
		addTVars($<integerValue>1);
	}
	| Expression {
		delLastVal();
		addTVars($<integerValue>1);}
	| {};
IntegerValue:
	  tValInt {$<integerValue>$ = $<integerValue>1;}
	| tDecVal {}
	| tExpVal {};
Expression:
	  IntegerValue {
		  	$<integerValue>$ = addTVarFromVal($<integerValue>1);
	  }
	| tVar {

		$<integerValue>$ = addTVarfromLVar(get_local_var_addr(deb[debIndex],$<stringValue>1));
	}
	| tEt tVar {
		$<integerValue>$ = addTVarFromVal(get_local_var_addr(deb[debIndex],$<stringValue>2));
	}
	| tMul tVar  {
		$<integerValue>$ = addTVarFromPointer(get_local_var_addr(deb[debIndex],$<stringValue>2));
	}
	| tVar tORB RepArgs tCRB{
		func tmp = getFunc($<stringValue>1);
		debIndex++;
		deb[debIndex] = getSize();
		write_ligne();write_char(ADD);write_int(SP);write_int(SP);write_int(4);write_endl();
		write_ligne();write_char(STRR);write_int(SP);write_int(ligne+1+2*RepTVars->size);write_endl();
		write_ligne();write_char(JMP[0]);write_int(tmp.address);write_endl();
		if(!(tmp.nbr_args == RepTVars->size)){
			fprintf(stderr,"Error l%d: Function %s as wrong number of args\n",mylineno,tmp.varname);exit(EXIT_FAILURE);
		}
		for(int i = 0; i < RepTVars->size; i++){
			write_str("%%Initialize args of function: %s\n ", tmp.args[i]);
			write_ligne();write_char(LOD);write_int(0);write_int(RepTVars->tab[i]);write_endl();
			write_ligne();write_char(STR); write_int(initialize_var_to_local_int(deb[debIndex],tmp.args[i], true, true, 0)); write_int(0);write_endl();
		}
		freeAllTVars();
		$<integerValue>$ = addTVarFromReg0();
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
	| tORB Expression tCRB {$<integerValue>$ = $<integerValue>2;};

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
void addTVars(int a){
    RepTVars->size++;
    RepTVars->tab = (int*)realloc(RepTVars->tab,RepTVars->size * sizeof(int));
	RepTVars->tab[RepTVars->size-1] = a;
}

void freeAllTVars(){
    free(RepTVars->tab);
    free(RepTVars);
	RepTVars = (argsArray*) malloc(sizeof(argsArray));
	RepTVars->size = 0;
	RepTVars->tab = (int*) malloc(sizeof(int));
}





int yyerror(char *s){
	printf("Error: %s at line %d\n",s,mylineno);
	exit(EXIT_FAILURE);
}
int main(void){
	//printf("|>.-O_|3(7_5`/573|\\/| : /<o|\\/||>1|_47o.-");
	printf("\nDebut de l'analyse syntaxique\n");

	//init vars locals
	init();
	//init RepVars
	RepVars = (Varray*) malloc(sizeof(Varray));
    RepVars->size = 0;
    RepVars->tab = (char**) malloc(sizeof(char*));
	RepTVars = (argsArray*) malloc(sizeof(argsArray));
	RepTVars->size = 0;
	RepTVars->tab = (int*) malloc(sizeof(int));
	

	
	yyparse();
	
	fclose(f);
	if(CondJumpList->size > 0){
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
				if(!strcmp(CondJumpList->liste[indexPatch].op,JMF)){
					sprintf(yo,"%-9d %-9s %-9d %-9d", CondJumpList->liste[indexPatch].pos,JMF,0, CondJumpList->liste[indexPatch].to);
				}else{
					sprintf(yo,"%-9d %-9s %-9d", CondJumpList->liste[indexPatch].pos,JMP, CondJumpList->liste[indexPatch].to);
				}
				
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
	}
	printAll();
	printf("\nFin de l'analyse syntaxique\n\n");
}


