# syntax-analyzer

Module:
    Debug : Erreurs / warnings
    Hash : Hash Element
    SymbolTab : HashTable / symbolTab
    ProgramData : Program's variable's hashtables
    tpcas_function : main functions for the program
    translator : asm translation
    tree: tree
    type: type
    utils : utils functions / macros

Les erreurs / warnings actuellement testées :
    Lexicale
    Syntaxique
    Semantique:
        déclaration variables
        assignations de type (left value / right value)
        reférences des variables
        evaluation des expressions (en cours : fonction en parametre de fonction)
        référence / appel de fonctions
        appel de variables n'étant pas des fonctions


Note aux correcteurs pour le rendu intermédiaire:
    il est possible que certaines fonctionnalités basiques de l'analyse sémantique soit imparfaite 
    (ex : détéctée plusieurs fois), à cause des fonctionnalités plus complexes, qui ont été réalisées en
    amont du premier rendu.


    Elements pouvant poser des problemes:
        Analyses d'expression "complexe" :
            ex : function( (expr : 4 * 5 + 'c'), function1(b, 2)) + 5;
