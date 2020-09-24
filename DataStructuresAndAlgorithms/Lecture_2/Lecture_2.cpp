// Lecture_2.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Write a method with the following signature using a stack(using counters is not allowed) :
// boolean balPar(String text);
// The method checks if the brackets() in the parameter are balanced.An extended version could include{}and [].
// You may use a built - in stack or implement your own.

#include <iostream>
#include <stack>
#include <vector>

using namespace std;

stack<char> myStack;
bool isEven;
bool startPar;

bool balPar(string text);
bool balPar2(string text);
void fillStack(string text, int l);

void fillStack(string text, int l)
{
	if (l == 0)
		return;
	char c = text.at(l - 1);
	myStack.push(c);
	fillStack(text, l - 1);

}

bool balPar(string text)
{
	if (myStack.empty())
	{
		fillStack(text, text.size());
		text = "";
	}

	if (!myStack.empty())
	{
		char c = myStack.top();
		myStack.pop();
		if (c == '(' && !myStack.empty())
		{
			text.push_back('(');
			return balPar(text);
		}
		else if (c == ')' && !myStack.empty())
		{
			text.push_back(')');
			return balPar(text);
		}
		else if (myStack.empty())
		{
			if (c == '(')
			{
				text.push_back('(');
			}
			else if (c == ')')
			{
				text.push_back(')');
			}

			vector<int> start, end;
			int startPar = text.find('(');
			int endPar = text.find(')');
			while (startPar != string::npos)
			{
				start.push_back(startPar);
				startPar = text.find('(', startPar + 1);
			}
			while (endPar != string::npos)
			{
				end.push_back(endPar);
				endPar = text.find(')', endPar + 1);
			}

			if (start.size() != 0 && start.size() == end.size())
			{
				return true;
			}
			return false;
		}
		else
		{
			return balPar(text);
		}
	}
}


bool balPar2(string text)
{
	stack<char> myStack2;

	for (int i = 0; i < text.length(); i++)
	{
		char c = text.at(i);

		if (c == '(')
		{
			myStack2.push(c);
		}
		else if (c == ')')
		{
			if (myStack2.empty())
				return false;
			myStack2.pop();
		}
	}
	if (myStack2.empty())
		return true;
	return false;
}


int main()
{
	//cout << balPar("()()(()()()()()()sdRADFSADS)") << endl;
	cout << balPar2("()()()(()))") << endl;

}
