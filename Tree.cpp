//
// Created by solomon on 17.10.15.
//

#include "Tree.h"

Tree::Root *Tree::autoCreateTree() {
    Root *root = new Root();

    int depth = 20;

    root->child = Tree::recursiveCreateChildren(depth);
    root->val = 50;

    return root;
}

Tree::ChildTree *Tree::recursiveCreateChildren(int i) {
    if (i>0)
    {
        ChildTree* child = new ChildTree();
        child->val = rand()%100;
        int c = child->val;
        ChildTree* brother;
        int width = rand()%4+1;

        child->child = Tree::recursiveCreateChildren(i-1);

        for (int j = 0; j < width-1; ++j) {
            brother = new ChildTree();
            brother->child = Tree::recursiveCreateChildren(i-1);
            child->bro = brother;
        }

        return child;
    }
    return NULL;
}

int Tree::searchIntInputNum(Tree::Root *root, int val) {
    if (root == NULL || val == NULL)
        return 0;

    Tree::ChildTree* tempChild = root->child;
    int counter = 0;

    if (root->val == val)
        counter++;

    counter += recursiveSearchInChildren(tempChild, val);

    return counter;
}

int Tree::recursiveSearchInChildren(Tree::ChildTree *child, int val) {
    int counter = 0;
    if (child == NULL || val == NULL)
        return 0;

    counter += Tree::recursiveSearchInChildren(child->child, val);
    counter += Tree::recursiveSearchInChildren(child->bro, val);

    if (child->val == val)
        counter++;

    return counter;
}
