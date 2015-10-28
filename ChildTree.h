//
// Created by solomon on 27.10.15.
//

#ifndef TREEMAS_CHILDTREE_H
#define TREEMAS_CHILDTREE_H

#include <stdlib.h>

template <typename valT>
class ChildTree
{
private:
    valT val;
public:
    ChildTree<valT> * child = NULL;
    ChildTree<valT> * bro = NULL;

    ChildTree(valT val)
    {
        this->val = val;
    }

    ~ChildTree()
    {
        delete val;
        delete bro;
        delete child;
    }

    valT getVal()
    {
        return this->val;
    }
};

#endif //TREEMAS_CHILDTREE_H
