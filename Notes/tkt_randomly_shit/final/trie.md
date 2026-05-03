# Trie

### Properties 
- Binary tree
- Used for coding prefix code (0: go left, 1: go left)
- leave is the characters 

##### Huffman's algorithm
- Greedy pick least frequent char 
- Must be a full tree

---

### Exam questions 
1. Find the optimal trie for encoding the following sentence. (19 Q1)
- Count the frequencies of each char 
- Each time pick 2 least frequent node
- Finish!
 

---

### Implementaions 
- not exists


---

##### Unrelated stuff
- this trie is not the one used in competitive programming 

- given a disjoint set union (DSU), you try to build a binary tree on the DSU then the tree is called kruskal reconstruction tree (KRT)
- trie is kinda kruskal reconstruction tree
- because for kruskal , each time you will pick the smallest edge , while for trie you are picking two smallest frequency node
