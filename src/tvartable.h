#ifndef TVARTABLE_H_
#define TVARTABLE_H_
#include <stdio.h>



typedef enum{ add,sub,mul,divi} op;

typedef struct {
    int* tvar;
    int size;
}tvartable;

tvartable *lvt;

void initTvartable(void);
int addTVarFromVal(int value);
int addTVarfromLVar(int addr);
int addTVarFromPointer(int addr);
int addTVarFromOperation(op ope, int tvar1, int tvar2);
void delLastVal();
void printAllTvar();

#endif