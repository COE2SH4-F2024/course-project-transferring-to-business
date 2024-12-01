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



void Food::generateFood(objPos blockOff)
{
    char input = mainGameMechsRef->getInput();
    if (input == 'p') {
        do
        {
            int randomX = rand() % (mainGameMechsRef->getBoardSizeX() - 2) +1;
            int randomY = rand() % (mainGameMechsRef->getBoardSizeY() - 2) + 1;
            foodPos.setObjPos(randomX, randomY, 'p');
        } while (foodPos.isPosEqual(&blockOff));

        mainGameMechsRef->clearInput();
    }
}

objPos Food::getFoodPos() const
{
    return foodPos;
}