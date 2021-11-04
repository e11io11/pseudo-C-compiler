%{
//#include "tree.h"
#include "tpcas.tab.h"
int lineno;
%}

%option nounput
%option noinput
%option noyywrap

%%
while                             {return WHILE;}
if                                {return IF;}
else                              {return ELSE;}
return                            {return RETURN;}
int|char                          {return TYPE;}
void                              {return VOID;}
[0-9]+                            {return NUM;}
'[^']'|'\\n'|'\\t'|'\\''          {return CHARACTER;}
[+-]                              {return ADDSUB;}
[*/%]                             {return DIVSTAR;}
[a-zA-Z_][a-zA-Z_0-9]*            {return IDENT;}
[;,!(){}=!]                       {return yytext[0];}
[ \n\t]*                          ;
<<EOF>>                           {return 0;}
%%

/*
Not done:
-comments (/* and //)
-comparisons (EQ and ORDER)
-OR and AND
*/

void printText(){
    printf("%s yo\n", yytext);
}