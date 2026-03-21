#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "AVLTree/AVLTree(intNode).h"

/*
print_tree reference:
https://stackoverflow.com/questions/64660540/how-can-i-print-a-binary-tree
*/

char buffer[1024] = {0};

static void print_node(AVLTreeADT t) {
    printf("%s+-%d\n", buffer, t->rt->value);
}

static void print_subtree(AVLTreeADT t,
                          const char* prf_right, /* right prefix */
                          const char* prf_left,  /* left prefix */
                          char* buf, int buf_sz) /* buffer management, to add prefixes to */
{
    if (t->rst) { /* right subtree */
        /* add the prefix for the right subtree, this is prf_right for
         * the right part (the first, before the root node) */
        int res = snprintf(buf, buf_sz, "%s", prf_right);
        print_subtree(t->rst, "  ", "| ", buf + res, buf_sz - res);
        *buf = '\0';
    }
    print_node(t);
    if (t->lst) { /* left subtree */
        /* add the prefix for the left subtree, this is prf_left
         * for the left part (the second, after the root node) */
        int res = snprintf(buf, buf_sz, "%s", prf_left);
        print_subtree(t->lst, "| ", "  ", buf + res, buf_sz - res);
        *buf = '\0';
    }
}

typedef enum {
    QUIT = 0,
    HELP,
    INSERT,
    PRINT,
    DELETE,
    CLEAR,
    TRAVERSAL,
    COMMAND_NUMBER,
    UNKNOWN_COMMAND = 999
} Command;

typedef enum {
    IN_ORDER = 0,
    PRE_ORDER,
    POST_ORDER,
    SUBCOMMAND_NUMBER,
    UNKNOWN_SUBCOMMAND = 999
} subcommand;

Command hashCommand(char* command) {
    assert(COMMAND_NUMBER == 7);
    if (strcmp(command, "quit") == 0 || strcmp(command, "q") == 0)
        return QUIT;
    else if (strcmp(command, "help") == 0 || strcmp(command, "h") == 0)
        return HELP;
    else if (strcmp(command, "insert") == 0 || strcmp(command, "i") == 0)
        return INSERT;
    else if (strcmp(command, "print") == 0 || strcmp(command, "p") == 0)
        return PRINT;
    else if (strcmp(command, "delete") == 0 || strcmp(command, "d") == 0)
        return DELETE;
    else if (strcmp(command, "clear") == 0 || strcmp(command, "c") == 0)
        return CLEAR;
    else if (strcmp(command, "traversal") == 0 || strcmp(command, "t") == 0)
        return TRAVERSAL;
    return UNKNOWN_COMMAND;
}

subcommand hashSubcommand(char* subcommand) {
    assert(SUBCOMMAND_NUMBER == 3);
    if (strcmp(subcommand, "in-order") == 0 || strcmp(subcommand, "in") == 0)
        return IN_ORDER;
    else if (strcmp(subcommand, "pre-order") == 0 || strcmp(subcommand, "pre") == 0)
        return PRE_ORDER;
    else if (strcmp(subcommand, "post-order") == 0 || strcmp(subcommand, "post") == 0)
        return POST_ORDER;
    return UNKNOWN_SUBCOMMAND;
}

void help() {
    assert(COMMAND_NUMBER == 7);
    printf("[INFO] Command list:\n");
    printf("[h]elp: Display command list\n");
    printf("[q]uit: Exit the simulator\n");
    printf("[i]nsert <value:int>: Insert a TreeNode(value)\n");
    printf("[p]rint: Print the whole tree\n");
    printf("[d]elete <value:int>: Delete the TreeNode(value)\n");
    printf("[c]lear: Clear the tree, i.e. set the root to null\n");
    printf("[t]raversal <type:[in]-order | [pre]-order | [post]-order>: Tree traversal\n");
}

void inOrderTraversal(AVLTreeADT t) {
    if (t == NULL) return;
    inOrderTraversal(t->lst);
    printf("%d ", GetNodeValue(t->rt));
    inOrderTraversal(t->rst);
}

void preOrderTraversal(AVLTreeADT t) {
    if (t == NULL) return;
    printf("%d ", GetNodeValue(t->rt));
    preOrderTraversal(t->lst);
    preOrderTraversal(t->rst);
}

void postOrderTraversal(AVLTreeADT t) {
    if (t == NULL) return;
    postOrderTraversal(t->lst);
    postOrderTraversal(t->rst);
    printf("%d ", GetNodeValue(t->rt));
}

int main() {
    printf("[INFO] AVLTree Simulator\n");
    printf("Author: K1tsune233\n");
    printf("Version: 1.1.0\n");
    printf("\n");
    char line[100];
    AVLTreeADT tree = EmptyAVLTree();

    while (true) {
        fgets(line, 100, stdin);
        char* command = strtok(line, " \n");
        // printf("[DEBUG] command = |%s|\n", command);

        assert(COMMAND_NUMBER == 7);
        switch (hashCommand(command)) {
            case QUIT:
                printf("[INFO] Exit.\n");
                exit(EXIT_SUCCESS);
                break;
            case HELP:
                help();
                break;
            case INSERT: {
                int val = 0;
                char* subcommand = strtok(NULL, " \n");
                if (!subcommand) {
                    printf("[ERROR] Insufficient argument.\n");
                    printf("Format: [i]nsert <value:int>\n");
                } else {
                    sscanf(subcommand, "%d", &val);
                    tree = AVLInsertNode(NewTreeNode(val), tree);
                    printf("[INFO] TreeNode(%d) inserted.\n", val);
                }
            } break;
            case PRINT:
                printf("[INFO] Printing AVLTree:\n");
                if (tree == NULL)
                    printf("(NULL)\n");
                else
                    print_subtree(tree, "  ", "  ", buffer, sizeof buffer);
                break;
            case DELETE:
                printf("[WARNING] Delete function has not be implemented.\n");
                printf("Pull requests are welcomed!");
                break;
            case CLEAR:
                tree = EmptyAVLTree();
                printf("[INFO] Tree cleared.\n");
                break;
            case TRAVERSAL: {
                char* subcommand = strtok(NULL, " \n");
                // printf("[DEBUG] subcommand = %s\n", subcommand);
                if (subcommand == NULL) {
                    printf("[ERROR] Insufficient argument.\n");
                    printf("Format: [t]raversal <type:[in]-order | [pre]-order | [post]-order>\n");
                } else {
                    printf("[INFO] Tree traversal in ");
                    switch (hashSubcommand(subcommand)) {
                        case IN_ORDER:
                            printf("in-order.\n");
                            inOrderTraversal(tree);
                            break;
                        case PRE_ORDER:
                            printf("pre-order.\n");
                            preOrderTraversal(tree);
                            break;
                        case POST_ORDER:
                            printf("post-order.\n");
                            postOrderTraversal(tree);
                            break;
                        default:
                            printf("[ERROR] Incorrect argument.\n");
                            printf("Format: [t]raversal <type:[in]-order | [pre]-order | [post]-order>\n");
                            break;
                    }
                    printf("\n");
                }
            } break;
            default:
                printf("[WARNING] Unknown command.\n");
                printf("Use [h]elp command to display command list.\n");
                break;
        }
        printf("\n");
    }
}