#include "../inc/type.h"
char __type_repr[5][16] = {"UNKNOWN", "int", "char", "function", "void"};

char * typeToChar(_type t) {
    if (t <= 0 || t >= 5) {
        return __type_repr[0];
    }
    return __type_repr[t];
}

_type charToType(const char * input) {
    return strcmp(input, "int") ? (strcmp(input, "char") ? _type_other : _type_char) : _type_int;
}

value getValue(_type t) {
    value result = {result.type = t};
    switch (t) {
        case _type_int: result.val.size = __SIZE_INT; break;
        case _type_char: result.val.size = __SIZE_CHAR; break;
        default:;
    }
    return result;
}

_type_fc_param * newFcParam(_type t) {
    _type_fc_param * result = (_type_fc_param *) malloc(sizeof(_type_fc_param));
    if (result == NULL) raiseError("Malloc error at newFcParam");
    result->type = t;
    return result;
}

value newValueFct(Node * headerRoot) {
    value result = getValue(_type_function);
    Node * root = headerRoot->firstChild;
    root = findLabelInTree(root, type);
    if (root)
        result.val.func.ret = charToType(root->value.comp);
    else result.val.func.ret = _type_void;

    root = findLabelInTree(headerRoot->firstChild, parameters);
    if (root) {
        root = findLabelInTree(root->firstChild, type);
        while (root) {
            _type_fc_param * temp;
            result.val.func.param_ct++;
            temp = result.val.func.param;
            result.val.func.param = newFcParam(charToType(root->value.comp));
            result.val.func.param->next = temp;
            root = findLabelInTree(root->nextSibling, type);
        }
    }

    return result;
}

value newValueInt() {
    return getValue(_type_int);
}

value newValueChar() {
    return getValue(_type_char);
}

value newValueVoid() {
    return getValue(_type_void);
}

value newValuePrim(_type t) {
    switch (t) {
        case _type_int : return newValueInt();
        case _type_char : return newValueChar();
        case _type_void : return newValueVoid();
        default: raiseError("newValuePrim can only take prim types");
    }
    return newValueVoid(); /* debug compiler, useless*/
}
void freeValueIter(_type_fc_param * iter) {
    if (iter) {
        freeValueIter(iter->next);
        cfree(iter);
    }
}

void freeValue(value v) {
    if (v.type == _type_function) freeValueIter(v.val.func.param);
}

void displayValue(value v) {
    printf("%s", typeToChar(v.type));
    if (v.type == _type_function) {
        _type_fc_param * iter = v.val.func.param;
        printf("<%d> [", v.val.func.param_ct);
        while (iter) {
            printf("%s%c", typeToChar(iter->type), iter->next ? ',': ']');
            iter = iter->next;
        }
        printf(" --> {%s}", typeToChar(v.val.func.ret));
    }
}