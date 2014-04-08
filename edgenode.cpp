#include "edgenode.h"

edgenode::edgenode(){
   // this->state = undiscovered;
   // this->parent = NULL;
}

edgenode::edgenode(int w, int y_node, edgenode* n){

    this->weight = w;
    this->y = y_node;
    this->next = n;

}

edgenode::~edgenode(){

}
