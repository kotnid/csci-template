# Stack 

### Properties 
- Last-In-First-Out (LIFO)
- Support push/ pop 

--- 

### Implementations explanation 
```c
typedef struct stackCDT *stackADT;
typedef int stackElementT;
```
- define a `stackADT` to be a pointer to `stackCDT`
- change data type by changing `int` to one you want 
- Advantage of using *Abstract* data types: user only need understand what the data type conceptully is

```c
// creates and returns a new, empty stack 
stackADT EmptyStack(void); 
 
// pushs element to top of stack
void Push(stackADT stack, stackElementT element);

// removes element from top of stack
stackElementT Pop(stackADT stack);

// returns depth of a stack
int StackDepth(stackADT stack);

// tells whether a stack is empty 
int StackIsEmpty(stackADT stack);
```

---

### Reverse Polish Notation
- calculate the expression in postfix form 
    - E.g. infix form : `50 * 15 + 38 / 20` => postfix form `50 15 * 38 20 / +`
- push number element inside stack, do operation when having operator 
    - E.g. [50] => [50, 15] => (do * operation) => [750] => ... 

--- 

### Exam questions 
- follow template implementations unless specify

1. Rewrite binary tree preorder traversal algorithm in pseudo-code, using a stack instead of recursion. (18 Q5)
```c
stackADT sk = EmptyStack();
Push(sk, root);
while(StackDepth(sk)){
    BinaryTreeADT node = Pop(sk);
    printf("%d ", GetNodeData(Root(node))); // assume it is integer 
    if (!TreeIsEmpty(RightSubtree(node))) Push(sk, RightSubtree(node));
    if (!TreeIsEmpty(LeftSubtree(node))) Push(sk, LeftSubtree(node));
}
```

2. Write the C function ReverseStack() for the array implementation. Assuming the top integer represents the index of the highest element in the entry array, reversing the stack is simply reversing the active portion of the array in place (18 Q7)
```c
#define MAXSTACK 20 
typedef char StackEntry;
typedef struct stack{
    int top;
    StackEntry entry[MAXSTACK];
}Stack;
void ReverseStack(Stack *SP){
    int l = 0, r = SP->top;
    StackEntry tmp;
    while(l < r){
        tmp = SP->entry[l];
        SP->entry[l] = SP->entry[r];
        SP->entry[r] = tmp;
        l++, r--;
    }
}
```

---

### Implementaions 
[link](../../../ADTImplementation/Stack/Stack.c)
