#include <stdbool.h> 
typedef struct BinaryTreeCDT *BinaryTreeADT; 
typedef struct TreeNodeCDT *TreeNodeADT; 
BinaryTreeADT NonemptyBinaryTree(TreeNodeADT, 
BinaryTreeADT, BinaryTreeADT); 
BinaryTreeADT EmptyBinaryTree(void); 
BinaryTreeADT LeftSubtree(BinaryTreeADT); 
BinaryTreeADT RightSubtree(BinaryTreeADT); 
bool TreeIsEmpty(BinaryTreeADT); 
TreeNodeADT Root(BinaryTreeADT); 
TreeNodeADT NewTreeNode(char*, int); 
int GetNodeData(TreeNodeADT); 
TreeNodeADT SpecialErrNode(void); 
bool IsSpecialErrNode(TreeNodeADT); 
char *GetNodeKey(TreeNodeADT); 