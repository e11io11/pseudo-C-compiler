/**
 * @author Antonin JEAN
 * @email ofghanirre@gmail.com
 * @create date 2022-02-01 16:53:05
 * @modify date 2022-02-01 16:53:05
 * @desc Src file for Hash fonctions
 */

#include "../inc/hash.h"

__longIndex getHashCode(const char * elem) {
    __longIndex result = 0;
    int i;
    if (elem == NULL) raiseError("getHashCode : elem is NULL");
    for (i = 0; elem[i]; i++) result = ((result << 5) + result) + elem[i];

    return result % HASH_SIZE;
}

HashElem * newHashElem(const char * key, value v, int lineno) {
    HashElem * result;
    result = (HashElem* ) malloc(sizeof(HashElem));
    if (result == NULL) raiseError("Malloc error at newHashElem");
    strcpy(result->h_key, key);
    result->h_val = v;
    result->h_next = NULL;
    result->lineno = lineno;

    return result;
}

void displayHashElem(HashElem * he) {
    printf("HashElem {{ key : %s -> Value : {", he->h_key);
    displayValue(he->h_val);
    printf("}, lineno : %u} next : %p }\n", 
    he->lineno, (void*) he->h_next);
}

void freeHashElem(HashElem * he) {
    freeValue(he->h_val);
    cfree(he);
}


void freeHashElemRecursively(HashElem * he) {
    if (he == NULL) return;

    freeHashElemRecursively(he->h_next);
    freeValue(he->h_val);
    cfree(he);
}