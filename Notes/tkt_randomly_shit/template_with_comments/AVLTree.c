#include "AVLTree.h"
#include <stdlib.h>
#include <string.h>

AVLTreeADT EmptyAVLTree(){
    return NULL;
}

AVLTreeADT NonemptyAVLTree(TreeNodeADT N, AVLTreeADT L, AVLTreeADT R){
    AVLTreeADT t = malloc(sizeof(*t));
    t->rt = N;
    t->lst = L;
    t->rst = R;
    return t;
}

TreeNodeADT AVLRoot(AVLTreeADT t) {
    if (AVLTreeIsEmpty(t)) exit(EXIT_FAILURE);
    return t->rt;
}

AVLTreeADT LeftAVLSubtree(AVLTreeADT t) {
    if (AVLTreeIsEmpty(t)) exit(EXIT_FAILURE);
    return t->lst;
}

AVLTreeADT RightAVLSubtree(AVLTreeADT t) {
    if (AVLTreeIsEmpty(t)) exit(EXIT_FAILURE);
    return t->rst;
}

int AVLTreeIsEmpty(AVLTreeADT t) {
    return t == NULL;
}

int AVLTreeHeight(AVLTreeADT t) {
    if(t == NULL) return -1;
    return AVLTreeHeight(t->lst) > AVLTreeHeight(t->rst)? AVLTreeHeight(t->lst)+1: AVLTreeHeight(t->rst)+1;
}

TreeNodeADT NewTreeNode(char* k, int d) {
    TreeNodeADT N = malloc(sizeof(*N));
    N->key = malloc(sizeof(char) * (strlen(k) + 1));
    strcpy(N->key, k);
    N->nodeData = d;
    return N;
}

int IsSpecialErrNode(TreeNodeADT N) {
    return N == NULL;
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

// Rotation 

/*
left-rotation
1. right child become new root 
2. left-subtree become (old leftsubtree + old root + left subtree of right child)
3. right-subtree unchange
*/
AVLTreeADT LeftRotate(AVLTreeADT t){
    return NonemptyAVLTree(
        AVLRoot(RightAVLSubtree(t)), 
        NonemptyAVLTree(
            AVLRoot(t),
            LeftAVLSubtree(t),
            LeftAVLSubtree(RightAVLSubtree(t))
        ),
        RightAVLSubtree(RightAVLSubtree(t))
    );
}

/*
right-rotation
1. left child become new root
2. left-subtree unchange
3. right-subtree become (right-subtree of left child + root + old right-subtree)
*/
AVLTreeADT RightRotate(AVLTreeADT t) {
    return NonemptyAVLTree(
        AVLRoot(LeftAVLSubtree(t)),
        LeftAVLSubtree(LeftAVLSubtree(t)),
        NonemptyAVLTree(
            AVLRoot(t),
            RightAVLSubtree(LeftAVLSubtree(t)),
            RightAVLSubtree(t)
        )
    );
}

AVLTreeADT RightLeftRotate(AVLTreeADT t) {
    return LeftRotate(
        NonemptyAVLTree(
            AVLRoot(t),
            LeftAVLSubtree(t),
            RightRotate(RightAVLSubtree(t))
        )
    );
}

AVLTreeADT LeftRightRotate(AVLTreeADT t) {
    return RightRotate(
        NonemptyAVLTree(
            AVLRoot(t),
            LeftRotate(LeftAVLSubtree(t)),
            RightAVLSubtree(t)
        )
    );
}

AVLTreeADT AVLInsertNode(TreeNodeADT X, AVLTreeADT T) {
    if (AVLTreeIsEmpty(T))return NonemptyAVLTree(X, EmptyAVLTree(), EmptyAVLTree());

    int sign = strcmp(GetNodeKey(X), GetNodeKey(AVLRoot(T)));
    if (sign < 0) { // put on left-subtree
        // form a new tree (updated left-subtree + root + right-subtree)
        AVLTreeADT NewTree = NonemptyAVLTree(AVLRoot(T),
                                             AVLInsertNode(X, LeftAVLSubtree(T)),
                                             RightAVLSubtree(T));   
        // unbalanced condition (left-subtree too long)
        if (AVLTreeHeight(LeftAVLSubtree(NewTree)) - AVLTreeHeight(RightAVLSubtree(NewTree)) == 2)
            return (strcmp(GetNodeKey(X),
                           GetNodeKey(AVLRoot(LeftAVLSubtree(NewTree)))) < 0 ?
                        RightRotate(NewTree) :
                        LeftRightRotate(NewTree)); 

        return NewTree;
    }
    if (sign > 0) { // put on right-subtree
        // form a new tree (left-subtree + root + updated right-subtree)
        AVLTreeADT NewTree = NonemptyAVLTree(AVLRoot(T),
                                             LeftAVLSubtree(T),
                                             AVLInsertNode(X, RightAVLSubtree(T)));
        // unbalanced condition (right-subtree too long)
        if (AVLTreeHeight(RightAVLSubtree(NewTree)) - AVLTreeHeight(LeftAVLSubtree(NewTree)) == 2)
            return (strcmp(GetNodeKey(X),
                           GetNodeKey(AVLRoot(RightAVLSubtree(NewTree)))) > 0 ?
                        LeftRotate(NewTree) :
                        RightLeftRotate(NewTree));

        return NewTree;
    }
    return NonemptyAVLTree(X, LeftAVLSubtree(T), RightAVLSubtree(T));
}