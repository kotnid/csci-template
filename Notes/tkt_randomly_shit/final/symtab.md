# Symtab

### Properties 
- key-value pair
- look up a value in the table and enter a value with its associated key


---

### Implementations explanation
```c
// creates a new, empty symbol table 
symtabADT EmptySymbolTable(void);

// creates or overwrite
void Enter(symtabADT table, char *key, void *value);

// return a pointers 
void *Lookup(symtabADT table, char *key);
```
```c
typedef void (*symtabFnT)(char*, void*); // function pointer
void forEachEntryDo(symtabFnT f, symtabADT table) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (table->buckets[i] == NULL) continue;
        f(table->buckets[i]->key, table->buckets[i]->value); // each key-value pair run the function
    }
}

void printing(char* key, void* val) {
    printf("printing: %s, %d\n", key, *(int*)val); // type cast void pointer to integer pointer
}
```

---

### Hashing
- reduce a search key into an integer in a fixed range
- collision when two or more keys with identical hashcode 

##### Seperate chaining
- put on same backet for collision (linked list)
- load factor = entries/bracket (better to have >= 1)
- too few bracket => large load factor => more collision => bad performance
- too small load factor => more empty bracket => waste space 

##### Open addressing hashing
- when collision occur, other position in the table are probed until an empty bracket is found
- load factor should below 0.5 
- primary clustering: key from into clusters, which requried serveral attempts to resolve the collision
- linear probing: h0 => h0+F(1) => h0+F(2) => ...
    - generally F(i) = i
    - slow when hash table get nearly full
- quadratic probing: h0 => h0+F(1) => h0+F(2) => ...
    - generally F(i) = i^2
    - not guarantee of finding an empty cell once the table gets more than half full 
- double hashing: h0 => h0 + hash2(key,n) => h0 + 2*hash2(key,n) => ...
    - F(i) = i*hash2(key,n)
    - more complicated and slower then quadratic probing

--- 

### Strings as Character Arrays
```c
char a[] = {'a', 'b'};
char b[2] = {'a', 'b'};
char c[2] = {'a', '\0'};
char d[2] = "ab";
char e[2] = "a";
printf("%s\n", a); // ababa
printf("%s\n", b); // aba
printf("%s\n", c); // a
printf("%s\n", d); // aba
printf("%s\n", e); // a
```
- read until `\0`

--- 

### Pointers 
- disclaimers: most examples probably won't be tested, read it for fun 
```c
int num;
int *ptr = &num; // &num = addr of num 
int num2 = *ptr; // *ptr = value of addr(num)
```

##### Void pointers
```c
void* vp;
double *dp;
int *ip;
vp = ip; // ok
vp = dp; // ok
```
- pointer to something
- compatible with any pointer type 

```c
typedef struct{
	int a, b;
}data;

int main(){
	data myData = {10, 20}; 
    data *dp = &myData;     
    void *vp = dp;		
	printf("%d", vp->a); // error!
	printf("%d", ((data*)vp)->a); // ok
}
```
- as vp is a generic pointer it will only store data but don't know meaning of data
- by type casting then we can access

```c
typedef struct{
    int a;
}data;

typedef struct{
    char c, d, e, f;
}data2;

int main(){
    data2 myData = {'A', 'B', 'C', 'D'}; 
    data2 *dp = &myData;     
    void *vp = dp;        
    printf("%d", ((data*)vp)->a);
}
```
- ewww more disgusting : /
- this is type punning
- memory: `0x41 0x42 0x43 0x44` -> little endian so value become `0x44434241`
- ceng3420 is still hurting me : (


```c
int myInt = 300; 
char *cPtr = (char *)&myInt;
printf("%d", *cPtr);
```
- 300 = 0x12C
- cPtr will only read 0x2C


##### Array pointers 
```c
int arr[5] = {1,2,3,4,5}; // arr is not assignable 
int *ptr = arr;
for(int i=0; i<5; i++)printf("%d ", *(ptr+i)); // 1 2 3 4 5
printf("%d", (ptr+3)[0]); // 4 
```

##### Function pointers 
```c
int f(int);
int *fpi(int);
int (*fi)(int);
```
- `f` is a function that accepts an integer argument and returns an integer
- `fpi` is a function that accepts an integer argument and returns an integer pointer
- `fi` is a pointer variable that point to a function that accepts an integer argument and returns an integer

```c
int y, x=5;
int (*func)(const int); // declare a function pointer name func
func = square; // func point to square function 
y = (*func)(x); // derefernce pointer => get the function => call function with argument

typedef int (*Pfi)(int);
Pfi func = square; // same but use typedef instead
```

##### Array of pointers to functions
```c
int (*x[4])(int, float);
typedef int (*Pfi)(int, float);
Pfi x[4];
x[2] = f1;
result = x[2](3,2.1); // same as f1(3,2.1)
```

##### Function as argument
```c
double f(const double x){return x*x;}
typedef double (*F1)(const double);

void tabulate(double (*fp)(const double)){
    for(int i=0; i<=10; i++)printf("%.2f ", fp(i));
}

void tabulate(F1 fp){
    for(int i=0; i<=10; i++)printf("%.2f ", fp(i));
}
```
- you may notice why `fp` isn't dereferenced but still able to run function
- because compiler automatically dereference it 
- not important though, just realize that while tidying notes

---

### Exam questions
- most questions just code tracing, similar to hw
- nth special at all

1. Write Pseudo code for Hash-Insert using closed hashing with quadratic probing, and Hash-Delete to delete the item if it is found in the table. Use the special value DELETED to mark for lazy deletion. (18 Q8)
```
Algorithm Hash-Insert(T, k)
    i = 0
    repeat
        j = (h(k) + i * i) mod m
        if T[j] == EMPTY or T[j] == DELETED
            T[j] = k
            return j
        i = i + 1
    until i == m
    return "Error: Hash table overflow"

Algorithm Hash-Delete(T, k)
    i = 0
    repeat
        j = (h(k) + i * i) mod m
        if T[j] == k
            T[j] = DELETED
            return j
        i = i + 1
    until T[j] == EMPTY or i == m
    return "Error: Key not found"    
```

2. Mary implements a hash table with 17 buckets. There will be about 20 entries to be stored in the table.  What collision resolution scheme would you suggest? Name and describe the scheme. Justify your answer. (20 Q2a)
- Seperate chaining
- As number of entries exceed number of available buckets
- Can consider load factor (Seperate chaining: >=1, open address hashing: <0.5)


---

### Implementaions 
[link](../../../ADTImplementation/Symtab/)