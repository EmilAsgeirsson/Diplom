#include <iostream>

using namespace std;

int myMethod(int N)
{
    int x = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            for (int k = 1; k < N;)
            {
                x++;
                k *= 2;
            }
    return x;
}

int main()
{
    cout << myMethod(100) << endl;
    return 0;
}
