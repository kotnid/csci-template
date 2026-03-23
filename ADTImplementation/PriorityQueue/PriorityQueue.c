#include "priorityQueue.h"
#include <stdbool.h>
#include <stdlib.h>

priorityQueueADT EmptyPriorityQueue() {
    priorityQueueADT pQ = malloc(sizeof(*pQ));
    pQ->numOfElem = 0;
    return pQ;
}
bool PriorityQueueIsEmpty(priorityQueueADT pQ) {
    return pQ->numOfElem == 0;
}

void priorityEnqueue(priorityQueueADT pQ, pQueueElementT X) {
    int hole;
    for (hole = (pQ->numOfElem)++;
         hole != 0 && pQ->heap[(hole - 1) / 2] > X;
         hole = (hole - 1) / 2)
        pQ->heap[hole] = pQ->heap[(hole - 1) / 2];
    pQ->heap[hole] = X;
}
pQueueElementT priorityDequeue(priorityQueueADT pQ) {
    pQueueElementT result, v;
    int hole, child;
    if (PriorityQueueIsEmpty(pQ)) exit(EXIT_FAILURE);
    result = pQ->heap[0];
    v = pQ->heap[--(pQ->numOfElem)];
    for (hole = 0; 2 * hole + 1 < pQ->numOfElem; hole = child) {
        child = 2 * hole + 1;
        if (child + 1 < pQ->numOfElem && pQ->heap[child + 1] < pQ->heap[child])
            child++;
        if (v > pQ->heap[child])
            pQ->heap[hole] = pQ->heap[child];
        else
            break;
    }
    pQ->heap[hole] = v;
    return result;
}