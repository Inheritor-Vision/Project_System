#ifndef WRITE_H_   
#define WRITE_H_  

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

int ligne;
int ligneCom;
FILE * f;

void initWrite(void);
void write_char(int a);
void write_int(int a);
void write_ligne();
void write_str(const char* a,...);
void write_endl();

#endif