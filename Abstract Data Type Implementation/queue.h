#include <stdlib.h>
typedef struct queueCDT *queueADT;
typedef struct customerDataT *queueElementT;
queueADT EmptyQueue(void);
void Enqueue(queueADT queue, queueElementT element);
queueElementT Dequeue(queueADT queue);
int QueueLength(queueADT queue);
int QueueIsEmpty(queueADT queue);

typedef enum
{
    vipBanking,
    ordinaryBanking
} accountType;

typedef struct customerDataT
{
    int timeOfArrival;
    int ServiceTimeStillNeeded;
    accountType A;
} customerDataT;

typedef struct counterT
{
    int numberOfCustomersServed;
    int totalServiceTime;
} counterT;