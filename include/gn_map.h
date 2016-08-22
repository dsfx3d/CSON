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

#endif // GN_MAP
