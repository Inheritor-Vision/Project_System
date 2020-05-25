#include "functable.h"
extern int mylineno;

void initFuncTable(){
    functable = (tfunc*)malloc(sizeof(tfunc));
    functable->size = 0;
    haveMain = false;
}

void addFunc(char* name, int addr, int argc){
    functable->size ++;
    int pos = functable->size-1;

    functable->tab = (func*)realloc(functable->tab,functable->size * sizeof(func));
    functable->tab[pos].varname = (char*)malloc(256*sizeof(char));
    strcpy(functable->tab[pos].varname, name);
    functable->tab[pos].address = addr;
    functable->tab[pos].nbr_args = argc;
    if(!strcmp("main", name)){
        haveMain = true;
    }
}

func getFunc(char* name){
    int index = 0;
    bool found = false;
    func res;
    while(index < functable->size && !found){
        if (!strcmp(functable->tab[index].varname, name)){
            found = true;
            res = functable->tab[index];
        }
        index ++;
    }
    if(!found){
        fprintf(stderr,"Error l%d: function %s not defined.\n",mylineno,name);exit(EXIT_FAILURE);
    }
    return res;
}

void modifyLastArgc(int argc){
    functable->tab[functable->size - 1].nbr_args = argc;
}

char* getLastName(void){
    return functable->tab[functable->size - 1].varname;
}