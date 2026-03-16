#include "symtab.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TABLE_SIZE 201
#define Multiplier -1664117991L

typedef struct cellT {
    char* key;
    void* value;
} cellT;

struct symtabCDT {
    cellT* buckets[TABLE_SIZE];
};

int Hash(char* s, int nBuckets) {
    unsigned long hashcode;
    hashcode = 0;
    for (int i = 0; s[i] != '\0'; i++)
        hashcode = hashcode * Multiplier + s[i];
    return (hashcode % nBuckets);
}

symtabADT EmptySymbolTable(void) {
    symtabADT table;
    table = malloc(sizeof(*table));
    for (int i = 0; i < TABLE_SIZE; i++)
        table->buckets[i] = NULL;
    return table;
}

void* Lookup(symtabADT table, char* key) {
    int hashCode = Hash(key, TABLE_SIZE), index = hashCode;
    cellT* target = table->buckets[index];
    while (target == NULL || strcmp(target->key, key) != 0) {
        index = (index + 1) % TABLE_SIZE;
        target = table->buckets[index];
        if (index == hashCode) {
            return NULL;
        }
    }
    return target->value;
}

void Enter(symtabADT table, char* key, void* value) {
    int hashCode = Hash(key, TABLE_SIZE), index = hashCode;
    cellT* target = table->buckets[index];
    if(Lookup(table, key) != NULL) {
        // Overwrite
        while (target == NULL || strcmp(target->key, key)!=0) {
            index = (index + 1) % TABLE_SIZE;
            target = table->buckets[index];
            if (index == hashCode) {
                printf("The table is full.\n");
                exit(EXIT_FAILURE);
            }
        }
        target->value = value;
        table->buckets[index] = target;
    } else {
        // Create new
        while (target != NULL) {
            index = (index + 1) % TABLE_SIZE;
            target = table->buckets[index];
            if (index == hashCode) {
                printf("The table is full.\n");
                exit(EXIT_FAILURE);
            }
        }
        target = malloc(sizeof(*target));
        target->key = malloc(sizeof(char) * strlen(key) + 1);
        strcpy(target->key, key);
        target->value = value;
        table->buckets[index] = target;
    }
}

void forEachEntryDo(symtabFnT f, symtabADT table) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (table->buckets[i] == NULL) continue;
        f(table->buckets[i]->key, table->buckets[i]->value);
    }
}

void printing(char* key, void* val) {
    printf("printing: %s, %d\n", key, *(int*)val);
}

void dbl(char* key, void* val) {
    *(int*)val = *(int*)val * 2;
    printf("dbl: %s, %d\n", key, *(int*)val);
}

// int main() {
//     symtabADT tb = EmptySymbolTable();
//     int val1 = 1, val2 = 123;
//     void *val1Ptr = &val1, *val2Ptr = &val2;
//     Enter(tb, "A", val1Ptr);
//     Enter(tb, "A", val2Ptr);
//     forEachEntryDo(printing, tb);
// }

// int main() {
//     symtabADT tb = EmptySymbolTable();
//     int val1 = 1, val2 = 123;
//     void *val1Ptr = &val1, *val2Ptr = &val2;
//     tb->buckets[Hash("a", TABLE_SIZE)] = malloc(sizeof(cellT));
//     tb->buckets[Hash("a", TABLE_SIZE)]->key = malloc(sizeof(char) * 100);
//     strcpy(tb->buckets[Hash("a", TABLE_SIZE)]->key, "dllm");
//     tb->buckets[Hash("a", TABLE_SIZE)]->value = val2Ptr;
//     Enter(tb, "a", val1Ptr);
//     printf("%d\n", *(int*)Lookup(tb, "a"));
//     Enter(tb, "a", val2Ptr);
//     printf("%d\n", *(int*)Lookup(tb, "a"));
//     void* tmp = Lookup(tb, "b");
//     if (tmp == NULL)
//         printf("%p\n", NULL);
//     else
//         printf("%d\n", *(int*)Lookup(tb, "b"));
//     symtabFnT printingPtr = &printing;
//     forEachEntryDo(printingPtr, tb);
//     forEachEntryDo(dbl, tb);
//     forEachEntryDo(printingPtr, tb);
// }
