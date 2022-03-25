/**
 * @author Antonin JEAN
 * @email ofghanirre@gmail.com
 * @create date 2022-02-13 05:12:43
 * @modify date 2022-02-13 05:12:43
 * @desc Src file related to programData's related structures
 */

#include "../inc/programData.h"
#include "../inc/symbolTab.h"

programSymbolTables newProgramSymbolTables() {
    programSymbolTables result;
    result.functionsAmount = 0;
    result.functions = NULL;
    return result;
}

functionSymbolTables * newFunctionSymbolTable() {
    functionSymbolTables * result = (functionSymbolTables*) malloc(sizeof(functionSymbolTables));
    result->next = NULL;
    return result;
}

void putFunctionSymbolTable(programSymbolTables * pst, functionSymbolTables * fst) {
    functionSymbolTables * temp;
    pst->functionsAmount += 1;
    temp = pst->functions;
    pst->functions = fst;
    fst->next = temp;
}

void displayProgramSymbolTables(programSymbolTables pst) {
    int cpt = 0;
    functionSymbolTables * temp;
    printf( "TPC hashValues :\n"
            "Global Values:\n");
    displayHashTable(pst.globals);
    printf("Functions:\t[total : %d]\n",pst.functionsAmount);
    
    temp = pst.functions;
    while (temp != NULL) {
        printf("++ FUNCTIONS [%d / %d]\n", ++cpt, pst.functionsAmount);
        printf("[%d]\t\tParameters:\t\t", cpt);
        displayHashTable(temp->parameters);
        printf("[%d]\t\tLocal Variables:\t", cpt);
        displayHashTable(temp->values);
        temp = temp->next;
    }
    printf("\n\n");
}

void freeProgramSymbolTables(programSymbolTables pst) {
    functionSymbolTables * temp = pst.functions;
    while (temp != NULL) {
        freeSymbolTab(&(temp->parameters));
        freeSymbolTab(&(temp->values));
        temp = temp->next;
    }

    freeSymbolTab(&(pst.globals));

    cfree(pst.functions);
}