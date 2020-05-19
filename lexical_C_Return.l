%{
#include "Compilator.y.tab.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
extern YYSTYPE yylval;
int var_to_local_int_lex(char*, int);
char * strdup( const char * source );
typedef enum { false, true } bool;


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
} Array;

Array *var;

%}
%%

[ \t]+% 
[ \t]+ {}
int {return(tInt);}

main    {return(tMain);}

return {return(tReturn);}
printf {return(tPrintf);}
const {return(tConst);}
void {return(tVoid);}
if {return(tIf);}
else { return(tElse);}
while {return(tWhile);}
">=" {return(tSupEqu);}
"<=" {return(tInfEqu);}
"==" {return(tEquEqu);}
">" {return(tSup);}
"<" {return(tInf);}
"+" {return(tAdd);}
"-" {return(tSub);}
"*" {return(tMul);}
"=" {return(tEqu);}
";" {return(tSC);}
"/" {return(tDiv);}
"{" {return(tOCB);}
"}" {return(tCCB);}
"(" {return(tORB);}
")" {return(tCRB);}
"," {return(tComma);}


\n {} 
[A-Za-z][A-Za-z0-9_]*  {yylval.stringValue = strdup(yytext);return(tVar);}

[0-9]+ {yylval.integerValue = atoi(yytext);return(tValInt);}
[0-9]+"."[0-9]+ {return(tDecVal);}
[0-9]+"e"[+-]?[0-9]+  {return(tExpVal);}


%%

int yywrap(void){}



/*int main(void) {
    printf("Debut de l'analyse lexical\n");
    yyparse();
    return 0;
}*/
