
%%

[ \t]+% 
[ \t]+ {printf(" ");}
int {printf(" tInt ");}
main {printf(" tMain ");}
return {printf(" tReturn ");}
printf {printf(" tPrintf");}
const { printf(" tConst");}
void {printf(" tVoid");}
"+" {printf(" tAdd ");}
"-" {printf(" tSub ");}
"*" {printf(" tMul ");}
"=" {printf(" tEqu ");}
";" {printf(" tSC ");}
"/" {printf(" tDiv ");}
"{" {printf(" tOCB ");}
"}" {printf(" tCCB ");}
"(" {printf(" tORB ");}
")" {printf(" tCRB ");}
"," {printf(" tComma ");}

\n {printf("tCR\n");}
[A-Za-z][A-Za-z0-9_]*  {printf(" tVar ");}
[0-9]+ {printf(" tValInt ");}
[0-9]+"."[0-9]+ {printf(" tDecVal");}
[0-9]+"e"[+-]?[0-9]+  {printf(" tExpVal");}


%%

int yywrap(void){}

int main(void) {
    printf("Debut de l'analyse lexical\n");
    yylex();
    return 0;
}
