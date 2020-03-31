#include <stdlib.h>
#include "ConditionalJump.h"
void init(){
    CondJumpList = (cjl*) malloc(sizeof(cjl));
    CondJumpList->size = 0;
}
void pushCondJump(int a){
    CondJumpList->size++;
    CondJumpList->liste = (int*) realloc(CondJumpList->liste, sizeof(int)* CondJumpList->size);
    CondJumpList->liste[CondJumpList->size] = a;

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
