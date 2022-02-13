/**
 * @author Antonin JEAN
 * @email ofghanirre@gmail.com
 * @create date 2022-02-09 11:48:16
 * @modify date 2022-02-09 11:48:16
 * @desc Src file containing Main functions to operate 
 * 
 * Theses functions are triggered by the main located on the tpcas.y
 * file
 * 
 * 
 */
#ifndef __TPCAS_FUNCTIONS_H__
#define __TPCAS_FUNCTIONS_H__

#include "../inc/includes.h"
#include "../inc/tree.h"
#include "../inc/symbolTab.h"
#include "../inc/programData.h"
#include <getopt.h>



int mainFct_load_arg(int argc, char * argv[], int * treeFlag);

_type mainFct_charToType(const char * input);

void mainFct_Tree_to_Hash(Node * root);
#endif