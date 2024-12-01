#include "Player.h"


Player::Player(GameMechs* thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    myDir = STOP;

    // more actions to be included
    playerPosListPtr = new objPosArrayList;
    new_head.pos->x = 4;
    new_head.pos-> y = 6;
    new_head.symbol = '*';  
    playerPosListPtr->insertHead(new_head);
}


Player::~Player()
{
    // delete any heap members here
}

objPosArrayList* Player::getPlayerPos() const
{
    // return the reference to the playerPos arrray list
    return playerPosListPtr;
}

void Player::updatePlayerDir()
{
        // PPA3 input processing logic
        char input = mainGameMechsRef->getInput();

        if(input != 0 || input != 'w' || input != 'a' || input != 's' || input != 'd')  // if not null character
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
    //mainGameMechsRef->clearInput();        
}

void Player::movePlayer()
{
    // PPA3 Finite State Machine logic
    switch(myDir) {
        case 0:
            if (!(playerPosListPtr->getHeadElement().pos->y <= 1)) {
                new_head.pos->y--;
                playerPosListPtr->insertHead(new_head);
                playerPosListPtr->removeTail();
            }
            else {
                new_head.pos->y = 8;
                playerPosListPtr->insertHead(new_head);
                playerPosListPtr->removeTail();
            }
            break;
        case 1:
            if (!(playerPosListPtr->getHeadElement().pos->y >= 8)) {
                new_head.pos->y++;
                playerPosListPtr->insertHead(new_head);
                playerPosListPtr->removeTail();
            }
            else {
                new_head.pos->y = 1;
                playerPosListPtr->insertHead(new_head);
                playerPosListPtr->removeTail();
            }
            break;
        case 2:
            if (!(playerPosListPtr->getHeadElement().pos->x <= 1)) {
                new_head.pos->x--;
                playerPosListPtr->insertHead(new_head);
                playerPosListPtr->removeTail();
            }
            else {
                new_head.pos->x = 18;
                playerPosListPtr->insertHead(new_head);
                playerPosListPtr->removeTail();
            }
            break;
        case 3:
            if (!(playerPosListPtr->getHeadElement().pos->x >= 18)) {
                new_head.pos->x++;
                playerPosListPtr->insertHead(new_head);
                playerPosListPtr->removeTail();
            }
            else {
                new_head.pos->x = 1;
                playerPosListPtr->insertHead(new_head);
                playerPosListPtr->removeTail();
            }
            break;
    }
    
}

// More methods to be added

//Debugging purposes
objPos Player::getnew_head() const {
    return new_head;

}