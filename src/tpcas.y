%{
#include "../src/tree.h"
#include <stdio.h>
int yylex();
int yyerror(char* msg);
extern int lineno;
%}


%union {
    Node* node;
}
%type <node> Prog DeclVars DeclFoncts Declarateurs DeclFonct EnTeteFonct Corps Parametres ListExp ListTypVar SuiteInstr Instr LValue Arguments TB FB M E T F Exp



%token DIVSTAR IDENT TYPE VOID WHILE IF RETURN ELSE OR AND EQ ORDER ADDSUB
%token NUM CHARACTER

%%
Prog:  DeclVars DeclFoncts                  {$$ = makeNode(Prog); addChild($$, $1); addChild($$, $2); printTree($$);}   
    ;
DeclVars:                                   
       DeclVars TYPE Declarateurs ';'       {$$ = makeNode(type); addSibling($$, $1); addChild($$, $3);}
    |                                       {$$ = makeNode(epsilon);}
    ;
Declarateurs:                                   
       Declarateurs ',' IDENT               {$$ = $1; addSibling($$, makeNode(ident));}
    |  IDENT                                {$$ = makeNode(ident);}
    ;
DeclFoncts:                                 
       DeclFoncts DeclFonct                 {$$ = $1; addSibling($$, $2);}
    |  DeclFonct                            {$$ = $1;}
    ;
DeclFonct:
       EnTeteFonct Corps                    {$$ = $1; addChild($$, $2);}
    ;
EnTeteFonct:
       TYPE IDENT '(' Parametres ')'        {$$ = makeNode(ident); addChild($$, makeNode(type)); addChild($$, $4);}
    |  VOID IDENT '(' Parametres ')'        {$$ = makeNode(ident); addChild($$, makeNode(void_)); addChild($$, $4);}
    ;
Parametres:
       VOID                                 {$$ = makeNode(void_);}
    |  ListTypVar                           {$$ = $1;}
    ;
ListTypVar:
       ListTypVar ',' TYPE IDENT            {$$ = makeNode(type); addSibling($$, $1); addChild($$, makeNode(ident));}
    |  TYPE IDENT                           {$$ = makeNode(type); addChild($$, makeNode(ident));}
    ;
Corps: '{' DeclVars SuiteInstr '}'          {$$ = $2; addSibling($$, $3);}
    ;
SuiteInstr:
       SuiteInstr Instr                     {$$ = $1; addSibling($$, $2);}
    |                                       {$$ = makeNode(epsilon);}
    ;
Instr:
       LValue '=' Exp ';'                   {$$ = $1; addChild($$, $3);}
    |  IF '(' Exp ')' Instr                 {$$ = makeNode(if_); addChild($$, $3); addChild($$, $5);}
    |  IF '(' Exp ')' Instr ELSE Instr      {$$ = makeNode(if_); addChild($$, $3); addChild($$, $5); addSibling($$, makeNode(else_)); addChild(($$->nextSibling), $7);}
    |  WHILE '(' Exp ')' Instr              {$$ = makeNode(while_); addChild($$, $3); addChild($$, $5);}
    |  IDENT '(' Arguments  ')' ';'         {$$ = makeNode(ident); addChild($$, $3);}
    |  RETURN Exp ';'                       {$$ = makeNode(return_); addChild($$, $2);}
    |  RETURN ';'                           {$$ = makeNode(return_);}
    |  '{' SuiteInstr '}'                   {$$ = $2;}
    |  ';'                                  {$$ = makeNode(epsilon);}
    ;
Exp :  Exp OR TB                            {$$ = makeNode(or); addChild($$, $1); addChild($$, $3);}
    |  TB                                   {$$ = $1;}
    ;
TB  :  TB AND FB                            {$$ = makeNode(and); addChild($$, $1); addChild($$, $3);}
    |  FB                                   {$$ = $1;}
    ;
FB  :  FB EQ M                              {$$ = makeNode(eq); addChild($$, $1); addChild($$, $3);}
    |  M                                    {$$ = $1;}
    ;
M   :  M ORDER E                            {$$ = makeNode(order); addChild($$, $1); addChild($$, $3);}
    |  E                                    {$$ = $1;}
    ;       
E   :  E ADDSUB T                           {$$ = makeNode(addsub); addChild($$, $1); addChild($$, $3);}  
    |  T                                    {$$ = $1;}
    ;    
T   :  T DIVSTAR F                          {$$ = makeNode(divstar); addChild($$, $1); addChild($$, $3);}
    |  F                                    {$$ = $1;}
    ;
F   :  ADDSUB F                             {$$ = makeNode(addsub); addChild($$, $2);}
    |  '!' F                                {$$ = $2;}
    |  '(' Exp ')'                          {$$ = $2;}
    |  NUM                                  {$$ = makeNode(num);}
    |  CHARACTER                            {$$ = makeNode(character);}
    |  LValue                               {$$ = $1;}
    |  IDENT '(' Arguments  ')'             {$$ = makeNode(ident); addChild($$, $3);}
    ;
LValue:
       IDENT                                {$$ = makeNode(ident);}
    ;
Arguments:
       ListExp                              {$$ = $1;}
    |                                       {$$ = makeNode(epsilon);}
    ;
ListExp:
       ListExp ',' Exp                      {$$ = $1; addSibling($$, $3);}
    |  Exp                                  {$$ = $1;}
    ;
%%
