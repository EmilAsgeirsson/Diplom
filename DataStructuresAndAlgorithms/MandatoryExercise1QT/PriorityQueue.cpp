#include "PriorityQueue.h"
#include <iostream>
#include <cmath>

using namespace std;

PriorityQueue::PriorityQueue()
    : mCurrentSize{0}, mComplexity(0), mArray(101)
{
}

PriorityQueue::PriorityQueue(unsigned size)
    : mCurrentSize{0}, mComplexity(0), mArray(size)
{

}

void PriorityQueue::insert(int x)
{
    // Assign a hole at the next empty element in the vector.
    unsigned hole = static_cast<unsigned>(++mCurrentSize);

    // Set the first value in the vector to the new value.
    mArray[0] = x;

    // As long a the new value is smaller that the one above, we perlocate each element down.
    for (;  x < mArray[hole / 2]; hole /= 2)
    {
        mComplexity++;
        mArray[hole] = mArray[hole / 2];
    }

    // When the element at the next node is no longer larger than x. We insert x into this spot.
    mArray[hole] = mArray[0];
    cout << "insert " << x << " at " << hole << endl;
}

// Finds, deletes and returns the smallest number in the heap
int PriorityQueue::deleteMin()
{
    if(mArray.empty())
    {
        cout << "Array empty. Cant delete anything" << endl;
        return -1;
    }

    int minItem = mArray[1];

    // Minimum item will always be at location 1.
    mArray[1] = mArray[static_cast<unsigned>(mCurrentSize--)];
    percolateDown(1);
    return minItem;

}

void PriorityQueue::percolateDown(unsigned hole)
{
    // Perculate down
    unsigned child;
    int tmp = mArray[hole];

    for (; hole * 2 <= static_cast<unsigned>(mCurrentSize); hole = child)
    {
        mComplexity++;
        child = hole * 2;

        // Check that child is not at the end of the array, so that the node has children and that the right child
        // is smaller than the left child.
        if (child != static_cast<unsigned>(mCurrentSize) && mArray[child + 1] < mArray[child])
        {
            ++child;
        }

        if (mArray[child] < tmp)
        {
            mArray[hole] = mArray[child];
        }
        else
        {
            break;
        }
    }
    mArray[hole] = tmp;
    //mArray.erase(mArray.begin()+ child);
    //mArray.pop_back();
}

int PriorityQueue::selectionProblem(unsigned k)
{
    int value = 0;
    for (unsigned i = 0; i < k; i++)
    {
       value = deleteMin();
    }

    cout << "Practical calculation: " << mComplexity << endl;
    return value;
}

void PriorityQueue::print()
{

    // print line
    for (int i = 0; i < 100; ++i)
    {
        cout << "-";
    }
    cout << endl;

    for (unsigned i = 1; i < mArray.size(); ++i)
    {
        if(i > static_cast<unsigned>(mCurrentSize))
        {
            mArray.erase(mArray.begin() + i);
            i--;
        }
    }

    cout << "As an Array\n[";


    // Index 0 is reserved for new entries
    for (unsigned i = 1; i < mArray.size(); ++i)
    {
        if(i == mArray.size() - 1)
        {
            cout << mArray[i] << "]" << endl;
        }
        else
        {
            cout << mArray[i] << " ";
        }
    }

    // print line
    for (int i = 0; i < 100; ++i) {
        cout << "-";
    }

    cout  << "\nAs a Tree" << endl;

    int level = 1;
    int levels = static_cast<int>(log2(mArray.size()));
    int space = static_cast<int>(pow(2, levels - 1) - 1);
    bool didIt = false;
    for (unsigned i = 1; i < mArray.size(); ++i)
    {
        if (!didIt)
        {
            for (int j = 0; j < space - 1; ++j)
            {
                cout << " ";
            }
            didIt = true;
        }
        cout << mArray[i] << " ";
        if (i == static_cast<unsigned>(pow(2, level) - 1))
        {
            level++;
            space -= i;
            didIt = false;
            cout << endl;
        }
    }

    cout << endl;
    // print line
    for (int i = 0; i < 100; ++i) {
        cout << "-";
    }
    cout << endl;

}

