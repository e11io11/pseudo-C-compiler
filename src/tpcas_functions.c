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
        {0,0,0,'?'}
    };
    int option_index = 0;

    while (1) {
        c = getopt_long(argc, argv, "ths", long_options, &option_index);
        if (c == -1) {
            break;
        }
        switch (c) {
            case 't': /* Enable tree display*/
                *treeFlag = 1;
                break;
            case 'h': /* Enable help Display */
                printf("Usage: ./tpcas [options] < [target]\nOptions:\n-h --help Print this message and exit.\n-t --tree Print target's abstract tree\n");
                break;
            case 's': /* Enable symbol table display */
                *symbolFlag = 1;
                break;
            case '?': /* Other unrecognized values */
                return 2;
        }
    }
    return 0;
}


Node * findLabelInTree(Node * root, label_t search) {
    while (root != NULL) {
        if (root->label == search) return root;
        root = root->nextSibling;
    }
    return NULL;
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
        iterator = findLabelInTree(iterator, declare_var);
        if (iterator != NULL) {
            Node * _iter_type = iterator->firstChild;
            do {
                _iter_type = findLabelInTree(_iter_type, type);
                if (_iter_type != NULL) {
                    Node * _iter_ident = _iter_type->firstChild;
                    _type t = mainFct_charToType(_iter_type->value.comp);
                    do {
                        _iter_ident = findLabelInTree(_iter_ident, ident);
                        if (_iter_ident != NULL) {
                            putHashVal(&result, newHashElem(_iter_ident->value.ident, t));
                            _iter_ident = _iter_ident->nextSibling;
                        }
                    } while (_iter_ident != NULL);
                    _iter_type = _iter_type->nextSibling;
                }
            } while (_iter_type != NULL);
            iterator = iterator->nextSibling;
        }
        
    } while (iterator != NULL);

    return result;
}


HashTable getHash_from_function_parameters(Node * parametersRoot) {
    HashTable result = newHashTable();
    if (parametersRoot == NULL) exit(EXIT_FAILURE);
    parametersRoot = parametersRoot->firstChild;
    while (parametersRoot != NULL) {
        if (parametersRoot->label != void_)
            putHashVal(&result, newHashElem(parametersRoot->firstChild->value.ident, mainFct_charToType(parametersRoot->value.comp)));
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
                    _type t = mainFct_charToType(_iter_type->value.comp);
                    Node * _iter_ident = _iter_type->firstChild;
                    while (_iter_ident != NULL) {
                        putHashVal(&result, newHashElem(_iter_ident->value.ident, t));
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
    unsigned int cpt_functions = mainFct_count_functions(root);
    programSymbolTables result = newProgramSymbolTables(cpt_functions);
    
    if (root != NULL) {
        Node * _iter = root->firstChild;
        unsigned int cpt = 0;
        do {
            _iter = findLabelInTree(_iter, declare_function);
            if (_iter != NULL) {
                Node * _iter_functions = _iter->firstChild;
                while (_iter_functions != NULL) {
                    if (_iter_functions->label == header) {
                        Node * _iter_type = _iter_functions->firstChild;
                        do {
                            _iter_type = findLabelInTree(_iter_type, parameters);
                            if (_iter_type != NULL) {
                                result.functions[cpt].parameters = getHash_from_function_parameters(_iter_type);
                                _iter_type = _iter_type->nextSibling;
                            }
                        } while (_iter_type != NULL);
                    } else if (_iter_functions->label == body) {
                        result.functions[cpt].values = getHash_from_function_body(_iter_functions);
                    }
                    _iter_functions = _iter_functions->nextSibling;
                }
                cpt++;
                _iter = _iter->nextSibling;
            }
        } while (_iter != NULL);
    }
    return result;
}


void mainFct_Tree_to_Hash(Node * root, int display) {
    programSymbolTables result;
    result = mainFct_init_Hash_from_functions(root);
    result.globals = mainFct_init_Hash_from_globals(root);

    if (display)
        displayProgramSymbolTables(result);

    freeProgramSymbolTables(result);
}


_type mainFct_charToType(const char * input) {
    return strcmp(input, "int") ?  (strcmp(input, "char") ? _type_other : _type_char) : _type_int;
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