#ifndef GENERIC_NODE_2
#define GENERIC_NODE_2

#include "utils.h"
#include "gn_map.h"

struct generic_node;

struct generic_node {
    generic_node();
    generic_node(int);
    void* data;
    int dsize,msize;

    generic_node** properties;
};

generic_node::generic_node() {
    data = NULL;
    dsize = msize = NULL;
}

generic_node::generic_node(int __numofproperties) {
    properties = (generic_node**)malloc(__numofproperties*sizeof(generic_node*));
    msize = __numofproperties;
    for(int i=0; i<msize; i++) {
        properties[i]=NULL;
    }
}


/**-------------------------------------------------------------------------------**/
#endif
