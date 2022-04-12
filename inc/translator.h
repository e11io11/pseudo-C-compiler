#ifndef __TRANSLATOR_H__
#define __TRANSLATOR_H__

#include "includes.h"

FILE * getFile();

void __initAsmFile(const char * name, programSymbolTables symbolTabs, Node* tree);
void initGlobalVariables(programSymbolTables symbolTabs);

#endif