#ifndef CONDITIONALJUMP_H_   
#define CONDITIONALJUMP_H_

typedef struct{
    char* op;
    int from;
    int to;
    int pos;
}patchStruct;

typedef struct{
patchStruct* liste;
int size;
}patch;

patch *CondJumpList;

void initCondJump(void);
int pushCondJump(char *op,int from,int pos);
void modifyLast(int index,int to);
/*void popCondJump(void);*/
void printAllCondJump(void);

#endif