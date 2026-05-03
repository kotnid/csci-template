// just copy from lecture notes, haven't test
typedef struct DisjSetCDT *DisjSetADT;

DisjSetADT NewDisjointSets(void);
void SetUnion(DisjSetADT, int, int);
int Find(int, DisjSetADT);