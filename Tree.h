//
// Created by solomon on 17.10.15.
//

#ifndef TREEMAS_TREE_H
#define TREEMAS_TREE_H
#include <stddef.h>
#include <stdlib.h>

class Tree
{
private:
    struct ChildTree
    {
        int val = NULL;
        ChildTree* child = NULL;
        ChildTree* bro = NULL;
    };

    struct Root
    {
        int val = 50;
        ChildTree* child = NULL;
    };

    ChildTree* recursiveCreateChildren(int left);

    Root* autoCreateTree();

    int recursiveSearchInChildren(ChildTree* child, int val);

public:
    Root* root = NULL;

    Tree()
    {
        this->root = autoCreateTree();
    }

    int searchIntInputNum(Root* root, int val);
};

#endif //TREEMAS_TREE_H
