#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../src/symboltable.h"
#include "../src/tvartable.h"
#include "../src/ConditionalJump.h"


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

    pushCondJump(25);
    pushCondJump(666);
    pushCondJump(420);
    pushCondJump(696969);
    printAllCondJump();
    printf("RES: %d\n", popCondJump());
    printAllCondJump();
    pushCondJump(420);
    pushCondJump(696969);
    pushCondJump(696969);
    printAllCondJump();


    
}