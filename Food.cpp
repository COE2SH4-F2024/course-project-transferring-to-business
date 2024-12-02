#include "Food.h"
#include <stdlib.h>
#include <cstdlib>
#include <time.h>

using namespace std;

Food::Food(GameMechs* thisGMRef)
{
    srand(time(NULL));
    foodPos = objPos(3,3,'$');
    mainGameMechsRef = thisGMRef;
}

Food::~Food() {

}



void Food::generateFood(objPosArrayList* blockOff)
{
    char input = mainGameMechsRef->getInput();
    int i;
    objPos tempPos;
    for (i = 0; i < blockOff->getSize(); i++) {
        do
        {
            int randomX = rand() % (mainGameMechsRef->getBoardSizeX() - 2) +1;
            int randomY = rand() % (mainGameMechsRef->getBoardSizeY() - 2) + 1;
            foodPos.setObjPos(randomX, randomY, '$');
            tempPos = (blockOff->getElement(i));
        } while (foodPos.isPosEqual(&tempPos));
    }

}


objPos Food::getFoodPos() const
{
    return foodPos;
}