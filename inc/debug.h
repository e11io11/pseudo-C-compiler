#ifndef __DEBUG_H__
#define __DEBUG_H__

#include "symbolTab.h"
#include "tree.h"

#define STYLE_BOLD         "\033[1m"
#define STYLE_NO_BOLD      "\033[22m"
#define COLOR_RESET      "\033[0m"
#define COLOR_RED         "\033[0;31m"
#define COLOR_PURPLE    "\033[0;35m"
#define COLOR_GREEN     "\033[0;32m"
#define COLOR_YELLOW    "\033[0;33m"
#define COLOR_CYAN      "\033[0;36m"

#define _ERROR_PREFIX COLOR_RED STYLE_BOLD "[ERROR] : " COLOR_YELLOW  "<<" COLOR_RED STYLE_BOLD " %s " COLOR_YELLOW  ">>  " STYLE_NO_BOLD COLOR_RESET "%s\n" COLOR_PURPLE "Error Code %d\n" COLOR_RESET
#define _WARNING_PREFIX COLOR_PURPLE STYLE_BOLD "{WARNING} : << %d >>  " STYLE_NO_BOLD COLOR_RESET "%s\n" COLOR_RESET

typedef enum {
    DB_ERR_UNKNOWN = 1,
    DB_ERR_REDEFINITION = 2,
    DB_ERR_INCORRECT_DEFINITION = 3,
    DB_ERR_MAIN_LACKING = 4,
    DB_ERR_INCORRECT_REFERENCE = 5,
} _error_type;


typedef enum {
    UNKNOWN = -1,
} _warn_type;

extern int _file_got_errors;


void debug_warning(_warn_type type, const char* message );
void debug_error(_error_type type, const char* message);
void debug_final();
void putHashVal_checked (SymbolTab* st, HashElem* he);
void function_parameters_checked (functionSymbolTables fst);
void function_main_checked (Node * rootHeader);
void variables_reference_checked (Node * function_iter, programSymbolTables pst );
#endif