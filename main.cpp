#include <iostream>
#include "Tree.h"
#include <ctime>
using namespace std;

int main() {

    srand ((unsigned int) time(NULL));
    cout << "Hello, World!" << endl;

    Tree <int> * treeClaI = new Tree<int>(15);
    Tree <char> * treeClaS = new Tree<char>(15);

    //cout << (char)900 << endl;

    int searchVal = 0; //990

    cout << searchVal << " : " << treeClaI->searchIntInputNum(treeClaI->getRoot(), searchVal) << endl;
    cout << searchVal << " : " << treeClaS->searchIntInputNum(treeClaS->getRoot(), (char)searchVal) << endl;

    int arr[2] = {1,2};
    //cout << treeCla->getSomeVal(treeCla->getRoot(), arr) << endl;

    return 0;
}