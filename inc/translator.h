#ifndef __TRANSLATOR_H__
#define __TRANSLATOR_H__

#include "includes.h"

FILE * getFile();

void __initAsmFile(const char * name, programSymbolTables symbolTabs, Node* tree);
void initGlobalVariables(programSymbolTables symbolTabs);
void initFunctions(programSymbolTables symbolTabs);
void initMain(programSymbolTables symbolTabs);
void initTextSection(programSymbolTables symbolTabs);
void initFunctionVariables(programSymbolTables symbolTabs, functionSymbolTables* func);


#endif