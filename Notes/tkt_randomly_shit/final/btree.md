# B Tree

### Properties 
- order (M): max children/ max key
- root: 2 and M children
- nonleaf node: M/2 - M children
- leaf nodes same depth and contains keys
- number of keys in a leaf: M/2 - M

##### Insertion
- Only difficulty arises when the node accepting the new key already has M keys.
- The node is then split into two nodes with ceil((M+1)/2) and floor((M+1)/2) keys, respectively.
- Check the parent, and split the parent if it already has M children.
- If the root is split, create a new root

---

### Exam questions 
- Same as asm4 (19 Q7)
- No more!

---

### Implementaions 
- not exists