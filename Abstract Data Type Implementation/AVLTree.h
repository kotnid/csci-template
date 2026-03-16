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
TreeNodeADT NewTreeNode(char*, int); 
char* GetNodeKey(TreeNodeADT); 
int GetNodeData(TreeNodeADT); 