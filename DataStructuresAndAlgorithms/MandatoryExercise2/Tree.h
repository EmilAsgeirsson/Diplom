#ifndef TREE_H
#define TREE_H
#include "Node.h"

using namespace std;

class Tree
{
public:
    Tree();
    Tree(Node *start, pair<int,int> knightEndPosition);

    void insertChild(Node *parent); 

    void printSteps();

private:
    vector<Node*> mGeneralTree;
    pair<int,int> mKnightEndPos;
};




#endif // TREE_H
