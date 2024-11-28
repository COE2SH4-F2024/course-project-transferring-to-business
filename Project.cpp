#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "Player.h"
#include "GameMechs.h"

using namespace std;

#define DELAY_CONST 100000

void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);

//iteration 0 - will be removed upon completion of iteration 1
objPos arb1(4, 4, 'w');
objPos arb2(2, 4, 'q');
objPos arb3(7, 8, 'a');

Player *playerPtr;
GameMechs  *mechPtr;

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
    playerPtr = new Player(mechPtr);
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
}

void DrawScreen(void)
{
    MacUILib_clearScreen();
    int i;
    int j;

    for (i=0; i <= 9; i++) {
        for (j=0; j <= 19; j++){
            if (i == 0 || i == 9 || j == 0 || j == 19) {
                MacUILib_printf("#");
            }
            else if (i == playerPtr->getPlayerPos().pos->y && j == playerPtr->getPlayerPos().pos->x) {
                MacUILib_printf("%c", playerPtr->getPlayerPos().symbol);
            }
            else {
                MacUILib_printf(" ");
            }
        }
    
        MacUILib_printf("\n");
    }
  
}

void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}


void CleanUp(void)
{
    MacUILib_clearScreen();    

    MacUILib_uninit();
}
