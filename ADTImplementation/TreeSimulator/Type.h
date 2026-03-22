#ifndef TYPE_H_
#define TYPE_H_
typedef enum {
    QUIT = 0,
    HELP,
    INSERT,
    PRINT,
    DELETE,
    CLEAR,
    TRAVERSAL,
    INSERT_MANY,
    NEW,
    DUMP_TREES,
    COMMAND_NUMBER,
    UNKNOWN_COMMAND = 999
} Command;

typedef enum {
    IN_ORDER = 0,
    PRE_ORDER,
    POST_ORDER,
    SUBCOMMAND_NUMBER,
    UNKNOWN_SUBCOMMAND = 999
} Subcommand;

typedef enum {
    BST = 0,
    AVL,
    TREE_TYPE_NUMBER,
    UNKNOWN_TREE_TYPE = 999
}TreeType;

typedef struct {
    TreeType type;
    void* root;
} Tree;

typedef Tree* TreePtr;

#define MAX_TREE_NUMBER 10
#endif // TYPE_H_