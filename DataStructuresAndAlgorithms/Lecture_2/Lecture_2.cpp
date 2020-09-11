// Lecture_2.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Write a method with the following signature using a stack(using counters is not allowed) :
// boolean balPar(String text);
// The method checks if the brackets() in the parameter are balanced.An extended version could include{}and [].
// You may use a built - in stack or implement your own.

#include <iostream>
#include <stack>

using namespace std;

stack<char> myStack;
bool isEven;
bool startPar;

bool balPar (string text);
void fillStack(string text, int l);

void fillStack(string text, int l)
{
	if (l == 0)
		return;
	char c = text.at(l - 1);
	myStack.push(c);
	fillStack(text, l - 1);
	
}

bool linear(string s, char c, int l)
{
	if (l == 0)
		return false;
	if (s.at(l - 1) == c)
		return true;
	return linear(s, c, l - 1);
}

bool balPar (string text)
{
	if (myStack.empty())
		fillStack(text, text.size());
	
	char c = myStack.top();
	myStack.pop();
	if (c == '(')
	{
		return balPar(text);
	}
	if (c == ')')
	{
		return balPar(text);
	}
	else if(myStack.empty())
		return true;

	/*stack<char> myStack;
	for (char i : text)
	{
		myStack.push(i);
	}

	bool startPar = false;
	bool isEven = true;

	for (char i : myStack)
	{
		char i = myStack.top();

		if (el == '(' && isEven == true)
		{
			startPar = true;
			isEven = false;
		}
		else if (el == '(' && startPar)
		{
			isEven = true;
		}
		else if (el == ')' && isEven == false)
		{
			isEven = true;
		}
		else if (el == ')' && isEven == true)
		{
			isEven = false;
		}
	}*/
}



int main ()
{
	cout << balPar("hejhej") << endl;

}
