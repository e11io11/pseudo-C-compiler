%{
/**
 * @author Antonin JEAN
 * @author Elliott FALGUEROLLE
 * @email ofghanirre@gmail.com
 * @create date 2021-11-14 19:56:15
 * @modify date 2021-11-14 19:56:15
 * @desc Bison file for the Syntax Analyzer
 * It recieves token from lex compiled file and 
 * operates based on the latter.
 */

#include "../src/tree.h"
#include <stdio.h>
#include <getopt.h>
int yylex();
int yyerror(char* msg);
extern int lineno;
int treeFlag;
%}

/* Type Node's definition : */
%union {
    Node* node;
}

/* List of all Possible Values for a node */
%type <node> Prog DeclVars DeclFoncts Declarateurs DeclFonct EnTeteFonct Corps Parametres ListExp ListTypVar SuiteInstr Instr LValue Arguments TB FB M E T F Exp


/* List of All possible Tokens */
%token DIVSTAR IDENT TYPE VOID WHILE IF RETURN ELSE OR AND EQ ORDER ADDSUB
%token NUM CHARACTER

%%
Prog:  DeclVars DeclFoncts                  {$$ = makeNode(Prog); addChild($$, $1); addChild($$, $2); if (treeFlag) printTree($$);}   
    ;
DeclVars:                                   
       DeclVars TYPE Declarateurs ';'       {$$ = $1; addChild($$, $3);}
    |                                       {$$ = makeNode(DeclVars);}
    ;
Declarateurs:                                   
       Declarateurs ',' IDENT               {$$ = $1; addChild($$, makeNode(ident));}
    |  IDENT                                {$$ = makeNode(type); addChild($$, makeNode(ident));}
    ;
DeclFoncts:                                 
       DeclFoncts DeclFonct                 {$$ = $1; addSibling($$, $2);}
    |  DeclFonct                            {$$ = $1;}
    ;
DeclFonct:
       EnTeteFonct Corps                    {$$ = makeNode(DeclFonct); addChild($$, $1); addChild($$, $2);}
    ;
EnTeteFonct:
       TYPE IDENT '(' Parametres ')'        {$$ = makeNode(EnTeteFonct); addChild($$, makeNode(type)); addChild($$, makeNode(ident)); addChild($$, $4);}
    |  VOID IDENT '(' Parametres ')'        {$$ = makeNode(EnTeteFonct); addChild($$, makeNode(void_)); addChild($$, makeNode(ident)); addChild($$, $4);}
    ;
Parametres:
       VOID                                 {$$ = makeNode(Parametres); addChild($$, makeNode(void_));}
    |  ListTypVar                           {$$ = makeNode(Parametres); addChild($$, $1);}
    ;
ListTypVar:
       ListTypVar ',' TYPE IDENT            {$$ = makeNode(type); addSibling($$, $1); addChild($$, makeNode(ident));}
    |  TYPE IDENT                           {$$ = makeNode(type); addChild($$, makeNode(ident));}
    ;
Corps: '{' DeclVars SuiteInstr '}'          {$$ = makeNode(Corps); addChild($$, $2); addChild($$, $3);}
    ;
SuiteInstr:
       SuiteInstr Instr                     {$$ = $1; addChild($$, $2);}
    |                                       {$$ = makeNode(SuiteInstr);}
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
       ListExp                              {$$ = makeNode(Arguments), addChild($$, $1);}
    |                                       {$$ = makeNode(Arguments);}
    ;
ListExp:
       ListExp ',' Exp                      {$$ = $1; addSibling($$, $3);}
    |  Exp                                  {$$ = $1;}
    ;
%%


int main(int argc, char** argv) {
    int c;
    static struct option long_options[] = {
        {"tree", no_argument, 0, 't'},
        {"help", no_argument, 0, 'h'},
        {0,0,0,'?'}
    };
    int option_index = 0;

    while (1) {
        c = getopt_long(argc, argv, "th", long_options, &option_index);
        if (c == -1) {
            break;
        }
        switch (c) {
            case 't': /* Enable the display of a tree */
                treeFlag = 1;
                break;
            case 'h': /* Enable Help Display */
                printf("Usage: ./tpcas [options] < [target]\nOptions:\n-h --help Print this message and exit.\n-t --tree Print target's abstract tree\n");
                break;
            case '?': /* Other unrecognized values */
                return 2;
        }
    }

    return yyparse();
}

int yyerror(char* msg) {
    fprintf(stderr, "Error near line %i.\n", lineno);
    return 0;
}