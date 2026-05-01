# Priority queue 

### Properties 
- queue but insert a new element at an appropriate position 
- dequeue deletes and returns the "smallest" element
- implement by partially ordered tree (min heap)
    - symetrical as possible (length differ at most one)
    - parent's key is smaller than it's children (root is the smallest)
- parent of node pQ->heap[n] is node pQ->head[(n-1)/2]
- left child of node pQ->heap[n] is node pQ->head[2*n+1]
- right child of node pQ->heap[n] is node pQ->head[2*n+2]

--- 

### Implementations explanation 
```c
void priorityEnqueue(priorityQueueADT pQ, pQueueElementT X) {
    int hole;
    // create a new hole (space for the element)
    // if parent is larger than new element, swap them 
    // else no need swap, break it
    for (hole = (pQ->numOfElem)++; hole != 0 && pQ->heap[(hole - 1) / 2] > X; hole = (hole - 1) / 2)
        pQ->heap[hole] = pQ->heap[(hole - 1) / 2];

    // postion for the element is found, update the value
    pQ->heap[hole] = X;
}
```

```c
pQueueElementT priorityDequeue(priorityQueueADT pQ) {
    pQueueElementT result, v;
    int hole, child;
    if (PriorityQueueIsEmpty(pQ)) exit(EXIT_FAILURE);

    // get current smallest node, remove it 
    result = pQ->heap[0];   
    v = pQ->heap[--(pQ->numOfElem)]; // leftover node

    for (hole = 0; 2 * hole + 1 < pQ->numOfElem; hole = child) {
        // pick left child of hole
        child = 2 * hole + 1;  

        // right child exist and value is smaller => choose right child
        if (child + 1 < pQ->numOfElem && pQ->heap[child + 1] < pQ->heap[child]) child++;

        // child is smaller => use child to fill the hole 
        if (v > pQ->heap[child]) pQ->heap[hole] = pQ->heap[child];
        else break; // leftover node is smaller => use leftover to fill
    }
    pQ->heap[hole] = v;
    return result;
}
```

---

### Exam questions (heap sort)
- given an array A[1..8] = [15,33,23,24,8,17,3,29], how can we sort it by using heap? (21 Q4ii)

1. build max heap 
- for each non-leaf node (n/2 to 1), if child has larger value then swap 
- then we get largest node
```
i = 4 (value = 24): left child A[8] = 29  => swap A[4] and A[8]
A = [15,33,23,29,8,17,3,24]
i = 3 (value = 23): left child A[6] = 17, right child A[7] = 3 => no swap 
A = [15,33,23,29,8,17,3,24]
i = 2 (value = 33): left child A[4] = 29, right child A[5] = 8 => no swap 
A = [15,33,23,29,8,17,3,24]
i = 1 (value = 15): left child A[2] = 33, right child A[3] = 23 => swap A[1] and A[2]
A = [33,15,23,29,8,17,3,24]

Continue shift down 
i = 2 (value = 15): left child A[4] = 29, right child A[5] = 8 => swap A[2] and A[4]
A = [33,29,23,15,8,17,3,24]
i = 4 (value = 15): left child A[8] = 24 => swap A[4] and A[8] 
A = [33,29,23,24,8,17,3,15]
```

2. repeatedly removing the maximum
- repeat the dequeue process (remove root => fill in hole)
```
Extract 33: Swap 33 & 15. [15, 29, 23, 24, 8, 17, 3 | 33]
    Sift 15 down (swaps with 29, then 24)
    Heap becomes [29, 24, 23, 15, 8, 17, 3]
Extract 29: Swap 29 & 3. [3, 24, 23, 15, 8, 17 | 29, 33]
    Sift 3 down (swaps with 24, then 15)
    Heap becomes [24, 15, 23, 3, 8, 17]
Extract 24: Swap 24 & 17. [17, 15, 23, 3, 8 | 24, 29, 33]
    Sift 17 down (swaps with 23)
    Heap becomes [23, 15, 17, 3, 8]
Extract 23: Swap 23 & 8. [8, 15, 17, 3 | 23, 24, 29, 33]
    Sift 8 down (swaps with 17)
    Heap becomes [17, 15, 8, 3]
Extract 17: Swap 17 & 3. [3, 15, 8 | 17, 23, 24, 29, 33]
    Sift 3 down (swaps with 15)
    Heap becomes [15, 3, 8]
Extract 15: Swap 15 & 8. [8, 3 | 15, 17, 23, 24, 29, 33]
    Sift 8 down (no swap needed, 8 > 3)
    Heap becomes [8, 3]
Extract 8: Swap 8 & 3. [3 | 8, 15, 17, 23, 24, 29, 33]

Final Sorted Array: [3, 8, 15, 17, 23, 24, 29, 33]
```


---

### Implementaions 
[link](../../../ADTImplementation/PriorityQueue/)
