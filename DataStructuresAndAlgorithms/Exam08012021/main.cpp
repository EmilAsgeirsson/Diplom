#include <iostream>
#include <cmath>
#include <tuple>

using namespace std;

int myMethod(int N)
{
    int x = 0;
    for (int i = 1; i <= sqrt(N); i++) //square root; C++: #include <math.h>
    {
        for (int j = 1; j <= N; j++)
        {
            for (int k = 1; k < N;)
            {
                x++;
                k = k * 2;
            }
        }
    }
    return x;
}


int sumDivisibleBy3(int N)
{
    // Check if the value is positive
    if(N < 0)
        return -1;

    // If N is 0, we have reached the minimum value and N is returned.
    if(N == 0)
        return N;

    // If N % 3 == 0 then we are in the table of 3's
    if(N % 3 == 0)
    {
        return sumDivisibleBy3(N-3)+N;
    }
    // If not we the value is reduced by one until we hit a value in the table of 3's.
    else
    {
        return sumDivisibleBy3(N-1);
    }
}


tuple<int, int, int> zAlgorithm(int Z)
{
    // I have chosen 317 as the max number since sqrt(100.000) = 316.23.
    // 317^2 is above 100000 and therefore it is unnecessary to check further X^Y.
    for (int X = 317; X > 1; X--)
    {
        // The lowest possible value for X is 2. If X is two and the equation is
        // X^Y. Then X^17 = 131072. Therefor Y is set to 16 to avoid going
        // beyond the maximum number of 100.000.
        for (int Y = 2; Y < 16; Y++)
        {
            // If X^Y becomes bigger than Z we skip the rest of the Y loop and goes
            // to the next X loop.
            if(static_cast<int>(pow(X,Y)) > Z)
                break;


            if(static_cast<int>(pow(X,Y)) == Z)
            {
                return make_tuple(X,Y,Z);
            }

         }
    }
    return make_tuple(0,0,Z);
}

int main()
{
    int N = 100;

    // Problem 1: Big Oh
    cout << myMethod(N) << endl;
    cout << N*sqrt(N)*log2(N) << endl;

    // Problem 2: sumDivisibleby3
    cout << sumDivisibleBy3(N) << endl;


    // Problem 4:
    int Z = 59049;
    cout << "input is: " << Z << endl;
    tuple<int,int,int> zAlgo = zAlgorithm(Z);
    cout << "X = " << get<0>(zAlgo) << " and Y = " << get<1>(zAlgo) << " and gives: " << pow(get<0>(zAlgo),get<1>(zAlgo)) <<endl;



    return 0;
}
