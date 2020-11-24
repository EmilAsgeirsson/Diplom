#include "Tree.h"

void Tree::insert(const pair<int, int> &x, Node *t)
{
    if( t == nullptr )
    {
        t = new Node{x};
    }
    else
    {
        for (Node* child : t->getChildren())
        {
            // Checks if the point is already any of the children.
            if(child->getPoint() == x)
            {
                return;
            }
        }
        t->addChild(new Node(x));
    }
}

bool Tree::contains(const pair<int, int> &x)
{
    return Tree::contains(x, mRoot);

}

bool Tree::contains(const pair<int, int> &x, Node *t)
{

}
