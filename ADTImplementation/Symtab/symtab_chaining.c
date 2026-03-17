#include <stdlib.h>
#include <string.h>

#include "symtab.h"
#define TABLE_SIZE 201
#define Multiplier -1664117991L

typedef struct cellT {
    char* key;
    void* value;
    struct cellT* next;
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

static cellT* FindCell(cellT* cp, char* key) {
    while ((cp != NULL ? strcmp(cp->key, key) != 0 : 0))
        cp = cp->next;
    return cp;
}

symtabADT EmptySymbolTable(void) {
    symtabADT table;
    int i;
    table = malloc(sizeof(*table));
    for (i = 0; i < TABLE_SIZE; i++)
        table->buckets[i] = NULL;
    return table;
}

void Enter(symtabADT table, char* key, void* value) {
    int hashCode;
    cellT* cp;
    hashCode = Hash(key, TABLE_SIZE);
    cp = FindCell(table->buckets[hashCode], key);
    if (cp == NULL) { /* New Entry */
        cp = malloc(sizeof(*cp));
        cp->key = malloc(sizeof(char) * (strlen(key) + 1));
        strcpy(cp->key, key);
        cp->next = table->buckets[hashCode];
        table->buckets[hashCode] = cp;
    };
    cp->value = value;
}

void* Lookup(symtabADT table, char* key) {
    int hashCode;
    cellT* cp;
    hashCode = Hash(key, TABLE_SIZE);
    cp = FindCell(table->buckets[hashCode], key);
    if (cp == NULL)
        return NULL;
    return cp->value;
}

void forEachEntryDo(symtabFnT f, symtabADT table) {
    cellT* cp;
    for (int i = 0; i < TABLE_SIZE; i++)
        for (cp = table->buckets[i];
             cp != NULL;
             cp = cp->next)
            f(cp->key, cp->value);
}