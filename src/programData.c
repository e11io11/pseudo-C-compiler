/**
 * @author Antonin JEAN
 * @email ofghanirre@gmail.com
 * @create date 2022-02-13 05:12:43
 * @modify date 2022-02-13 05:12:43
 * @desc Src file related to programData's related structures
 */

#include "../inc/programData.h"
#include "../inc/symbolTab.h"

programSymbolTables newProgramSymbolTables(unsigned int cpt) {
    programSymbolTables result;
    result.functionsAmount = cpt;
    result.functions = (functionSymbolTables *) malloc(sizeof(functionSymbolTables) * cpt);
    return result;
}

void displayProgramSymbolTables(programSymbolTables pst) {
    int cpt = 0;
    printf( "TPC hashValues :\n"
            "Global Values:\n");
    displayHashTable(pst.globals);
    printf("Functions:\t[total : %d]\n",pst.functionsAmount);
    

    for (cpt = 0; cpt < pst.functionsAmount; cpt++) {
        printf("++ FUNCTIONS [%d / %d]\n", cpt+1, pst.functionsAmount);
        printf("[%d]\t\tParameters:\t\t", cpt+1);
        displayHashTable(pst.functions[cpt].parameters);
        printf("[%d]\t\tLocal Variables:\t", cpt+1);
        displayHashTable(pst.functions[cpt].values);
    }
    printf("\n\n");
}

void freeProgramSymbolTables(programSymbolTables pst) {
    int i;
    for (i = 0; i < pst.functionsAmount; i++) {
        freeSymbolTab(&(pst.functions[i].parameters));
        freeSymbolTab(&(pst.functions[i].values));
    }

    freeSymbolTab(&(pst.globals));

    cfree(pst.functions);
}