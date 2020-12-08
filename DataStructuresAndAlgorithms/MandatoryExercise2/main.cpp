/*#include <iostream>
#include "Driver.h"
#include <cstdio>
#include <ctime>

using namespace std;

int main()
{

    std::clock_t start;
    double duration;

    start = std::clock();

    int numSteps = MinimumSteps(1000, 1000, 999, 999, 1, 1);

    duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;
    cout << "Min number of steps = " << numSteps << endl;

    std::cout<<"printf: "<< duration <<'\n';

    return 0;
}
*/

#include "Driver.h"
#include <iostream>
#include <cstdio>
#include <ctime>

using namespace std;

int main() {

    // From [1,1] -> [999,999]:
    //  Â· Runtime: ~ 18 sec.
    // Â Â· Memory: ~ 190 MB.

    // Positions are indexed starting from 0.
    // So the position [0,0] translates to A1 in chess nomenclature.

    clock_t start;
    double duration;
    start = clock();

    cout << (MinimumSteps(5, 5, 0, 0, 0, 0) == 0) << endl;
    cout << (MinimumSteps(5, 5, 0, 0, 1, 0) == 3) << endl;
    cout << (MinimumSteps(5, 5, 0, 0, 2, 0) == 2) << endl;
    cout << (MinimumSteps(5, 5, 0, 0, 3, 0) == 3) << endl;
    cout << (MinimumSteps(5, 5, 0, 0, 4, 0) == 2) << endl;
    cout << (MinimumSteps(5, 5, 0, 0, 0, 1) == 3) << endl;
    cout << (MinimumSteps(5, 5, 0, 0, 1, 1) == 4) << endl;
    cout << (MinimumSteps(5, 5, 0, 0, 2, 1) == 1) << endl;
    cout << (MinimumSteps(5, 5, 0, 0, 3, 1) == 2) << endl;
    cout << (MinimumSteps(5, 5, 0, 0, 4, 1) == 3) << endl;
    cout << (MinimumSteps(5, 5, 0, 0, 0, 2) == 2) << endl;
    cout << (MinimumSteps(5, 5, 0, 0, 1, 2) == 1) << endl;
    cout << (MinimumSteps(5, 5, 0, 0, 2, 2) == 4) << endl;
    cout << (MinimumSteps(5, 5, 0, 0, 3, 2) == 3) << endl;
    cout << (MinimumSteps(5, 5, 0, 0, 4, 2) == 2) << endl;
    cout << (MinimumSteps(5, 5, 0, 0, 0, 3) == 3) << endl;
    cout << (MinimumSteps(5, 5, 0, 0, 1, 3) == 2) << endl;
    cout << (MinimumSteps(5, 5, 0, 0, 2, 3) == 3) << endl;
    cout << (MinimumSteps(5, 5, 0, 0, 3, 3) == 2) << endl;
    cout << (MinimumSteps(5, 5, 0, 0, 4, 3) == 3) << endl;
    cout << (MinimumSteps(5, 5, 0, 0, 0, 4) == 2) << endl;
    cout << (MinimumSteps(5, 5, 0, 0, 1, 4) == 3) << endl;
    cout << (MinimumSteps(5, 5, 0, 0, 2, 4) == 2) << endl;
    cout << (MinimumSteps(5, 5, 0, 0, 3, 4) == 3) << endl;
    cout << (MinimumSteps(5, 5, 0, 0, 4, 4) == 4) << endl;
    cout << (MinimumSteps(1000, 1000, 0, 0, 999, 999) == 666) << endl;

    duration = ( clock() - start ) / (double) CLOCKS_PER_SEC;

    std::cout<<"Duration: "<< duration <<'\n';
}
