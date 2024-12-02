#include "Player.h"
#include "Food.h"

Player::Player(GameMechs* thisGMRef, Food* foodRef)
{
    mainGameMechsRef = thisGMRef;
    foodPtr = foodRef;
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
    delete playerPosListPtr;
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
    new_head.setObjPos(playerPosListPtr->getHeadElement());
    new_head.symbol = '*';
    
    switch(myDir) {
        case UP:
            if (!(playerPosListPtr->getHeadElement().pos->y <= 1)) {
                new_head.pos->y--;
            }
            else {
                new_head.pos->y = 8;
            }
            break;
        case DOWN:
            if (!(playerPosListPtr->getHeadElement().pos->y >= 8)) {
                new_head.pos->y++;
            }
            else {
                new_head.pos->y = 1;
            }
            break;
        case LEFT:
            if (!(playerPosListPtr->getHeadElement().pos->x <= 1)) {
                new_head.pos->x--;
            }
            else {
                new_head.pos->x = 18;
            }
            break;
        case RIGHT:
            if (!(playerPosListPtr->getHeadElement().pos->x >= 18)) {
                new_head.pos->x++;
            }
            else {
                new_head.pos->x = 1;
            }
            break;
        
    }
    
    if (checkFoodCollision()) {
        increasePlayerLength();
    }
    else if (checkSelfCollision()) {
        mainGameMechsRef->setExitTrue();
        mainGameMechsRef->setLoseFlag();
    }
    else {
        playerPosListPtr->insertHead(new_head);
        playerPosListPtr->removeTail();
    }
    
}

// More methods to be added

//Debugging purposes
objPos Player::getnew_head() const {
    return new_head;

}

bool Player::checkFoodCollision() {

    objPos* tempFoodPos= new objPos;
    tempFoodPos->setObjPos((foodPtr->getFoodPos()));

    if (playerPosListPtr->getHeadElement().isPosEqual(tempFoodPos)) {
        return true;
    }

    else {
        return false;
    }
}

void Player::increasePlayerLength() {
    playerPosListPtr->insertHead(new_head);
    foodPtr->generateFood(playerPosListPtr);
    mainGameMechsRef->incrementScore();
}

bool Player::checkSelfCollision() {
    objPos tempPos;
    for (int i = 1; i < playerPosListPtr->getSize(); i++) {
        tempPos = playerPosListPtr->getElement(i);
        if (playerPosListPtr->getHeadElement().isPosEqual(&tempPos)) {
            return true;
        }
    }
    return false;
}