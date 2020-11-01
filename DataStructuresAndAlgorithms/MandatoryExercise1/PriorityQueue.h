#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H
#include <string>
#include <vector>

    // Write a method that solves the selection problem using a priority queue(you
	// must write your own PQ), and conduct a series of experiments that indicate
	// that the time complexity of your method is O(N · log(N)).
class PriorityQueue
{
	public:
	PriorityQueue(std::vector<int> array);

	//void insert();

	void print();

	private:
	std::vector<int> mArray;
};

#endif PRIORITYQUEUE_H