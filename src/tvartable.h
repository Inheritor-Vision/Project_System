#ifndef TVARTABLE_H_
#define TVARTABLE_H_
#include <stdio.h>
extern FILE * f;

typedef struct {
    int* tvar;
    int size;
}tvartable;

tvartable *lvt;

#endif