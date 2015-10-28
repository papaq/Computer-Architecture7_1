#include <iostream>
#include "Tree.h"
#include <ctime>
using namespace std;

int main() {

    srand ((unsigned int) time(NULL));
    cout << "Hello, World!" << endl;

    Tree <int> * treeCla = new Tree<int>();
    treeCla->setRoot();
    //cout << "50:" << treeCla->searchIntInputNum(treeCla->root, 50);

    return 0;
}