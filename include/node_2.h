#ifndef GENERIC_NODE_2
#define GENERIC_NODE_2

struct generic_node;

struct generic_node {
    void* data;
    int dsize,msize;

    gn_map* properties;
}

//generic_node
void define(int,int);

#endif
