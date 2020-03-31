#ifndef TVARTABLE_H_
#define TVARTABLE_H_
#include <stdio.h>

extern FILE * f;
extern void write_int(int);
extern void writeln_str(char*);
extern void write_endl();
extern void write_ligne();

typedef enum{ add,sub,mul,divi} op;

typedef struct {
    int* tvar;
    int size;
}tvartable;

tvartable *lvt;

void initTvartable(void);
int addTVarFromVal(int value);
int addTVarfromLVar(int addr);
int addTVarFromOperation(op ope, int tvar1, int tvar2);
void delLastVal();
void printAllTvar();

#endif