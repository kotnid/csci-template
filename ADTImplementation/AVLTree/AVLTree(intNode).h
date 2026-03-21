#include <stdio.h> 
typedef struct AVLTreeCDT *AVLTreeADT; 
typedef struct TreeNodeCDT *TreeNodeADT; 
AVLTreeADT NonemptyAVLTree(TreeNodeADT, AVLTreeADT, AVLTreeADT); 
AVLTreeADT EmptyAVLTree(void); 
AVLTreeADT LeftAVLSubtree(AVLTreeADT); 
AVLTreeADT RightAVLSubtree(AVLTreeADT); 
int AVLTreeIsEmpty(AVLTreeADT); 
int AVLTreeHeight(AVLTreeADT); 
TreeNodeADT AVLRoot(AVLTreeADT); 
TreeNodeADT NewTreeNode(int); 
int GetNodeValue(TreeNodeADT);
AVLTreeADT AVLInsertNode(TreeNodeADT X, AVLTreeADT T);

struct AVLTreeCDT {
    TreeNodeADT rt;
    AVLTreeADT lst, rst;
};
struct TreeNodeCDT {
    int value;
};