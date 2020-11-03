#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H
#include <vector>


// Write a method that solves the selection problem using a priority queue(you
// must write your own PQ), and conduct a series of experiments that indicate
// that the time complexity of your method is O(N · log(N)).
class PriorityQueue
{
public:
    PriorityQueue();
    PriorityQueue(unsigned size);
    PriorityQueue(std::vector<int> array);

    void insert(int x);

    int deleteMin();
    void percolateDown(unsigned hole);
    int selectionProblem(unsigned k);

    void print();

private:   
    int mCurrentSize;
    int mComplexity;
    std::vector<int> mArray;
};


#endif // PRIORITYQUEUE_H
