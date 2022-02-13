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
#include <string.h>
int yylex();
int yyerror(char* msg);
void printTreeWithValues(Node* node);
extern int lineno;
int treeFlag;
Node* tree;
Node* temp;
int parse;
%}

/* Type Node's definition : */
%union {
    Node* node;
    char byte;
    int num;
    char ident[64];
    char comp[4];
}

/* List of all Possible Values for a node */
%type <node> Prog DeclVars DeclFoncts Declarateurs DeclFonct EnTeteFonct Corps 
%type <node> Parametres ListExp ListTypVar SuiteInstr Instr LValue Arguments TB 
%type <node> FB M E T F Exp Switch EnTeteSwitch CorpsSwitch SuiteSwitch SwitchElement SwitchEndElement


/* List of All possible Tokens */
%token <byte> CHARACTER ADDSUB DIVSTAR
%token <num> NUM
%token <ident> IDENT
%token <comp> ORDER EQ TYPE
%token OR AND IF WHILE RETURN VOID ELSE CASE BREAK SWITCH DEFAULT


%precedence ')'
%precedence ELSE


%%
Prog:  DeclVars DeclFoncts                  {$$ = makeNode(program); tree = $$; addChild($$, $1); addChild($$, $2);}   
    ;
DeclVars:                                   
       DeclVars TYPE Declarateurs ';'       {$$ = $1; addChild($$, temp = makeNode(type)); strcpy(temp->value.comp, $2); addChild(temp, $3);}
    |                                       {$$ = makeNode(declare_var);}
    ;
Declarateurs:                                   
       Declarateurs ',' IDENT               {$$ = $1; addSibling($$, temp = makeNode(ident)); strcpy(temp->value.ident, $3);}
    |  IDENT                                {$$ = makeNode(ident); strcpy($$->value.ident, $1);}
    ;
DeclFoncts:                                 
       DeclFoncts DeclFonct                 {$$ = $1; addSibling($$, $2);}
    |  DeclFonct                            {$$ = $1;}
    ;
DeclFonct:
       EnTeteFonct Corps                    {$$ = makeNode(declare_function); addChild($$, $1); addChild($$, $2);}
    ;
EnTeteFonct:
       TYPE IDENT '(' Parametres ')'        {$$ = makeNode(header); addChild($$, temp = makeNode(type)); strcpy(temp->value.comp, $1); addChild($$, temp = makeNode(ident)); strcpy(temp->value.ident, $2); addChild($$, $4);}
    |  VOID IDENT '(' Parametres ')'        {$$ = makeNode(header); addChild($$, makeNode(void_)); addChild($$, temp = makeNode(ident)); strcpy(temp->value.ident, $2); addChild($$, $4);}
    ;
Parametres:
       VOID                                 {$$ = makeNode(parameters); addChild($$, makeNode(void_));}
    |  ListTypVar                           {$$ = makeNode(parameters); addChild($$, $1);}
    ;
ListTypVar:
       ListTypVar ',' TYPE IDENT            {$$ = makeNode(type); strcpy($$->value.comp, $3); addSibling($$, $1); addChild($$, temp = makeNode(ident)); strcpy(temp->value.ident, $4);}
    |  TYPE IDENT                           {$$ = makeNode(type); strcpy($$->value.comp, $1); addChild($$, temp = makeNode(ident)); strcpy(temp->value.ident, $2);}
    ;
Corps: '{' DeclVars SuiteInstr '}'          {$$ = makeNode(body); addChild($$, $2); addChild($$, $3);}
    ;
SuiteInstr:
       SuiteInstr Instr                     {temp = $1;
                                            if (temp == NULL) $$ = $2;              //this block makes it so no sibling
                                            else {$$ = temp; addSibling($$, $2);}}  //is ever added to a NULL
    |                                       {$$ = NULL;}
    ;
Instr:
       LValue '=' Exp ';'                   {$$ = makeNode(assign); addChild($$, $1); addChild($$, $3);}
    |  IF '(' Exp ')' Instr                 {$$ = makeNode(if_); addChild($$, $3); addChild($$, $5);}
    |  IF '(' Exp ')' Instr ELSE Instr      {$$ = makeNode(if_); addChild($$, $3); addChild($$, $5); addSibling($$, makeNode(else_)); addChild(($$->nextSibling), $7);}
    |  WHILE '(' Exp ')' Instr              {$$ = makeNode(while_); addChild($$, $3); addChild($$, $5);}
    |  IDENT '(' Arguments  ')' ';'         {$$ = makeNode(call); addChild($$, temp = makeNode(ident)); strcpy(temp->value.ident, $1); addChild($$, $3);}
    |  RETURN Exp ';'                       {$$ = makeNode(return_); addChild($$, $2);}
    |  RETURN ';'                           {$$ = makeNode(return_);}
    |  '{' SuiteInstr '}'                   {$$ = $2;}
    |  ';'                                  {$$ = NULL;}
    |  Switch
    ;
Exp :  Exp OR TB                            {$$ = makeNode(or); addChild($$, $1); addChild($$, $3);}
    |  TB                                   {$$ = $1;}
    ;
TB  :  TB AND FB                            {$$ = makeNode(and); addChild($$, $1); addChild($$, $3);}
    |  FB                                   {$$ = $1;}
    ;
FB  :  FB EQ M                              {$$ = makeNode(eq); strcpy($$->value.comp, $2); addChild($$, $1); addChild($$, $3);}
    |  M                                    {$$ = $1;}
    ;
M   :  M ORDER E                            {$$ = makeNode(order); strcpy($$->value.comp, $2); addChild($$, $1); addChild($$, $3);}
    |  E                                    {$$ = $1;}
    ;       
E   :  E ADDSUB T                           {$$ = makeNode(addsub); $$->value.byte = $2; addChild($$, $1); addChild($$, $3);}  
    |  T                                    {$$ = $1;}
    ;    
T   :  T DIVSTAR F                          {$$ = makeNode(divstar); $$->value.byte = $2; addChild($$, $1); addChild($$, $3);}
    |  F                                    {$$ = $1;}
    ;
F   :  ADDSUB F                             {$$ = makeNode(addsub); $$->value.byte = $1; addChild($$, $2);}
    |  '!' F                                {$$ = $2;}
    |  '(' Exp ')'                          {$$ = $2;}
    |  NUM                                  {$$ = makeNode(num); $$->value.num = $1;}
    |  CHARACTER                            {$$ = makeNode(character); $$->value.byte = $1;}
    |  LValue                               {$$ = $1;}
    |  IDENT '(' Arguments  ')'             {$$ = makeNode(ident); strcpy($$->value.ident, $1); addChild($$, $3);}
    ;
LValue:
       IDENT                                {$$ = makeNode(ident); strcpy($$->value.ident, $1);}
    ;
Arguments:
       ListExp                              {$$ = makeNode(arguments), addChild($$, $1);}
    |                                       {$$ = makeNode(arguments);}
    ;
ListExp:
       ListExp ',' Exp                      {$$ = $1; addSibling($$, $3);}
    |  Exp                                  {$$ = $1;}
    ;
Switch:
        EnTeteSwitch CorpsSwitch            {$$ = makeNode(switch_); addChild($$, $1); addChild($$, $2);}
    ;
EnTeteSwitch:
        SWITCH '(' Exp ')'                  {$$ = makeNode(header); addChild($$, $3);}
    ;
CorpsSwitch: 
        '{' SuiteSwitch SwitchEndElement '}'{$$ = $2; addChild($$, $3);}
    |   '{' '}'                             {$$ = makeNode(body);}
    ;

SuiteSwitch:
        SuiteSwitch SwitchElement           {$$ = $1; addChild($$, $2);}
    |                                       {$$ = makeNode(body);}
    ;
SwitchElement:
        CASE Exp ':'                        {$$ = makeNode(case_); addChild($$, $2);}
    |   DEFAULT ':'                         {$$ = makeNode(default_);}
    |   BREAK ';'                           {$$ = makeNode(break_);}
    |   Instr                               {$$ = $1;}
    ;
SwitchEndElement:               
        BREAK ';'                           {$$ = makeNode(break_);}
    |   Instr                               {$$ = $1;}
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

    parse = yyparse();
    if (!parse) {
        if (treeFlag) {
            //printTree(tree);
            printTreeWithValues(tree);
        }
        deleteTree(tree);
    }
    return parse;
}

int yyerror(char* msg) {
    fprintf(stderr, "Error near line %i.\n", lineno);
    return 0;
}