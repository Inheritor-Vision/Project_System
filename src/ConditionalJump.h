#ifndef CONDITIONALJUMP_H_   
#define CONDITIONALJUMP_H_

typedef struct{
int* liste;
int size;
}cjl;

cjl *CondJumpList;

void initCondJump(void);
void pushCondJump(int a);
int popCondJump(void);
void printAllCondJump(void);

#endif