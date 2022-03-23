/**
 * @author Antonin JEAN
 * @email ofghanirre@gmail.com
 * @create date 2022-02-01 16:53:33
 * @modify date 2022-02-01 16:53:33
 * @desc Header file for Hash related functions
 */

#ifndef __HASH_H__
#define __HASH_H__

#include "includes.h"

#define HASH_CODE 21

__longIndex getHashCode(const char * elem);

HashElem * newHashElem(const char * key, _type type, int lineno);

void displayHashElem(HashElem * he);

void freeHashElem(HashElem * he);
void freeHashElemRecursively(HashElem * he);
#endif
