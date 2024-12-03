#ifndef FOOD_H
#define FOOD_H


#include "Player.h"
#include "objPos.h"
#include "objPosArrayList.h"
#include "GameMechs.h"
#include <stdlib.h>


class Food
{
private:
    objPos foodPos; //current positon of food on board
    GameMechs* mainGameMechsRef; //pointer to GameMechs object, allowing access to initialized game mechanics

public:

    Food(GameMechs* thisGMRef); //constructor with food position initialization and reference to game mechanics
    ~Food(); //not needed but still implemented

    void generateFood(objPosArrayList* blockOff); //creates new random position for food while avoiding blocked positions
    objPos getFoodPos() const; //food position getter

};


#endif