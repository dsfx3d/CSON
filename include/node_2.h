#ifndef GENERIC_NODE_2
#define GENERIC_NODE_2

struct generic_node;
struct gn_map;

//gn_map
gn_map* get(generic_node*,std::string);
//generic_node
void define(int,int);


/**-------------------------------------------------------------------------------**/

struct gn_map {
    std::string key;
    generic_node* ptr;
};
struct generic_node {
    generic_node();
    void* data;
    int dsize, msize;

    gn_map *pmap;
};

void set(generic_node* node, std::string key, generic_node* ptr) {
    gn_map* n = get(node, key);
    n->ptr = ptr;
}

gn_map* get(generic_node* node, std::string key) {
    for(int i=0; i<node->msize; i++)
        if(((node->pmap)[i]).key == key)
            return &((node->pmap)[i]);
    return NULL;
}

generic_node::generic_node() {
    data = NULL;
    pmap = NULL;
    dsize = msize = 0;
}

generic_node* generate(std::string arr[], int numptr) {
    generic_node *node = new generic_node;
    node->pmap = (gn_map*)malloc(numptr*sizeof(gn_map));
    node->msize;

    for(int i=0; i<numptr; i++) {
    //    ((node->pmap)[i]).key = &((arr[i])[0]);
    }
    return node;
}/**/

void binddata(generic_node*node,void*data,int size) {
    /*SHOULD I ALLOCATE SPACE FOR NODE->DATA BEFORE COPYING OR DOES MEMCPY TAKES CARE OF IT ITSELF*/
    memcpy(&(node->data),&data,sizeof(void*));
}/**/
#endif
