#ifndef __DEBUG_H__
#define __DEBUG_H__

#include "debug_messages.h"
#include "symbolTab.h"
#include "tree.h"
#include "type.h"
#include "builtin_func.h"

#ifdef _WIN32
    #define STYLE_BOLD         ""
    #define STYLE_NO_BOLD      ""
    #define COLOR_RESET      ""
    #define COLOR_RED         ""
    #define COLOR_PURPLE    ""
    #define COLOR_GREEN     ""
    #define COLOR_YELLOW    ""
    #define COLOR_CYAN      ""
#else
    #define STYLE_BOLD         "\033[1m"
    #define STYLE_NO_BOLD      "\033[22m"
    #define COLOR_RESET      "\033[0m"
    #define COLOR_RED         "\033[0;31m"
    #define COLOR_PURPLE    "\033[0;35m"
    #define COLOR_GREEN     "\033[0;32m"
    #define COLOR_YELLOW    "\033[0;33m"
    #define COLOR_CYAN      "\033[0;36m"
#endif

#define _ERROR_PREFIX COLOR_RED STYLE_BOLD "[ERROR] : " COLOR_YELLOW  "<<" COLOR_RED STYLE_BOLD " %s " COLOR_YELLOW  ">>  " STYLE_NO_BOLD COLOR_RESET "%s\n" COLOR_PURPLE "Error Code %d\n" COLOR_RESET
#define _WARNING_PREFIX COLOR_PURPLE STYLE_BOLD "{WARNING} : << %s >>  " STYLE_NO_BOLD COLOR_RESET "%s\n" COLOR_PURPLE "Warning Code %d\n" COLOR_RESET

typedef enum {
    DB_ERR_UNKNOWN = 1,
    DB_ERR_REDEFINITION = 2,
    DB_ERR_INCORRECT_DEFINITION = 3,
    DB_ERR_MAIN_LACKING = 4,
    DB_ERR_INCORRECT_REFERENCE = 5,
    DB_ERR_INCORRECT_ASSIGNMENT = 6,
    DB_ERR_INCORRECT_USAGE = 7,
    DB_ERR_RETURN_VOID = 8,
} _error_type;

typedef enum {
    DB_WRN_UNKNOWN = 1,
    DB_WRN_ASSIGNMENT_OVERFLOW = 2,
    DB_WRN_INCOHERENT_RETURN = 3,
    DB_WRN_MISSING_RETURN = 4,
    DB_WRN_POST_RETURN_CODE = 5,
} _warning_type;

typedef enum {
    UNKNOWN = -1,
} _warn_type;

extern int _file_got_errors;
extern int _display_warnings;

void debug_warning(_warning_type type, const char* message );
void debug_error(_error_type type, const char* message);
int debug_final();
void putHashVal_checked (SymbolTab* st, HashElem* he);
void function_parameters_checked (functionSymbolTables fst);
void function_main_checked (Node * rootHeader);
void variables_reference_checked (Node * function_iter, programSymbolTables pst );
#endif


#ifdef UNDEF_______dbg

/* Reférence : */
/**
 * @brief loop through the functions of the program
 * and check if there var referenced are correct
 * 
 */
variables_reference_checked()
    /**
     * @brief check if :
     * a variable is declared : 
     * a variable called is a function
     * 
     */
L>  function_body_checked() {
        db_error_var_undeclared()
        db_error_var_not_callable()
    }
    L>

        

program
├── declare var
│   └── type: int
│       └── ident: i
├── declare function
│   ├── header
│   │   ├── void
│   │   ├── ident: fun
│   │   └── parameters
│   │       ├── type: char
│   │       │   └── ident: c
│   │       └── type: int
│   │           └── ident: a
│   └── body
│       └── declare var
│           └── type: int
│               └── ident: i
├── declare function
│   ├── header
│   │   ├── type: int
│   │   ├── ident: t
│   │   └── parameters
│   │       └── void
│   └── body
│       ├── declare var
│       └── return
│           └── num: 5
└── declare function
    ├── header
    │   ├── type: int
    │   ├── ident: main
    │   └── parameters
    │       └── void
    └── body
        ├── declare var
        │   ├── type: int
        │   │   └── ident: a
        │   ├── type: char
        │   │   └── ident: b
        │   └── type: int
        │       └── ident: r
        ├── assign
        │   ├── ident: a
        │   └── character: c
        ├── if
        │   ├── eq: ==
        │   │   ├── ident: a
        │   │   └── num: 0
        │   └── assign
        │       ├── ident: a
        │       └── addsub: +
        │           ├── addsub: +
        │           │   ├── divstar: *
        │           │   │   ├── num: 0
        │           │   │   └── num: 5
        │           │   └── num: 4
        │           └── ident: b
        ├── call
        │   ├── ident: fun
        │   └── arguments
        │       ├── ident: fun
        │       │   └── arguments
        │       │       ├── num: 2
        │       │       └── num: 2
        │       └── ident: d
        ├── assign
        │   ├── ident: b
        │   └── ident: t
        │       └── arguments
        ├── assign
        │   ├── ident: r
        │   └── addsub: -
        │       ├── num: 4
        │       └── num: 5
        └── return
            └── num: 0
return : 2


program
├── declare var
├── declare function
│   ├── header
│   │   ├── void
│   │   ├── ident: fun
│   │   └── parameters
│   │       ├── type: char
│   │       │   └── ident: b
│   │       └── type: int
│   │           └── ident: a
│   └── body
│       └── declare var
└── declare function
    ├── header
    │   ├── type: int
    │   ├── ident: main
    │   └── parameters
    │       └── void
    └── body
        ├── declare var
        ├── call
        │   ├── ident: fun
        │   └── arguments
        │       ├── ident: fun
        │       │   └── arguments
        │       │       ├── num: 2
        │       │       └── ident: frere
        │       └── ident: d
        └── return
            └── num: 0
            
#endif