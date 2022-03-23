/**
 * @author Antonin JEAN
 * @email ofghanirre@gmail.com
 * @create date 2022-02-01 18:04:13
 * @modify date 2022-02-01 18:04:13
 * @desc Header file for SymbolTab related function
 */

#ifndef __SYMBOL_TAB_H__
#define __SYMBOL_TAB_H__

#include "hash.h"
#include "includes.h"


void displayHashTable(SymbolTab st);
#define displaySymbolTab displayHashTable

SymbolTab newHashTable();
#define newSymbolTab newHashTable

HashElem * getHashVal(SymbolTab st, const char * key);

void putHashVal(SymbolTab * st, HashElem * he);

void freeHashTable(SymbolTab * st);
#define freeSymbolTab freeHashTable

void testHashTableRepartition(SymbolTab * st, int input_amount);
#define testSymbolTabRepartition testHashTableRepartition

HashElem * findHashElem(HashTable st, const char * key);

#endif