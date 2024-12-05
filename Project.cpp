#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "Player.h"
#include "GameMechs.h"
#include "Food.h"
#include <time.h>

using namespace std;

#define DELAY_CONST 100000

void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);


Player *playerPtr;
GameMechs  *mechPtr;
Food *foodPtr;


int main(void)
{
    Initialize();

    while(mechPtr->getExitFlagStatus() == false)  
    {
        GetInput();
        RunLogic();
        DrawScreen();
        LoopDelay();
    }

    CleanUp();

}


void Initialize(void)
{
    MacUILib_init();
    MacUILib_clearScreen();

    mechPtr = new GameMechs(); //create GameMechs object to manage game mechanics
    foodPtr = new Food(mechPtr); //create food object, pass reference to game mechanics
    playerPtr = new Player(mechPtr, foodPtr); //create player object, passing references to GameMechs and Food objects
    
}

void GetInput(void)
{
   if (MacUILib_hasChar()){
        mechPtr->setInput(MacUILib_getChar()); 
    }
}

void RunLogic(void)
{
    if(mechPtr->getInput() != 0)  // if not null character
    {
        switch(mechPtr->getInput())
        {                      
            case 27:  // char 27 is the escape key
                mechPtr->setExitTrue(); //ends the game by setting exit flag to true
                break;
        }
        playerPtr->updatePlayerDir(); //update player direction based on input
        playerPtr->movePlayer(); //move player based on current direction
    }

}

void DrawScreen(void)
{
    MacUILib_clearScreen();
    int i;
    int j;
    int k;

    bool playerDrawn;

    for (i=0; i <= (mechPtr->getBoardSizeY() - 1); i++) {
        for (j=0; j <= (mechPtr->getBoardSizeX() - 1); j++){
            
            playerDrawn = false;

            for (k = 0; k < playerPtr->getPlayerPos()->getSize(); k++) {
                if (i == playerPtr->getPlayerPos()->getElement(k).pos->y && j == playerPtr->getPlayerPos()->getElement(k).pos->x) {
                    //draw player symbol if segment found at position (i,j)
                    MacUILib_printf("%c", playerPtr->getPlayerPos()->getElement(k).symbol);
                    playerDrawn = true;
                }
            }
            if(playerDrawn){} //skip all other if conditions if true

            else if (i == foodPtr->getFoodPos().pos->y && j == foodPtr->getFoodPos().pos->x) { 
                //check if current position matches food position
                MacUILib_printf("%c", foodPtr->getFoodPos().symbol); //draw food symbol
            }
            
            else if (i == 0 || i == (mechPtr->getBoardSizeY() - 1) || j == 0 || j == (mechPtr->getBoardSizeX() - 1)) {
                //check if current position is border
                MacUILib_printf("#"); // draw border symbol
            }

            else {
                    MacUILib_printf(" "); //draw empty space
                }

        }
        MacUILib_printf("\n");
    }

    MacUILib_printf("SCORE: %d\n", mechPtr->getScore());
}




void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}


void CleanUp(void)
{
    MacUILib_clearScreen(); 
    if (mechPtr->getLoseFlagStatus()) 
        printf("GAME OVER!!");
        
    delete playerPtr;
    delete foodPtr;
    delete mechPtr;
    //free memory of player, food and gamemechs objects
    MacUILib_uninit();
}
