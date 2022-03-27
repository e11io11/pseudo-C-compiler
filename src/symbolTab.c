/**
 * @author Antonin JEAN
 * @email ofghanirre@gmail.com
 * @create date 2022-02-01 18:03:25
 * @modify date 2022-02-01 18:03:25
 * @desc Src file for HashTable related functions
 */

#include "../inc/symbolTab.h"

void displayHashTable(HashTable st) {
    __longIndex i;
    short isEmpty = 1;
    printf("HASHTABLE : [%lu]\n", st.elemAmount);
    for (i = 0; i < st.size; i++) {
        if (st.hashList[i] != NULL) {
            int cpt = 0;
            HashElem * temp = NULL;
            isEmpty = 0;
            printf("HC : %lu >>>\t", i); 
            temp = st.hashList[i];
            while (temp != NULL) {
                if (cpt != 0) printf("\t\tL> ");
                displayHashElem(temp);
                temp = temp->h_next;
                cpt++;
            }
        }
    }
    if (isEmpty) printf("--> EMPTY\n\n");
}


HashTable newHashTable() {
    HashTable result;
    int i;
    result.size = HASH_SIZE;
    for (i = 0; i < result.size; i++)
        result.hashList[i] = NULL;
    result.elemAmount = 0;
    return result;
}


HashElem * findHashElem(HashTable st, const char * key) {
    HashElem * temp = NULL;

    temp = st.hashList[getHashCode(key)];
    while (temp != NULL && strcmp(temp->h_key, key)) {
        temp = temp->h_next;
    }
    return temp;
}


HashElem * getHashVal(HashTable st, const char * key) {
    if (key == NULL) return NULL;
    return findHashElem(st, key);
}

HashElem ** HashTableValues(HashTable * ht) {
    HashElem ** result = (HashElem **) malloc (sizeof (HashElem *) * ht->elemAmount);
    int i, cpt = 0;
    
    for (i = 0; i < ht->size; i++) {
        HashElem * temp = ht->hashList[i];
        while (temp != NULL) {
            result[cpt++] = temp;
            temp = temp->h_next;
        }
    }
    return result;
}

void putHashVal(HashTable * st, HashElem * he) {
    if (st == NULL) raiseError("putHashVal : st is NULL");
    else if (st == NULL) raiseError("putHashVal : he is NULL");
    else {
        HashElem * temp;
        __longIndex index = getHashCode(he->h_key);
        temp = st->hashList[index];
        while (temp != NULL) {
            if (strcmp(temp->h_key, he->h_key) == 0){
                temp->h_val = he->h_val;
                freeHashElem(he);
                return;
            }
            temp = temp->h_next;
        }
        temp = st->hashList[index];
        if (temp == NULL) st->hashList[index] = he;
        else {
            he->h_next = st->hashList[index];
            st->hashList[index] = he;
        }
        st->elemAmount += 1;
        
    }
}


void freeHashTable(HashTable * st) {
    __longIndex i;
    for (i = 0; i < st->size; i++) {
        freeHashElemRecursively(st->hashList[i]);
    }
}


void testHashTableRepartition(HashTable * st, int input_amount) {
    if (st == NULL) raiseError("testHashTableRepartition : st is NULL");
    else {
        __longIndex i, empty_count, multiple_count;
        empty_count = 0;
        multiple_count = 0;
        for (i = 0; i < st->size; i++) {
            HashElem * temp = st->hashList[i];
            if (temp == NULL) empty_count++;
            else if (temp->h_next != NULL) multiple_count++;
        }

        printf( "HashTable Repartition Datas:\n"
                "Total inputs\t:\t%d\n\n"
                "Total Elem\t:\t%lu\n"
                "------------------------------\n"
                "Filled Elem\t:\t%lu\t%f of total\n"
                "Empty Elem\t:\t%lu\t%f of total\n"
                "Multi Elem\t:\t%lu\t%f of total\t%f of Filled\n",
                input_amount,
                st->size,
                st->size - empty_count, ((float) (st->size - empty_count) / st->size) * 100.,
                empty_count, ((float) empty_count / st->size) * 100.,
                multiple_count, ((float) multiple_count / st->size) * 100.,
                ((float) multiple_count / (st->size - empty_count)) * 100.
        );
    }  
}