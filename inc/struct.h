/**
 * @author Antonin JEAN
 * @email ofghanirre@gmail.com
 * @create date 2022-02-01 16:27:46
 * @modify date 2022-02-01 16:27:46
 * @desc Header file for Struct related data
 */

#ifndef __STRUCT_TAB_MATIERE_H__
#define __STRUCT_TAB_MATIERE_H__

#define HASH_SIZE 4096

typedef unsigned long __longIndex;

typedef enum _type {
    _type_other,
    _type_int,
    _type_char,
    _type_function
} _type;


typedef _type value;

typedef struct HashElem {
    char h_key[256];
    value h_val;
    int lineno;
    struct HashElem * h_next;
} HashElem;

typedef struct SymbolTab {
    HashElem * hashList[HASH_SIZE];
    __longIndex size;
    __longIndex elemAmount;
} SymbolTab, HashTable;

typedef struct functionSymbolTables {
    SymbolTab parameters;
    SymbolTab values;
    struct functionSymbolTables * next;
} functionSymbolTables;

typedef struct programSymbolTables {
    SymbolTab globals;
    functionSymbolTables * functions;
    unsigned int functionsAmount;
} programSymbolTables;


#endif