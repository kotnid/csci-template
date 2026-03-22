#include "Commands.h"
#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "AVLTree.h"
#include "Util.h"

void runHelp() {
    assert(COMMAND_NUMBER == 10);
    char* subcommand = strtok(NULL, " \n");
    if (!subcommand) {
        printf("[INFO] Command list:\n");
        printf("[h]elp (<command:str>): This command\n");
        printf("%s", strcat(commandFormat(QUIT), ": Exit the simulator\n"));
        printf("%s", strcat(commandFormat(INSERT), ": Insert a TreeNode with value\n"));
        printf("[i]nsert_[m]any <count:int> (<value:int> ...): Insert a number of different TreeNodes with values\n");
        printf("[p]rint: Print the whole tree\n");
        printf("[d]elete <value:int>: Delete the TreeNode(value)\n");
        printf("[c]lear: Clear the tree, i.e. set the root to null\n");
        printf("[t]raversal <type:[in]-order | [pre]-order | [post]-order>: Tree traversal\n");
        printf("[n]ew <index:int> <type:[b]inary_[s]earch_[t]ree | [avl]_tree>: Create a new tree.\n");
        printf("[d]ump_[t]rees: Dump trees.");

        return;
    }
    switch (hashCommand(subcommand)) {
        case QUIT:
            printf("[Info] Manul for quit:\n");
            printf("\n");
            printf("FORMAT\n");
            printf("[q]uit\n");
            printf("\n");
            printf("DESCRIPTION\n");
            printf("Exit the simulator\n");
            break;
        case HELP:
            printf("[Info] Manul for help:\n");
            printf("\n");
            printf("FORMAT\n");
            printf("[h]elp (command:str)\n");
            printf("\n");
            printf("DESCRIPTION\n");
            printf("If help command is used without argument, the full command list will be displayed.\n");
            printf("If help command is used with argument <command>, the manul of that command will be displayed.\n");
            printf("\n");
            printf("MANUL CONVENTION\n");
            printf("The format of a command is like this: [c]ommand_name <argument:type> (<optional argument:type> ...)\n");
            printf("1.  The branket[] in command_name denotes the short form of the command.\n");
            printf("    Either full command or short form is accepted in the simulator\n");
            printf("2.  The symbol <argument:type> denotes the argument and the \"type\" denotes the argument type.\n");
            printf("    The type is usually \"int\" or \"str\".\n");
            printf("3.  The argument falls inside branket() is optional.\n");
            printf("4.  ... denotes variable amount of arguments.\n");
            break;
        case INSERT:
            printf("[WARNING] The guide of this command has not been written.\n");
            break;
        case INSERT_MANY:
            printf("[WARNING] The guide of this command has not been written.\n");
            break;
        case PRINT:
            printf("[WARNING] The guide of this command has not been written.\n");
            break;
        case DELETE:
            printf("[WARNING] The guide of this command has not been written.\n");
            break;
        case CLEAR:
            printf("[WARNING] The guide of this command has not been written.\n");
            break;
        case TRAVERSAL:
            printf("[WARNING] The guide of this command has not been written.\n");
            break;
        case NEW:
            printf("[WARNING] The guide of this command has not been written.\n");
            break;
        default:
            printf("[ERROR] Unknow command.\n");
            break;
    }
}

static void AVLInOrderTraversal(AVLTreeADT t) {
    if (t == NULL) return;
    AVLInOrderTraversal(t->lst);
    printf("%d ", GetNodeValue(t->rt));
    AVLInOrderTraversal(t->rst);
}

static void AVLPreOrderTraversal(AVLTreeADT t) {
    if (t == NULL) return;
    printf("%d ", GetNodeValue(t->rt));
    AVLPreOrderTraversal(t->lst);
    AVLPreOrderTraversal(t->rst);
}

static void AVLPostOrderTraversal(AVLTreeADT t) {
    if (t == NULL) return;
    AVLPostOrderTraversal(t->lst);
    AVLPostOrderTraversal(t->rst);
    printf("%d ", GetNodeValue(t->rt));
}

void runTraversal(TreePtr trees[]) {
    char* subcommand1 = strtok(NULL, " \n");
    char* subcommand2 = strtok(NULL, " \n");
    if (!subcommand1 || !subcommand2) {
        printf("[ERROR] Insufficient argument.\n");
        printCommandFormat(TRAVERSAL);
        return;
    }
    int index;
    if (!sscanf(subcommand1, "%d", &index)) {
        printf("[ERROR] Invalid argument.\n");
        printCommandFormat(TRAVERSAL);
        return;
    }

    printf("[INFO] Traversing Tree(%d) in ", index);
    switch (hashSubcommand(subcommand2)) {
        case IN_ORDER:
            printf("in-order.\n");
            switch (trees[index]->type) {
                case AVL:
                    AVLInOrderTraversal(trees[index]->root);
                    break;
                case BST:
                    break;
                default:
                    break;
            }
            break;
        case PRE_ORDER:
            printf("pre-order.\n");
            switch (trees[index]->type) {
                case AVL:
                    AVLPreOrderTraversal(trees[index]->root);
                    break;
                case BST:
                    break;
                default:
                    break;
            }
            break;
        case POST_ORDER:
            printf("post-order.\n");
            switch (trees[index]->type) {
                case AVL:
                    AVLPostOrderTraversal(trees[index]->root);
                    break;
                case BST:
                    break;
                default:
                    break;
            }
            break;
        default:
            printf("[ERROR] Invalid argument.\n");
            printf("Format: [t]raversal <type:[in]-order | [pre]-order | [post]-order>\n");
            break;
    }
    printf("\n");
}

void runInsert(TreePtr trees[]) {
    char* subcommand1 = strtok(NULL, " \n");
    char* subcommand2 = strtok(NULL, " \n");
    if (!subcommand1 || !subcommand2) {
        printf("[ERROR] Insufficient argument.\n");
        printCommandFormat(INSERT);
        return;
    }
    int index, val;
    if (!sscanf(subcommand1, "%d", &index) || !sscanf(subcommand2, "%d", &val)) {
        printf("[ERROR] Invalid argument.\n");
        printCommandFormat(INSERT);
    }
    if (index >= MAX_TREE_NUMBER) {
        printf("[ERROR] Index is too large.\n");
        printf("Enter a number less than %d.\n", MAX_TREE_NUMBER);
        return;
    }
    if (trees[index] == NULL) {
        printf("[ERROR] Inserting to uninitialized tree.\n");
        printf("Run new command first.\n");
        return;
    }

    assert(TREE_TYPE_NUMBER == 2);
    switch (trees[index]->type) {
        case AVL:
            trees[index]->root = AVLInsertNode(NewTreeNode(val), trees[index]->root);
            printf("[INFO] TreeNode(%d) inserted in Tree(%d).\n", val, index);
            break;
        case BST:
            break;
        default:
            assert(false && "[ERROR] UNREACHABLE\n");
            break;
    }
}

void runInsertMany(TreePtr trees[]) {
    char* subcommand1 = strtok(NULL, " \n");
    char* subcommand2 = strtok(NULL, " \n");
    // printf("[DEBUG] subcommand = {%s, %s}\n", subcommand1, subcommand2);
    if (!subcommand1 || !subcommand2) {
        printf("[ERROR] Insufficient argument.\n");
        printCommandFormat(INSERT_MANY);
        return;
    }

    int index, count;
    if (!sscanf(subcommand1, "%d", &index) || !sscanf(subcommand2, "%d", &count)) {
        printf("[ERROR] Invalid argument.\n");
        printCommandFormat(INSERT_MANY);
        return;
    }
    if (index >= MAX_TREE_NUMBER) {
        printf("[ERROR] Index is too large.\n");
        printf("Enter a number less than %d.\n", MAX_TREE_NUMBER);
        return;
    }
    if (trees[index] == NULL) {
        printf("[ERROR] Inserting to uninitialized tree.\n");
        printf("Run new command first.\n");
        return;
    }
    if (count > 100) {
        printf("[ERROR] Count is too large.\n");
        printf("Input a number less than 100.\n");
        return;
    }
    int arr[100] = {0}, i = 0;
    while ((subcommand2 = strtok(NULL, " \n"))) {
        sscanf(subcommand2, "%d", &arr[i]);
        i++;
    }
    if (i < count) {
        printf("[ERROR] Insufficient argument.\n");
        printCommandFormat(INSERT_MANY);
        return;
    }

    assert(TREE_TYPE_NUMBER == 2);
    switch (trees[index]->type) {
        case AVL:
            for (int i = 0; i < count; i++) {
                trees[index]->root = AVLInsertNode(NewTreeNode(arr[i]), trees[index]->root);
            }
            printf("[INFO] %d node(s) inserted in Tree(%d).\n", count, index);
            break;
        case BST:
            break;
        default:
            assert(false && "[ERROR] UNREACHABLE\n");
            break;
    }
}

void runNew(TreePtr trees[]) {
    char* subcommand1 = strtok(NULL, " \n");
    char* subcommand2 = strtok(NULL, " \n");
    if (!subcommand1 || !subcommand2) {
        printf("[ERROR] Insufficient argument.\n");
        printf("Format: [n]ew <index:int> <type:[b]inary_[s]earch_[t]ree | [avl]_tree>\n");
        return;
    }
    int index;
    if (!sscanf(subcommand1, "%d", &index)) {
        printf("[ERROR] Invalid argument.\n");
        printf("Format: [n]ew <index:int> <type:[b]inary_[s]earch_[t]ree | [avl]_tree>\n");
        return;
    }
    if (index >= MAX_TREE_NUMBER) {
        printf("[ERROR] Index is too large.\n");
        printf("Enter a number less than %d.\n", MAX_TREE_NUMBER);
        return;
    }
    switch (hashTreeType(subcommand2)) {
        case AVL:
            trees[index] = (TreePtr)malloc(sizeof(Tree));
            trees[index]->type = AVL;
            trees[index]->root = EmptyAVLTree();
            printf("[INFO] A new AVL Tree labeled as index %d is created.\n", index);
            break;
        case BST:
            printf("[WARNING] New BST function has not be implemented.\n");
            printf("Pull requests are welcomed!");
            break;
        default:
            printf("[ERROR] Invalid argument.\n");
            printf("Format: [n]ew <index:int> <type:[b]inary_[s]earch_[t]ree | [avl]_tree>\n");
            break;
    }
}

void runDumpTrees(TreePtr trees[]) {
    printf("[INFO] Printing all tree info:\n");
    for (int i = 0; i < MAX_TREE_NUMBER; i++) {
        if (trees[i] == NULL)
            printf("Trees[%d] is uninitialized.\n", i);
        else
            printf("Trees[%d] is a %s with root %p\n", i, reverseHashTreeType(trees[i]->type), trees[i]->root);
    }
}