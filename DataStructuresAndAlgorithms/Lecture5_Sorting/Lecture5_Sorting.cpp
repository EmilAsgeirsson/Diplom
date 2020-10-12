#include <iostream>
#include <algorithm> 

using namespace std;
/*
* 1.
* A table holds N sorted numbers.
* The task is to determine if the table contains two numbers whose sum is equal to the value of parameter x.
* The method should be written in two versions: one with quadratic time complexity and one with linear.
*/
bool quadraticTime(int *sortedArray, int size, int x)
{
	cout << "Quadratic Time" << endl;
	//int sortedArray[] = { 1, 3, 4, 7, 9, 10, 12, 15, 18, 20 };
	int numberOfOperations = 1;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			numberOfOperations++;
			int sum = sortedArray[i] + sortedArray[j];

			if (sum == x && i != j)
			{
				cout << "x = " << sortedArray[i] << " + " << sortedArray[j] << endl;
				cout << "Number of Operations = " << numberOfOperations << "\n" << endl;
				return true;
			}
		}
	}
	
	cout << endl << "Number of Operations = " << numberOfOperations << "\n" << endl;
	cout << " No two numbers sum to the input." << endl;
	return false;
}

bool linearTime(int* sortedArray, int size, int x)
{
	cout << "Linear Time" << endl;
	
	int numberOfOperations = 1;
	int iterBack = 0;
	for (int i = 1; ; i++)
	{
		int sum = sortedArray[i] + sortedArray[i - 1 - iterBack];

		if (sum == x)
		{
			cout << "x = " << sortedArray[i] << " + " << sortedArray[i - 1 - iterBack] << endl;
			cout << "Number of Operations = " << numberOfOperations << "\n" << endl;
			return true;
		}

		if (sum > x)
		{
			iterBack++;
			i--;
		}
		
		if (iterBack == size - 1)
		{
			cout << "Number of Operations = " << numberOfOperations << endl;
			cout << "No two numbers sum to the input." << endl;
			return false;
		}

		numberOfOperations++;
	}
	
}

/*
* 2.
* The words stale and least are anagrams, i.e.they contain the exact same characters.
* Write a method that can decide if two words (strings) are anagrams.
*     7.44
*     7.38
*/
bool anagram(string stringOne, string stringTwo)
{
	// If they are different size, they are not anagrams.
	if (size(stringOne) == size(stringTwo))
	{
		// Iterate through the whole string.
		for (int i = 0; i < stringOne.size(); i++)
		{
			cout << "From stringOne with letter: " << stringOne[i] << ", found: " << stringTwo.find(stringOne[i]) << endl;
			// If the letter is not found in the string. Return false
			if (stringTwo.find(stringOne[i]) == string::npos)
			{
				return false;
			}
		}
		// If all letters are found. Return true.
		return true;
	}
	// Different size. Return false.
	return false;
}


int main()
{
	int input = 23;
	int sortedArray[] = { 1, 3, 4, 7, 9, 10, 12, 15, 18, 20 };
	cout << "input = " << input << endl;
	quadraticTime(sortedArray, size(sortedArray), input);
	linearTime(sortedArray, size(sortedArray), input);

	cout << "anagram: " << anagram("least", "stale") << endl; 

}


