#include "BinarySearchTree.h"

BinarySearchTree::BinarySearchTree() : root{ nullptr }
{
}


BinarySearchTree::BinarySearchTree(const BinarySearchTree & rhs) : root{ nullptr }
{
    root = clone(rhs.root);
}


BinarySearchTree::BinarySearchTree(BinarySearchTree && rhs) : root{ rhs.root }
{
    rhs.root = nullptr;
}

BinarySearchTree::~BinarySearchTree()
{
    makeEmpty();
}

const int & BinarySearchTree::findMin() const
{
    if (isEmpty())
        return -1;
    return findMin(root)->element;
}


const int & BinarySearchTree::findMax() const
{
    if (isEmpty())
        return -1;
    return findMax(root)->element;
}

bool BinarySearchTree::contains(const int & x) const
{
    return contains(x, root);
}

bool BinarySearchTree::isEmpty() const
{
    return root == nullptr;
}

void BinarySearchTree::printTree() const
{
    if (isEmpty())
        cout << "Empty tree" << endl;
    else
        printTree(root);
}

void BinarySearchTree::makeEmpty()
{
    makeEmpty(root);
}


void BinarySearchTree::insert(const int & x)
{
    insert(x, root);
}

void BinarySearchTree::insert(int && x)
{
    insert(std::move(x), root);
}

void BinarySearchTree::remove(const int & x)
{
    remove(x, root);
}

// Preorder means that we print the node before the childs.
void BinarySearchTree::preorderTraversal()
{
    preorderTraversal(root);
}

void BinarySearchTree::inorderTraversal()
{
    inorderTraversal(root);
}

void BinarySearchTree::postorderTraversal()
{
    postorderTraversal(root);
}

void BinarySearchTree::levelorderTraversal()
{
    printLevelOrder(root);
}

void BinarySearchTree::insert(const int & x, BinaryNode * & t)
{
    if (t == nullptr)
        t = new BinaryNode{ x, nullptr, nullptr };
    else if (x < t->element)
        insert(x, t->left);
    else if (t->element < x)
        insert(x, t->right);
    else
        ;  // Duplicate; do nothing
}


void BinarySearchTree::insert(int && x, BinaryNode * & t)
{
    if (t == nullptr)
        t = new BinaryNode{ std::move(x), nullptr, nullptr };
    else if (x < t->element)
        insert(std::move(x), t->left);
    else if (t->element < x)
        insert(std::move(x), t->right);
    else
        ;  // Duplicate; do nothing
}

void BinarySearchTree::remove(const int & x, BinaryNode * & t)
{
    if (t == nullptr)
        return;   // Item not found; do nothing
    if (x < t->element)
        remove(x, t->left);
    else if (t->element < x)
        remove(x, t->right);
    else if (t->left != nullptr && t->right != nullptr) // Two children
    {
        t->element = findMin(t->right)->element;
        remove(t->element, t->right);
    }
    else
    {
        BinaryNode *oldNode = t;
        t = (t->left != nullptr) ? t->left : t->right;
        delete oldNode;
    }
}

BinaryNode * BinarySearchTree::findMin(BinaryNode *t) const
{
    if (t == nullptr)
        return nullptr;
    if (t->left == nullptr)
        return t;
    return findMin(t->left);
}

BinaryNode * BinarySearchTree::findMax(BinaryNode *t) const
{
    if (t != nullptr)
        while (t->right != nullptr)
            t = t->right;
    return t;
}

bool BinarySearchTree::contains(const int & x, BinaryNode *t) const
{
    if (t == nullptr)
        return false;
    else if (x < t->element)
        return contains(x, t->left);
    else if (t->element < x)
        return contains(x, t->right);
    else
        return true;    // Match
}

void BinarySearchTree::makeEmpty(BinaryNode * & t)
{
    if (t != nullptr)
    {
        makeEmpty(t->left);
        makeEmpty(t->right);
        delete t;
    }
    t = nullptr;
}


void BinarySearchTree::printTree(BinaryNode *t) const
{
    if (t != nullptr)
    {
        printTree(t->left);
        cout << t->element << " ";
        printTree(t->right);
    }
}

BinaryNode * BinarySearchTree::clone(BinaryNode *t) const
{
    if (t == nullptr)
        return nullptr;
    else
        return new BinaryNode{ t->element, clone(t->left), clone(t->right) };
}

void BinarySearchTree::preorderTraversal(BinaryNode *node)
{
    if (node == nullptr)
        return;

    // first print data of node
    cout << node->element << " ";

    // then recur on left sutree
    preorderTraversal(node->left);

    // now recur on right subtree
    preorderTraversal(node->right);
}

void BinarySearchTree::inorderTraversal(BinaryNode *node)
{
    if (node == nullptr)
            return;

        // first recur on left child
        inorderTraversal(node->left);

        // then print the data of node
        cout << node->element << " ";

        // now recur on right child
        inorderTraversal(node->right);
}

void BinarySearchTree::postorderTraversal(BinaryNode* node)
{
    if (node == nullptr)
                return;

    // then recur on left sutree
    //preorderTraversal(node->left);
    postorderTraversal(node->left);

    // now recur on right subtree
    postorderTraversal(node->right);
    //preorderTraversal(node->right);

    // first print data of node
    cout << node->element << " ";
}

void BinarySearchTree::printLevelOrder(BinaryNode* root)
{
    int h = height(root);
    for (int i = 1; i <= h; i++)
        printGivenLevel(root, i);
}


/* Print nodes at a given level */
void BinarySearchTree::printGivenLevel(BinaryNode* root, int level)
{
    if (root == nullptr)
        return;
    if (level == 1)
        cout << root->element << " ";
    else if (level > 1)
    {
        printGivenLevel(root->left, level-1);
        printGivenLevel(root->right, level-1);
    }
}

int BinarySearchTree::height(BinaryNode* node)
{
    if (node == nullptr)
        return 0;
    else
    {
        /* compute the height of each subtree */
        int lheight = height(node->left);
        int rheight = height(node->right);

        /* use the larger one */
        if (lheight > rheight)
            return(lheight + 1);
        else return(rheight + 1);
    }
}
