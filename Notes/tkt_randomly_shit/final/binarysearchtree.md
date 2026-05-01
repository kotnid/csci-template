# Binary Search Tree 

### Terminologies 

##### height 
- height count from 0 and started from null
- root has height 1

##### siblings 
- same parent 

##### interior nodes/leaves
- have child and no child 

##### Binary Tree
- node has 0-2 children 
- node except root can call left/right child of its parent 

--- 

### Properties 
- binary tree but satisfy two more conditions
    - key values are unique 
    - key value must be greater than all left-subtree nodes, and less then all right-subtree nodes 
- we can find the minimum element by keep traversal left child until not left child
    - then that node will be the min node

--- 

### Implementations explanation 

```c
BinaryTreeADT InsertNode(BinaryTreeADT t, TreeNodeADT n) {
    // empty tree => build a new tree and n is root 
    if (TreeIsEmpty(t))return NonemptyBinaryTree(n, EmptyBinaryTree(), EmptyBinaryTree());

    // compare the key
    int sign = strcmp(GetNodeKey(n), GetNodeKey(Root(t))); 

    // key value is same (suppose won't happen) => replace root
    if (sign == 0) return NonemptyBinaryTree(n, LeftSubtree(t), RightSubtree(t));

    // key value is smaller => go to left subtree 
    if (sign < 0) return NonemptyBinaryTree(Root(t), InsertNode(LeftSubtree(t), n), RightSubtree(t));

    // key value is larger => go to right subtree
    return NonemptyBinaryTree(Root(t), LeftSubtree(t), InsertNode(RightSubtree(t), n));
}
```

```c
BinaryTreeADT DeleteNode(BinaryTreeADT t, char* k) {
    if (TreeIsEmpty(t)) exit(EXIT_FAILURE);
    int sign = strcmp(k, GetNodeKey(Root(t)));

    // deleted node is not the root => go to corresponding subtree  
    if (sign < 0) return NonemptyBinaryTree(Root(t), DeleteNode(LeftSubtree(t), k), RightSubtree(t));
    if (sign > 0) return NonemptyBinaryTree(Root(t), LeftSubtree(t), DeleteNode(RightSubtree(t), k));

    // deleted node is root => check if subtree exists
    if (!TreeIsEmpty(LeftSubtree(t)) && !TreeIsEmpty(RightSubtree(t))) {
        // find minimum node => make it to new root (so won't affect the tree structure) => now become delete minimum node 
        TreeNodeADT M = FindMinNode(RightSubtree(t));
        return NonemptyBinaryTree(M, LeftSubtree(t), DeleteNode(RightSubtree(t), GetNodeKey(M)));
    };

    // one subtree is empty => return another subtree 
    return TreeIsEmpty(RightSubtree(t)) ? LeftSubtree(t) : RightSubtree(t);
}
```

---

### Exam questions 
- not many, usually test avl tree
- or draw binary tree after some operations

1. Write an algorithm in pseudo code that returns the number of non-leaf nodes in a binary tree. (18 Q6)
```
Algorithm CountNonLeaf(root)
    if root is NULL
        return 0
    if root.left is NULL and root.right is NULL
        return 0

    return 1 + CountNonLeaf(root.left) + CountNonLeaf(root.right)
```



---

### Implementaions 
[link](../../../ADTImplementation/BinarySearchTree/)
