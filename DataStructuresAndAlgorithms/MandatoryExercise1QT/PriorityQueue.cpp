#include "PriorityQueue.h"
#include <iostream>
#include <cmath>

using namespace std;

PriorityQueue::PriorityQueue()
    : mCurrentSize{0}, mArray(101)
{
}

PriorityQueue::PriorityQueue(vector<int> array)
{
    mArray = array;
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
        mArray[hole] = mArray[hole / 2];
    }

    // When the element at the next node is no longer larger than x. We insert x into this spot.
    mArray[hole] = mArray[0];




    //if(mArray.size() == 0)
    //{
    //    cout << "array empty. Adding " << x << endl;
    //    mArray.push_back(x);
    //}




    /*
    for (unsigned i = 0; i < mArray.size();i++)
    {
        // If element is already inserted. Skip it. I dont't want duplicates
        if(x == mArray[i] || i > 100)
            break;


        if (x < mArray[i])
        {
            cout << x << " is smaller than " << mArray[i] << endl;
            mArray.insert(mArray.begin() + i, x);
            return;
        }

        if(i == mArray.size() - 1)
        {
            cout << x << " is larger than all elements and is pushed back " << endl;
            mArray.push_back(x);
        }
    }
    */
}

// Finds, deletes and returns the smallest number in the heap
void PriorityQueue::deleteMin()
{
    if(mArray.empty())
    {
        cout << "Array empty. Cant delete anything" << endl;
        return;
    }

    //int minItem = mArray[1];

    // Minimum item will always be 1.
    mArray[1] = mArray[static_cast<unsigned>(mCurrentSize--)];

    // Perculate down
    unsigned child;
    unsigned hole = 1;
    int tmp = mArray[hole];

    for (; hole * 2 <= static_cast<unsigned>(mCurrentSize); hole = child)
    {
        child = hole * 2;
        // Check that child is not at the end of the array, so that the node har children.
        if (child != static_cast<unsigned>(mCurrentSize) && mArray[child + 1] < mArray[child])
            ++child;
        if (mArray[child] < tmp)
            mArray[hole] = mArray[child];
        else
            break;
    }
    mArray[hole] = tmp;
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
        if(i >= static_cast<unsigned>(mCurrentSize))
        {
            mArray.erase(mArray.begin() + i);
            i--;
        }
    }

    cout << mArray.size() << endl;

    cout << endl << "As an Array\n[";


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
    cout << space << " " << levels << endl;
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

}

