#ifndef NODE_H
#define NODE_H
#include <vector>

using namespace std;


class Node
{
public:
    Node(pair<int,int> point);
    Node(pair<int,int> point, Node* parent);

    // Getter methods
    pair<int,int> getPoint();
    Node* getParent();
    int getDist();

    // Set point
    void setPoint(pair<int,int> point);

    // Add child to vector
    void addChild(Node* child);


private:
    pair<int, int> mPoint;
    int mDist;
    Node* mParent;
    vector<Node*> mChildren;
};

#endif // NODE_H
