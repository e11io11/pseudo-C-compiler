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

HashElem * newHashElem(const char * key, _type type) {
    HashElem * result;
    result = (HashElem* ) malloc(sizeof(HashElem));
    if (result == NULL) raiseError("Malloc error at newHashElem");
    strcpy(result->h_key, key);
    result->h_val = type;
    result->h_next = NULL;

    return result;
}

void displayHashElem(HashElem * he) {
    printf("HashElem {{ key : %s -> Value : %u } next : %p }\n", 
    he->h_key, he->h_val, (void*) he->h_next);
}

void freeHashElem(HashElem * he) {
    cfree(he);
}


void freeHashElemRecursively(HashElem * he) {
    if (he == NULL) return;

    freeHashElemRecursively(he->h_next);
    cfree(he);
}