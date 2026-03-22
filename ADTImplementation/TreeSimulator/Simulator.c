#include "Simulator.h"
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Commands.h"
#include "Util.h"

int main() {
    printf("AVLTree Simulator\n");
    printf("Author: K1tsune233\n");
    printf("Version: 2.1.1\n");
    printf("\n");

    TreePtr trees[MAX_TREE_NUMBER];
    memset(trees, 0, MAX_TREE_NUMBER * sizeof(TreePtr));
    char line[100];
    while (true) {
        fgets(line, 100, stdin);
        char* command = strtok(line, " \n");
        // printf("[DEBUG] command = |%s|\n", command);

        assert(COMMAND_NUMBER == 9);
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
                runPrintTree(trees);
                break;
            case DELETE:
                runDelete(trees);
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