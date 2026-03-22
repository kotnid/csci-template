# Tree Simulator
Aim to visualize tree-kind data structures.

## How to Run?
1. Run `./sim.sh`.

## History
### v2.1.0
New tree supported:
- Binary Search Tree

### v2.0.1
Command updated:
- PRINT

Deprecated command:
- CLEAR: Equivalent to call NEW on existing tree.

### v2.0.0
The simulator is reconstructed.

Feature added:
- The simulator can now maintain multiple trees
- The simulator can now handle different kinds of trees

Command added:
- NEW
- DUMP_TREE

Command updated:
- QUIT
- INSERT
- INSERT_MANY
- TRAVERSAL

### v1.2.1
Command updated:
- HELP

### v1.2.0
Command added:
- INSERT_MANY

### v1.1.0
Command added:
- TRAVERSAL

### v1.0.0
New tree supported:
- AVL Tree

Command added:
- QUIT
- HELP
- INSERT
- PRINT
- DELETE
- CLEAR

## Reference
1. [How can I print a binary tree?](https://stackoverflow.com/questions/64660540/how-can-i-print-a-binary-tree) 

The function `print_node` and `print_subtree` in `Commands.c` come from the answer by user Luis Colorado.