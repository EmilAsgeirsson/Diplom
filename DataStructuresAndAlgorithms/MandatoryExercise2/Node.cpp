#include "Node.h"
#include "iostream"

Node::Node(pair<int, int> point)
    :mPoint{point}, mDist{0}, mParent(nullptr), mChildren(vector<Node*> {})
{

}

Node::Node(pair<int, int> point, Node *parent)
    : mPoint(point), mParent(parent)
{
    if(parent==nullptr)
    {
        mDist=0;
    }
    else
    {
        mDist=parent->getDist()+1;
    }    
}

void Node::addChild(Node *child)
{
    mChildren.push_back(child);
}

pair<int, int> Node::getPoint()
{
    return mPoint;
}

Node *Node::getParent()
{
    return mParent;
}

int Node::getDist()
{
    return mDist;
}

void Node::setPoint(pair<int, int> point)
{
    mPoint = point;
}


