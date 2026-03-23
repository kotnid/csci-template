#include <stdbool.h>

typedef struct priorityQueueCDT* priorityQueueADT;
typedef int pQueueElementT;

priorityQueueADT EmptyPriorityQueue(void);
void PriorityEnqueue(priorityQueueADT, pQueueElementT);
pQueueElementT PriorityDequeue(priorityQueueADT);
bool PriorityQueueIsEmpty(priorityQueueADT);

struct priorityQueueCDT {
    pQueueElementT heap[1000];
    int numOfElem;
};