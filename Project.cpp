#include <iostream>
#include "MacUILib.h"
#include "objPos.h"

using namespace std;

#define DELAY_CONST 100000

bool exitFlag;

void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);

char input;
objPos arb1(4, 4, 'w');
objPos arb2(2, 4, 'q');
objPos arb3(7, 8, 'a');

int main(void)
{

    Initialize();

    while(exitFlag == false)  
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

    exitFlag = false;
}

void GetInput(void)
{
   if (MacUILib_hasChar()){
        input = MacUILib_getChar();
    }
}

void RunLogic(void)
{
    if(input != 0)  // if not null character
    {
        switch(input)
        {                      
            case 27:  // char 27 is the escape key
                exitFlag = 1;
                break;
        }
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
            else if (i == arb1.pos->x && j == arb1.pos->y) {
                MacUILib_printf("%c", arb1.symbol);
            }
            else if (i == arb2.pos->x && j == arb2.pos->y) {
                MacUILib_printf("%c", arb2.symbol);
            }
            else if (i == arb3.pos->x && j == arb3.pos->y) {
                MacUILib_printf("%c", arb3.symbol);
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
