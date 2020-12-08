#ifndef DRIVER_H
#define DRIVER_H
#include "Tree.h"
#include <iostream>

    int MinimumSteps(int boardHeight, int boardWidth, int knightStartXPosition, int knightStartYPosition, int knightEndXPosition, int knightEndYPosition);

    // Check if placement of x,y coordinate is within the board.
    bool valid(int x, int y, int boardHeight, int boardWidth);




#endif // DRIVER_H
