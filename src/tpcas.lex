%{
//#include "tree.h"
#include "tpcas.tab.h"
int lineno;
%}

%option nounput
%option noinput
%option noyywrap

%x COMMENT

%%

while                             {return WHILE;}
if                                {return IF;}
else                              {return ELSE;}
return                            {return RETURN;}
int|char                          {return TYPE;}
void                              {return VOID;}
[0-9]+                            {return NUM;}                     
'[^']'|'\\n'|'\\t'|'\\''          {return CHARACTER;}
==|!=                             {return EQ;}
\<|\>|\<\=|\>\=                   {return ORDER;}
\|\|                              {return OR;}
&&                                {return AND;}
[+-]                              {return ADDSUB;}
[*/%]                             {return DIVSTAR;}
[a-zA-Z_][a-zA-Z_0-9]*            {return IDENT;}
[;,!(){}=]                        {return yytext[0];}
\/\*                              {BEGIN COMMENT;}
\/\/.*                            ;
[ \n\t]*                          ;
<<EOF>>                           {return 0;}


<COMMENT>\*\/                     {BEGIN INITIAL;}
<COMMENT>[.\n\t]*                 ;
%%

/*
Not done:
-comparisons (EQ and ORDER)
-OR and AND
*/

void printText(){
    printf("%s yo\n", yytext);
}