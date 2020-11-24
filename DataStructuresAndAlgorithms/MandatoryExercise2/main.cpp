#include <iostream>
#include "Driver.h"
#include <cstdio>
#include <ctime>

using namespace std;

int main()
{

    std::clock_t start;
    double duration;

    start = std::clock();

    Driver d;
    int numSteps = d.minimumSteps(1000, 1000, 999, 999, 1, 1);

    duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;
    cout << "Min number of steps = " << numSteps << endl;

    std::cout<<"printf: "<< duration <<'\n';

    return 0;
}
