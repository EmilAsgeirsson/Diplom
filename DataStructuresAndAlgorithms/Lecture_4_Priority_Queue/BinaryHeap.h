#ifndef BINARY_HEAP_H
#define BINARY_HEAP_H

#include <vector>
#include <iostream>
#include <math.h>

using namespace std;

// BinaryHeap class
//
// CONSTRUCTION: with an optional capacity (that defaults to 100)
//
// ******************PUBLIC OPERATIONS*********************
// void insert( x )       --> Insert x
// deleteMin( minItem )   --> Remove (and optionally return) smallest item
// Comparable findMin( )  --> Return smallest item
// bool isEmpty( )        --> Return true if empty; else false
// void makeEmpty( )      --> Remove all items
// ******************ERRORS********************************
// Throws UnderflowException as warranted

template <typename Comparable>
class BinaryHeap
{
    public:
    explicit BinaryHeap(int capacity = 100)
        : array(capacity + 1), currentSize{ 0 }
    {
    }

    explicit BinaryHeap(const vector<Comparable>& items)
        : array(items.size() + 10), currentSize{ items.size() }
    {
        for (int i = 0; i < items.size(); ++i)
            array[i + 1] = items[i];
        buildHeap();
    }

    bool isEmpty() const
    {
        return currentSize == 0;
    }

    /**
     * Find the smallest item in the priority queue.
     * Return the smallest item, or throw Underflow if empty.
     */
    const Comparable& findMin() const
    {
        if (isEmpty())
            throw - 1;
        return array[1];
    }

    /**
     * Insert item x, allowing duplicates.
     */
    void insert(const Comparable& x)
    {
        if (currentSize == array.size() - 1)
            array.resize(array.size() * 2);

        // Percolate up
        int hole = ++currentSize;
        Comparable copy = x;

        array[0] = std::move(copy);
        for (; x < array[hole / 2]; hole /= 2)
            array[hole] = std::move(array[hole / 2]);
        array[hole] = std::move(array[0]);
    }


    /**
     * Insert item x, allowing duplicates.
     */
    void insert(Comparable&& x)
    {
        if (currentSize == array.size() - 1)
            array.resize(array.size() * 2);

        // Percolate up
        int hole = ++currentSize;
        for (; hole > 1 && x < array[hole / 2]; hole /= 2)
            array[hole] = std::move(array[hole / 2]);
        array[hole] = std::move(x);
    }

    /**
     * Remove the minimum item.
     * Throws UnderflowException if empty.
     */
    void deleteMin()
    {
        if (isEmpty())
            throw - 1;

        array[1] = std::move(array[currentSize--]);
        percolateDown(1);
    }

    /**
     * Remove the minimum item and place it in minItem.
     * Throws Underflow if empty.
     */
    void deleteMin(Comparable& minItem)
    {
        if (isEmpty())
            throw - 1;

        minItem = std::move(array[1]);
        array[1] = std::move(array[currentSize--]);
        percolateDown(1);
    }

    void makeEmpty()
    {
        currentSize = 0;
    }

    void increaseKey(int p, int delta) {
        array[p] += delta;
        percolateDown(p);
    }

    void decreaseKey(int p, int delta) {
        array[p] -= delta;
        percolateUp(p);
    }

    void changeKey(int p, int delta) {
        array[p] += delta;
        print(true, true); cout << endl << "Reordering.." << endl;
        (delta < 0) ? percolateUp(p) : percolateDown(p);
    }

    void print(bool asArray = true, bool asTree = false)
    {
        if (asArray) printArray();
        if (asArray && asTree) cout << endl;
        if (asTree) printTreee();
    }

    private:
    int                currentSize;  // Number of elements in heap
    vector<Comparable> array;        // The heap array

    /**
     * Establish heap order property from an arbitrary
     * arrangement of items. Runs in linear time.
     */
    void buildHeap()
    {
        for (int i = currentSize / 2; i > 0; --i)
            percolateDown(i);
    }

    /**
     * Internal method to percolate down in the heap.
     * hole is the index at which the percolate begins.
     */
    void percolateDown(int hole)
    {
        int child;
        Comparable tmp = std::move(array[hole]);

        for (; hole * 2 <= currentSize; hole = child)
        {
            child = hole * 2;
            if (child != currentSize && array[child + 1] < array[child])
                ++child;
            if (array[child] < tmp)
                array[hole] = std::move(array[child]);
            else
                break;
        }
        array[hole] = std::move(tmp);
    }

    void percolateUp(int hole) {
        int x = array[hole];

        for (; hole > 1 && x < array[hole / 2]; hole /= 2)
            array[hole] = std::move(array[hole / 2]);
        array[hole] = x;
    }

    // Display
    void printTree() {
        int level = 1;
        int levels = log2(array.size());
        int space = pow(2, levels - 1) - 1;
        bool didIt = false;
        for (int i = 1; i < array.size(); ++i) {
            if (!didIt) {
                for (int j = 0; j < space - 1; ++j) {
                    cout << " ";
                }
                didIt = true;
            }
            cout << array[i] << " ";
            if (i == pow(2, level) - 1) {
                level++;
                space -= i;
                didIt = false;
                cout << endl;
            }
        }
    }

    void printTreee() {
        int height = log2(array.size() - 1) + 1;
        int leaves = array.size() - pow(2, height - 1);
        int* levelWidths = new int[height];
        for (int k = 0; k < height; ++k) {
            levelWidths[k] = -1;
        }
        for (int i = height; i >= 0; --i) {
            int startNode = pow(2, i);
            int endNode = (i == height) ? array.size() : pow(2, i + 1);
            for (int j = startNode; j < endNode; ++j) {
                int nodeWidth = numberWidth(array[j]);
                levelWidths[i] += nodeWidth + 1;
            }
        }

        for (int i = 0; i < height; ++i) {
            int startNode = pow(2, i);
            int endNode = (i == height) ? array.size() : pow(2, i + 1);
            int spaces = levelWidths[height - 1] / 2 - levelWidths[i] / 2;
            spacer(spaces);
            for (int j = startNode; j < endNode; ++j) {
                cout << array[j] << " ";
            } cout << endl;
        }
    }

    void spacer(int numSpaces) {
        for (int i = 0; i < numSpaces; ++i) {
            cout << " ";
        }
    }

    int numberWidth(int number) {
        return ceil(log10(number));
    }

    void printArray() {
        for (int i = 1; i < array.size(); ++i) {
            cout << array[i] << " ";
        } cout << endl;
    }
};

#endif