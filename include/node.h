#ifndef GENERIC_NODE
#define GENERIC_NODE

#include "utility.h"
//#include <stdlib.h>

/*                                                     .
    getbool(generic_node) always returns true  ???
                                                       */
    // how is bool represented in memory ?

struct generic_node {
    generic_node();

    char* key;
    void* data;
    int id;
    char* desc;
    int size;

    int level;

    generic_node *parent;
    int numchild, maxchild;
    generic_node* *childs;
};



//binds generic data to node
void binddata(generic_node*,void*,int);

//binds boolean to node
void setbool(generic_node*,bool);

//binds single char to node
void setchar(generic_node*,char);

//binds integer data to node
void setint(generic_node*,int);

//binds float data to node
void setfloat(generic_node*,float);

//binds double data to node
void setdouble(generic_node*,double);

//binds string data to node
void setstring(generic_node*,char*);

//binds Node with data pointer
void setGNode(generic_node*,char*);


int getint(generic_node);
char getchar(generic_node);
char* getstring(generic_node);
bool getbool(generic_node);
float getfloat(generic_node);
double getdouble(generic_node);

//RE
void allocchilds(generic_node***,int);
void addchild(generic_node*,generic_node*);

/**//**//**//**//**//**//**//**//**//**//**//**//**/
////////////////////////////////////////////////////
/**//**//**//**//**//**//**//**//**//**//**//**//**/
////////////////////////////////////////////////////
/**//**//**//**//**//**//**//**//**//**//**//**//**/
generic_node::generic_node() {
    id=generateId();
    key=desc=NULL;
    data=NULL;
    size=0;

    level=0;

    numchild=0;
    maxchild=1;
    childs = (generic_node**)malloc(2*sizeof(void*));
//    parent=lsibling=rsibling=favchild=NULL;
}/**/


void binddata(generic_node*node,void*data,int size) {
    /*SHOULD I ALLOCATE SPACE FOR NODE->DATA BEFORE COPYING OR DOES MEMCPY TAKES CARE OF IT ITSELF*/
    memcpy(&(node->data),&data,sizeof(void*));
    node->size=size;
}/**/


void setchar(generic_node* node, char c) {
    *(char*)node->data = c;
    node->size = sizeof(char);
}/**/


void setint(generic_node* node, int val) {
    *(int*)node->data = val;
    node->size = sizeof(int);
}/**/


void setstring(generic_node* node, char* s) {
    memcpy(node,s,strlen(s));
    node->size = strlen(s);
}/**/


void* getdata(generic_node node) {
    if(node.data!=NULL)
        return node.data;
}/**/


char getchar(generic_node node) {
    if(node.data!=NULL) return *(char*)node.data;
}/**/


int getint(generic_node node) {
    if(node.data!=NULL) return *(int*)node.data;
}/**/


char* getstring(generic_node node) {
    if(node.data!=NULL) return (char*)node.data;
}/**/


bool getbool(generic_node node) {
    if(node.data!=NULL) return (bool*)node.data;
}/**/


float getfloat(generic_node node) {
    if(node.data!=NULL) return *(float*)node.data;
}/**/


double getdouble(generic_node node) {
    if(node.data!=NULL) return *(double*)node.data;
}/**/


void allocchilds(generic_node* **childs, int size) {
    realloc(*childs,size*sizeof(generic_node*));
}/**/


void addchild(generic_node* parent, generic_node* child) {
    if(parent->numchild==parent->maxchild) allocchilds(&(parent->childs),parent->maxchild*2);

    parent->childs[parent->numchild] = child;
    child->parent = parent;
    child->level = parent->level+1;
    parent->numchild++;
}/**/

#endif
