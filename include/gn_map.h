#ifndef GN_MAP
#define GN_MAP

struct gn_map {
    gn_map(char*);

    char* key;
    void* value;
    int vsize;
};

void setvalue(gn_map*,void*,int);
void* getvalue(gn_map*);
void clr(gn_map* map);


gn_map::gn_map(char* key) {
    gn_map* map = (gn_map*)malloc(sizeof(gn_map));
    map->key = key;
    map->value = NULL;
}

void setvalue(gn_map* map, void* value, int vsize) {
    map->value = value;
    map->vsize = vsize;
}

void* getvalue(gn_map* map) {
    return map->value;
}

gn_map* mget(gn_map* map, char* key, int msize) {
    for(int i=0; i<msize; i++) {
        if((map[i]).key == key) {
            return map+i;
        }
    }
    return NULL;
}

void mset(gn_map* map, char* key, void* v, int vsize, int msize) {
    gn_map* m = mget(map, key, msize);
    m->value = v;
    m->vsize = vsize;
}

#endif // GN_MAP
