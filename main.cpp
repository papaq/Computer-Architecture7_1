#include <iostream>
#include "Tree.h"
#include <ctime>
#include <chrono>
using namespace std;

int main() {

    srand ((unsigned int) time(NULL));
    cout << "Hello, World!" << endl;

    auto begin = std::chrono::high_resolution_clock::now();

    Tree <int> * treeClaI = new Tree<int>(15);
    //Tree <char> * treeClaS = new Tree<char>(15);

    int searchVal = 0; //990

    cout << searchVal << " : " << treeClaI->searchIntInputNum(treeClaI->getRoot(), searchVal) << endl;
    //cout << searchVal << " : " << treeClaS->searchIntInputNum(treeClaS->getRoot(), (char)searchVal) << endl;

    //int arr[2] = {1,2};
    //cout << treeCla->getSomeVal(treeCla->getRoot(), arr) << endl;

    auto end = chrono::high_resolution_clock::now();
    double time = chrono::duration_cast<std::chrono::nanoseconds>(end-begin).count() / 1000000000.0;
    cout << "Worked for " <<  time << " s" << endl;

    return 0;
}