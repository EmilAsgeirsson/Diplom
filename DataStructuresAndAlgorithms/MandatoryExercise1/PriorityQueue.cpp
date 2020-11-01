#include "PriorityQueue.h"
#include <iostream>

using namespace std;

PriorityQueue::PriorityQueue(vector<int> array)
{
	mArray = array;
}

//void PriorityQueue::insert()
//{
//
//}

void PriorityQueue::print()
{
	for (int i = 0; i < mArray.size(); i++)
	{
		cout << mArray[i] << endl;
	}

}