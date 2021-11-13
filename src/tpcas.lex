%{
#include "../src/tree.h"
#include "tpcas.tab.h"
int lineno = 1;
%}

%option nounput
%option noinput
%option noyywrap

%x COMMENT

%%
<*>\n                                {lineno += 1;}

<INITIAL>while                       {return WHILE;}
<INITIAL>if                          {return IF;}
<INITIAL>else                        {return ELSE;}
<INITIAL>return                      {return RETURN;}
<INITIAL>int|char                    {return TYPE;}
<INITIAL>void                        {return VOID;}
<INITIAL>[0-9]+                      {return NUM;}                     
<INITIAL>'[^']'|'\\n'|'\\t'|'\\''    {return CHARACTER;}
<INITIAL>==|!=                       {return EQ;}
<INITIAL>\<|\>|\<\=|\>\=             {return ORDER;}
<INITIAL>\|\|                        {return OR;}
<INITIAL>&&                          {return AND;}
<INITIAL>[+-]                        {return ADDSUB;}
<INITIAL>[*/%]                       {return DIVSTAR;}
<INITIAL>[a-zA-Z_][a-zA-Z_0-9]*      {return IDENT;}
<INITIAL>[;,!(){}=]                  {return yytext[0];}
<INITIAL>\/\*                        {BEGIN COMMENT;}
<INITIAL>\/\/.*                      ;
<INITIAL>[ \t]*                      ;
<INITIAL>.                           {return 1;}
<INITIAL><<EOF>>                     {return 0;}

<COMMENT><<EOF>>                     {return 1;}
<COMMENT>\*\/                        {BEGIN INITIAL;}
<COMMENT>\t                          ;
<COMMENT>.                           ;
%%

