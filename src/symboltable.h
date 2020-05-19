#ifndef SYMBOLTABLE_H_   
#define SYMBOLTABLE_H_
#include<stdbool.h>
extern char* strdup(const char*);

//typedef enum { false, true } bool;


typedef struct { 
    char* varname;
    bool cst;
    int address;
    bool init;
    int depth;


} lvar;

typedef struct {
  lvar *tab;
  int size;
  int nbvar;
} Array;

Array *var;

void init();
int set_var_to_local_int(char* a, bool cst, bool init, int depth);
int assign_var_to_local_int(char* a);
//int assign_ptr_to_local_ptr(char* a);
int get_local_var_addr(char* a);
//int get_local_ptr_addr(char *a);
int varname_to_address(char* a);
int initialize_var_to_local_int(char* a, bool cst, bool init, int depth);
//int initialize_var_to_local_ptr(char* a,bool cst, bool init, int depth, int addr);
void del_var_name(char* dvar);
void incrementeDepth(void);
void decrementeDepth(void);
void printAll(void);


#endif 