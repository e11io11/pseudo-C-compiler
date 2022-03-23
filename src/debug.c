#include "../inc/debug.h"

char * _error_type_message[256] = {"_", "Unknown", "Redefinition of an Object"};

int _file_got_errors = 0;

void debug_warning(_warn_type type, const char* message ) {
    fprintf(stderr, _WARNING_PREFIX, type, message);
}

void debug_error(_error_type type, const char* message) {
    fprintf(stderr, _ERROR_PREFIX, _error_type_message[type], message, type);
    _file_got_errors += 1;
}

void debug_final() {
    if (_file_got_errors) {
        fprintf(stderr, 
        COLOR_GREEN "-----------------------------------------\n"
        COLOR_RED STYLE_BOLD "%d ERROR%s occured during compilation, exiting\n"
        COLOR_GREEN "-----------------------------------------\n",
        _file_got_errors, _file_got_errors > 1 ? "S" : "");
        exit(EXIT_FAILURE);
    }
}


void putHashVal_checked (SymbolTab* st, HashElem* he) {
    HashElem* test;
    if ((test = findHashElem(*st, he->h_key))) {
        char buf[512];
        sprintf(buf, "Value : " COLOR_CYAN STYLE_BOLD "%s" COLOR_RESET", defined at line " COLOR_GREEN "%d" COLOR_RESET ", is redefined at line " COLOR_GREEN "%d", he->h_key, test->lineno, he->lineno);
        debug_error(DB_ERR_REDEFINITION, buf);
    }

    putHashVal(st, he);
}