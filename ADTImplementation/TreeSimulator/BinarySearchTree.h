#ifndef BINARY_SEARCH_TREE_H_
#define BINARY_SEARCH_TREE_H_
#include "TreeNode.h"
#include <stdbool.h>
typedef struct BinaryTreeCDT* BinaryTreeADT;

BinaryTreeADT NonemptyBinaryTree(TreeNodeADT,
                                 BinaryTreeADT, BinaryTreeADT);
BinaryTreeADT EmptyBinaryTree(void);
BinaryTreeADT LeftSubtree(BinaryTreeADT);
BinaryTreeADT RightSubtree(BinaryTreeADT);
bool TreeIsEmpty(BinaryTreeADT);
TreeNodeADT Root(BinaryTreeADT);
BinaryTreeADT InsertNode(BinaryTreeADT t, TreeNodeADT n);

struct BinaryTreeCDT {
    TreeNodeADT rt;
    BinaryTreeADT lst, rst;
};
#endif