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
	 	 0		number of properties
	 
	 * properties : double pointer to hold references to properties of data. to be used while structuring multiple nodes
*/
struct generic_node {
	void* data;
	TYPE type;
	
	void **meta;
	void **properties;
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
	param3: number of properties */
void define(generic_node*, TYPE, int);

/*initilizes a node according to type
	param1: referebce to node
	param2: size to reserve for node data
	param3: number of properties */
void define(generic_node*, int, int);






void setType(generic_node* node, TYPE type) {
	node->type = type;
}/**/

void setType(generic_node* node, int size) {
	node->type = (TYPE)size;
}/**/

void define(generic_node* node, int type, int numofproperties) {
	node->data = NULL;
	setType(node,type);
	
	node->meta = (void**)malloc(sizeof(void*));
	node->properties = (void**)malloc(sizeof(void*)*numofproperties);
	
	node->meta[0] = malloc(sizeof(int));
	*(int*)(node->meta[0]) = numofproperties;
	
}/**/

#endif
