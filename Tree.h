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

template<typename T>
class Tree{
private:
    Root<T> *root = NULL;
    int treepth = 2;

    ChildTree<T> *recursiveCreateChildren(int depth, int width) {
        if (depth > 0) {
            ChildTree<T> *child = new ChildTree<T>((T)0); // ((100-depth)*10 + (3-width)); // (2); // rand()%100
            //std::cout << child->getVal() << std::endl;
            int nextWidth = 3; // rand()%4+1

            child->child = Tree::recursiveCreateChildren(depth - 1, nextWidth);

            if (width > 1) {
                child->bro = Tree::recursiveCreateChildren(depth, width - 1);
            }

            //std::cout << "x" << std::endl;
            return child;
        }
        return NULL;
    }

    Root<T> *autoCreateTree(void) {
        Root<T> *root = new Root<T>((T)0);
        //std::cout << root->getVal() << std::endl;
        int nextWidth = 3;

        root->child = Tree::recursiveCreateChildren(treepth, nextWidth);

        return root;
    };

    int recursiveSearchInChildren(ChildTree<T> *child, T val) {
        int counter = 0;
        if (!child)
            return 0;

        counter += Tree::recursiveSearchInChildren(goDown(child), val);
        counter += Tree::recursiveSearchInChildren(goRight(child), val);

        if (child->getVal() == val)
            counter++;

        return counter;
    }

    template <typename G>
    ChildTree<T> *goDown(G *root) { //Root<T>
        return root->child;
    }

    /*
    ChildTree<T> *goDown(ChildTree<T> *child) {
        return child->child;
    }
    */

    ChildTree<T> *goRight(ChildTree<T> *child) {
        return child->bro;
    }
    
    ChildTree<T> *navigateToMyChild(ChildTree<T> *child, int childNum) {
        if (!checkIfChild(child) && checkIfPos(childNum))
            return NULL;
        if (!(child = goAllRight(goDown(child), childNum-1)))
            return NULL;
        return child;
    }

    ChildTree<T> *goAllRight(ChildTree<T> *child, int broNum) {
        for (int i = 0; i < broNum; ++i) {
            if (!checkIfBro(child))
                return NULL;
            child = goRight(child);
        }
        return child;
    }

    bool checkIfPos(int val){
        return val > 0;
    }

    bool checkIfBro(ChildTree<T> *child) {
        return child->bro != NULL;
    }

    bool checkIfChild(ChildTree<T> *child) {
        return child->child != NULL;
    }
    
public:
    Root<T> * getRoot(){
        return root;
    }

    Tree() {
        this->root = autoCreateTree();
    };

    Tree(int depth) {
        treepth = depth;
        root = autoCreateTree();
    };

    int searchIntInputNum(Root<T> *root, T val) {
        if (root == NULL)
            return 0;

        ChildTree<T> *tempChild = goDown(root);
        int counter = 0;

        if (root->getVal() == val)
            counter++;

        counter += recursiveSearchInChildren(tempChild, val);

        return counter;
    }

    T getSomeVal(Root<T> *root, int arr[]) {
        if (root && goDown(root) && arr && checkIfPos(arr[0])) {
            int len = (sizeof((arr))/sizeof((arr[0])));
            ChildTree<T> *child = goDown(root);
            if (!(child = goAllRight(child, arr[0]-1)))
                return -1;
            for (int i = 1; i < len; ++i)
                if (!(child = navigateToMyChild(child, arr[i])))
                    return -1;
            return child->getVal();
        }
        return -1;
    }
};

#endif //TREEMAS_TREE_H
