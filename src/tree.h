/* tree.h */

typedef enum {
  divstar,
  ident,
  while_,
  if_,
  else_,
  return_,
  type,
  void_,
  num,
  character,
  eq,
  order,
  or,
  and,
  addsub,
  epsilon,
  Prog,
  Arguments,
  SuiteInstr,
  LValue,
  DeclVars,
  Parametres,
  DeclFonct,
  EnTeteFonct,
  Corps,
  switch_,
  case_,
  default_,
  break_,
  SuiteSwitch
  /* list all other node labels, if any */
  /* The list must coincide with the string array in tree.c */
  /* To avoid listing them twice, see https://stackoverflow.com/a/10966395 */
} label_t;

typedef struct Node {
  label_t label;
  struct Node *firstChild, *nextSibling;
  int lineno;
} Node;

Node *makeNode(label_t label);
void addSibling(Node *node, Node *sibling);
void addChild(Node *parent, Node *child);
void deleteTree(Node*node);
void printTree(Node *node);

#define FIRSTCHILD(node) node->firstChild
#define SECONDCHILD(node) node->firstChild->nextSibling
#define THIRDCHILD(node) node->firstChild->nextSibling->nextSibling
