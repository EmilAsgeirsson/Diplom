#ifndef DRIVER_H
#define DRIVER_H
#include "Tree.h"

class Driver
{
public:
    int minimumSteps(int boardHeight, int boardWidth, int knightStartXPosition, int knightStartYPosition, int knightEndXPosition, int knightEndYPosition);

private:
    // Check if placement of x,y coordinate is within the board.
    bool valid(int x, int y, int boardHeight, int boardWidth);

};


#endif // DRIVER_H
