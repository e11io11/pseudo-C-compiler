/**
 * @author Antonin JEAN
 * @email ofghanirre@gmail.com
 * @create date 2022-02-01 17:54:20
 * @modify date 2022-02-01 17:54:20
 * @desc Src file for utils fonctions
 */

#include "../inc/utils.h"

void display() {
    printf("\n");
}

void debug(char arg[]) {
    static int cpt = 0;
    printf("\n[ LOG ] from %s\t [%d]\n", arg, cpt++);
}

void cfree(void* p) {
    if ( p != NULL ) free(p);
}

void raiseError(const char * log) {
    perror("ERROR :\t"); perror(log); exit(3);
}

void raiseWarning(const char *log) {
    perror("WARN : \t"); perror(log);
}