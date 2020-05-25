#include "tvartable.h"
#include "write.h"
#include "operation.h"
#include <stdlib.h>

void initTvartable(){
    lvt = malloc(sizeof(tvartable));
    lvt->size = 0;
}

int addTVarFromVal(int value){
    lvt->size++;
    lvt->tvar = realloc(lvt->tvar, sizeof(int) *  lvt->size);
    lvt->tvar[lvt->size-1] = (lvt->size-1) * 4 + 4000;
    write_str("%%Store value %d dans la tvar %d\n", value, lvt->tvar[lvt->size-1]);
    write_ligne();write_char(AFC);write_int(0);write_int(value);write_endl();
    write_ligne();write_char(STR);write_int(lvt->tvar[lvt->size-1]);write_int(0);write_endl();
    return lvt->tvar[lvt->size-1];
}

int addTVarfromLVar(int addr){
    lvt->size++;
    lvt->tvar = realloc(lvt->tvar, sizeof(int) *  lvt->size);
    lvt->tvar[lvt->size-1] = (lvt->size-1) * 4 + 4000;
    write_str("%%Store value %d de lvar dans la tvar %d\n", addr, lvt->tvar[lvt->size-1]);
    write_ligne();write_char(LOD);write_int(0);write_int(addr);write_endl();
    write_ligne();write_char(STR);write_int(lvt->tvar[lvt->size-1]);write_int(0);write_endl();
    return lvt->tvar[lvt->size-1];
}
int addTVarFromPointer(int addr){
    lvt->size++;
    lvt->tvar = realloc(lvt->tvar, sizeof(int) *  lvt->size);
    lvt->tvar[lvt->size-1] = (lvt->size-1) * 4 + 4000;
    write_str("%%Store value %d de lvar dans la tvar %d\n", addr, lvt->tvar[lvt->size-1]);
    write_ligne();write_char(LOD);write_int(0);write_int(addr);write_endl();
    write_ligne();write_char(LODR);write_int(0);write_int(0);write_endl();
    write_ligne();write_char(STR);write_int(lvt->tvar[lvt->size-1]);write_int(0);write_endl();
    return lvt->tvar[lvt->size-1];
}

int addTVarFromOperation(op ope, int tvar1, int tvar2){
    switch(ope){
        case add:
            write_str("%%Load value from tvar %d and %d then add and store in %d\n",tvar1,tvar2,tvar1);
            write_ligne();write_char(LOD);write_int(0);write_int(tvar1);write_endl();
            write_ligne();write_char(LOD);write_int(1);write_int(tvar2);write_endl();
            write_ligne();write_char(ADD);write_int(0);write_int(0);write_int(1);write_endl();
            write_ligne();write_char(STR);write_int(tvar1);write_int(0);write_endl();break;
        case sub:
            write_str("%%Load value from tvar %d and %d then sub and store in %d\n",tvar1,tvar2,tvar1);
            write_ligne();write_char(LOD);write_int(0);write_int(tvar1);write_endl();
            write_ligne();write_char(LOD);write_int(1);write_int(tvar2);write_endl();
            write_ligne();write_char(SOU);write_int(0);write_int(0);write_int(1);write_endl();
            write_ligne();write_char(STR);write_int(tvar1);write_int(0);write_endl();break;
        case mul:
            write_str("%%Load value from tvar %d and %d then mul and store in %d\n",tvar1,tvar2,tvar1);
            write_ligne();write_char(LOD);write_int(0);write_int(tvar1);write_endl();
            write_ligne();write_char(LOD);write_int(1);write_int(tvar2);write_endl();
            write_ligne();write_char(MUL);write_int(0);write_int(0);write_int(1);write_endl();
            write_ligne();write_char(STR);write_int(tvar1);write_int(0);write_endl();break;
        case divi:
            write_str("%%Load value from tvar %d and %d then div and store in %d\n",tvar1,tvar2,tvar1);
            write_ligne();write_char(LOD);write_int(0);write_int(tvar1);write_endl();
            write_ligne();write_char(LOD);write_int(1);write_int(tvar2);write_endl();
            write_ligne();write_char(DIV);write_int(0);write_int(0);write_int(1);write_endl();
            write_ligne();write_char(STR);write_int(tvar1);write_int(0);write_endl();break;
        default:break;
    }
    delLastVal();
    return tvar1;
}

void delLastVal(){
    if(lvt->size != 0){
        lvt->size--;
        lvt->tvar = realloc(lvt->tvar, sizeof(int) *  lvt->size);
    }else{
        printf("ERROR delLastVal\n");
    }
    
}
void printAllTvar(){
    printf("------------------\n");
    printf("|  id  | address |\n");
    
    for (int a = 0; a < lvt->size; a++){
        printf("------------------\n");
        printf("|%-6d|%-9d|\n",a,lvt->tvar[a]);
    }
    printf("------------------\n");
}