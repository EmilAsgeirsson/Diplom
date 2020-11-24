#ifndef TREE_H
#define TREE_H
#include <vector>
#include "Node.h"

using namespace std;

class Tree
{
public:
    Tree();

    void insert(const pair<int,int> &x, Node *t);
    bool contains(const pair<int,int> &x);


private:
    Node* mRoot;

    bool contains(const pair<int,int> &x, Node* t);
};




#endif // TREE_H
