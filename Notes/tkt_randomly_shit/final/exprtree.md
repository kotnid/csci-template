# Expr Tree

### Terminologies 

##### in-order traversal
- Predecessor is the node printed exactly before target node 
- Successor is the node printed exactly after your target node
```
Algorithm dfs(root)
    dfs(root.left)
    print(root)
    dfs(root.right)
```

##### pre-order traversal
```
Algorithm dfs(root)
    print(root)
    dfs(root.left)
    dfs(root.right)
```

##### post-order traversal
```
Algorithm dfs(root)
    dfs(root.left)
    dfs(root.right)
    print(root)
```

--- 

### Properties 
- tree that represents an expression

---

### Implementations explanation
```c
int Eval(ExprTreeADT t) {
    ExprTreeNodeADT N = ExprTreeRoot(t); 
    switch (NodeType(N)) {
        case integer: // leave node, return the value 
            return NodeValue(N);
        case operator: { // get left/right subtree value and calculate
            int lhs = Eval(LeftExprSubtree(t)); 
            int rhs = Eval(RightExprSubtree(t));
            switch (NodeOp(N)) {
                case '+':
                    return lhs + rhs;
                case '-':
                    return lhs - rhs;
                case '*':
                    return lhs * rhs;
                case '/':
                    return lhs / rhs;
            }
        }
    }
    exit(EXIT_FAILURE);
}
```

```c
enum nodetype { operator, integer }; // create a list of constant
typedef enum nodetype NodeTypeT;

struct ExprTreeNodeCDT {
    NodeTypeT T;
    union {
        char op;
        int value;
    } content;
};

ExprTreeNodeADT NewOpNode(char op) {
    ExprTreeNodeADT N = malloc(sizeof(*N));
    N->T = operator;
    N->content.op = op;
    return N;
}
```

---

### Exam questions 
1. Consider the following binary search tree. Which node is the successor of node 19? Which node is the predecessor of node 18? (21 Q3ii)
```
          20 
         /  \
       18    35
      /  \   / \
    14   19 30  40
   /  \
  10  17
   \
   11
```
- Successor of 19: 20, Predecessor of 18: 17 

2. Draw the expression tree for the expression (2 - 4 * 5) + 6 * (3 + 1). Write the preorder traversal and postorder traversal of the tree. (18 Q7)
```
            [+]
           /   \
         /       \
      [-]         [*]
     /   \       /   \
   [2]   [*]   [6]   [+]
         / \         / \
       [4] [5]     [3] [1]
```
- preorder: `+ - 2 * 4 5 * 6 + 3 1`
- postorder: `2 4 5 * - 6 3 1 + * +`

---

### Implementaions 
[link](../../../ADTImplementation/ExprTree/)

---

### Appendix: How to build a expr tree (not included)

##### postfix 
```c
ExprTreeADT BuildExprTree(char* postfixStr) {
    StackADT s = EmptyStack();
    
    char* token = strtok(postfixStr, " ");
    
    while (token != NULL) {
        // If the token is a single character operator (+, -, *, /)
        if (strlen(token) == 1 && (token[0] == '+' || token[0] == '-' || 
                                   token[0] == '*' || token[0] == '/')) {
            
            // Pop the right and left subtrees
            ExprTreeADT R = Pop(s);
            ExprTreeADT L = Pop(s);
            
            // Use your ADT to create an operator node
            ExprTreeNodeADT opNode = NewOpNode(token[0]);
            
            // Combine them into a new subtree and push back to stack
            ExprTreeADT newTree = NonemptyExprSubtree(opNode, L, R);
            Push(s, newTree);
        } 
        else {
            // Otherwise, it's a number. Convert the string token to an integer
            int value = atoi(token);
            
            // Use your ADT to create an integer leaf node
            ExprTreeNodeADT intNode = NewIntNode(value);
            
            // A number is a leaf, so its left and right subtrees are empty
            ExprTreeADT leafTree = NonemptyExprSubtree(intNode, EmptyExprTree(), EmptyExprTree());
            
            Push(s, leafTree);
        }
        
        // Move to the next space-separated token
        token = strtok(NULL, " ");
    }
    
    // The final tree is the last item on the stack
    ExprTreeADT root = Pop(s);
    free(s);
    
    return root;
}
```

##### infix
- transfer it into postfix to do (Shunting Yard Algorithm)
```c
void infixToPostfix(const char* infix, char* postfix) {
    StackADT stack = EmptyStack();
    int i = 0, p = 0;
    
    while (infix[i] != '\0') {
        char current = infix[i];

        // Skip spaces in the input
        if (isspace(current)) {
            i++;
            continue;
        }

        // RULE 1: If operand (number or letter), add to output
        if (isalnum(current)) {
            // Loop to catch multi-digit numbers (like "15")
            while (isalnum(infix[i])) {
                postfix[p++] = infix[i++];
            }
            postfix[p++] = ' '; // Add space separator
            continue; // Skip the i++ at the bottom of the loop
        } 
        
        // RULE 2: If '(', push to stack
        else if (current == '(') {
            pushChar(stack, current);
        } 
        
        // RULE 3: If ')', pop to output until '(' is found
        else if (current == ')') {
            while (!isEmpty(stack) && peekChar(stack) != '(') {
                postfix[p++] = popChar(stack);
                postfix[p++] = ' ';
            }
            popChar(stack); // Discard the '('
        } 
        
        // RULE 4: If Operator
        else if (current == '+' || current == '-' || current == '*' || current == '/') {
            while (!isEmpty(stack) && precedence(peekChar(stack)) >= precedence(current)) {
                postfix[p++] = popChar(stack);
                postfix[p++] = ' ';
            }
            pushChar(stack, current);
        }
        
        i++;
    }

    // RULE 5: Pop remaining operators from stack to output
    while (!isEmpty(stack)) {
        postfix[p++] = popChar(stack);
        postfix[p++] = ' ';
    }

    // Null-terminate the string and trim the trailing space
    if (p > 0) postfix[p - 1] = '\0';
    else postfix[0] = '\0';

    free(stack);
}
```