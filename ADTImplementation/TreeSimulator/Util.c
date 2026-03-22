#include "Util.h"
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

Command hashCommand(char* command) {
    assert(COMMAND_NUMBER == 10);
    if (strcmp(command, "quit") == 0 || strcmp(command, "q") == 0)
        return QUIT;
    else if (strcmp(command, "help") == 0 || strcmp(command, "h") == 0)
        return HELP;
    else if (strcmp(command, "insert") == 0 || strcmp(command, "i") == 0)
        return INSERT;
    else if (strcmp(command, "insert_many") == 0 || strcmp(command, "im") == 0)
        return INSERT_MANY;
    else if (strcmp(command, "print") == 0 || strcmp(command, "p") == 0)
        return PRINT;
    else if (strcmp(command, "delete") == 0 || strcmp(command, "d") == 0)
        return DELETE;
    else if (strcmp(command, "clear") == 0 || strcmp(command, "c") == 0)
        return CLEAR;
    else if (strcmp(command, "traversal") == 0 || strcmp(command, "t") == 0)
        return TRAVERSAL;
    else if (strcmp(command, "new") == 0 || strcmp(command, "n") == 0)
        return NEW;
    else if (strcmp(command, "dump_trees") == 0 || strcmp(command, "dt") == 0)
        return DUMP_TREES;
    return UNKNOWN_COMMAND;
}

Subcommand hashSubcommand(char* subcommand) {
    assert(SUBCOMMAND_NUMBER == 3);
    if (strcmp(subcommand, "in-order") == 0 || strcmp(subcommand, "in") == 0)
        return IN_ORDER;
    else if (strcmp(subcommand, "pre-order") == 0 || strcmp(subcommand, "pre") == 0)
        return PRE_ORDER;
    else if (strcmp(subcommand, "post-order") == 0 || strcmp(subcommand, "post") == 0)
        return POST_ORDER;
    return UNKNOWN_SUBCOMMAND;
}

TreeType hashTreeType(char* treeType) {
    assert(TREE_TYPE_NUMBER == 2);
    if (strcmp(treeType, "binary_search_tree") == 0 || strcmp(treeType, "bst") == 0)
        return BST;
    else if (strcmp(treeType, "avl_tree") == 0 || strcmp(treeType, "avl") == 0)
        return AVL;
    return UNKNOWN_TREE_TYPE;
}

char* reverseHashTreeType(TreeType treeType) {
    assert(TREE_TYPE_NUMBER == 2);
    switch (treeType) {
        case BST:
            return "binary search tree";
            break;
        case AVL:
            return "AVL tree";
        default:
            assert(false && "[ERROR] UNREACHABLE");
            break;
    }
    return "";
}

char* commandFormat(Command command) {
    assert(COMMAND_NUMBER == 9);
    switch (command) {
        case QUIT:
            return "[q]uit";
            break;
        case HELP:
            break;
        case INSERT:
            return "[i]nsert <index:int> <value:int>";
            break;
        case INSERT_MANY:
            return "[i]nsert_[m]any <index:int> <count:int> (<value:int> ...)";
            break;
        case PRINT:
            break;
            case TRAVERSAL:
            return "[t]raversal <index:int> <type:[in]-order | [pre]-order | [post]-order>";
            break;
        default:
            return "";
            break;
    }
    return "";
}

void printCommandFormat(Command command) {
    printf("Format: ");
    printf("%s", commandFormat(command));
    printf("\n");
}