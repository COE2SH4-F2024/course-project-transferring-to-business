#include "Food.h"
#include <stdlib.h>
#include <cstdlib>
#include <time.h>

using namespace std;

Food::Food(GameMechs* thisGMRef)
{
    srand(time(NULL)); 
    foodPos = objPos(3,3,'$'); //start position of the food, with food symbol
    mainGameMechsRef = thisGMRef; //reference to main game mechanics for later use
}

Food::~Food() {
 //no cleanup necessary
}



void Food::generateFood(objPosArrayList* blockOff)
{
    char input = mainGameMechsRef->getInput(); 
    int i;
    objPos tempPos;
    for (i = 0; i < blockOff->getSize(); i++) {
        do
        {
            int randomX = rand() % (mainGameMechsRef->getBoardSizeX() - 2) +1;  //generate food in random X coordinate inside game boundary
            int randomY = rand() % (mainGameMechsRef->getBoardSizeY() - 2) + 1; //generate food in random Y coordinate inside game boundary
            foodPos.setObjPos(randomX, randomY, '$'); 
            tempPos = (blockOff->getElement(i)); //get a blocked position from block0ff list 
        } while (foodPos.isPosEqual(&tempPos));  //loop as long as the food position coincides with a blocked position
    }

}


objPos Food::getFoodPos() const
{
    return foodPos; 
}