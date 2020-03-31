#include <stdlib.h>
#include <stdio.h>
#include "conditionaljump.h"
void initCondJump(){
    CondJumpList = (cjl*) malloc(sizeof(cjl));
    CondJumpList->size = 0;
}
void pushCondJump(int a){
    CondJumpList->size++;
    CondJumpList->liste = (int*) realloc(CondJumpList->liste, sizeof(int)* CondJumpList->size);
    CondJumpList->liste[CondJumpList->size-1] = a;

}
int popCondJump(){
    int res = -1;
    if(CondJumpList->size == 0){
        printf("ERROR popCondJump1\n");
    }else{
        CondJumpList->size--;
        res = CondJumpList->liste[CondJumpList->size];
        CondJumpList->liste = (int*) realloc(CondJumpList->liste, sizeof(int)* CondJumpList->size);
    }
    

    return res;
}

void printAllCondJump(){
    printf("-------------------\n");
    printf("|  index  |  value  |\n");
    for (int a = 0; a < CondJumpList->size; a++){
        printf("-------------------\n");
        printf("|%-9d|%-9d|\n", a, CondJumpList->liste[a]);
    }
    printf("-------------------\n");
}
