#include "Player.h"


Player::Player(GameMechs* thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    myDir = STOP;

    // more actions to be included
    playerPos.pos->x = 4;
    playerPos.pos-> y = 6;
    playerPos.symbol = '*';
}


Player::~Player()
{
    // delete any heap members here
}

objPos Player::getPlayerPos() const
{
    // return the reference to the playerPos arrray list
    return playerPos;
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
                if (myDir == LEFT ||myDir == RIGHT ||myDir == STOP){ 
                    myDir = UP;
                }
                break;

            case 'a':
                if (myDir == UP ||myDir == DOWN ||myDir == STOP){
                    myDir = LEFT;
                }
                break;

            case 's':
                if (myDir == LEFT ||myDir == RIGHT ||myDir == STOP){
                    myDir = DOWN;
                }
                break;

            case 'd':
                if (myDir == UP ||myDir == DOWN ||myDir == STOP){
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