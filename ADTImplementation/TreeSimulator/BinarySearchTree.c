#include "BinarySearchTree.h"
#include <stdlib.h>
#include <string.h>

BinaryTreeADT EmptyBinaryTree() {
    return NULL;
}

BinaryTreeADT NonemptyBinaryTree(TreeNodeADT N,
                                 BinaryTreeADT L, BinaryTreeADT R) {
    BinaryTreeADT t = malloc(sizeof(*t));
    t->rt = N;
    t->lst = L;
    t->rst = R;
    return t;
}

TreeNodeADT Root(BinaryTreeADT t) {
    if (TreeIsEmpty(t)) exit(EXIT_FAILURE);
    return t->rt;
}

BinaryTreeADT LeftSubtree(BinaryTreeADT t) {
    if (TreeIsEmpty(t)) exit(EXIT_FAILURE);
    return t->lst;
}

BinaryTreeADT RightSubtree(BinaryTreeADT t) {
    if (TreeIsEmpty(t)) exit(EXIT_FAILURE);
    return t->rst;
}

bool TreeIsEmpty(BinaryTreeADT t) {
    return t == NULL;
}

BinaryTreeADT InsertNode(BinaryTreeADT t, TreeNodeADT n) {
    if (TreeIsEmpty(t))
        return NonemptyBinaryTree(n,
                                  EmptyBinaryTree(), EmptyBinaryTree());
    else {
        int sign = GetNodeValue(n) - GetNodeValue(Root(t));
        if (sign == 0) return NonemptyBinaryTree(n,
                                                 LeftSubtree(t), RightSubtree(t));
        if (sign < 0) return NonemptyBinaryTree(Root(t),
                                                InsertNode(LeftSubtree(t), n), RightSubtree(t));
        return NonemptyBinaryTree(Root(t),
                                  LeftSubtree(t), InsertNode(RightSubtree(t), n));
    }
}