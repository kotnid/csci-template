#include <stdio.h>
#include "BinaryTree.h"

void printCurrentNodeADT(BinaryTreeADT t) {
    if (t == NULL) {
        printf("NULL\n");
        return;
    }
    printf("(%s, %d)\n", GetNodeKey(Root(t)), GetNodeData(Root(t)));
}

void inOrder(BinaryTreeADT t) {
    if (t == NULL) return;
    inOrder(t->lst);
    printCurrentNodeADT(t);
    inOrder(t->rst);
}

int main() {
    BinaryTreeADT t = EmptyBinaryTree();
    TreeNodeADT nodeAlice = NewTreeNode("Alice", 0);
    TreeNodeADT nodeBob = NewTreeNode("Bob", 1);
    TreeNodeADT nodeCharlie = NewTreeNode("Charlie", 2);
    TreeNodeADT nodeDave = NewTreeNode("Dave", 3);
    TreeNodeADT nodeEve = NewTreeNode("Eve", 4);
    TreeNodeADT nodeFred = NewTreeNode("Fred", 5);
    t = InsertNode(t, nodeAlice);
    t = InsertNode(t, nodeBob);
    t = InsertNode(t, nodeCharlie);
    t = InsertNode(t, nodeDave);
    t = InsertNode(t, nodeEve);
    t = InsertNode(t, nodeFred);

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
    BinaryTreeADT lChild = LeftSubtree(t);
    BinaryTreeADT rChild = RightSubtree(t);
    BinaryTreeADT llChild = lChild!=NULL? LeftSubtree(lChild): NULL;
    BinaryTreeADT lrChild = lChild!=NULL? RightSubtree(lChild): NULL;
    BinaryTreeADT rlChild = rChild!=NULL? LeftSubtree(rChild): NULL;
    BinaryTreeADT rrChild = rChild!=NULL? RightSubtree(rChild): NULL;
    printf("Root->Left: ");
    printCurrentNodeADT(lChild);
    printf("Root->Right: ");
    printCurrentNodeADT(rChild);
    printf("Root->Left->Left: ");
    printCurrentNodeADT(llChild);
    printf("Root->Left->Right: ");
    printCurrentNodeADT(lrChild);
    printf("Root->Right->Left: ");
    printCurrentNodeADT(rlChild);
    printf("Root->Right->Right: ");
    printCurrentNodeADT(rrChild);
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