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
    int nbr_args;
} func;

typedef struct {
  func *tab;
  int size;
} tfunc;

tfunc *functable;

void initFuncTable();
void addFunc(char* name, int addr, int argc);
func getFunc(char* name);
void modifyLastArgc(int argc);
char* getLastName(void);


#endif