#include "SplayTree.h"
#include <stdlib.h>

// void splay(SplayTreeADT x) {
//     while (x->parent != NULL) {
//         // Zig
//         if (x->parent->parent == NULL) {
//             if (x->parent->l == x)
//                 rightRotation(x->parent);
//             else
//                 leftRotation(x->parent);
//         } else if (x->parent->parent->l == x->parent && x->parent->l == x) {
//             //  X 位於左子節點的左子節點 ZIG - ZIG
//             rightRotation(x->parent->parent);
//             rightRotation(x->parent);
//         } else if (x->parent->parent->r == x->parent && x->parent->r == x) {
//             //  X 位於右子節點的右子節點 ZIG- ZIG
//             leftRotation(x->parent);
//             leftRotation(x->parent);
//         } else if (x->parent->parent->l == x->parent && x->parent->r == x) {
//             //  X 位於左子節點的右子節點 ZIG - ZAG
//             leftRotation(x->parent);
//             rightRotation(x->parent);
//         } else {
//             //  X 位於右子節點的左子節點 ZIG - ZAG
//             rightRotation(x->parent);
//             leftRotation(x->parent);
//         }
//     }
// }

// void insertElement(Comparable data) {
//     // Some insertion code
//     // 執行新增的程式碼，故省略，完成後執行 splay新增的節點
//     splay(newNode);
// }

// TreeNode findElement(Comparable data) {
//     // Some search code
//     // 執行查詢的程式碼，故省略，完成後執行 splay查詢到的節點
//     splay(target);
// }