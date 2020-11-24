#include "Driver.h"
#include <bits/stdc++.h>

using namespace std;


int Driver::minimumSteps(int boardHeight, int boardWidth, int knightStartXPosition, int knightStartYPosition, int knightEndXPosition, int knightEndYPosition)
{
    // Directions that the knight can move to from the current position.
    int dx[] = { -2, -1, 1, 2, -2, -1, 1, 2 };
    int dy[] = { -1, -2, -2, -1, 1, 2, 2, 1 };


    pair<int,int> startPos(knightStartXPosition, knightStartYPosition);
    pair<int,int> endPos(knightEndXPosition, knightEndYPosition);


    //Tree tree(startPos);
    queue<pair<int,int>> myStack;
    myStack.push(startPos);

    // Creating a map for the entire chessboard.
    bool visit[boardWidth + 1][boardHeight + 1];

    // make all cell unvisited
    for (int i = 1; i <= boardWidth; i++)
    {
        for (int j = 1; j <= boardHeight; j++)
        {
            visit[i][j] = false;
        }
    }

    // Set the start position of the knight to true.
    visit[knightStartXPosition][knightStartYPosition] = true;

    pair<int,int> next;
    int counter = 0, x, y;
    while(!myStack.empty())
    {
        counter++;
        next = myStack.front();
        myStack.pop();
        // If destination is reached. return
        if (next.first == endPos.first && next.second == endPos.second)
        {

            // Maybe something with tree height?
            return counter;
        }

        for (unsigned i = 0; i < 8 ; i++)
        {
            x = next.first + dx[i];
            y = next.second + dy[i];

            if(valid(x,y, boardHeight, boardWidth))
            {
                visit[x][y] = true;
                myStack.push(pair<int,int>(x,y));
            }
        }
    }


    return 0;
}

bool Driver::valid(int x, int y, int boardHeight, int boardWidth)
{
    if(x > boardWidth || y > boardHeight || x < 1 || y < 1)
    {
        return false;
    }
    return true;
}

void Driver::print()
{

}
