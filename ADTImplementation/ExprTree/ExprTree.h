#include <stdbool.h>
typedef struct ExprTreeCDT* ExprTreeADT;
typedef struct ExprTreeNodeCDT* ExprTreeNodeADT;
enum nodetype { operator, integer };
typedef enum nodetype NodeTypeT;
ExprTreeNodeADT NewOpNode(char);
ExprTreeNodeADT NewIntNode(int);
NodeTypeT NodeType(ExprTreeNodeADT);
char NodeOp(ExprTreeNodeADT);
int NodeValue(ExprTreeNodeADT);
ExprTreeNodeADT ExprTreeRoot(ExprTreeADT);
ExprTreeADT EmptyExprTree(void);
ExprTreeADT NonemptyExprTree(ExprTreeNodeADT, ExprTreeADT, ExprTreeADT);
bool ExprTreeIsEmpty(ExprTreeADT);
ExprTreeADT LeftExprSubtree(ExprTreeADT);
ExprTreeADT RightExprSubtree(ExprTreeADT);

int Eval(ExprTreeADT);