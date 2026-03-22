#include "Simulator.h"
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Commands.h"
#include "Util.h"

/*
print_tree reference:
https://stackoverflow.com/questions/64660540/how-can-i-print-a-binary-tree
*/

// char buffer[1024] = {0};

// static void print_node(AVLTreeADT t) {
//     printf("%s+-%d\n", buffer, t->rt->value);
// }

// static void print_subtree(AVLTreeADT t,
//                           const char* prf_right, /* right prefix */
//                           const char* prf_left,  /* left prefix */
//                           char* buf, int buf_sz) /* buffer management, to add prefixes to */
// {
//     if (t->rst) { /* right subtree */
//         /* add the prefix for the right subtree, this is prf_right for
//          * the right part (the first, before the root node) */
//         int res = snprintf(buf, buf_sz, "%s", prf_right);
//         print_subtree(t->rst, "  ", "| ", buf + res, buf_sz - res);
//         *buf = '\0';
//     }
//     print_node(t);
//     if (t->lst) { /* left subtree */
//         /* add the prefix for the left subtree, this is prf_left
//          * for the left part (the second, after the root node) */
//         int res = snprintf(buf, buf_sz, "%s", prf_left);
//         print_subtree(t->lst, "| ", "  ", buf + res, buf_sz - res);
//         *buf = '\0';
//     }
// }

int main() {
    printf("AVLTree Simulator\n");
    printf("Author: K1tsune233\n");
    printf("Version: 2.0.0\n");
    printf("\n");

    TreePtr trees[MAX_TREE_NUMBER];
    memset(trees, 0, MAX_TREE_NUMBER * sizeof(TreePtr));
    char line[100];
    while (true) {
        fgets(line, 100, stdin);
        char* command = strtok(line, " \n");
        // printf("[DEBUG] command = |%s|\n", command);

        assert(COMMAND_NUMBER == 10);
        switch (hashCommand(command)) {
            case QUIT:
                printf("[INFO] Exit.\n");
                exit(EXIT_SUCCESS);
                break;
            case HELP:
                runHelp();
                break;
            case INSERT:
                runInsert(trees);
                break;
            case INSERT_MANY:
                runInsertMany(trees);
                break;
            case PRINT:
                // printf("[INFO] Printing AVLTree:\n");
                // if (tree == NULL)
                //     printf("(NULL)\n");
                // else
                //     print_subtree(tree, "  ", "  ", buffer, sizeof buffer);
                break;
            case DELETE:
                printf("[WARNING] Delete function has not be implemented.\n");
                printf("Pull requests are welcomed!");
                break;
            case CLEAR:
                // tree = EmptyAVLTree();
                // printf("[INFO] Tree cleared.\n");
                break;
            case TRAVERSAL:
                runTraversal(trees);
                break;
            case NEW:
                runNew(trees);
                break;
            case DUMP_TREES:
                runDumpTrees(trees);
                break;
            default:
                printf("[WARNING] Unknown command.\n");
                printf("Use [h]elp command to display command list.\n");
                break;
        }
        printf("\n");
    }
}