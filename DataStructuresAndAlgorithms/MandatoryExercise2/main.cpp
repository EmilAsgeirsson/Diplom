#include <iostream>
#include "Driver.h"

using namespace std;

int main()
{

    //Tree tree;

    //tree.insert(pair<int,int>(1,1), nullptr);

    Driver d;

    int numSteps = d.minimumSteps(1000, 1000, 0, 0, 999, 999);
    cout << "Min number of steps =" << numSteps << endl;
    return 0;
}
