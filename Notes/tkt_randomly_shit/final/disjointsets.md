# Disjoint Sets

### Terminologies

##### Set
- Unbound collection of *distinct* elements
- Two sets are disjoint if they do not share any elements

---

### Properties 
- Classification of elements into different 'types' or 'class' (sets)
- Union: merge two sets
- Find: find which set does an element belongs to 

---

### Implementation details 
```c
// returns new disjoint sets (each element belongs to a different class)
DisjSetADT NewDisjointSets(void);
// union is a C keyword so can't use that
void SetUnion(DisjSetADT, int, int);
// find which set does an element belongs to
int Find(int, DisjSetADT);
```

```c
int Find(int X, DisjSetADT S) {
    // <= 0 indicate it is the head/root of the set
    if (S->class[X] <= 0) return X;
    // continue go up 
    return Find(S->class[X], S);
}
void SetUnion(DisjSetADT S, int X1, int X2) {
    int R1, R2;
    R1 = Find(X1, S); R2 = Find(X2, S); // find which set does X1X2 belongs to
    if (R1 != R2) S->class[R2] = R1; // merge 
}
```
- For better efficiency(as Find complexity is determined by tree height), we want to reduce height of tree 
- for now S->class[i] < 1 means it is head, and abs value is the height
```c
void SetUnion(DisjSetADT S, int X1, int X2) {
    int R1, R2;
    R1 = Find(X1, S); R2 = Find(X2, S); 
    if (R1 != R2) {
        if (-(S->class[R1]) < -(S->class[R2]))S->class[R1] = R2; // R2 is deeper, its height won't change
        else { // R1 is deeper
            if (S->class[R1] == S->class[R2])(S->class[R1])--; // height increase by 1
            S->class[R2] = R1;
        }
    }
}
```



---

### Exam questions 
- not exists
 

---

### Implementaions 
- [link](../../../ADTImplementation/DisjointSets)


---

##### Unrelated stuff
- DSU is commonly used in competitive programming, so there is many different versions of DSU (one of my favourite ds yay!, so oi-template has most of it)
- Path Compression + heuristic merging => O(a(n)) (where a is Ackermann function)
- Weighted DSU => maintain value on edge  
    - common application: maintain relationship between 3 group (%3 addition)
    - NOI2011 is a classical exampley
- Krsukal Reconstruction Tree => Build a binary tree during kruskal algoritm (MST) 
    - common application: given a graph, denote value of a path is maximum value of edge, find shortest path for u, v
    - value = the value of Lowest Common Ancestor (LCA) of u and v in the KRT
- DSU on tree
    - common application: each node in tree has a color, find each subtree has how many distinct color 
    - O(N^2) total, but we can keep the heavy son value for each subtree, and repeat do light son 
    - complexity become O(NlogN)
- DSU rollback
    - common application: ask for connectivity but has deletetion 
    - rely on Segment Tree Divide & Conquer 
    - idk that ask left god (!prayer)
    - appear on 25 HKOI training camp can cc (i haven't though)
