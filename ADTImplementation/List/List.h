typedef struct listCDT* listADT;
typedef int listElementT;

listADT EmptyList(void);
listADT Cons(listElementT, listADT);
listElementT Head(listADT);
listADT Tail(listADT);
int ListIsEmpty(listADT);

typedef struct listCDT* listADT;
struct listCDT {
    listElementT h;
    listADT t;
};