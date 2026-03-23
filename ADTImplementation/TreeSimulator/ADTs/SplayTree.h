#ifndef SPLAY_TREE_H_
#define SPLAY_TREE_H_
#include <stdbool.h>
typedef struct SplayTreeCDT* SplayTreeADT;

void splay(SplayTreeADT);

struct SplayTreeCDT {
    int val;
    SplayTreeADT parent, l, r;
};
#endif