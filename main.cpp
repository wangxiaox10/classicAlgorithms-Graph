#include <iostream>
#include "graph.h"
using namespace std;



int main()
{
    cout << "Hello World!" << endl;
    bool directed = false;
    Graph* g = new Graph(directed);

    g->initialize_graph(directed);
    g->read(directed);
    g->print_graph();
    g->bsf(1);
    g->findPath(1, 4);
    g->findConnectedComponents();
    cout << "Hello World!" << endl;
    return 0;
}

