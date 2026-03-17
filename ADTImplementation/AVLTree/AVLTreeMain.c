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

void inOrder(AVLTreeADT t) {
    if (t == NULL) return;
    inOrder(t->lst);
    printCurrentNodeADT(t);
    inOrder(t->rst);
}

int main() {
    AVLTreeADT t = EmptyAVLTree();
    TreeNodeADT nodeAlice = NewTreeNode("Alice", 0);
    TreeNodeADT nodeBob = NewTreeNode("Bob", 1);
    TreeNodeADT nodeCharlie = NewTreeNode("Charlie", 2);
    TreeNodeADT nodeDave = NewTreeNode("Dave", 3);
    TreeNodeADT nodeEve = NewTreeNode("Eve", 4);
    TreeNodeADT nodeFred = NewTreeNode("Fred", 5);
    t = AVLInsertNode(nodeAlice, t);
    t = AVLInsertNode(nodeBob, t);
    t = AVLInsertNode(nodeCharlie, t);
    t = AVLInsertNode(nodeDave, t);
    t = AVLInsertNode(nodeEve, t);
    t = AVLInsertNode(nodeFred, t);

    printf("In-order Tree Tranversal\n");
    inOrder(t);
    printf("\n");
    /*
     * Expected Output:
     * (Alice, 0)
     * (Bob, 1)
     * (Charlie, 2)
     * (Dave, 3)
     * (Eve, 4)
     * (Fred, 5)
     */

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
    /*
     * Expected Output:
     * Root: (Dave, 3)
     * Root->Left: (Bob, 1)
     * Root->Right: (Eve, 4)
     * Root->Left->Left: (Alice, 0)
     * Root->Left->Right: (Charlie, 2)
     * Root->Right->Left: NULL
     * Root->Right->Right: (Fred, 5)
     */
}