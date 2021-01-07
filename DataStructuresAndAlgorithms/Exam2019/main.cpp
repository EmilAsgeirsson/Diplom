#include <iostream>
#include <vector>
using namespace std;

bool isPrime(int n)
{
    // Corner cases
    if (n <= 1)  return false;
    if (n <= 3)  return true;

    // This is checked so that we can skip
    // middle five numbers in below loop
    if (n%2 == 0 || n%3 == 0) return false;

    for (int i=5; i*i<=n; i=i+6)
        if (n%i == 0 || n%(i+2) == 0)
           return false;

    return true;
}


int nextPrime(int N) {
    // Base case
    if (N <= 1)
        return 2;
    int prime = N;
    bool found = false;
    // Loop continuously until isPrime returns
    // true for a number greater than n
    while (!found) {
        prime++;
        if (isPrime(prime))
            found = true;
    }
    return prime;
}

int bigoh()
{
    int arr[562] = {};

    int arrSize = *(&arr +1) - arr;
    int arrSize2 = sizeof(arr)/sizeof(arr[0]);


    int x = 0;
    for (int i = 0; i < arrSize; i++)
        for (int j = 0; j < arrSize/2; j++)
            for (int k = 0; k < arrSize; k++)
            {
                x++;
                if (k==1)
                    break;
            }
    return x;
}


int addOddNum(int n)
{
    if(n < 0)
        return 0;

    if(n == 1)
    {
        return n;
    }

    if(n % 2 == 0)
    {
        return addOddNum(n-1)+n;
    }
    else {
        return addOddNum(n-2)+n;
    }
}

void problem3()
{
    vector<int> yada{5, 28, 7, 25, 7, 9, 28, 11, 67, 5, 33, 28};

    for (unsigned i = 0; i < yada.size(); i++)
    {
        //total.push_back(vector<int> {yada[i]});
    }

    for (unsigned i = 0; i < yada.size(); i++)
    {

    }
}


int main()
{
    cout << nextPrime(2500*2) << endl;
    return 0;
}
