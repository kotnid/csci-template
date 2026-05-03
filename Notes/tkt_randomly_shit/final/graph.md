# Graph

### Terminologies
##### graph
- Degree: number of edges connected to a node
    - if the edges is directed then can be seperated into indegree/ outdegree
- Adjacent: A is adjacent to B when exist an edges B->A
- Path: line connect u to v 
    - length = number of edges passed
    - simple path: path that contains no duplicated nodes (except the first and last)
- Cycle: path that starts and ends at the same node
    - simple cylce: cycle that contains no duplicated nodes

##### Type of graphs
- Cyclic graph: graph contains cycle
- Acyclic graph: graph doesn't contains cycle
- Directed Acyclic graph(DAG): directed graph + not contains cycle
- Complete graph: every pair of nodes is connected by an edge
- Connected graph: only one connected component (every node can visit another node by edge)
- Strongly connected graph: directed + path connect every pairs of node
- Weakly connected graph: directed + connected if remove direction of edges (transform into undirected graph)

##### Topological sort of DAG
- Ordering of vertices in a directed acylic graph
    - if exist path U to V, then U will appear first in ordering
```
S = {set of nodes which indegree = 0}
while S is not empty:
    u = front(S)
    pop(S)
    print u
    for every vertex v which is adjacent to u:
        indegree[v]--;
        if indegree[v] is 0:
            Push v into S
```

##### Depth-First Search
- it can be implemented by stack 
```
Algorithm dfs(int u):
    visited[u] = 1;
    for every vertex v which is adjacent to u:
        if visisted[v] is 0:
            dfs(v)
```

###### Breadth-First Search
- it can be implemented by queue
- if graph is unweighted(all edges have same value), we can use BFS to find shortest path
- visit all nodes one hop away => visit all nodes two hop away (which is not visited) => ... 
```
Algorithm bfs(int u):
    queue Q 
    Push u into Q
    while Q is not empty:
        u = first element in Q 
        pop Q 
        for every vertex v which is adjacent to u:
            if visited[v] = 0:
                Push v into Q
                visited[v] = 1
```

##### Dijsktra's algorithm 
- for finding shortest path in weighted graph



---

### Implementations explanation
- Adjacency matrices: use a 2d array store edge value of 2 nodes (inf if edge not exists)
    - space requirement large
- Ajacency lists: for each node create a list storing adjacent nodes
    - standard way to represent
    - can implement by listADT


---

### Exam questions 
- Usually given a directed graph, ask you to run dijkstra once (22 Q3a, 20 Q1)
- Find a topological order for a DAG (18 Q9)
- Dry run DFS/ BFS (21 Q6ii)
- building DFS tree on a direct graph, although i think won't test now? (21 Q6iii)  

1. Given the below prev array after a BFS traversal from source v2, draw the BFS tree rooted at v2. (21 Q6i)
```
      v1 v2  v3 v4 v5 v6 v7
prev: v2 nil v1 v1 v6 v2 nil
```
```
          v2
        /    \
      v1      v6
     /  \       \
   v3    v4      v5
```



---

### Implementaions 
- not exists


---

##### Unrelated stuff
- dijsktra is my favourite algor : > 
- the lecture notes is not clear, in fact you cannot use dijsktra in weighted graph which has negative edge
    - why? because dijsktra is a greedy algorithm (each pick visit node with smallest value)
    - so it assume visited node has fixed value already 
    - but if negative edge exists, then the assumption is wrong 
    - maybe mentioned during lesson? idk as i never attend 
- BFS not only work on unweighted graph, if edges only has 2 values (0 and X), then we can use 01BFS    
    - support by dequeue (double end queue)
    - faster then dijkstra! 
- How can we find the Strongly Connected Component(SCC) in a directed graph? Tarjan algorithm!
    - can see see the code [link](https://github.com/kotnid/oi-template/tree/main/graph)
