/*
*
* dsfx3d_is_dope
*
*/
#ifndef GENERIC_NODE
#define GENERIC_NODE 

enum TYPE {BOOL=1,CHAR=1,INT=4};

/*
	Generic Node which can conain any data and can be represented in any basic data structure
	
	 * data : pointer to hold reference to data
	 
	 * type : enum for datatype
	 
	 * meta : double pointer to hold references to meta-data;
	 	index	desc
	 	 0		number of attributes
	 
	 * properties : double pointer to hold references to properties of data. to be used while structuring multiple nodes
*/
struct generic_node {
	void* data;
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
	
	node->meta = (void**)malloc(sizeof(void*));
	node->attr = (void**)malloc(sizeof(void*));
	
	node->meta[0] = malloc(sizeof(int));
	*(int*)(node->meta[0]) = 1;
	
}/**/

int getAttrCount(generic_node node) {
	return *(int*)node.meta[0];
}/**/

#endif
