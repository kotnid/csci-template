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
    else if (strcmp(command, "traversal") == 0 || strcmp(command, "t") == 0)
        return TRAVERSAL;
    else if (strcmp(command, "new") == 0 || strcmp(command, "n") == 0)
        return NEW;
    else if (strcmp(command, "dump_trees") == 0 || strcmp(command, "dt") == 0)
        return DUMP_TREES;
    else if (strcmp(command, "search") == 0 || strcmp(command, "s") == 0)
        return SEARCH;
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
    assert(TREE_TYPE_NUMBER == 3);
    if (strcmp(treeType, "binary_search_tree") == 0 || strcmp(treeType, "bst") == 0)
        return BST;
    else if (strcmp(treeType, "avl_tree") == 0 || strcmp(treeType, "avl") == 0)
        return AVL;
    else if (strcmp(treeType, "splay_tree") == 0 || strcmp(treeType, "spl") == 0)
        return SPL;
    return UNKNOWN_TREE_TYPE;
}

char* reverseHashTreeType(TreeType treeType) {
    assert(TREE_TYPE_NUMBER == 3);
    switch (treeType) {
        case BST:
            return "binary search tree";
        case AVL:
            return "AVL tree";
        case SPL:
            return "splay tree";
        default:
            assert(false && "[ERROR] UNREACHABLE");
            break;
    }
    return "";
}

char* commandFormat(Command command) {
    assert(COMMAND_NUMBER == 10);
    switch (command) {
        case QUIT:
            return "[q]uit";
        case HELP:
            break;
        case INSERT:
            return "[i]nsert <index:int> <value:int>";
        case INSERT_MANY:
            return "[i]nsert_[m]any <index:int> <count:int> (<value:int> ...)";
        case PRINT:
            return "[p]rint <index:int>";
        case DELETE:
            return "[d]elete <index:int> <value:int>";
        case TRAVERSAL:
            return "[t]raversal <index:int> <type:[in]-order | [pre]-order | [post]-order>";
        case SEARCH:
            return "[search] <index:int> <value:int>";
        default:
            return "";
    }
    return "";
}

void printCommandFormat(Command command) {
    printf("Format: ");
    printf("%s", commandFormat(command));
    printf("\n");
}

void todo(char* fn) {
    printf("[WARNING] %s has not be implemented.\n", fn);
    printf("Pull requests are welcomed!");
}

/**
 * @name readAndParseSubcommandToInt
 * This function takes 1 subcommands from terminal, parse them to string and save them to a return array.
 * Count check and type check are done, but no further checking is done.
 * Print error message in terminal if failed.
 * @param {int*} ret The address of parsed interger
 * @param {Command} caller The instruction name of the caller
 * @return {bool} Success or not
 */

bool readAndParseSubcommandToInt(int* ret, Command caller) {
    char* subcommand = strtok(NULL, " \n");
    if (!subcommand) {
        printf("[ERROR] Insufficient argument.\n");
        printCommandFormat(caller);
        return false;
    }
    if (!sscanf(subcommand, "%d", ret)) {
        printf("[ERROR] Invalid argument.\n");
        printCommandFormat(caller);
        return false;
    }
    return true;
}