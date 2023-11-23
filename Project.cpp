#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "GameMechs.h"
#include "Player.h"



using namespace std;

#define DELAY_CONST 100000

objPos myPos;

bool exitFlag;

GameMechs* myGM; //Declare pointer to a gameMechanics class in the global scop
Player* myPlayer;

void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);



int main(void)
{

    Initialize();

    while(myGM->getExitFlagStatus() == false)  // Update the program loop to access the exit flag in the gameMechanics object
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

    myGM = new GameMechs(26,13); //During initialization, create a gameMechanics object on the heap
    myPlayer = new Player(myGM);
}

void GetInput(void)
{
    myGM -> getInput(); // In input collection stage, collect the input ASCII character into the corresponding field in gameMechanics object using the correct setter method
}

void RunLogic(void)
{
    myPlayer->updatePlayerDir(); 
}

void DrawScreen(void)
{
    MacUILib_clearScreen();  

    objPos tempPos;
    myPlayer->getPlayerPos(tempPos);

    MacUILib_printf("BoardSize: %dx%d,  Player Pos: <%d, %d> + %c\n",
                    myGM -> getBoardSizeX(),
                    myGM -> getBoardSizeY(),
                    tempPos.x, tempPos.y, tempPos.symbol);  


    //MacUILib_printf("Object <%d, %d> with %c\n", myPos.x, myPos.y, myPos.symbol);
    

}

void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}


void CleanUp(void)
{
    MacUILib_clearScreen();    
  
    MacUILib_uninit();
        // Perform any required end-game actions


    delete myGM;       // Delete the GameMechs object
    delete myPlayer;   // Delete the Player object

}
