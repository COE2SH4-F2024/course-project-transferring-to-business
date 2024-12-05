#ifndef PLAYER_H
#define PLAYER_H

#include "GameMechs.h"
#include "objPos.h"
#include "objPosArrayList.h"
#include "Food.h"

class Food;

class Player
{
    public:
        enum Dir {UP, DOWN, LEFT, RIGHT, STOP};  // This is the direction state
        
        Player(GameMechs* thisGMRef, Food* foodRef); //default constructor
        ~Player(); //destructor

        objPosArrayList* getPlayerPos() const; //player position getter 
        objPos getnew_head() const; //current head position getter
        void updatePlayerDir(); //updates player direction
        void movePlayer(); //moves player based on direction

        // More methods to be added here
        bool checkFoodCollision(); //collision with food detection
        void increasePlayerLength(); 
        bool checkSelfCollision(); //collision with self detection


    private:
        objPosArrayList *playerPosListPtr; //pointer to list of positions of player's body
        objPos new_head; //current position of player's head
        enum Dir myDir; //player's current direction

        GameMechs* mainGameMechsRef; //reference to main game mechanics
        Food* foodPtr; //reference to food object
};

#endif