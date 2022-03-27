/**
 * @author Antonin JEAN
 * @email ofghanirre@gmail.com
 * @create date 2022-02-01 17:54:32
 * @modify date 2022-02-01 17:54:32
 * @desc Header file for utils fonctions
 */

#ifndef __UTILS_H__
#define __UTILS_H__

#include <stdio.h>
#include <stdlib.h>

void display();
void debug(char arg[]);
void cfree(void* p);
void raiseError(const char * log);
void raiseWarning(const char *log);

#endif