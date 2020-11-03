#include <iostream>
#include <vector>
#include <cmath>
#include "PriorityQueue.h"
#include "QuickSelect.h"
#include <ctime>


using namespace std;

int main()
{
    srand( static_cast<unsigned int>(time(nullptr)));

    // create array
    unsigned size = 15;
    PriorityQueue pq(size + 1);
    vector<int> keys(size);
    for (unsigned i = 0; i < keys.size(); i++)
    {
        keys[i] = rand() % 99 + 1;
        pq.insert(rand() % 99 + 1);
    }

    cout << "printing priority queue" << endl;
   pq.print();

    // The selection problem states that you have an unsorted list and must find the k'th smallest element.
    // The idea here would be deleteMin untill we've found the k'th smallest element.

    int N = keys.size();
    unsigned k = size/2;
    double thcalcPQ = N * log2(N);
    cout << "Theoretical calcuation: " << thcalcPQ << endl;
    cout << "Selection problem returned: " <<  pq.selectionProblem(k) << endl;

    pq.print();

    return 0;
    QuickSelect qSelect(keys);

    qSelect.quickselect(keys, 0 , keys.size()-1, k);
    double thcalcQS = N;
    cout << "Theoretical calcuation: " << thcalcQS << endl;

    qSelect.printComplexity();

    return 0;
}
