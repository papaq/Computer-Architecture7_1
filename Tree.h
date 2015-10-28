//
// Created by solomon on 17.10.15.
//

#ifndef TREEMAS_TREE_H
#define TREEMAS_TREE_H

#include <iostream>
//#include <stddef.h>
//#include <stdlib.h>
//#include "ChildTree.h"
#include "Root.h"

template <typename T>
class Tree
{
private:
    ChildTree<T>* recursiveCreateChildren(int depth, int width)
    {
        if (depth>0)
        {
            ChildTree<T>* child = new ChildTree<T>(20); // rand()%100

            int nextWidth = 3; // rand()%4+1

            child->child = Tree::recursiveCreateChildren(depth-1, nextWidth);

            if (width > 1)
            {
                child->bro = Tree::recursiveCreateChildren(depth, width-1);
            }

            //std::cout << "x" << std::endl;
            return child;
        }
        return NULL;
    }

    Root<T>* autoCreateTree(void) {
        Root<T> *root = new Root<T>(20);

        int depth = 2;
        int nextWidth = 3;

        root->child = Tree::recursiveCreateChildren(depth, nextWidth);

        return root;
    };

    int recursiveSearchInChildren(ChildTree<T>* child, T val)
    {
        int counter = 0;
        if (child == NULL || val == NULL)
            return 0;

        counter += Tree::recursiveSearchInChildren(child->child, val);
        counter += Tree::recursiveSearchInChildren(child->bro, val);

        if (child->getVal() == val)
            counter++;

        return counter;
    }

public:
    Root<T>* root = NULL;

    Tree(){
        this->root = autoCreateTree();
    };

    int searchIntInputNum(Root<T>* root, T val)
    {
        if (root == NULL || val == NULL)
            return 0;

        ChildTree<T>* tempChild = root->child;
        int counter = 0;

        if (root->getVal() == val)
            counter++;

        counter += recursiveSearchInChildren(tempChild, val);

        return counter;
    }
};

#endif //TREEMAS_TREE_H
