#include "Commands.h"
#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "ADTs/AVLTree.h"
#include "ADTs/BinarySearchTree.h"
#include "ADTs/SplayTree.h"
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
    int index, val;
    if (!readAndParseSubcommandToInt(&index, INSERT) || !readAndParseSubcommandToInt(&val, INSERT)) {
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

    assert(TREE_TYPE_NUMBER == 3);
    switch (trees[index]->type) {
        case AVL:
            trees[index]->root = AVLInsertNode(NewTreeNode(val), trees[index]->root);
            printf("[INFO] TreeNode(%d) inserted in Tree(%d).\n", val, index);
            break;
        case BST:
            trees[index]->root = InsertNode(trees[index]->root, NewTreeNode(val));
            printf("[INFO] TreeNode(%d) inserted in Tree(%d).\n", val, index);
            break;
        case SPL:
            trees[index]->root = Splay_Insert(trees[index]->root, val);
            printf("[INFO] TreeNode(%d) inserted in Tree(%d).\n", val, index);
            break;
        default:
            assert(false && "[ERROR] UNREACHABLE\n");
            break;
    }
}

void runInsertMany(TreePtr trees[]) {
    int index, count;
    if (!readAndParseSubcommandToInt(&index, INSERT_MANY) || !!readAndParseSubcommandToInt(&count, INSERT_MANY)) {
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
    char* subcommand;
    while ((subcommand = strtok(NULL, " \n"))) {
        sscanf(subcommand, "%d", &arr[i]);
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
            for (int i = 0; i < count; i++) {
                trees[index]->root = InsertNode(trees[index]->root, NewTreeNode(arr[i]));
            }
            printf("[INFO] %d node(s) inserted in Tree(%d).\n", count, index);
            break;
        default:
            assert(false && "[ERROR] UNREACHABLE\n");
            break;
    }
}

char buffer[1024] = {0};

static void AVL_print_node(AVLTreeADT t, FILE* o) {
    fprintf(o, "%s+-%d\n", buffer, t->rt->value);
}

static void AVL_print_subtree(AVLTreeADT t,
                              FILE* o,
                              const char* prf_right,
                              const char* prf_left,
                              char* buf, int buf_sz) {
    if (t->rst) {
        int res = snprintf(buf, buf_sz, "%s", prf_right);
        AVL_print_subtree(t->rst, o, "  ", "| ", buf + res, buf_sz - res);
        *buf = '\0';
    }
    AVL_print_node(t, o);
    if (t->lst) {
        int res = snprintf(buf, buf_sz, "%s", prf_left);
        AVL_print_subtree(t->lst, o, "| ", "  ", buf + res, buf_sz - res);
        *buf = '\0';
    }
}

static void BST_print_node(BinaryTreeADT t, FILE* o) {
    fprintf(o, "%s+-%d\n", buffer, t->rt->value);
}

static void BST_print_subtree(BinaryTreeADT t,
                              FILE* o,
                              const char* prf_right,
                              const char* prf_left,
                              char* buf, int buf_sz) {
    if (t->rst) {
        int res = snprintf(buf, buf_sz, "%s", prf_right);
        BST_print_subtree(t->rst, o, "  ", "| ", buf + res, buf_sz - res);
        *buf = '\0';
    }
    BST_print_node(t, o);
    if (t->lst) {
        int res = snprintf(buf, buf_sz, "%s", prf_left);
        BST_print_subtree(t->lst, o, "| ", "  ", buf + res, buf_sz - res);
        *buf = '\0';
    }
}

static void SPL_print_node(SplayTreeADT t, FILE* o) {
    fprintf(o, "%s+-%d\n", buffer, t->val);
}

static void SPL_print_subtree(SplayTreeADT t,
                              FILE* o,
                              const char* prf_right,
                              const char* prf_left,
                              char* buf, int buf_sz) {
    if (t->r) {
        int res = snprintf(buf, buf_sz, "%s", prf_right);
        SPL_print_subtree(t->r, o, "  ", "| ", buf + res, buf_sz - res);
        *buf = '\0';
    }
    SPL_print_node(t, o);
    if (t->l) {
        int res = snprintf(buf, buf_sz, "%s", prf_left);
        SPL_print_subtree(t->l, o, "| ", "  ", buf + res, buf_sz - res);
        *buf = '\0';
    }
}

void runPrintTree(TreePtr trees[]) {
    char* subcommand = strtok(NULL, " \n");
    if (!subcommand) {
        printf("[ERROR] Insufficient argument.\n");
        printCommandFormat(INSERT);
        return;
    }
    int index;
    if (!sscanf(subcommand, "%d", &index)) {
        printf("[ERROR] Invalid argument.\n");
        printCommandFormat(INSERT);
    }
    if (index >= MAX_TREE_NUMBER) {
        printf("[ERROR] Index is too large.\n");
        printf("Enter a number less than %d.\n", MAX_TREE_NUMBER);
        return;
    }
    if (trees[index] == NULL) {
        printf("[ERROR] Printing uninitialized tree.\n");
        return;
    }

    printf("[INFO] Printing Tree(%d):\n", index);
    assert(TREE_TYPE_NUMBER == 3);
    switch (trees[index]->type) {
        case AVL:
            if (trees[index]->root == NULL)
                printf("(NULL)\n");
            else
                AVL_print_subtree(trees[index]->root, stdout, "  ", "  ", buffer, sizeof buffer);
            break;
        case BST:
            if (trees[index]->root == NULL)
                printf("(NULL)\n");
            else
                BST_print_subtree(trees[index]->root, stdout, "  ", "  ", buffer, sizeof buffer);
            break;
        case SPL:
            if (trees[index]->root == NULL)
                printf("(NULL)\n");
            else
                SPL_print_subtree(trees[index]->root, stdout, "  ", "  ", buffer, sizeof buffer);
            break;
        default:
            break;
    }
}

void runDelete(TreePtr trees[]) {
    int index, val;
    if (!readAndParseSubcommandToInt(&index, DELETE) || !readAndParseSubcommandToInt(&val, DELETE)) {
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

    assert(TREE_TYPE_NUMBER == 2);
    switch (trees[index]->type) {
        case AVL:
            todo("AVL delete function");
            break;
        case BST:
            if (!IsNodeExist(trees[index]->root, val)) {
                printf("[ERROR] Deleting non-existent node.\n");
                return;
            }
            trees[index]->root = DeleteNode(trees[index]->root, val);
            printf("[INFO] TreeNode(%d) deleted in Tree(%d).\n", val, index);
            break;
        default:
            assert(false && "[ERROR] UNREACHABLE\n");
            break;
    }
}

void runNew(TreePtr trees[]) {
    int index;
    if(!readAndParseSubcommandToInt(&index, NEW)) return;
    char* subcommand2 = strtok(NULL, " \n");
    if (!subcommand2) {
        printf("[ERROR] Insufficient argument.\n");
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
            break;
        case BST:
            trees[index] = (TreePtr)malloc(sizeof(Tree));
            trees[index]->type = BST;
            trees[index]->root = EmptyBinaryTree();
            break;
        case SPL:
            trees[index] = (TreePtr)malloc(sizeof(Tree));
            trees[index]->type = SPL;
            trees[index]->root = NULL;
            break;
        default:
            printf("[ERROR] Invalid argument.\n");
            printf("Format: [n]ew <index:int> <type:[b]inary_[s]earch_[t]ree | [avl]_tree> | [spl]ay_tree\n");
            return;
    }
    printf("[INFO] A new %s labeled as index %d is created.\n", reverseHashTreeType(hashTreeType(subcommand2)), index);
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

void runSearch(TreePtr trees[]) {
    int index, val;
    if (!readAndParseSubcommandToInt(&index, SEARCH) || !readAndParseSubcommandToInt(&val, SEARCH)) return;
    bool found;
    switch (trees[index]->type) {
        case BST:
            found = IsNodeExist(trees[index]->root, val);
            break;
        case AVL:
            printf("[WARNING] Not implemented\n");
            break;
        case SPL:
            trees[index]->root = Splay_Find(trees[index]->root, val, &found);
            break;

        default:
            break;
    }
    if (found)
        printf("[INFO] Node(%d) exist in Tree(%d)\n", val, index);
    else
        printf("[INFO] Node(%d) does not exist in Tree(%d)\n", val, index);
}