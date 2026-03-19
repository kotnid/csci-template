#include "ExprTree.h"
#include <stdlib.h>

struct ExprTreeCDT {
    ExprTreeNodeADT N;
    ExprTreeADT L, R;
};
struct ExprTreeNodeCDT {
    NodeTypeT T;
    union {
        char op;
        int value;
    } content;
};

ExprTreeNodeADT NewOpNode(char op) {
    ExprTreeNodeADT N = malloc(sizeof(*N));
    N->T = operator;
    N->content.op = op;
    return N;
}

ExprTreeNodeADT NewIntNode(int v) {
    ExprTreeNodeADT N = malloc(sizeof(*N));
    N->T = integer;
    N->content.value = v;
    return N;
}

NodeTypeT NodeType(ExprTreeNodeADT N) {
    return N->T;
}
char NodeOp(ExprTreeNodeADT N) {
    return N->content.op;
}
int NodeValue(ExprTreeNodeADT N) {
    return N->content.value;
}

ExprTreeADT EmptyExprTree() {
    return NULL;
}
ExprTreeADT NonemptyExprSubtree(ExprTreeNodeADT N,
                                ExprTreeADT L, ExprTreeADT R) {
    ExprTreeADT t = malloc(sizeof(*t));
    t->N = N;
    t->L = L;
    t->R = R;
    return t;
}
bool ExprTreeIsEmpty(ExprTreeADT t) {
    return t == NULL;
}

ExprTreeNodeADT ExprTreeRoot(ExprTreeADT t) {
    return t->N;
}
ExprTreeADT LeftExprSubtree(ExprTreeADT t) {
    return t->L;
}
ExprTreeADT RightExprSubtree(ExprTreeADT t) {
    return t->R;
}

int Eval(ExprTreeADT t) {
    ExprTreeNodeADT N = ExprTreeRoot(t);
    switch (NodeType(N)) {
        case integer:
            return NodeValue(N);
        case operator: {
            int lhs = Eval(LeftExprSubtree(t));
            int rhs = Eval(RightExprSubtree(t));
            switch (NodeOp(N)) {
                case '+':
                    return lhs + rhs;
                case '-':
                    return lhs - rhs;
                case '*':
                    return lhs * rhs;
                case '/':
                    return lhs / rhs;
            }
        }
    }
    exit(EXIT_FAILURE);
}