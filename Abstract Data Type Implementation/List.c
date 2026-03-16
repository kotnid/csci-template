#include "List.h"
#include <stdlib.h>

listADT EmptyList() {
    return NULL;
}

listADT Cons(listElementT h1, listADT t1) {
    listADT list = malloc(sizeof(*list));
    list->h = h1;
    list->t = t1;
    return list;
}

listElementT Head(listADT list) {
    if (ListIsEmpty(list))
        exit(EXIT_FAILURE);
    return list->h;
}
listADT Tail(listADT list) {
    if (ListIsEmpty(list))
        exit(EXIT_FAILURE);
    return list->t;
}

int ListIsEmpty(listADT list) {
    return list == NULL;
}