/*
*
* dsfx3d_is_dope
*
*/
#include "require/common.h"
#include "require/generic_node.h"

enum {CUSTOM=10};
typedef generic_node Node;

struct S {
	int x;
};

int main() {
	Node node;
	define(&node, (int)INT);
//	setString(&node, "wtf");	
}
