#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../symboltable.h"


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

    

    for (int i = 0; i < 3; i++){
        //tab[i] = malloc((i+1) * sizeof(char));
        if (i == 0){
            printf("%d ???\n", set_var_to_local_int("ptdr",false,false,2));
        }else if (i == 1)  {
            printf("%d ???\n", set_var_to_local_int("mot",false,false,2));
        }else{
            printf("%d ???\n", set_var_to_local_int("tiki",false,false,2));
        }
        printf("%s\n", var->tab[i].varname);
    }
    printf("%d ???\n", set_var_to_local_int("lolxD",false,false,2));
    printf("%s\n", var->tab[3].varname);
    printf("%d ???\n", set_var_to_local_int("mot",false,false,2));
    printf("%s\n", var->tab[1].varname);
    printf("%d ???\n", set_var_to_local_int("abc",false,false,2));
    printf("%s\n", var->tab[4].varname);
    printf("%d\n", get_local_var_addr("ptdr"));

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

    
}