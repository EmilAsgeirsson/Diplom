#include <iostream>
#include "someInterface.h"
#include <cstdio>
#include <ctime>

using namespace std;

int main()
{   

    // Problem 2
    vector<int> x {1,2,4,7,5,8,10,12};
    //cout << recLinSearch(x, x.size()-1, 12) << endl;


    // Problem 3
    std::clock_t start;
    double duration;

    start = std::clock();

    int max = 0;
    unsigned index = 0;
    for (unsigned i = 0; i < 10000;i++)
    {
        int returnedVal = iterativeMethod(static_cast<int>(i),0);
        if(returnedVal > max)
        {
            index = i;
            max = returnedVal;
        }
    }
    duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;

    cout << "Longest chain is: " << max << " at index: " << index << endl;
    std::cout<<"printf: "<< duration <<'\n';


    // Problem 5
    cout << endl << endl;
    cout << pyth() << endl;
    cout << pyth2(1,1) << endl;

    return 0;
}
