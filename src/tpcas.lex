%{
/**
 * @author Antonin JEAN
 * @author Elliott FALGUEROLLE
 * @email ofghanirre@gmail.com
 * @create date 2021-11-14 19:57:47
 * @modify date 2021-11-14 19:57:47
 * @desc Lex file for the Syntax Analyzer
 * It reads an input and separate tokens out
 * of it, these tokens are then sent to a Bison
 * file.
 */

#include "../inc/tree.h"
#include "tpcas.tab.h"

int lineno = 1;
%}


%option nounput
%option noinput
%option noyywrap
%option yylineno

%x COMMENT

%%
<*>\n                                {lineno += 1;}

<INITIAL>while                       {return WHILE;}
<INITIAL>if                          {return IF;}
<INITIAL>else                        {return ELSE;}
<INITIAL>switch                      {return SWITCH;}
<INITIAL>case                        {return CASE;}
<INITIAL>default                     {return DEFAULT;}
<INITIAL>break                       {return BREAK;}
<INITIAL>return                      {return RETURN;}
<INITIAL>int|char                    {strcpy(yylval.comp, yytext); return TYPE;}
<INITIAL>void                        {return VOID;}
<INITIAL>[0-9]+                      {yylval.num = atoi(yytext); return NUM;}                     
<INITIAL>'[^']'|'\\n'|'\\t'|'\\''    {yylval.byte = yytext[1]; return CHARACTER;}
<INITIAL>==|!=                       {strcpy(yylval.comp, yytext); return EQ;}
<INITIAL>\<|\>|\<\=|\>\=             {strcpy(yylval.comp, yytext); return ORDER;}
<INITIAL>\|\|                        {return OR;}
<INITIAL>&&                          {return AND;}
<INITIAL>[+-]                        {yylval.byte = yytext[0]; return ADDSUB;}
<INITIAL>[*/%]                       {yylval.byte = yytext[0]; return DIVSTAR;}
<INITIAL>[a-zA-Z_][a-zA-Z_0-9]*      {strcpy(yylval.ident, yytext); return IDENT;}
<INITIAL>[;,!(){}=:]                 {return yytext[0];}
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

