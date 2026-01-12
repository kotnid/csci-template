#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

typedef struct cellT{
    queueElementT value;
    struct cellT *next;
}cellT;

struct queueCDT{
    cellT *front, *rear;
    size_t SIZE;
};

queueADT EmptyQueue(){
    queueADT queue;
    queue = (queueADT)malloc(sizeof(*queue));
    queue->front = NULL;
    queue->SIZE = 0;
    return (queue);
}

void Enqueue(queueADT queue, queueElementT element){
    cellT *cp;
    cp = (cellT*)malloc(sizeof(cellT));
    cp->value = element; 
    cp->next = NULL;
    if(queue->front==NULL){
        queue->front = cp;
    }else{
        queue->rear->next = cp;
    }
    queue->rear = cp;
    queue->SIZE++;
}

queueElementT Dequeue(queueADT queue){
    queueElementT result;
    if(queue->front==NULL){
        printf("Queue is empty.\n");
        exit(EXIT_FAILURE);
    }
    result = queue->front->value;
    queue->front = queue->front->next;
    queue->SIZE--;
    return result;
}

int QueueLength(queueADT queue){
    return queue->SIZE;
}

int QueueIsEmpty(queueADT queue){
    return (queue->SIZE == 0);
}



// #include <stdio.h>
// int main(){
//     queueADT queue = EmptyQueue();
//     for(int i = 0; i < 10; i++) Enqueue(queue, i);

//     while(!QueueIsEmpty(queue)){
//         int u = Dequeue(queue);
//         printf("%d %d\n", u, QueueLength(queue));
//     }
// };