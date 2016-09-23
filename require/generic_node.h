/*
*
* dsfx3d_is_dope
*
*/
#ifndef GENERIC_NODE
#define GENERIC_NODE 

#include "common.h"

enum TYPE {BOOL=1,CHAR=1,INT=4,FLOAT=4,DOUBLE=8,STRING=4};
typedef char Byte;

/*
	Generic Node which can conain any data and can be represented in any basic data structure
	
	 * data : pointer to hold reference to data
	 
	 * type : enum for datatype
	 
	 * meta : double pointer to hold references to meta-data;
	 	index	desc
	 	 0		id
	 	 1		number of attr
	 	 
	 
	 * attr : double pointer to hold references to properties of data. to be used while structuring multiple nodes
	 	
*/
struct generic_node {
	Byte *data;
	TYPE type;
	
	void **meta;
	void **attr;
};

/*initilizes a node according to type
	param1: referebce to node
	param2: datatype for node*/
void setType(generic_node*, TYPE);

/*initilizes a node according to type
	param1: referebce to node
	param2: sizeof data for custom datatypes*/
void setType(generic_node*, int);

/*initilizes a node according to type
	param1: referebce to node
	param2: datatype for node
	param3: number of attr */
void define(generic_node*, TYPE);

/*initilizes a node according to type
	param1: referebce to node
	param2: size to reserve for node data
	param3: number of attr */
void define(generic_node*, int);

/* return number of attrs 
	param1: reference to node */
int getAttrCount(generic_node); 

/* reserves a space for new property*/
void addAttr(generic_node*);

void setType(generic_node* node, TYPE type) {
	node->type = type;
}/**/

void setType(generic_node* node, int size) {
	node->type = (TYPE)size;
}/**/

void define(generic_node* node, int type) {
	node->data = NULL;
	setType(node,type);
	
	node->meta = (void**)malloc(sizeof(void*)*2);
	
	node->meta[0] = malloc(sizeof(int));
	node->meta[1] = malloc(sizeof(int));
	*(int*)(node->meta[0]) = rand()% 9999+1000;
	*(int*)(node->meta[1]) = 0;	
	
	node->attr = NULL;
}/**/

int getID(generic_node node) {
	return *(int*)node.meta[0];
}

int getAttrCount(generic_node node) {
	return *(int*)node.meta[1];
}/**/


void setBool(generic_node* node, bool val) {
	node->data = (Byte*)malloc(BOOL);
	*(node->data) = val;
	node->type = BOOL;
}/**/

void setChar(generic_node* node, char val) {
	node->data = (Byte*)malloc(CHAR);
	*(node->data) = val;
	node->type = CHAR;
}/**/

void setInt(generic_node* node, int val) {
	node->data = (Byte*)malloc(INT);
	*(node->data) = val;
	node->type = INT;
}/**/

void setFloat(generic_node* node, float val) {
	node->data = (Byte*)malloc(FLOAT);
	*(node->data) = val;
	node->type = FLOAT;
}/**/

void setDouble(generic_node* node, double val) {
	node->data = (Byte*)malloc(DOUBLE);
	*(node->data) = val;
	node->type = DOUBLE;
}/**/

void setString(generic_node* node, string val) {
	node->data = (Byte*)malloc(sizeof(string));
	strcpy(node->data,&(val[0]));
	node->type = STRING;
}

bool getBool(generic_node node) {
	return *(bool*)(node.data);
}/**/

char getChar(generic_node node) {
	return *(char*)(node.data);
}/**/

int getInt(generic_node node) {
	return *(int*)(node.data);
}/**/

float getFloat(generic_node node) {
	return *(float*)(node.data);
}/**/

double getDouble(generic_node node) {
	return *(double*)(node.data);
}/**/

string getString(generic_node node) {
	return node.data;
}/**/


#endif
