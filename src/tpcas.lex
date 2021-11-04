%{
//#include "tree.h"
#include "tpcas.tab.h"
int lineno;
%}

%option nounput
%option noinput
%option noyywrap

%%
(while|for|if)                    ;
[*/%]                             {return DIVSTAR;}
[a-zA-Z_][a-zA-Z_0-9]*            {return IDENT;}
.                                 ;
<<EOF>>                           {return 0;}
%%