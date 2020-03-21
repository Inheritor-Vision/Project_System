#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "symboltable.h"


void init(){
    var = (Array*)malloc(sizeof(Array));
    var->size = 0;
    //var->tab = (lvar*) malloc(sizeof(lvar));
}

int set_var_to_local_int(char* a, bool cst, bool init, int depth){
    int fin = 0;
    int index = 0;
    int res = -1;
    while(!fin && index < var->size){
        if (!strcmp(var->tab[index].varname, a)){
            var->tab[index].cst = cst;
            var->tab[index].init = init;
            var->tab[index].depth = depth;
            fin = 1;
            res = var->tab[index].address;

        }
        index ++;
    }
    if (!fin){
        var->size++;
        int pos = var->size-1;
        res = (var->size - 1) * 4 + 8000;
        var->tab = (lvar*)realloc(var->tab,var->size * sizeof(lvar));
        var->tab[pos].varname = strdup(a);
        var->tab[pos].address = res;
        var->tab[pos].cst = cst;
        var->tab[pos].init = init;
        var->tab[pos].depth = depth;

    }
    return res;
}

int assign_var_to_local_int(char* a, int depth){
    int fin = 0;
    int index = 0;
    int res = -1;
    while(!fin && index < var->size){
        if (!strcmp(var->tab[index].varname, a)){
            if(var->tab[index].cst == false){
                var->tab[index].init = true;
                var->tab[index].depth = depth;
                res = var->tab[index].address;
            }else{
                if(var->tab[index].init == true){
                    printf("ERROR assign_var_to_local_int\n");
                }else{
                    var->tab[index].init = true;
                    var->tab[index].depth = depth;
                    res = var->tab[index].address;
                }
            }
            fin = 1;
        }
        index ++;
    }
    if (!fin){
        printf("ERROR assign_var_to_local_int\n");
    }
    return res;
}


int get_local_var_addr(char* a){
    int fin = 0;
    int index = 0;
    int res = -1;
    while(!fin && index < var->size){
        if (!strcmp(var->tab[index].varname, a)){
            fin = 1;
            res = var->tab[index].address;

        }
        index ++;
    }
    if (!fin){
        printf("ERROR get_local_var_addr\n");
    }
    return res;
}

int varname_to_address(char* a){
    int fin = 0;
    int index = 0;
    int res = -1;
    while(!fin && index < var->size){
        if (!strcmp(var->tab[index].varname, a)){
            res = var->tab[index].address;
            fin = 1;
        }
        index ++;
    }
    if (!fin){
        printf("ERROR varname_to_address\n");

    }
    return res;
}

int initialize_var_to_local_int(char* a, bool cst, bool init, int depth){
    int fin = 0;
    int index = 0;
    int res = -1;
    while(!fin && index < var->size){
        if (!strcmp(var->tab[index].varname, a)){
            printf("ERROR initialize_var_to_local_int1\n");
            fin = 1;
        }
        index ++;
    }
    if (!fin){
        var->size++;
        int pos = var->size-1;
        res = (var->size - 1) * 4 + 8000;
        var->tab = (lvar*)realloc(var->tab,var->size * sizeof(lvar));
        var->tab[pos].varname = strdup(a);
        var->tab[pos].address = res;
        var->tab[pos].cst = cst;
        var->tab[pos].init = init;
        var->tab[pos].depth = depth;

    }
    return res;
}