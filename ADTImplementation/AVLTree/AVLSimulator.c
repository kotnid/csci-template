#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "AVLTree(intNode).h"

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

void help() {
    printf("[INFO] Command list:\n");
    printf("[h]elp: Display command list\n");
    printf("[q]uit: Exit the simulator\n");
    printf("[i]nsert <value:int>: Insert a TreeNode(value)\n");
    printf("[p]rint: Print the whole tree\n");
    printf("[d]elete <value:int>: Delete the TreeNode(value)\n");
    printf("[c]lear: Clear the tree, i.e. set the root to null\n");
}

int main() {
    printf("[INFO] AVLTree Simulator\n");
    printf("Author: K1tsune233\n");
    printf("Version: 1.0.0\n");
    printf("\n");
    char command[100];
    memset(command, 0, 100);
    AVLTreeADT tree = EmptyAVLTree();
    while (true) {
        scanf("%s", command);
        // printf("[DEBUG] %s\n", command);
        if (strcmp(command, "quit") == 0 || strcmp(command, "q") == 0) {
            printf("[INFO] Exit.\n");
            exit(EXIT_SUCCESS);
        } else if (strcmp(command, "help") == 0 || strcmp(command, "h") == 0) {
            help();
        } else if (strcmp(command, "insert") == 0 || strcmp(command, "i") == 0) {
            int val;
            scanf("%d", &val);
            tree = AVLInsertNode(NewTreeNode(val), tree);
            printf("[INFO] TreeNode(%d) inserted.\n", val);
        } else if (strcmp(command, "print") == 0 || strcmp(command, "p") == 0) {
            printf("[INFO] Printing AVLTree:\n");
            if(tree == NULL) printf("NULL\n");
            else print_subtree(tree, "  ", "  ", buffer, sizeof buffer);
        } else if (strcmp(command, "delete") == 0 || strcmp(command, "delete") == 0) {
            printf("[WARNING] Delete function has not be implemented.\n");
            printf("Pull requests are welcomed!");
        } else if(strcmp(command, "clear") == 0 || strcmp(command, "c") == 0) {
            tree = EmptyAVLTree();
        } else {
            printf("[WARNING] Unknown command.\n");
            printf("Use help command to display command list.\n");
        }
        printf("\n");
    }
}