#ifndef GRAPH_H
#define GRAPH_H
#include "edgenode.h"
#include <queue>
#define MAXV 1000  // maximum number of vertices

class Graph{
    int nvertices;
    int nedges;
    bool directed;
    edgenode* edges[MAXV+1];
    int degree[MAXV+1];
    State state[MAXV+1];
    int parent[MAXV+1];
    Color color[MAXV+1];

public:
    Graph(bool d);
    ~Graph();

    void initialize_graph(bool directed);
    void read(bool directed);
    void insert_edge(int x, int y, bool directed);
    void print_graph();
    void bsf(int root); // traverse the graph setting node p as root
    void findPath(int start, int end);
    void initializeSearch();
    void findConnectedComponents();
    void initializeColor();
    void twoColor();
};

#endif // GRAPH_H
