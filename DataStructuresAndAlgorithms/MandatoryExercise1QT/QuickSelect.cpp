#include "QuickSelect.h"

using namespace std;

QuickSelect::QuickSelect(vector<int> & a)
{
    mArray = a;
}

// left is the left-most index of the subarray.
// right is the right-most index of the subarray.
// k is the desired rank (1 is minimum) in the entire array.
void QuickSelect::quickselect(vector<int>& a, int left, int right, int k )
{
    if( left + 10 <= right )
    {
        unsigned pivot = median3(a ,left, right );

        // Begin partitioning
        int i = left, j = right - 1;
        for( ; ; )
        {
            mComplexity++;
            while( a[ ++i ] < pivot ) { }
            while( pivot < a[ --j ] ) { }
            if( i < j )
            {
                std::swap( a[ i ], a[ j ] );
                mComplexity++;
            }
                else
                break;
        }

        swap( a[ i ], a[ right - 1 ] ); // Restore pivot
        mComplexity++;

        // Recurse; only this part changes
        if( k <= i )
            quickselect(a, left, i - 1, k );
        else if( k > i + 1 )
            quickselect(a, i + 1, right, k );
    }
    else // Do an insertion sort on the subarray
        insertionSort(a, left, right );

}

unsigned QuickSelect::median3(vector<int>& a ,int left, int right)
{

    int center = ( left + right ) / 2;

    if( a[ center ] < a[ left ] )
        swap( a[ left ], a[ center ] );
    if( a[ right ] < a[ left ] )
        swap( a[ left ], a[ right ] );
    if( a[ right ] < a[ center ] )
        swap( a[ center ], a[ right ] );

    // Place pivot at position right - 1
    swap( a[ center ], a[ right - 1 ] );
    return a[ right - 1 ];

}

void QuickSelect::insertionSort(vector<int>& a, int begin, int end)
{

    if( begin == end )
        return;

    vector<int>::iterator j;

    for (vector<int>::iterator p = a.begin() + begin + 1; p != a.end(); p++)
    {
        vector<int>::iterator tmp = p;
        for( j = p; j != a.begin() + begin && tmp < j-1; --j )
        {
            j = j-1;
        }
        j = tmp;
    }
}
