## hashing
- reduce a search key into an integer in a fixed range
- collision when two or more keys with identical hashcode 

#### seperate chaining
- put on same backet for collision (linked list)
- load factor = entries/bracket (better to have >= 1)
- too few bracket => large load factor => more collision => bad performance
- too small load factor => more empty bracket => waste space 

#### open addressing hashing
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

## pointers
- ew
```c
int num;
int *ptr = &num; // &num = addr of num
int num2 = *ptr; // *ptr = value of addr(num)
```

#### array pointers
```c
int arr[5] = {1,2,3,4,5}; // arr is not assignable
int *ptr = arr;  
for(int i=0; i<5; i++)printf("%d ", *(ptr+i)); // 1 2 3 4 5
printf("%d",(ptr+3)[0]); // 4   
```

#### function pointers
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

#### array of pointers to functions 
```c
int (*x[4])(int, float);
typedef int (*Pfi)(int, float);
Pfi x[4];
x[2] = f1;
result = x[2](3,2.1); // same as f1(3,2.1)
```

#### function as argument
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