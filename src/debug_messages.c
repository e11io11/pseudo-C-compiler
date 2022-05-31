#include "../inc/debug_messages.h"

char buf[512];


void db_error_var_not_callable(Node * root) {
    sprintf(buf, "variable : " COLOR_CYAN STYLE_BOLD "'%s'" COLOR_RESET" is not callable (as a function)" COLOR_RESET "\n"
        " -- referenced at line %d ", root->value.ident, root->lineno);
    debug_error(DB_ERR_INCORRECT_USAGE, buf);
}


void db_error_var_undeclared(Node * root, int foundFlag) {
    sprintf(buf, "variable : " COLOR_CYAN STYLE_BOLD "'%s'" COLOR_RESET" undeclared %s" COLOR_RESET "\n"
                    " -- referenced at line %d ", root->value.ident, foundFlag ? COLOR_CYAN "(already used before)" : COLOR_GREEN "(first use in this function)", root->lineno);
    debug_error(DB_ERR_INCORRECT_REFERENCE, buf);
}

void db_error_fun_lValue(Node * root) {
    sprintf(buf, "Can not use the type " COLOR_CYAN STYLE_BOLD "function" COLOR_RESET" as a LValue.\nOccured at line " COLOR_GREEN "%d" COLOR_RESET, 
    root->lineno);
    debug_error(DB_ERR_INCORRECT_ASSIGNMENT, buf);
}


void db_error_void_rValue(Node * root) {
    sprintf(buf, "Can not assign the type " COLOR_CYAN STYLE_BOLD "void" COLOR_RESET" to a LValue.\nOccured at line " COLOR_GREEN "%d" COLOR_RESET, 
    root->lineno);
    debug_error(DB_ERR_INCORRECT_ASSIGNMENT, buf);
}

void db_error_void_return(Node * root) {
    sprintf(buf, "Can not return the type " COLOR_CYAN STYLE_BOLD "void" COLOR_RESET" from a non-void returning function.\nOccured at line " COLOR_GREEN "%d" COLOR_RESET, 
    root->lineno);
    debug_error(DB_ERR_RETURN_VOID, buf);
}


void db_error_switch_case_non_constant(Node * case_root) {
    sprintf(buf, "Case label shall be an " COLOR_CYAN STYLE_BOLD "integer constant " COLOR_RESET ".\nOccured at line " COLOR_GREEN "%d" COLOR_RESET,
    case_root->lineno);
    debug_error(DB_ERR_SWITCH_CASE_NON_CONSTANT, buf);
}

void db_error_switch_case_repeats(Node * case_root, int label, int previous_lineno) {
    sprintf(buf, "Multiple cases can not contains the same label : " COLOR_CYAN STYLE_BOLD "%d" COLOR_RESET " or " COLOR_CYAN STYLE_BOLD "'%c'" COLOR_RESET " was previously found at line " COLOR_GREEN "%d" COLOR_RESET ".\nOccured at line " COLOR_GREEN "%d" COLOR_RESET,
    label, label ? (char) label : 1, previous_lineno, case_root->lineno);
    debug_error(DB_ERR_SWITCH_CASE_NON_CONSTANT, buf);
}

void db_error_switch_multiple_default(Node * default_root) {
    sprintf(buf, "Switch bloc shall contains an unique" COLOR_CYAN STYLE_BOLD " default label " COLOR_RESET ".\n"\
    "Occured at line " COLOR_GREEN "%d" COLOR_RESET,
    default_root->lineno);
    debug_error(DB_ERR_SWITCH_MULTIPLE_DEFAULT, buf);
}


void db_warning_assignment(Node * root, _type leftValue, _type rightValue) {
    sprintf(buf, "Assignment of an " COLOR_CYAN STYLE_BOLD "%s" COLOR_RESET" into a " COLOR_CYAN STYLE_BOLD "%s" COLOR_RESET" may result in  " COLOR_RED STYLE_BOLD "data Overflow" COLOR_RESET ".\nOccured at line " COLOR_GREEN "%d" COLOR_RESET,
        typeToChar(rightValue), typeToChar(leftValue), root->lineno);
    debug_warning(DB_WRN_ASSIGNMENT_OVERFLOW, buf);
}

void db_error_fun_rValue(Node * root) {
    sprintf(buf, "Can not assign the type " COLOR_CYAN STYLE_BOLD "function" COLOR_RESET" to a LValue.\nOccured at line " COLOR_GREEN "%d" COLOR_RESET,
        root->lineno);
    debug_error(DB_ERR_INCORRECT_ASSIGNMENT, buf);
}

void db_error_overwrite_builtin(Node * root) {
    sprintf(buf, "The name " COLOR_CYAN STYLE_BOLD "%s" COLOR_RESET " can not be used as it is already the name of a " COLOR_GREEN "builtin function" COLOR_RESET ":\n" \
    COLOR_YELLOW "[HINT] You can display the builtin functions by using the tag --b\n" COLOR_RESET \
    "Occured at line " COLOR_GREEN "%d" COLOR_RESET,
        root->value.ident, root->lineno);
    debug_error(DB_ERR_BUILTIN_OVERWRITE, buf);
}

void db_warn_void_fun_return(Node * root, _type returnVal) {
    sprintf(buf, STYLE_BOLD "'return'" COLOR_RESET " with an " COLOR_CYAN STYLE_BOLD "%s" COLOR_RESET" value, in function returning " COLOR_CYAN STYLE_BOLD "void" COLOR_RESET ".\nOccured at line " COLOR_GREEN "%d" COLOR_RESET,
        typeToChar(returnVal), root->lineno);
    debug_warning(DB_WRN_INCOHERENT_RETURN, buf);
}

void db_warn_fun_return(Node * root, _type returnVal, _type returnFun) {
    sprintf(buf, "returning " COLOR_CYAN STYLE_BOLD "%s" COLOR_RESET" from a function with return type " COLOR_CYAN STYLE_BOLD "%s" COLOR_RESET ".\nOccured at line " COLOR_GREEN "%d" COLOR_RESET,
        typeToChar(returnVal), typeToChar(returnFun) , root->lineno);
    debug_warning(DB_WRN_INCOHERENT_RETURN, buf);
}

void db_warn_fun_missing_return(Node * root, _type returnFun) {
    sprintf(buf, "control reaches end of " COLOR_CYAN STYLE_BOLD "non-void function" COLOR_RESET" (from a function with return type " COLOR_CYAN STYLE_BOLD "%s" COLOR_RESET ").\nOccured at line " COLOR_GREEN "%d" COLOR_RESET,
        typeToChar(returnFun) , root->lineno);
    debug_warning(DB_WRN_MISSING_RETURN, buf);
}

void db_warn_post_return_instructions(Node * root) {
    sprintf(buf, "Unreachable instructions following a " COLOR_CYAN STYLE_BOLD "return" COLOR_RESET ".\nOccured at line " COLOR_GREEN "%d" COLOR_RESET,
        root->lineno);
    debug_warning(DB_WRN_POST_RETURN_CODE, buf);
}
