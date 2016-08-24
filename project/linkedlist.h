#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "../include/node_2.h"

typedef struct generic_node ListNode;

int _numpro=1;

void push(ListNode**,int);

void push(ListNode** head, int val) {
    ListNode* n = new ListNode(_numpro);
    n->data = &val;
    n->dsize = sizeof(int);
    (n->properties)[0] = *head;
    *head = n;
}

ListNode* nodeAt(ListNode*head, int i) {
    for(int ii=1;ii<=i;ii++) {
        head = (head->properties)[0];
    }
    return head;
}

#endif // LINKED_LIST_H
