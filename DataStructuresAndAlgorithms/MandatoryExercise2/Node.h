#ifndef NODE_H
#define NODE_H
#include <vector>

using namespace std;


class Node
{
public:
    Node();
    Node(pair<int,int> point);
    Node(pair<int,int> point, vector<Node*> children);

    Node *newNode(pair<int,int> key);

    // Getter methods
    pair<int,int> getPoint();
    vector<Node*> getChildren();

    // Set point
    void setPoint(pair<int,int> point);

    // Add child to vector
    void addChild(Node* child);


private:
    pair<int, int> mPoint;
    vector<Node*> mChildren;
};

#endif // NODE_H
