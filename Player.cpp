#include "Player.h"
#include "Food.h"

Player::Player(GameMechs* thisGMRef, Food* foodRef)
{
    mainGameMechsRef = thisGMRef; //reference to game mechanics object
    foodPtr = foodRef; //reference to food object
    myDir = STOP; //keep player stopped at initial state

    playerPosListPtr = new objPosArrayList(); //keeps track of player's position 
    new_head.pos->x = 4; //initial x coordinate
    new_head.pos-> y = 6; //initial y coordinate
    new_head.symbol = '*';  
    playerPosListPtr->insertHead(new_head);
    
}


Player::~Player()
{
    delete playerPosListPtr; //free memory for the position list
}

objPosArrayList* Player::getPlayerPos() const
{
    return playerPosListPtr; // returns the reference to the playerPos arrray list
}

void Player::updatePlayerDir()
{
        // PPA3 input processing logic, self explanatory
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
}

void Player::movePlayer()
{
    // PPA3 Finite State Machine logic, self explanatory
    new_head.setObjPos(playerPosListPtr->getHeadElement());
    new_head.symbol = '*';
    
    switch(myDir) {
        case UP:
            if (!(playerPosListPtr->getHeadElement().pos->y <= 1)) {
                new_head.pos->y--;
            }
            else {
                new_head.pos->y = (mainGameMechsRef->getBoardSizeY()-2);
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
                new_head.pos->x = (mainGameMechsRef->getBoardSizeX()-2);
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

objPos Player::getnew_head() const {
    return new_head;
}

bool Player::checkFoodCollision() {

    objPos* tempFoodPos= new objPos; //temp objPos pointer to store food position
    tempFoodPos->setObjPos((foodPtr->getFoodPos())); //set temp position of player to match food position

    if (playerPosListPtr->getHeadElement().isPosEqual(tempFoodPos)) { //if head matches food position
        delete tempFoodPos; //clean temporary position memory
        return true; 
    }

    else {
        delete tempFoodPos; //clean temporary position memory
        return false;
    }
}

void Player::increasePlayerLength() {
    playerPosListPtr->insertHead(new_head); //add new head 
    foodPtr->generateFood(playerPosListPtr); //generate new food position
    mainGameMechsRef->incrementScore();
}

bool Player::checkSelfCollision() {
    objPos tempPos; //temp variable to hold segment's position
    for (int i = 1; i < playerPosListPtr->getSize(); i++) { //checking head against rest of body
        tempPos = playerPosListPtr->getElement(i); 
        if (playerPosListPtr->getHeadElement().isPosEqual(&tempPos)) { //check if head matches position of a body segment
            return true;
        }
    }
    return false;
}