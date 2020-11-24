#include "Driver.h"
#include "Node.h"

using namespace std;

int Driver::minimumSteps(int boardHeight, int boardWidth, int knightStartXPosition, int knightStartYPosition, int knightEndXPosition, int knightEndYPosition)
{
    // Directions that the knight can move to from the current position.
    int dx[] = { -2, -1, 1, 2, -2, -1, 1, 2 };
    int dy[] = { -1, -2, -2, -1, 1, 2, 2, 1 };
    
    // Create start Node and tree.
    Node* knightStart = new Node(pair<int,int>(knightStartXPosition, knightStartYPosition));
    pair<int,int>knightEndPos(knightEndXPosition, knightEndYPosition);
    Tree board(knightStart, knightEndPos);

    // Create a double array with the size of the chessboard
    bool visit[boardWidth + 1][boardHeight + 1];
    
    // make all points unvisited
    for (int i = 0; i <= boardWidth; i++)
    {
        for (int j = 0; j <= boardHeight; j++)
        {
            visit[i][j] = false;
        }
    }

    // Set the start position of the knight to true.
    visit[knightStartXPosition][knightStartYPosition] = true;

    // Create a vector to insert all the points aswell to access them.
    vector<Node*> iterationVector;
    iterationVector.push_back(knightStart);
    for(unsigned j = 0;; j++)
    {
        Node* next = iterationVector.at(j);

        for (unsigned i = 0; i < 8; i++)
        {
            // Setup next point in childarray
            pair<int,int> nextPoint(next->getPoint().first+dx[i], next->getPoint().second+dy[i]);

            // If point is on board and we haven't visited yet - do this
            if(valid(nextPoint.first, nextPoint.second, boardWidth, boardHeight) && visit[nextPoint.first][nextPoint.second] == false)
            {
                // Make point visited
                visit[nextPoint.first][nextPoint.second] = true;

                // Create a new node. Insert it into the tree and the iteration vector.
                Node* child = new Node(nextPoint, next);
                iterationVector.push_back(child);
                board.insertChild(child);
            }

            // If we are at the final point. Print steps and return number of steps.
            if(nextPoint.first == knightEndXPosition &&nextPoint.second == knightEndYPosition)
            {
                board.printSteps();
                return iterationVector.back()->getDist();
            }
        }
    }
}


// Is it within the board.
bool Driver::valid(int x, int y, int boardHeight, int boardWidth)
{
    if(x >= boardWidth || y >= boardHeight || x < 1 || y < 1)
    {
        return false;
    }
    return true;
}
