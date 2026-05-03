# Minimum spanning tree

### Terminologies

##### Spanning tree
- Spanning tree of a graph is a tree that includes all the nodes in the graph
- Exist only if the graph is connected
- n nodes, n-1 edges 

---

### Properties 
- Spanning tree
- Lowest total cost

##### Prim's Algorithm
- Implementation is almost same as dijkstra 
- Start with random node, push adjacent node into heap 
- Keep visit with the smallest value 

##### Kruskal's Algorithm 
- Sort the edges from smallest to largest 
- For each edge, if U-V is connected then skip this edge, else add this to MST
- Support by disjoint sets

---

### Exam questions 
1. Find a minimum spanning tree of the undirected graph, using Kruskal's algorithm. You should show each step clearly. (22 Q3c)
2. Find a minimum spanning tree for the graph below, using Prim's algorithm. You should show each step clearly. (19 Q2)
 

---

### Implementaions 
- not exists


---

##### Unrelated stuff
- exist third algor for finding MST, boruvka 
    - welp i also just know that 