
#ifndef __TYPE_H__
#define __TYPE_H__

#include "includes.h"
#include "tree.h"

char * typeToChar(_type t);

_type charToType(const char * input);

_type_fc_param * newFcParam(_type t);

value newValueFct(Node * headerRoot);

value newValueInt();

value newValueChar();

value newValueVoid();

value newValuePrim(_type t);

void freeValue(value v);

void displayValue(value v);
#endif