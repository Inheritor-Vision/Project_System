#ifndef WRITE_H_   
#define WRITE_H_  

#include <stdio.h>
#include <stdlib.h>

int ligne;
FILE * f;

void initWrite(void);
void write_int(int a);
void write_ligne();
void writeln_str(char* a);
void write_endl();

#endif