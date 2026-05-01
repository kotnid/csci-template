# Queue 

### Properties 
- First-In-First-Out (FIFO)

--- 

### Implementations explanations
```c
typedef struct cellT
{
    queueElementT value;
    struct cellT *next;
} cellT;

struct queueCDT
{
    cellT *front, *rear;
};
```
- implemented by linked list

---

### Exam questions
- just code tracing nth special

---

### Implementaions 
[link](../../../ADTImplementation/Stack/Queue.c)
