#include <iostream>
#include <stdlib.h>
#include <string.h>
#include "include/gn_map.h"

using namespace std;

typedef gn_map GMap;

int main(int argc, char* argv[]) {

    int i=10;
    GMap *map = new GMap("next");
    setvalue(map, &i, sizeof(int));

    cout << *(int*)getvalue(map);

}
