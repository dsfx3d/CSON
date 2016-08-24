#include <iostream>
#include <string.h>

#include "project/linkedlist.h"

using namespace std;

typedef ListNode Node;

int main(int argc, char* argv[]) {
    Node *list=NULL;
    for(int i=0; i<5; i++) {
        push(&list,i);
    }
}

