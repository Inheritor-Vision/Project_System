
#include "write.h"

void initWrite(void){
    ligne = 0;
	ligneCom = 0;
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
	
}
void write_char(int a){
	fprintf(f,"%-9c ", a);
}

void write_cond(char* a){
	fprintf(f,"%-9s ",a);
}

void write_str(const char* a,...){
	va_list valist;
	va_start(valist,a);
	vfprintf(f,a,valist);
	va_end(valist);
	ligneCom++;
}

void write_endl(){
	fprintf(f,"\n");
	ligne ++;
	ligneCom++;
}

