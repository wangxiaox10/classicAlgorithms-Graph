#ifndef EDGENODE_H
#define EDGENODE_H
#include <stddef.h>  //define NULL

enum State{undiscovered = 1, discovered, processed};
enum Color{uncolored = 1, white, black };

class edgenode{
public:
    int y;
    int weight;
    edgenode* parent;
    edgenode* next;
    State state;
public:
    edgenode();
    edgenode(int w,int y_node, edgenode* n);
    ~edgenode();
};

#endif
