# List

### Properties 
- a list from a head(element) and tail(list)
- empty list has no head/tail

--- 

### Implementations explanation 
```c
// returns an empty list
listADT EmptyList(void);

// construct a list
listADT Cons(listElementT, listADT);

// returns head of a list
listElementT Head(listADT);

// return tails of a list
listADT Tail(listADT);

// check if list is empty
int ListIsEmpty(listADT);
```

```c
listADT Append(listADT L1, listElementT x) {
    if (ListIsEmpty(L1)) return (Cons(x, EmptyList()));
    else return (Cons(Head(L1), Append(Tail(L1), x)));
}
```

---

### Big-O notation 
- remove all terms whose contribution become not significant when problem size becomes large
    - E.g. n^2 + n + 1 => O(N^2)
- remove all coefficent
    - E.g. 4n^2 => O(N^2)
- remove all constant factor 
    - E.g. 3n-2 => O(N)

--- 

### Sorting 

##### Selection sort
```c
for(int p = 0; p<n; p++){
    // select the smallest integer from between p and n-1 
    int mn = p;
    for(int i=p+1; i<n; i++)if(a[i] < a[mn])mn = i;

    // swap the selected smallest integer and the integer at position
    {
        int tmp = a[p];
        a[p] = a[mn];
        a[mn] = tmp;
    }
}
// Time complexity: O(N^2)
```

##### Merge sort
```c
void Merge(int res[], int a1[], int n1, int a2[], int n2){
    int p = 0, p1 = 0, p2 = 0;
    while(p1 < n1 && p2 < n2){ // put smaller one into result array
        if(a1[p1] < a2[p2])res[p++] = a1[p1++];
        else res[p++] = a2[p2++];
    }
    while(p1 < n1)res[p++] = a1[p1++]; // put remain elements
    while(p2 < n2)res[p++] = a2[p2++];
}

void MergeSort(int arr[], int n){
    int n1, n2, *a1, *a2;
    if(n <= 1)return ; // sorted already
    n1 = n/2, n2 = n-n1; // split array into 2 half
    a1 = malloc(n1*sizeof(int));
    a2 = malloc(n2*sizeof(int));
    for(int i=0; i<n1; i++)a1[i] = arr[i];
    for(int i=0; i<n2; i++)a2[i] = arr[i+n1];
    MergeSort(a1, n1); MergeSort(a2, n2);
    Merge(arr, a1, n1, a2, n2);
}
// Time complexity: O(NlogN)
```

###### Quick sort
```c
int Partition(int arr[], int n){ // return number of element < pivot
    int p, q, pivot;
    pivot = arr[0], p = 1, q = n-1;
    while(1){
        // find first position which need swap 
        while(p < q && arr[q] >= pivot)q--; 
        while(p < q && arr[p] < pivot)p++; 
        if(p == q)break;
        {int tmp; tmp = arr[p], arr[p] = arr[q], arr[q] = tmp;} // swap them
    }
    if(arr[p] >= pivot)return 0; // every element >= pivot 
    arr[0] = arr[p], arr[p] = pivot;
    return p;
}

void QuickSort(int arr[], int n){
    int pivotPosition;
    if(n <= 1)return ;
    pivotPosition = Partition(arr, n);
    QuickSort(arr, pivotPosition);
    QuickSort(arr+pivotPosition+1, n-pivotPosition-1);
}
// Time complexity: O(NlogN)
// If array is sorted => partition n times => worst case  O(N^2)
// On average fastest
```

---

### Exam questions 
- sorting usually is dry running
- or using list to make some customized sorting 

1. Write the function minHead in C. The function takes a listADT argument and returns a list where the smallest element is at the head, and the tail contains all other elements. (19 Q5a)
```c
listADT minHead(listADT L){
    if(ListIsEmpty(L) || ListIsEmpty(Tail(L)))return L;
    ListADT T = minHead(Tail(L)); // recursively do
    if(Head(L) <= Head(T))return Cons(Head(L), T);
    else return Cons(Head(T), Cons(Head(L), Tail(T)));
}
// Time Complexity: O(N)
```

2. Write a function that accepts a listADT argument, and return the sorted list by making use the minHead function. (19 Q5b)
```c
listADT PriscillaSort(listADT L){
    listADT L1, R;
    R = EmptyList(); // result list
    L1 = L;
    while(!ListIsEmpty(L1)){
        L1 = minHead(L1); // get smallest element in array
        R = Cons(Head(L1), R);
        L1 = Tail(L1);
    }
    return R;
}
// Time complexity: O(N^2)
```

---

### Implemenations
[link](../../../ADTImplementation/List/)