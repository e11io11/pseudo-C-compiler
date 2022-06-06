#ifndef __TRANSLATOR_H__
#define __TRANSLATOR_H__

#include "includes.h"
#include "builtin_func.h"

FILE * getFile();

void __initAsmFile(const char * name, programSymbolTables symbolTabs, Node* tree);
void initGlobalVariables(programSymbolTables symbolTabs);
void initFunctions(programSymbolTables symbolTabs);
void initMain(programSymbolTables symbolTabs, functionSymbolTables* func);
void initTextSection(programSymbolTables symbolTabs);
void initFunctionVariables(programSymbolTables symbolTabs, functionSymbolTables* func);
void initAssign(programSymbolTables symbolTabs, functionSymbolTables* func, Node* node);
void initFunctionBody(programSymbolTables symbolTabs, functionSymbolTables* func, Node* node);
void initRValue(programSymbolTables symbolTabs, functionSymbolTables* func, Node* node);
void initIdent(programSymbolTables symbolTabs, functionSymbolTables* func, Node* node);
void initBuiltins();

#endif