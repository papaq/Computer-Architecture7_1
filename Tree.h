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

            if (width > 0)
            {
                child->bro = Tree::recursiveCreateChildren(depth, width-1);
            }

            std::cout << "x" << std::endl;
            return child;
        }
        return NULL;
    }

    Root<T>* autoCreateTree(void) {
        Root<T> *root = new Root<T>(40);

        int depth = 1;
        int nextWidth = 3;

        root->child = Tree::recursiveCreateChildren(depth, nextWidth);

        return root;
    };
    //int recursiveSearchInChildren(ChildTree* child, int val);

public:
    Root<T>* root = NULL;
    int a;

    Tree(){};

    void setRoot()
    {
        this->root = autoCreateTree();
    }

    //int searchIntInputNum(Root* root, int val);
};

#endif //TREEMAS_TREE_H
