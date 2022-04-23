/**
 * @author Antonin JEAN
 * @email ofghanirre@gmail.com
 * @create date 2022-02-09 11:42:30
 * @modify date 2022-02-09 11:42:30
 * @desc Src file containing Main functions to operate 
 * 
 * Theses functions are triggered by the main located on the tpcas.y
 * file
 * 
 */

#include "../inc/tpcas_functions.h"

int mainFct_load_arg(int argc, char * argv[], int * treeFlag, int * symbolFlag) {
    int c;
    static struct option long_options[] = {
        {"tree", no_argument, 0, 't'},
        {"symbol", no_argument, 0, 's'},
        {"help", no_argument, 0, 'h'},
        {"symbolTab", no_argument, 0, 's'},
        {0,0,0,'?'}
    };
    int option_index = 0;
    while (1) {
        c = getopt_long(argc, argv, "ths", long_options, &option_index);
        if (c == -1) {
            return 0;
        }
        switch (c) {
            case 't': /* Enable tree display*/
                *treeFlag = 1;
                break;
            case 'h': /* Enable help Display */
                printf("Usage: ./tpcas [options] < [target]\nOptions:\n-h --help Print this message and exit.\n-t --tree Print target's abstract tree\n-s --symbol Print target's symbol table\n");
                return 2;
            case 's': /* Enable symbol table display */
                *symbolFlag = 1;
                break;
            case '?': /* Other unrecognized values */
                return 2;
        }
    }
    return 0;
}




void raiseTreeError() {
    fprintf(stderr, "/!\\ ERROR:"
                    "while flowing the Tree -> At least one value was expected but lacked");
    exit(EXIT_FAILURE);
}


HashTable mainFct_init_Hash_from_globals(Node * root) {
    Node * iterator;
    HashTable result = newSymbolTab();
    iterator = root->firstChild; /* iterator = declare var */

    do {
        if (iterator != NULL) {
            if (iterator->label == declare_var) {
                Node * _iter_type = iterator->firstChild;
                do {
                    _iter_type = findLabelInTree(_iter_type, type);
                    if (_iter_type != NULL) {
                        Node * _iter_ident = _iter_type->firstChild;
                        _type t = charToType(_iter_type->value.comp);
                        do {
                            _iter_ident = findLabelInTree(_iter_ident, ident);
                            if (_iter_ident != NULL) {
                                putHashVal_checked(&result, newHashElem(_iter_ident->value.ident, newValuePrim(t), _iter_ident->lineno));
                                _iter_ident = _iter_ident->nextSibling;
                            }
                        } while (_iter_ident != NULL);
                        _iter_type = _iter_type->nextSibling;
                    }
                } while (_iter_type != NULL);
            } else if (iterator->label == declare_function) {
                Node * _iter_functions = iterator->firstChild;
                while (_iter_functions != NULL) {
                    if (_iter_functions->label == header) {
                        Node * _iter_header = findLabelInTree(_iter_functions->firstChild, ident);
                        if (_iter_header != NULL) {
                            putHashVal_checked(&result, newHashElem(_iter_header->value.ident, newValueFct(_iter_functions), _iter_header->lineno));
                        }
                    }
                    _iter_functions = _iter_functions->nextSibling;
                }
            }
        }
        iterator = iterator->nextSibling;
    } while (iterator != NULL);
    return result;
}


HashTable getHash_from_function_parameters(Node * parametersRoot) {
    HashTable result = newHashTable();
    if (parametersRoot == NULL) exit(EXIT_FAILURE);
    parametersRoot = parametersRoot->firstChild;
    while (parametersRoot != NULL) {
        if (parametersRoot->label != void_)
            putHashVal_checked(&result, newHashElem(parametersRoot->firstChild->value.ident, newValuePrim(charToType(parametersRoot->value.comp)), parametersRoot->lineno));
        parametersRoot = parametersRoot->nextSibling;
    }

    return result;
}


HashTable getHash_from_function_body(Node * bodyRoot) {
    HashTable result = newHashTable();
    bodyRoot = bodyRoot->firstChild;
    do {
        bodyRoot = findLabelInTree(bodyRoot, declare_var);
        if (bodyRoot != NULL) {
            Node * _iter_type = bodyRoot->firstChild;
            do {
                _iter_type = findLabelInTree(_iter_type, type);
                if (_iter_type != NULL) {
                    _type t = charToType(_iter_type->value.comp);
                    Node * _iter_ident = _iter_type->firstChild;
                    while (_iter_ident != NULL) {
                        putHashVal_checked(&result, newHashElem(_iter_ident->value.ident, newValuePrim(t), _iter_ident->lineno));
                        _iter_ident = _iter_ident->nextSibling;
                    }
                    _iter_type = _iter_type->nextSibling;
                }
                
            } while (_iter_type != NULL);
            bodyRoot = bodyRoot->nextSibling;
        }
    } while (bodyRoot != NULL);

    return result;
}


unsigned int mainFct_count_functions(Node * root) {
    unsigned int cpt = 0;
    if (root == NULL) return 0;
    root = root->firstChild;

    while (root != NULL) {
        if (root->label == declare_function) cpt++;
        root = root->nextSibling;
    } 
    return cpt;
}


programSymbolTables mainFct_init_Hash_from_functions(Node * root) { 
    programSymbolTables result = newProgramSymbolTables();

    if (root != NULL) {
        Node * _iter = root->firstChild;
        unsigned int cpt = 0;
        function_main_checked(findLabelInTree(_iter, declare_function));
        do {
            _iter = findLabelInTree(_iter, declare_function);
            if (_iter != NULL) {
                Node * _iter_functions = _iter->firstChild;
                functionSymbolTables * temp;
                putFunctionSymbolTable(&result, temp = newFunctionSymbolTable());
                temp->root = _iter;
                while (_iter_functions != NULL) {
                    if (_iter_functions->label == header) {
                        Node * _iter_type = _iter_functions->firstChild;
                        do {
                            _iter_type = findLabelInTree(_iter_type, parameters);
                            if (_iter_type != NULL) {
                                temp->parameters = getHash_from_function_parameters(_iter_type);
                                _iter_type = _iter_type->nextSibling;
                            }
                        } while (_iter_type != NULL);
                    } else if (_iter_functions->label == body) {
                        temp->values = getHash_from_function_body(_iter_functions);
                    }
                    _iter_functions = _iter_functions->nextSibling;
                }
                cpt++;
                _iter = _iter->nextSibling;
                function_parameters_checked(*temp);
            }
        } while (_iter != NULL);
    }
    

    return result;
}


programSymbolTables mainFct_Tree_to_Hash(Node * root) {
    programSymbolTables result;
    result = mainFct_init_Hash_from_functions(root);
    result.globals = mainFct_init_Hash_from_globals(root);
    variables_reference_checked (root, result );
    return result;
}


void mainFct_testHashTable() {
    HashTable st = newHashTable();
    int i;

    for (i = 0; i < 10000; i++) {
        char temp [6];
        sprintf(temp, "%d", i);
        putHashVal(&st, newHashElem(temp, newValueInt(), 0));
    }

    displayHashTable(st);
    testHashTableRepartition(&st, 10000);
    freeHashTable(&st);

}
/*
program
├── declare var
│   ├── type: int
│   │   ├── ident: vga
│   │   └── ident: vgb
│   └── type: int
│       └── ident: vgc
├── declare function
│   ├── header
│   │   ├── void
│   │   ├── ident: fun1
│   │   └── parameters
│   │       ├── type: char
│   │       │   └── ident: c
│   │       ├── type: int
│   │       │   └── ident: b
│   │       └── type: int
│   │           └── ident: a
│   └── body
│       └── declare var
└── declare function
    ├── header
    │   ├── void
    │   ├── ident: function
    │   └── parameters
    │       └── void
    └── body
        ├── declare var
        │   └── type: char
        │       └── ident: var1
        ├── assign
        │   ├── ident: var1
        │   └── num: 10
        ├── if
        │   ├── and
        │   │   ├── eq: !=
        │   │   │   ├── ident: var1
        │   │   │   └── num: 10
        │   │   └── order: >
        │   │       ├── ident: var1
        │   │       └── num: 2
        │   └── assign
        │       ├── ident: var1
        │       └── addsub: +
        │           ├── ident: var1
        │           └── num: 1
        └── return
            └── num: 42

*/