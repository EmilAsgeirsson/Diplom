#include <iostream>
#include <vector>
#include "PriorityQueue.h"

using namespace std;

int main()
{
    vector<int> keys = { 3, 6, 12, 1, 8, 13, 19, 21, 26, 22, 18, 14, 9, 5};
    //vector<int> keys = { 3, 6, 12 };

    //PriorityQueue pq(keys);

    PriorityQueue pq;

    for (unsigned i = 0; i < keys.size(); i++)
    {
        pq.insert(keys[i]);
    }

    cout << "printing priority queue" << endl;
    pq.print();

    pq.deleteMin();

    pq.print();

    return 0;
}
