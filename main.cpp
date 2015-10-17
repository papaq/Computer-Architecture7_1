#include <iostream>
#include "Tree.h"
using namespace std;

int main() {
    cout << "Hello, World!" << endl;

    Tree* treeCla = new Tree();
    cout << "5200:" << treeCla->searchIntInputNum(treeCla->root, 5200);

    return 0;
}