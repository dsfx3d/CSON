#ifndef UTILS_H
#define UTILS_H

char mem[1024*1024*1024]; //1MB
int nexti = 0;

void* malloc(int t_size) {
    int i = nexti;
    nexti+=t_size;
    return &(mem[i]);
}

#endif
