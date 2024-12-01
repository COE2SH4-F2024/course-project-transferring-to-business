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
    objPos foodPos;

    int boardX;
    int boardY;

public:
    Food(int boardX, int boardY);
    Food(const Food& other);
    ~Food();
    Food& operator=(const Food& other);
    
    void generateFood(const objPos& block0ff);
    objPos getFoodPos() const;
};


#endif