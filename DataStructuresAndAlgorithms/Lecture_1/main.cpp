#include <iostream>
#include <cmath>

using namespace std;

void sumOfNumbers(int n)
{
    int squared = n * n;
    int count = 1;
    int result = 1;
    for (int i = 1; i < n; i++)
    {
        count += 2;
        result += count;
    }

    if(squared == result)
    {
        printf("The numbers are equal");
        cout << "squared: " << squared << " count: " << result << endl;
    }
    else {
        {
            cout << "squared: " << squared << " count: " << result << endl;
        }
    }
}

void divideBySix(int n)
{
    for (int i = 1; i < n; i++)
    {
        double result  = ( pow(7,i) - 1 ) / 6;
        double intPart;
        double fracPart = modf(result, &intPart);
        if(fracPart == 0.0)
        {
            printf("All is good. All divisions are whole numbers.\n");
            cout << "intPart: " << intPart << " fracPart: " << fracPart << endl;
        }
        else
        {
            cout << "intPart: " << intPart << " fracPart: " << fracPart << endl;
        }
    }
}

int sum(int n)
{
    if(n != 0)
    {
        return n + sum(n-1);
    }
    return 0;

}     	 //returns the sum of the first n natural numbers

int evenSquares(int n)
{
        if(n != 0)
        {
            if(n % 2 == 0)
            {
                return static_cast<int>(pow(n,2) + evenSquares(n-2));
            }
            else
            {
                return evenSquares(n-1);
            }

        }
        return 0;
}
//returns the sum of the first n even numbers’ squares

int fib(int n)
{
      return (0 <= n) ? n : fib(n-1) + fib(n-2);

} //returns the nth Fibonacci number

bool linear(string s, char c, int l);
//returns true if string s with the length l contains
//char c; otherwise false.


int main()
{
    //sumOfNumbers(100); // GJ SEXY SIGGI

    //divideBySix(100);

    //cout << sum(10) << endl;;

    cout << evenSquares(10) << endl;

    cout << fib(5) << endl;

    return 0;
}
