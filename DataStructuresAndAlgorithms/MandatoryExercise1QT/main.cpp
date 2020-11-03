#include <iostream>
#include <vector>
#include <cmath>
#include "PriorityQueue.h"
#include "QuickSelect.h"
#include <ctime>


using namespace std;

int main()
{
    //vector<int> keys = { 3, 6, 12, 1, 8, 13, 19, 21, 26, 22, 18, 14, 9, 5};

    srand( static_cast<unsigned int>(time(nullptr)));



    // create array
    unsigned size = 10000;
    PriorityQueue pq(size + 1);
    vector<int> keys(size);
    for (unsigned i = 0; i < keys.size(); i++)
    {
        keys[i] = rand() % 99 + 1;
        pq.insert(rand() % 99 + 1);
    }

    cout << "printing priority queue" << endl;
    pq.print();



    pq.print();
    //cout << "After deleteMin" << endl;

    //pq.print();

    // The selection problem states that you have an unsorted list and must find the k'th smallest element.
    // The idea here would be deleteMin untill we've found the k'th smallest element.

    int N = keys.size();
    double thcalc = N * log2(N);
    unsigned k = 450;
    cout << "Theoretical calcuation: " << thcalc << endl;
    int foundValue = pq.selectionProblem(k);
    cout << "Selection problem returned: " << foundValue << endl;

    //pq.print();

    return 0;

    QuickSelect qSelect(keys);

    //int k = 3;
    qSelect.quickselect(keys, 0 , keys.size()-1, k);
    cout << keys[k] << endl;

    return 0;
}
