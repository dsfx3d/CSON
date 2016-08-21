#include <iostream>
#include <stdlib.h>
#include <string.h>

#include "include/node.h"

using namespace std;

typedef generic_node Node;

struct Student {
    char* name;
    int id;
};

int main() {
    Node n,m,o,p,q,c;

    char ch = 'c';
    char* nd = strdup("dope");
    int md = 10;
    bool od = true;
    float pd = 10.0;
    double qd = 22.123;

    binddata(&c,&ch,sizeof(char));
    binddata(&n,nd,strlen(nd));
    binddata(&m,&md,sizeof(int));
    binddata(&o,&od,sizeof(bool));
    binddata(&p,&pd,sizeof(float));
    binddata(&q,&qd,sizeof(double));

    cout
        <<"supported primitive data types\n"
        <<"\n char   : "<<
        *(char*)getdata(c) << "\t\t" << sizeof(c) << "b"
        <<"\n string : "<<
        (char*)getdata(n) << "\t\t" << sizeof(n) << "b"
        <<"\n int    : "<<
        *(int*)getdata(m) << "\t\t" << sizeof(m) << "b"
        <<"\n bool   : "<<
        *(bool*)getdata(o) << "\t\t" << sizeof(o) << "b"
        <<"\n float  : "<<
        *(float*)getdata(p) << "\t\t" << sizeof(p) << "b"
        <<"\n double : "<<
        *(double*)getdata(q) << "\t" << sizeof(q) << "b"
        <<endl<<endl<<endl;
        ;

    cout<<"compatible with other data structures :\n\n *structs\n  Student{int id, int name}\n\n   ";

    Student dope, dsfx3d;

    dope.id=1327;
    dope.name= strdup("dope");

    dsfx3d.id=1327;
    dsfx3d.name=strdup("dsfx3d");

    Node cse4, gdope, gdsfx3d;

    binddata(&gdope,&dope,sizeof(Student));
    binddata(&gdsfx3d,&dsfx3d,sizeof(Student));

    addchild(&cse4,&gdope);
    addchild(&cse4,&gdsfx3d);

    for(int i=0; i<cse4.numchild; i++) {
        cout
        <<
        ((Student*)(cse4.childs[i])->data)->id \
        << "\t" <<
        ((Student*)(cse4.childs[i])->data)->name
        <<"\t" <<
        "\n   ";
    }

}
