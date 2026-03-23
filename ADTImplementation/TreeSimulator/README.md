# Tree Simulator
Aim to visualize tree-kind data structures.

## How to Run?
1. Run `./sim.sh`.

## History
### v3.1.0
New Utility Command:
- `readAndParseSubcommandToInt`

Deprecated Utility Commands:
- parseSubcommandTo2Int: Equivalent to call `readAndParseSubcommandToInt` twice.

### v3.0.0
New feature:
- `Util.h` and `Util.c` are added for utility functions benefits developers

New tree supported:
- Splay tree

New Commands:
- Search

## v2.1.1
New Commands:
- DELETE

### v2.1.0
New tree supported:
- Binary Search Tree

### v2.0.1
Modified Commands:
- PRINT

Deprecated Commands:
- CLEAR: Equivalent to call NEW on existing tree.

### v2.0.0
The simulator is reconstructed.

New Features:
- The simulator can now maintain multiple trees
- The simulator can now handle different kinds of trees

New Commands:
- NEW
- DUMP_TREE

Modified Commands:
- QUIT
- INSERT
- INSERT_MANY
- TRAVERSAL

### v1.2.1
Modified Command:
- HELP

### v1.2.0
New Command:
- INSERT_MANY

### v1.1.0
New Command:
- TRAVERSAL

### v1.0.0
New tree supported:
- AVL Tree

New Commands:
- QUIT
- HELP
- INSERT
- PRINT
- DELETE
- CLEAR

## Reference
1. [How can I print a binary tree?](https://stackoverflow.com/questions/64660540/how-can-i-print-a-binary-tree) 

The function `print_node` and `print_subtree` in `Commands.c` come from the answer by user Luis Colorado.