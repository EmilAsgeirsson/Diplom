#include "Tree.h"
#include "iostream"

using namespace std;

//build tree from first point
Tree::Tree(Node *startPos, pair<int,int> knightEndPosition)
    : mKnightEndPos(knightEndPosition)
{
    mGeneralTree.push_back(startPos);
}

void Tree::insertChild(Node *point)
{
    mGeneralTree.push_back(point);
}

void Tree::printSteps()
{
    vector<Node*> mSteps{mGeneralTree.back()};

    cout << "Steps from end to begin: " << endl;
    for (unsigned i = 0; mSteps[i]->getParent() != nullptr; i++)
    {
        cout << "Step: " << mSteps.size() << " - point: [" << mSteps[i]->getPoint().first <<  "," << mSteps[i]->getPoint().second << "]" << std::endl;
        mSteps.push_back(mSteps[i]->getParent());
    }
    return;
}
