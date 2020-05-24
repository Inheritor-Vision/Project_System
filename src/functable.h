#ifndef FUNCTABLE_H_   
#define FUNCTABLE_H_
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include<stdbool.h>

bool haveMain;

typedef struct { 
    char* varname;
    int address;
} func;

typedef struct {
  func *tab;
  int size;
} tfunc;

tfunc *functable;

void initFuncTable();
void addFunc(char* name, int addr);
func getFunc(char* name) ;


#endif