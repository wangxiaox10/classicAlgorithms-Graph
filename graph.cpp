#include "graph.h"

#include <iostream>

using namespace std;

Graph::Graph(bool d){
    this->directed = d;
}

Graph::~Graph(){
}

void Graph::initialize_graph(bool directed){
    int i;
    this->nvertices = 0;
    this->nedges = 0;
    this->directed = directed;

    cout<<"continue1"<<endl;
    for( i=1; i<= MAXV; i++){
        this->degree[i] = 0;
        this->edges[i]= NULL;
    }
    cout<<"continue2"<<endl;
}

void Graph::read(bool directed){
    //this->directed = directed;
    cout<<"start reading graph"<<endl;

    //this->initialize_graph(directed);
    cout<<"finish initializing graph"<<endl;
    int m;
    cin>>this->nvertices>>m;

    cout<<"got #vertices and #edges"<<this->nvertices<<" "<<m<<endl;

    for( int i=1; i<=m; i++){
        int x;
        int y;
        cin>>x>>y;
        cout<<"inserting ("<<x<<","<<y<<")"<<endl;
        this->insert_edge(x, y, directed);
        cout<<"finish inserting ("<<x<<","<<y<<")"<<endl;
    }
}

void Graph::insert_edge(int x, int y, bool directed){
    edgenode *p = new edgenode(0, y, this->edges[x]);

    this->edges[x] = p;
    this->degree[x] ++;

    if( directed == false)
        insert_edge(y, x, true);
    else
        this->nedges++;
}

void Graph::print_graph(){
    edgenode *p;
    for( int i=1; i<= this->nvertices; i++){
        cout<<i<<":";
        p = this->edges[i];
        while( p!= NULL){
            cout<<p->y<<" ";
            p = p->next;
        }
        cout<<endl;
    }
}

void Graph::bfs(int root){
    this->initializeSearch();

    state[root] = discovered;
    parent[root] = 0;
    queue<int> Q;
    Q.push(root);
    while(!Q.empty()){
        int u = Q.front();
        Q.pop();
        cout<<"bsf via "<<u<<endl;
        edgenode *p;
        p = this->edges[u];
        while( p!= NULL){
            cout<<"("<<u<<","<<p->y<<")"<<endl;
            processEdge(u, p->y);
            if( state[p->y] == undiscovered){
                state[p->y] = discovered;
                parent[p->y] = u;
                Q.push(p->y);
            }
            p = p->next;
        }
        state[u] = processed;
        cout<<endl<<"Thanks, bye!"<<endl;
    }
}

void Graph::findPath(int start, int end){
    cout<<"start findign path from "<<start<<" to "<<end<<endl;
    if( start == end || parent[end] == 0){
        cout<<start<<" ";
    }else{
        findPath(start, parent[end]);
        cout<<end<<" ";
    }
}

void Graph::initializeSearch(){
    for( int i=1; i<=this->nvertices; i++){
        state[i] = undiscovered;
        parent[i] = -1;
    }
}

void Graph::findConnectedComponents(){
    initializeSearch();

    int countComponents = 0;
    for( int i=1; i<= this->nvertices; i++){
        if( state[i] == undiscovered){
            countComponents ++;
            cout<<"Component:"<<countComponents<<endl;
            this->bfs(i);
            cout<<endl;
        }
    }
    cout<<"There are "<<countComponents<<" components in the graph"<<endl;
}

void Graph::processEdge(int x, int y){
    if(color[x] == color[y]){
        cout<<"not bipartie due to:("<<x<<","<<y<<")."<<color[x]<<" "<<color[y]<<endl;
    }
    if( color[x] == uncolored){
        color[y] = uncolored;
    }else{
        color[y] = (Color)(5-color[x]);
    }
}



void Graph::initializeColor(){
    for( int i=1; i<=this->nvertices; i++)
        this->color[i] = uncolored;

}

void Graph::twoColor(){
    initializeColor();
    bool bipartie = true;

    initializeSearch();
    for( int i=1; i<=this->nvertices; i++){
        if(state[i] == undiscovered){
            color[i] = white;
            bfs(i);
        }
    }
}
