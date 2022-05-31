#ifndef __BUILTIN_FUNC_H__
#define __BUILTIN_FUNC_H__

#include "struct.h"
#include "programData.h"


typedef struct blt_f_decl {
    char name[256];
    char parameters[1024];
    unsigned int parametersAmount;
    char return_value[5];
    char asm_src_code[8096];
} blt_f_decl;


typedef struct builtinFunctionSymbolTables {
    SymbolTab fcts;
    int amount;
} builtinFunctionSymbolTables;

void blt_func_init();


extern builtinFunctionSymbolTables blt_functions;
#define BLT_FUNCTIONS blt_functions.fcts
#define AMOUNT_BLT_FUNCTIONS blt_functions.amount


void displayBuiltin();
void displayBuiltinDecl();
#endif