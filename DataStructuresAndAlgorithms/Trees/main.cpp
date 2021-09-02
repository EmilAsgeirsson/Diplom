#include <iostream>
#include "BinarySearchTree.h"
#include "AvlTree.h"
#include <vector>

using namespace std;

int main()
{
    //vector<int> keys {25, 20, 36, 10, 22, 30, 40, 5, 12, 28, 38, 48, 1, 8, 15, 45, 50};
    //vector<int> keys {1, 2, 3, 4, 5, 6, 7,8};
    //vector<int> keys {5, 2, 8, 1, 4, 3};
    //vector<int> keys {9, 12, 5, 6, 1};
    vector<int> keys {17,21,23,44,32,65,38,56,46,69,33,77,67,56,39,61,60,62,50,71};
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
