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

    mechPtr = new GameMechs();
    foodPtr = new Food(mechPtr);
    playerPtr = new Player(mechPtr, foodPtr);
    
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
                mechPtr->setExitTrue();
                break;
        }
        playerPtr->updatePlayerDir();
        playerPtr->movePlayer();
    }

    // if (mechPtr->getLoseFlagStatus()) {
    //     MacUILib_clearScreen();
    //     MacUILib_printf("GAME OVER!");
    // }
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
                    MacUILib_printf("%c", playerPtr->getPlayerPos()->getElement(k).symbol);
                    //break;
                    playerDrawn = true;
                }
            }
            if(playerDrawn){}

            else if (i == foodPtr->getFoodPos().pos->y && j == foodPtr->getFoodPos().pos->x) {
                MacUILib_printf("%c", foodPtr->getFoodPos().symbol);

            }
            
            else if (i == 0 || i == (mechPtr->getBoardSizeY() - 1) || j == 0 || j == (mechPtr->getBoardSizeX() - 1)) {
                MacUILib_printf("#");
            }

            else {
                    MacUILib_printf(" ");
                }

        }
        MacUILib_printf("\n");
    }

    MacUILib_printf("\nCOMMENTS!!!!!!!!!!!!!!\nIMPLEMENTGAMEBOARDMEMBERS");
    MacUILib_printf("NUMBER OF SEGMENTS PRINTED: %d\n", k);
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

    MacUILib_uninit();
}
