#include <stdio.h>
#include "AVLTree.h"

void printCurrentNodeADT(AVLTreeADT t) {
    // printf("DEBUG: n = %p\n", n);
    if (t == NULL) {
        printf("NULL\n");
        return;
    }
    printf("(%s, %d)\n", GetNodeKey(AVLRoot(t)), GetNodeData(AVLRoot(t)));
}

void printTreeADT(AVLTreeADT t) {
    printf("Printing tree:\n");
    printf("Root: ");
    printCurrentNodeADT(t);
    AVLTreeADT lChild = LeftAVLSubtree(t);
    AVLTreeADT rChild = RightAVLSubtree(t);
    printf("Root->Left: ");
    printCurrentNodeADT(lChild);
    printf("Root->Right: ");
    printCurrentNodeADT(rChild);
    printf("Root->Left->Left: ");
    printCurrentNodeADT(LeftAVLSubtree(lChild));
    printf("Root->Left->Right: ");
    printCurrentNodeADT(RightAVLSubtree(lChild));
    printf("Root->Right->Left: ");
    printCurrentNodeADT(LeftAVLSubtree(rChild));
    printf("Root->Right->Right: ");
    printCurrentNodeADT(RightAVLSubtree(rChild));
    printf("\n");
}

int main() {
    AVLTreeADT t = EmptyAVLTree();
    TreeNodeADT initNodes[] = {NewTreeNode("2", 1), NewTreeNode("3", 2), NewTreeNode("4", 3), NewTreeNode("5", 4), NewTreeNode("6", 5)};
    for(int i=0; i<5; i++) {
        t = AVLInsertNode(initNodes[i], t);
    }
 
    printTreeADT(t);
    t = AVLInsertNode(NewTreeNode("8", 6), t);
    printTreeADT(t);

    t = AVLInsertNode(NewTreeNode("7", 7), t);
    printTreeADT(t);
    
    t = AVLInsertNode(NewTreeNode("9", 8), t);
    printTreeADT(t);
}