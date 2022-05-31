#ifndef __DEBUG_MESSAGES_H__
#define __DEBUG_MESSAGES_H__

#include "includes.h"
#include "tree.h"

void db_error_var_not_callable(Node * root);
void db_error_var_undeclared(Node * root, int foundFlag);
void db_error_fun_lValue(Node * root);
void db_error_void_rValue(Node * root);
void db_error_fun_rValue(Node * root);
void db_error_void_return(Node * root);
void db_error_overwrite_builtin(Node * root);
void db_error_switch_case_non_constant(Node * case_root);
void db_error_switch_multiple_default(Node * default_root);
void db_error_switch_case_repeats(Node * case_root, int label, int previous_lineno);

void db_warning_assignment(Node * root, _type leftValue, _type rightValue);
void db_warn_void_fun_return(Node * root, _type returnVal);
void db_warn_fun_return(Node * root, _type returnVal, _type returnFun);
void db_warn_fun_missing_return(Node * root, _type returnFun);
void db_warn_post_return_instructions(Node * root);

#endif