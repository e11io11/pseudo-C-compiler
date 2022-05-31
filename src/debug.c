#include "../inc/debug.h"

char * _error_type_message[256] = {
    "_", 
    "Unknown", 
    "Redefinition of an Object", 
    "Incorrect Definition of an Object", 
    "Main Function is Lacking", 
    "Incorrect Reference of an Object", 
    "Incorrect type assignment of an Object", 
    "Incorrect Usage of an Object",
    "Invalid Return Value"
};

char * _warning_type_message[256] = {
    "_", 
    "Unknown", 
    "Overflow Risk", 
    "Incoherent return",
    "Missing return",
    "Post-Return Instructions",
};

int _file_got_errors = 0;
int _file_got_warnings = 0;
int _display_warnings = 1;

void debug_warning(_warning_type type, const char* message ) {
    if (_display_warnings) {
        fprintf(stderr, _WARNING_PREFIX, _warning_type_message[type], message, type);
        _file_got_warnings += 1;
    }
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
        COLOR_GREEN "-----------------------------------------\n" COLOR_RESET,
        _file_got_errors, _file_got_errors > 1 ? "S" : "");
        return 2;
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
                sprintf(buf, "Value | : " COLOR_CYAN STYLE_BOLD "%s" COLOR_RESET", defined at line " COLOR_GREEN "%d" COLOR_RESET ", is redefined at line " COLOR_GREEN "%d", temp->h_key, temp->lineno, local_fun_variables[j]->lineno);
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

void variable_call_checked(Node * callRoot, SymbolTab global, SymbolTab parameters, SymbolTab local);
void function_call_checked(HashElem * fun, Node * argumentsRoot,  SymbolTab global, SymbolTab parameters, SymbolTab local);

_type evalExprType(Node * exprRoot, SymbolTab global, SymbolTab parameters, SymbolTab local) {
    if (exprRoot) {
        switch (exprRoot->label) {
            case ident: {
                HashElem * elem;
                if ((elem = findHashElem(local, exprRoot->value.ident))
                    || (elem = findHashElem(global, exprRoot->value.ident))
                    || (elem = findHashElem(BLT_FUNCTIONS, exprRoot->value.ident))) {
                        
                        if (elem->h_val.type == _type_function) {
                            if (! exprRoot->firstChild) {
                                /**
                                 * @brief ERROR FUN RVALUE
                                 */
                                db_error_fun_rValue(exprRoot);
                                return ERROR;
                            }
                            if (exprRoot->firstChild && exprRoot->firstChild->label == arguments) 
                                function_call_checked (elem, exprRoot->firstChild, global, parameters, local);
                            else function_call_checked (elem, exprRoot->nextSibling, global, parameters, local);

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
                        /**
                        * @brief ERROR VOID RVALUE
                        */
                        db_error_void_rValue(exprRoot);
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
        if ((elem = findHashElem(local, assignRoot->value.ident)) 
            || (elem = findHashElem(global, assignRoot->value.ident))
            || (elem = findHashElem(BLT_FUNCTIONS, assignRoot->value.ident))) {
                leftValue = elem->h_val.type;
                if (leftValue == _type_function) {
                    /**
                     * @brief ERROR FUN LVALUE
                     */
                    db_error_fun_lValue(assignRoot);
                }
        } else { return ;} /* already debuged in variable reference check */
        assignRoot = assignRoot->nextSibling;
        rightValue = evalExprType(assignRoot, global, parameters, local);
        switch ((int) rightValue) {
            case ERROR:;
            case IGNORE: return; 
            case _type_void: {
                        /**
                         * @brief ERROR VOID RVALUE
                         */
                        db_error_void_rValue(assignRoot);
                        return;
            };
            case _type_int: {
                if (leftValue == _type_char) {
                    /**
                     * @brief WARNING UNMATCH ASSIGNMENT
                     */
                    db_warning_assignment(assignRoot, leftValue, rightValue);
                }
            }
            default: {
                return ;
            }
        }
    }
}

void function_call_checked(HashElem * fun, Node * argumentsRoot,  SymbolTab global, SymbolTab parameters, SymbolTab local) {
    if (argumentsRoot) {
        Node * arg_iter = argumentsRoot->firstChild;
        int i;
        int save_line = argumentsRoot->lineno;
        _type_fc fct = fun->h_val.val.func;
        _type_fc_param * param_iter = fct.param;
        for (i = 0; i < fct.param_ct; i++) {
            _type leftValue, rightValue;
            leftValue = param_iter->type;
            if (!arg_iter) {
                char buf[512];
                sprintf(buf, "Not enough arguments were given " COLOR_CYAN STYLE_BOLD " ( expected amount : %d )" COLOR_RESET "\n" \
                    " -- referenced at line %d ", fct.param_ct, save_line);  
                debug_error(DB_ERR_INCORRECT_USAGE, buf);
                break;
            }
            save_line = arg_iter->lineno;

            rightValue = evalExprType(arg_iter, global, parameters, local);

            switch ((int) rightValue) {
                case IGNORE: ;
                case ERROR: break;
                case _type_void: {
                        /**
                        * @brief ERROR VOID RVALUE
                        */
                        db_error_void_rValue(arg_iter);
                        break;
                    }
                case _type_int : {
                    if (leftValue == _type_char) {
                        /**
                         * @brief WARNING TYPE ASSIGNMENT
                         */
                        db_warning_assignment(arg_iter, leftValue, rightValue);
                    }
                }
                default :;
                
            }

            param_iter = param_iter->next;
            arg_iter = arg_iter->nextSibling;
        }
        if (arg_iter) {
            char buf[512];
            sprintf(buf, "Too much arguments were given " COLOR_CYAN STYLE_BOLD " ( expected amount : %d )" COLOR_RESET "\n" \
                " -- referenced at line %d ", fct.param_ct, arg_iter->lineno);  
            debug_error(DB_ERR_INCORRECT_USAGE, buf);
        }
    }
}


void variable_call_checked(Node * callRoot, SymbolTab global, SymbolTab parameters, SymbolTab local) {
    if (callRoot) {
        Node * call_iter = callRoot->firstChild;
        HashElem * elem;
        if ((elem = findHashElem(local, call_iter->value.ident))
            || (elem = findHashElem(global, call_iter->value.ident))
            || (elem = findHashElem(BLT_FUNCTIONS, call_iter->value.ident))
        ) {
            if (elem->h_val.type != _type_function) {
                db_error_var_not_callable(call_iter);
                return ;
            }
            if (call_iter->firstChild && call_iter->firstChild->label == arguments) 
                function_call_checked (elem, call_iter->firstChild, global, parameters, local);
            else function_call_checked (elem, call_iter->nextSibling, global, parameters, local);
        }
    }
}
void function_return_checked(Node * bodyRoot, _type returnFun) {
    Node * root = findLabelInTree(bodyRoot->firstChild, return_);
    if (!root && returnFun != _type_void)
        db_warn_fun_missing_return(bodyRoot, returnFun);
} 

void function_body_checked (Node * root, SymbolTab global, SymbolTab parameters, SymbolTab local, SymbolTab * varMemory, _type returnType) {
    if (root == NULL) return;
    else {
        Node * iter_ident = root;
        if (root->label == ident) {
            HashElem * elem;
                if (!(
                    (elem = findHashElem(local, iter_ident->value.ident))
                    || (elem = findHashElem(global, iter_ident->value.ident))
                    || (elem = findHashElem(BLT_FUNCTIONS, iter_ident->value.ident)))) 
                {
                    int foundFlag = findHashElem(*varMemory, iter_ident->value.ident) ? 1 : 0;
                    puts("\n");
                    if (!foundFlag)
                        putHashVal(varMemory, newHashElem(iter_ident->value.ident, newValueVoid(), iter_ident->lineno));
                    
                    /**
                     * @brief ERROR UNDECLARED VARIABLE
                     */
                    db_error_var_undeclared(iter_ident, foundFlag ? 1 : 0);
                    
                }
                else {
                    if (iter_ident->firstChild != NULL) {
                        if (elem->h_val.type != _type_function) {
                            /**
                             * @brief ERROR VAR IS NOT CALLABLE
                             */
                            db_error_var_not_callable(iter_ident);
                        }
                        else {;}
                    }
                }            
        } else {
            if (root->label == assign)
                variables_assignment_checked(root, global, parameters, local);
            else if (root->label == call)
                variable_call_checked(root, global, parameters, local);
            else if (root->label == return_) {
                _type retVal = evalExprType(root->firstChild, global, parameters, local);
                switch((int) retVal) {
                    case ERROR:
                    case IGNORE: break;
                    case _type_void: {
                        if (returnType != _type_void) {
                            db_error_void_return(root);
                        }
                        break;
                    }
                    default : {
                        if (returnType == _type_void) {
                            /**
                             * @brief WARN RETURN IN A VOID RETURNING FUNCTION
                             */
                            db_warn_void_fun_return(root, retVal);
                        } else {
                            if (retVal == _type_int && returnType == _type_char) {
                                db_warn_fun_return(root, retVal, returnType);
                            }
                        }
                    }
                }
                if (root->nextSibling) {
                    db_warn_post_return_instructions(root->nextSibling);
                }
            }
        }
        function_body_checked(root->firstChild, global, parameters, local, varMemory, returnType);
        function_body_checked(root->nextSibling, global, parameters, local, varMemory, returnType);
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
        _type ret = _type_void;
        Node * temp = findLabelInTree(function_iter->firstChild->firstChild, type);
        if (temp) ret = charToType(temp->value.comp);
        Node * body_iter = findLabelInTree(function_iter->firstChild, body);
        if (body_iter) {
            Node * declare_var_iter = body_iter->firstChild;
            declare_var_iter = findLabelInTree (declare_var_iter, declare_var);
            function_body_checked(declare_var_iter->nextSibling, pst.globals, fst_list[cpt]->parameters, fst_list[cpt]->values, &varMemory, ret);
            function_return_checked(body_iter, ret);
            freeSymbolTab(&varMemory);
            varMemory = newSymbolTab();
            cpt++;
        }
        function_iter = findLabelInTree(function_iter->nextSibling, declare_function);
    }
}