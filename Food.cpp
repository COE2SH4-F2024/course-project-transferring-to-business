#include "Food.h"
#include <stdlib.h>
#include <cstdlib>

Food::Food(int boardX, int boardY) : boardSizeX(boardX), boardSizeY(boardY) 
{
    foodPos = objPos(0,0,'*');
}

Food::~Food()
{}

Food::Food(const Food& other) : boardSizeX(other.boardSizeX), boardSizeY(other.boardSizeY),foodPos(other.foodPos)
{}

Food& Food::operator=(const Food& other)
{
    if (this != &other)
    {
        boardSizeX = other.boardSizeX;
        boardSizeY = other.boardSizeY;

    }
    
}
void Food::generateFood(const objPos& block0ff)
{
    do
    {
        int randomX = rand() % (boardSizeX - 2) +1;
        int randomY = rand() % (boardSizeY - 2) + 1;
        foodPos.setObjPos(randomX, randomY, '*');
    } while (foodPos.isPosEqual(&block0ff));
    
}

objPos Food::getFoodPos() const
{
    return foodPos;
}