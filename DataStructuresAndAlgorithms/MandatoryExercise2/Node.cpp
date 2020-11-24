#include "Node.h"

Node::Node()
    :mPoint{}, mChildren(vector<Node*> {})
{

}

Node::Node(pair<int, int> point)
    :mPoint{point}, mChildren(vector<Node*> {})
{

}

Node::Node(pair<int, int> point, vector<Node *> children)
    :mPoint{point}, mChildren(children)
{

}

Node *Node::newNode(pair<int, int> key)
{
    Node *temp = new Node();
    temp->mPoint = key;
    return temp;
}

pair<int, int> Node::getPoint()
{
    return mPoint;
}

vector<Node *> Node::getChildren()
{
    return mChildren;
}

void Node::setPoint(pair<int, int> point)
{
    mPoint = point;
}

void Node::addChild(Node *child)
{
    mChildren.push_back(child);
}
