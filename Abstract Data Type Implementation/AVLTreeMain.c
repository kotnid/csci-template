#include <stdio.h>
#include "AVLTree.h"

void printTreeADT(TreeNodeADT n) {
    printf("DEBUG: n = %p\n", n);
    if(n == NULL) printf("NULL\n");
    printf("(%s, %d)\n", GetNodeKey(n), GetNodeData(n));
}

void inOrder(AVLTreeADT t) {
    if(t == NULL) return;
    inOrder(t->lst);
    printTreeADT(t->rt);
    inOrder(t->rst);
}


int main() {
    AVLTreeADT t = EmptyAVLTree();
    TreeNodeADT nodeAlice = NewTreeNode("Alice", 0);
    TreeNodeADT nodeBob = NewTreeNode("Bob", 1);
    TreeNodeADT nodeCharlie = NewTreeNode("Charlie", 2);
    TreeNodeADT nodeDave = NewTreeNode("Dave", 3);
    TreeNodeADT nodeEve = NewTreeNode("Eve", 4);
    t = AVLInsertNode(nodeAlice, t);
    t = AVLInsertNode(nodeBob, t);
    t = AVLInsertNode(nodeCharlie, t);
    t = AVLInsertNode(nodeDave, t);
    t = AVLInsertNode(nodeEve, t);

    printf("In-order Tree Tranversal\n");
    inOrder(t);
    printf("\n");
    /*
     * Expected Output:
     * Alice: 0
     * Bob: 1
     * Charlie: 2
     * Dave: 3
     */

    printf("Root: ");
    printTreeADT(AVLRoot(t));
    AVLTreeADT lChild = LeftAVLSubtree(t);
    printf("Root->Left: ");
    printTreeADT(AVLRoot(lChild));
    printf("Root->Right: ");
    printTreeADT(AVLRoot((RightAVLSubtree(t))));
    printf("Root->Left->Left: ");
    printTreeADT(AVLRoot(LeftAVLSubtree(lChild)));
    printf("Root->Left->Right: ");
    printTreeADT(AVLRoot(RightAVLSubtree(lChild)));
    printf("\n");
}