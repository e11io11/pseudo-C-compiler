#include "../inc/debug.h"

char * _error_type_message[256] = {"_", "Unknown", "Redefinition of an Object", "Incorrect Definition of an Object", "Main Function is Lacking", "Incorrect Reference of an Object", "Incorrect type assignment of an Object"};
char * _warning_type_message[256] = {"_", "Unknown", "Overflow Risk"};
int _file_got_errors = 0;
int _file_got_warnings = 0;

void debug_warning(_warn_type type, const char* message ) {
    fprintf(stderr, _WARNING_PREFIX, _warning_type_message[type], message, type);
    _file_got_warnings += 1;
}

void debug_error(_error_type type, const char* message) {
    fprintf(stderr, _ERROR_PREFIX, _error_type_message[type], message, type);
    _file_got_errors += 1;
}

int debug_final() {
    if (_file_got_warnings) {
        fprintf(stderr, 
        COLOR_GREEN "-----------------------------------------\n"
        COLOR_PURPLE STYLE_BOLD "%d WARNING%s occured during compilation, please check before processing\n"
        COLOR_GREEN "-----------------------------------------\n" COLOR_RESET,
        _file_got_warnings, _file_got_warnings > 1 ? "S" : "");
    }
    if (_file_got_errors) {
        fprintf(stderr, 
        COLOR_GREEN "-----------------------------------------\n"
        COLOR_RED STYLE_BOLD "%d ERROR%s occured during compilation, exiting\n"
        COLOR_GREEN "-----------------------------------------\n",
        _file_got_errors, _file_got_errors > 1 ? "S" : "");
        return 1;
    }
    return 0;
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

void function_parameters_checked (functionSymbolTables fst) {
    HashElem ** local_fun_variables = HashTableValues(&(fst.values));
    HashElem ** param_fun = HashTableValues(&(fst.parameters));
    int i, j;
    for (i = 0; i < fst.parameters.elemAmount; i++) {
        HashElem* temp = param_fun[i];
        for (j = 0; j < fst.values.elemAmount; j++) {
            if (strcmp(temp->h_key, local_fun_variables[j]->h_key) == 0) {
                char buf[512];
                sprintf(buf, "Value : " COLOR_CYAN STYLE_BOLD "%s" COLOR_RESET", defined at line " COLOR_GREEN "%d" COLOR_RESET ", is redefined at line " COLOR_GREEN "%d", temp->h_key, temp->lineno, local_fun_variables[j]->lineno);
                debug_error(DB_ERR_REDEFINITION, buf);
            }
        }
    }
    free(local_fun_variables);
    free(param_fun);
}

void function_main_checked (Node * function_iter) {
    int mainDefinitioncpt = 0;
    char buf[512];
    while (function_iter) {
        Node * rootHeader = function_iter->firstChild;
        Node * iter_type = findLabelInTree(rootHeader->firstChild, type);
        Node * iter_ident = findLabelInTree(rootHeader->firstChild, ident);
        if (iter_type == NULL) iter_type = findLabelInTree(rootHeader->firstChild, void_);
        if (strcmp(iter_ident->value.ident, "main") == 0) {
            if (iter_type->label == void_ || strcmp(iter_type->value.comp, "int")) {
                sprintf(buf, "Function : " COLOR_CYAN STYLE_BOLD "main" COLOR_RESET" shall return an " COLOR_GREEN "int" COLOR_RESET
                ", was found returning " COLOR_GREEN "%s" COLOR_RESET " instead\n"
                " -- defined at line %d ", iter_type->label == void_ ? "void" : iter_type->value.comp, iter_type->lineno);
                debug_error(DB_ERR_INCORRECT_DEFINITION, buf);
            } else mainDefinitioncpt++;
        }
        function_iter = function_iter->nextSibling;
    }
    if (mainDefinitioncpt == 0) {
        sprintf(buf, "Init function " COLOR_CYAN STYLE_BOLD "int main()" COLOR_RESET" can't be found");
        debug_error(DB_ERR_MAIN_LACKING, buf);
    }
}

#define ERROR -2
#define IGNORE -1

_type evalExprType(Node * exprRoot, SymbolTab global, SymbolTab parameters, SymbolTab local) {
    if (exprRoot) {
        switch (exprRoot->label) {
            case ident: {
                HashElem * elem;
                if ((elem = findHashElem(local, exprRoot->value.ident)) || 
                    (elem = findHashElem(parameters, exprRoot->value.ident)) ||
                    (elem = findHashElem(global, exprRoot->value.ident))) {
                        
                        if (elem->h_val.type == _type_function) {
                            if (! exprRoot->firstChild) {
                                char buf[512];
                                sprintf(buf, "Can not assign the type " COLOR_CYAN STYLE_BOLD "function" COLOR_RESET" to a LValue.\nOccured at line " COLOR_GREEN "%d" COLOR_RESET, exprRoot->lineno);
                                debug_error(DB_ERR_INCORRECT_ASSIGNMENT, buf);
                                return ERROR;
                            }
                            return elem->h_val.val.func.ret;
                        }
                        return elem->h_val.type;
                } else { return IGNORE;}
            }
            case num: return _type_int;
            case character: return _type_char;
            default: {
                _type t1, t2;
                t1 = evalExprType(exprRoot->firstChild, global, parameters, local);
                t2 = evalExprType(exprRoot->firstChild->nextSibling, global, parameters, local);
                switch ((int) t1) {
                    case IGNORE: return t2;
                    case ERROR: return ERROR;
                    case _type_void: {
                        char buf[512];
                        sprintf(buf, "Can not assign the type " COLOR_CYAN STYLE_BOLD "void" COLOR_RESET" to a LValue.\nOccured at line " COLOR_GREEN "%d" COLOR_RESET, exprRoot->lineno);
                        debug_error(DB_ERR_INCORRECT_ASSIGNMENT, buf);
                        return ERROR;
                    }
                    default: {
                        if (t2 == ERROR) return ERROR;
                        if (t2 == IGNORE) return t1;
                        return _type_int;
                    }
                }
            }
        }
    }
    return IGNORE;
}

void variables_assignment_checked(Node * assignRoot, SymbolTab global, SymbolTab parameters, SymbolTab local) {
    if (assignRoot) {
        _type leftValue, rightValue;
        HashElem * elem;
        assignRoot = assignRoot->firstChild;
        if ((elem = findHashElem(local, assignRoot->value.ident)) || 
            (elem = findHashElem(parameters, assignRoot->value.ident)) ||
            (elem = findHashElem(global, assignRoot->value.ident))) {
                leftValue = elem->h_val.type;
                if (leftValue == _type_function) {
                    char buf[512];
                    sprintf(buf, "Can not use the type " COLOR_CYAN STYLE_BOLD "function" COLOR_RESET" as a LValue.\nOccured at line " COLOR_GREEN "%d" COLOR_RESET, assignRoot->lineno);
                    debug_error(DB_ERR_INCORRECT_ASSIGNMENT, buf);
                }
        } else { return ;}
        assignRoot = assignRoot->nextSibling;
        rightValue = evalExprType(assignRoot, global, parameters, local);
        switch ((int) rightValue) {
            case ERROR:;
            case IGNORE: return;
            case _type_int: {
                if (leftValue == _type_char) {
                    char buf[512];
                    sprintf(buf, "Assignment of an " COLOR_CYAN STYLE_BOLD "%s" COLOR_RESET" into a " COLOR_CYAN STYLE_BOLD "%s" COLOR_RESET" may result in  " COLOR_RED STYLE_BOLD "data Overflow" COLOR_RESET ".\nOccured at line " COLOR_GREEN "%d" COLOR_RESET, typeToChar(rightValue), typeToChar(leftValue), elem->lineno);
                    debug_warning(DB_WRN_ASSIGNMENT_OVERFLOW, buf);
                }
            }
            default: {
                return ;
            }
        }
    }
}

void function_body_checked (Node * root, SymbolTab global, SymbolTab parameters, SymbolTab local, SymbolTab * varMemory) {
    if (root == NULL) return;
    else {
        if (root->label == ident) {
            Node * iter_ident = root;
            while (iter_ident != NULL){
                if (!(findHashElem(local, iter_ident->value.ident) || findHashElem(parameters, iter_ident->value.ident) || findHashElem(global, iter_ident->value.ident))) {
                    char buf[512];
                    int foundFlag = findHashElem(*varMemory, iter_ident->value.ident) ? 1 : 0;
                    puts("\n");
                    if (!foundFlag)
                        putHashVal(varMemory, newHashElem(iter_ident->value.ident, newValueVoid(), iter_ident->lineno));
                    sprintf(buf, "variable : " COLOR_CYAN STYLE_BOLD "'%s'" COLOR_RESET" undeclared %s" COLOR_RESET "\n"
                    " -- referenced at line %d ", iter_ident->value.ident, foundFlag ? COLOR_CYAN "(already used before)" : COLOR_GREEN "(first use in this function)", iter_ident->lineno);
                    debug_error(DB_ERR_INCORRECT_REFERENCE, buf);
                }
                iter_ident = findLabelInTree(iter_ident->nextSibling, ident);
            }
        } else {
            if (root->label == assign)
                variables_assignment_checked(root, global, parameters, local);

            function_body_checked(root->firstChild, global, parameters, local, varMemory);
            function_body_checked(root->nextSibling, global, parameters, local, varMemory);
        }
    }
}

void variables_reference_checked (Node * root, programSymbolTables pst ) {
    functionSymbolTables * fst_iter = pst.functions;
    Node * function_iter = findLabelInTree(root->firstChild, declare_function);
    functionSymbolTables * fst_list[pst.functionsAmount];
    SymbolTab varMemory = newSymbolTab();
    int cpt = pst.functionsAmount - 1;

    /* Initilisation of function array */
    while (fst_iter) {
        fst_list[cpt--] = fst_iter;
        fst_iter = fst_iter->next;
    }

    cpt = 0;
    while ( function_iter ) {
        Node * body_iter = findLabelInTree(function_iter->firstChild, body);
        if (body_iter) {
            Node * declare_var_iter = body_iter->firstChild;
            declare_var_iter = findLabelInTree (declare_var_iter, declare_var);
            function_body_checked(declare_var_iter->nextSibling, pst.globals, fst_list[cpt]->parameters, fst_list[cpt]->values, &varMemory);
            freeSymbolTab(&varMemory);
            varMemory = newSymbolTab();
            cpt++;
        }
        function_iter = findLabelInTree(function_iter->nextSibling, declare_function);
    }
}