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
    PriorityQueue(std::vector<int> array);

    void insert(int x);

    void deleteMin();

    void print();

private:   
    int mCurrentSize;
    std::vector<int> mArray;
    std::vector<int>::iterator mIt;



};


#endif // PRIORITYQUEUE_H
