#include "BinaryTree.h"
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

TreeNodeADT NewTreeNode(char* k, int d) {
    TreeNodeADT N = malloc(sizeof(*N));
    N->key = malloc(sizeof(char) * (strlen(k) + 1));
    strcpy(N->key, k);
    N->nodeData = d;
    return N;
}

char* GetNodeKey(TreeNodeADT N) {
    if (IsSpecialErrNode(N)) exit(EXIT_FAILURE);
    char* k = malloc(sizeof(char) * (strlen(N->key) + 1));
    strcpy(k, N->key);
    return k;
}

int GetNodeData(TreeNodeADT N) {
    return N->nodeData;
}

TreeNodeADT SpecialErrNode() {
    return NULL;
}

bool IsSpecialErrNode(TreeNodeADT N) {
    return N == NULL;
}

BinaryTreeADT InsertNode(BinaryTreeADT t, TreeNodeADT n) {
    if (TreeIsEmpty(t))
        return NonemptyBinaryTree(n,
                                  EmptyBinaryTree(), EmptyBinaryTree());
    else {
        int sign = strcmp(GetNodeKey(n), GetNodeKey(Root(t)));
        if (sign == 0) return NonemptyBinaryTree(n,
                                                 LeftSubtree(t), RightSubtree(t));
        if (sign < 0) return NonemptyBinaryTree(Root(t),
                                                InsertNode(LeftSubtree(t), n), RightSubtree(t));
        return NonemptyBinaryTree(Root(t),
                                  LeftSubtree(t), InsertNode(RightSubtree(t), n));
    }
}