#include <iostream>
#include "Tree.h"
#include <ctime>
using namespace std;

int main() {

    srand ((unsigned int) time(NULL));
    cout << "Hello, World!" << endl;

    Tree <int> * treeCla = new Tree<int>();
    //treeCla->setRoot();
    int searchVal = 202;
    cout << searchVal << ":" << treeCla->searchIntInputNum(treeCla->root, searchVal);

    return 0;
}