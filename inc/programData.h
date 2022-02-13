/**
 * @author Antonin JEAN
 * @email ofghanirre@gmail.com
 * @create date 2022-02-13 05:13:13
 * @modify date 2022-02-13 05:13:13
 * @desc Src file related to programData's related structures
 */

#ifndef __PROGRAM_DATA_H__
#define __PROGRAM_DATA_H__

#include "includes.h"


programSymbolTables newProgramSymbolTables(unsigned int cpt);

void displayProgramSymbolTables(programSymbolTables pst);

void freeProgramSymbolTables(programSymbolTables pst);
#endif