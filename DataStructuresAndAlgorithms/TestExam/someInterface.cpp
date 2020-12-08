#include "someInterface.h"
#include <cmath>

using namespace std;

bool recLinSearch(vector<int> x, int n, int val)
{
    if(n < 0)
    {
        return false;
    }

    if(x[n] == val)
    {
        return true;
    }
    else
    {
        return(recLinSearch(x, n-1, val));
    }
}


int iterativeMethod(int n, int x)
{
    if(n == 0)
    {
        return -1;
    }

    if(n == 1)
    {
        //cout << "1" << endl;
        return x+1;
    }

    if(n%2 == 1)
    {
        x++;
        //cout << n << " -> ";
        return iterativeMethod(3*n+1,x);
    }

    if(n%2 == 0)
    {
        x++;
        //cout << n << " -> ";
        return iterativeMethod(n/2,x);
    }

    return -1;
}


int pyth()
{
    for (int i = 1; ;i++)
    {
        for (int j = i; ;j++)
        {
            if(j < i)
            {
                continue;
            }

            int a,b,c;
            a = i;
            b = j;
            c = 1000 - a - b;

            if(b >= c)
            {
                break;
            }

            if((a*a + b*b) == c*c)
            {
              cout << "[" << a << ", " << b << ", " << c << "]" << endl;
              cout << a+b+c << endl;
              return a*b*c;
            }
        }
    }
}


int pyth2(int a, int b)
{
    const int sum = 1000;

    int c = sum - a - b;

    if(c < b)
    {
        cout << "[" << a << ", " << b << ", " << c << "]" << endl;
        return pyth2(a+1, a+2);
    }

    if((a*a + b*b) == c*c)
    {
      cout << "[" << a << ", " << b << ", " << c << "]" << endl;
      cout << a+b+c << endl;
      return a*b*c;
    }
    else
    {
        return pyth2(a, b+1);
    }


}
