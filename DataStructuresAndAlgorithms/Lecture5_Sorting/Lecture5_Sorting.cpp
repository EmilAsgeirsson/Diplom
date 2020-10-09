#include <iostream>
#include <algorithm> 

using namespace std;
/*
* 1.
* A table holds N sorted numbers. 
* The task is to determine if the table contains two numbers whose sum is equal to the value of parameter x.
* The method should be written in two versions: one with quadratic time complexity and one with linear.
*/
void numberEqualX(int x)
{
    int sortedArray [] = {5, 9, 12, 3, 8, 10, 4, 1};
    //sort(sortedArray, sortedArray.length -1);
    size
    sort(sortedArray, sortedArray + sortedArray.length - 1);
    for (auto y : sortedArray)
    {
        cout << y << ",";
    }
    cout << endl;
}
/* 
* 2.
* The words stale and least are anagrams, i.e.they contain the exact same characters. 
* Write a method that can decide if two words (strings) are anagrams.
*     7.44
*     7.38
*/

int main()
{
    numberEqualX(2);
    std::cout << "Hello World!\n";
}


