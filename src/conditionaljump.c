#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "conditionaljump.h"
void initCondJump(){
    CondJumpList = (patch*) malloc(sizeof(patch));
    CondJumpList->size = 0;
}
int pushCondJump(char* op, int from, int pos){
    CondJumpList->size++;
    CondJumpList->liste = (patchStruct*) realloc(CondJumpList->liste, sizeof(patchStruct) * CondJumpList->size);
    CondJumpList->liste[CondJumpList->size-1].op = (char*)malloc(sizeof(char)*strlen(op));
    strcpy(CondJumpList->liste[CondJumpList->size-1].op,op);
    CondJumpList->liste[CondJumpList->size-1].from = from;
    CondJumpList->liste[CondJumpList->size-1].to = -1;
    CondJumpList->liste[CondJumpList->size-1].pos = pos;
    return CondJumpList->size-1;

}
/*void popCondJump(){
    patchStruct res;
    if(CondJumpList->size == 0){
        printf("ERROR popCondJump1\n");
    }else{
        
        CondJumpList->size--;
        printf("%d\n",CondJumpList->size);
        res = CondJumpList->liste[CondJumpList->size];
        free(CondJumpList->liste[CondJumpList->size].op);
        CondJumpList->liste = (patchStruct*) realloc(CondJumpList->liste, sizeof(patchStruct)* CondJumpList->size);
    }
    

    return res;
}*/

void modifyLast(int index,int to){
    CondJumpList->liste[index].to = to;
}

void printAllCondJump(){
    printf("--------------------------------------\n");
    printf("|  index  |   op   |  from  |   to   |\n");
    for (int a = 0; a < CondJumpList->size; a++){
        printf("--------------------------------------\n");
        printf("|%-9d|%-8s|%-8d|%-8d|\n", a, CondJumpList->liste[a].op, CondJumpList->liste[a].from, CondJumpList->liste[a].to);
    }
    printf("--------------------------------------\n");
}
