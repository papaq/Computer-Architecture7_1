//
// Created by solomon on 17.10.15.
//

#include "Tree.h"
// #include <iostream>

/*template <typename T>
Root<T>* Tree<T>::autoCreateTree() {
    Root<T> *root = new Root<T>(40);

    int depth = 5;
    int nextWidth = 3;

    root->child = Tree<T>::recursiveCreateChildren(depth, nextWidth);

    return root;
    }

template <typename  T>
ChildTree<T>* Tree<T>::recursiveCreateChildren(int depth, int width) {
    if (depth>0)
    {
        ChildTree<T>* child = new ChildTree<T>(20); // rand()%100

        //int c = child->getVal();
        //ChildTree* brother;

        int nextWidth = 3; // rand()%4+1

        child->child = Tree::recursiveCreateChildren(depth-1, nextWidth);

        if (width > 0)
        {
            child->bro = Tree::recursiveCreateChildren(depth, width-1);
        }

        /*
        for (int j = 0; j < width; ++j) {
            brother = new ChildTree();
            brother->child = Tree::recursiveCreateChildren(depth-1, nextWidth);
            child->bro = brother;
        }
        //
        //std::cout << "x" << std::endl;
        return child;
    }
    return NULL;
}
*/

/*
int Tree::searchIntInputNum(Root *root, int val) {
    if (root == NULL || val == NULL)
        return 0;

    ChildTree* tempChild = root->child;
    int counter = 0;

    if (root->val == val)
        counter++;

    counter += recursiveSearchInChildren(tempChild, val);

    return counter;
}

int Tree::recursiveSearchInChildren(ChildTree *child, int val) {
    int counter = 0;
    if (child == NULL || val == NULL)
        return 0;

    counter += Tree::recursiveSearchInChildren(child->child, val);
    counter += Tree::recursiveSearchInChildren(child->bro, val);

    if (child->val == val)
        counter++;

    return counter;
}
*/