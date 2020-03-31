
#include "write.h"

void initWrite(void){
    ligne = 12000;
    f = fopen("compil.asm","w");
	if (f == NULL){
		printf("unable to open file");
		exit(2);
	}
}

void write_int(int a){
	fprintf(f, "%-9d ", a);
}

void write_ligne(){
	fprintf(f, "%-9d ", ligne);
	ligne ++;
}

void writeln_str(char* a){
	fprintf(f, "%s\n", a);
}

void write_endl(){
	fprintf(f,"\n");
}