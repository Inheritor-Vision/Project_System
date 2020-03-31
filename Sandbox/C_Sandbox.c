#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../src/symboltable.h"
#include "../src/tvartable.h"
#include "../src/conditionaljump.h"
#include "../src/write.h"


//Varray *RepVars;




/*void addVarray(int a){
    RepVars->size++;
    RepVars->tab = (int*)realloc(RepVars->tab,RepVars->size * sizeof(int));
    RepVars->tab[RepVars->size-1] = a;
}

void freeAllVarray(){
    free(RepVars->tab);
    free(RepVars);
    RepVars = malloc(sizeof(Varray));
    RepVars->size = 0;
    RepVars->tab = malloc(sizeof(int*));
}*/



int main(){
    

    init();

    /*f = fopen("compil.asm","w");
	if (f == NULL){
		printf("unable to open file");
		exit(EXIT_FAILURE);
	}
    set_var_to_local_int("ptdr",true,true,0);
    set_var_to_local_int("LOLXd",false,true,1);
    set_var_to_local_int("TIKI",true,false,1);
    set_var_to_local_int("mdr",false,false,0);
    set_var_to_local_int("pilip",true,true,3);
    set_var_to_local_int("vozion",true,true,0);
    set_var_to_local_int("ophCourse",false,true,9);
    printAll();
    decrementeDepth();
    printAll();
    set_var_to_local_int("dieu",true,true,9);
    printAll();
    


    addTVarFromVal(10);
    addTVarFromVal(11);
    addTVarFromOperation(add,addTVarFromVal(12),addTVarFromVal(13));
    printAllTvar();
    delLastVal();
    printAllTvar();
    addTVarFromVal(14);
    printAllTvar();*/
    /*RepVars = malloc(sizeof(Varray));
    RepVars->size = 0;
    RepVars->tab = malloc(sizeof(int*));
    addVarray(1);
    printf("%d\n",RepVars->tab[0]);
    addVarray(7);
    printf("%d\n",RepVars->tab[1]);
    addVarray(9);
    printf("%d\n",RepVars->tab[2]);
    addVarray(13);
    printf("%d\n",RepVars->tab[3]);
    printf("%d\n",RepVars->tab[1]);
    freeAllVarray();
    
    addVarray(1);
    printf("%d\n",RepVars->tab[0]);
    addVarray(7);
    printf("%d\n",RepVars->tab[1]);*/

    int a = pushCondJump("JMP",10);
    int b =pushCondJump("JMF",20);
    int c =pushCondJump("JMP",30);
    int d =pushCondJump("JMF",40);
    printAllCondJump();
    modifyLast(d,13);
    printAllCondJump();
    int e =pushCondJump("JMP",50);
    int f =pushCondJump("JMF",60);
    int g =pushCondJump("JMP",70);
    modifyLast(g,15);
    modifyLast(e,17);
    printAllCondJump();
   


    
}