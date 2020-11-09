#include <iostream>
#include "BinarySearchTree.h"
#include "AvlTree.h"
#include <vector>

using namespace std;

int main()
{
    //vector<int> keys {1, 2, 3, 4, 5, 6, 7,8};
    vector<int> keys {9, 12, 5, 6, 1};

    BinarySearchTree bTree;

    for (unsigned i = 0; i < keys.size(); i++)
    {
        bTree.insert(keys[i]);
    }

    cout << "print Tree" << endl;
    bTree.printTree();

    cout << "\npreorder" << endl;
    bTree.preorderTraversal();

    cout << "\ninorder" << endl;
    bTree.inorderTraversal();

    cout << "\npostorder" << endl;
    bTree.postorderTraversal();

    cout << "\nlevelorder" << endl;
    bTree.levelorderTraversal();
    cout << endl;


    return 0;
}
