#include "Player.h"


Player::Player(GameMechs* thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    myDir = STOP;

    // more actions to be included
}


Player::~Player()
{
    // delete any heap members here
}

objPos Player::getPlayerPos(objPos &returnPos) const
{
    // return the reference to the playerPos arrray list
}

void Player::updatePlayerDir()
{
        // PPA3 input processing logic
        char input = mainGameMechsRef->getInput();

        if(input != 0)  // if not null character
    {
        switch(input)
        {                      
            case 'w':
                if (myDir == LEFT ||myDir == RIGHT){ 
                    myDir = UP;
                }
                break;

            case 'a':
                if (myDir == UP ||myDir == DOWN){
                    myDir = LEFT;
                }
                break;

            case 's':
                if (myDir == LEFT ||myDir == RIGHT){
                    myDir = DOWN;
                }
                break;

            case 'd':
                if (myDir == UP ||myDir == DOWN){
                    myDir = RIGHT;
                }
                break;  
        }
    }        
}

void Player::movePlayer()
{
    // PPA3 Finite State Machine logic
    switch(myDir) {
        case 0:
            if (!(playerPos.pos->y <= 1)) {
                playerPos.pos->y--;
            }
            else {
                playerPos.pos->y = 8;
            }
            break;
        case 1:
            if (!(playerPos.pos->y >= 8)) {
                playerPos.pos->y++;
            }
            else {
                playerPos.pos->y = 1;
            }
            break;
        case 2:
            if (!(playerPos.pos->x <= 1)) {
                playerPos.pos->x--;
            }
            else {
                playerPos.pos->x = 18;
            }
            break;
        case 3:
            if (!(playerPos.pos->x >= 18)) {
                playerPos.pos->x++;
            }
            else {
                playerPos.pos->x = 1;
            }
            break;
    }
    
}

// More methods to be added