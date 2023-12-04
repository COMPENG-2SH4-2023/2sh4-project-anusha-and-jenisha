#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "Player.h" 
#include "GameMechs.h"
#include "Food.h"
#include "objPosArrayList.h"

using namespace std;

//100000
#define DELAY_CONST 100000


objPos myPos;


//these are both references (pointers) of their respective class type
GameMechs* myGM;
Player* myPlayer;

Food* myFood;


 //get the position of the food
    objPos foodPos;

//declare thse global
    objPosArrayList* playerBody;
    objPos tempBody;

//bool exitFlag;

bool collisionFlag = false;

void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);



int main(void)
{

    Initialize();

    while(myGM->getExitFlagStatus() == false)   
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

    myGM = new GameMechs(10, 30);
    
    myFood = new Food(myGM);

    //Constructor: this sets the initial starting position of the '*' - see the Player(GameMechs* thisGMRef) method
    myPlayer = new Player(myGM, myFood);



    //newly added here
    playerBody = myPlayer->getPlayerPos();


}

void GetInput(void)
{
   myGM -> getInput(); 
}

void RunLogic(void)
{

    myFood->getFoodPos(foodPos);


    //call the updatePlayerDir method
    //this method checks if the keyboard input is "wasd" and updates the position accordingly
    myPlayer->updatePlayerDir();

    //must move the player after updating position in previous line
    myPlayer->movePlayer();
    
    //collision detection ///////////////////////
    myPlayer->checkSelfCollision();

    

    //clear the key input so it's not repeated processed
    myGM->clearInput(); 

   
}

void DrawScreen(void)
{
    MacUILib_clearScreen();   

    playerBody = myPlayer->getPlayerPos();
    objPos tempBody;

   

    char symbolArray [10][30];


    int sizeX = myGM->getBoardSizeX();
    int sizeY = myGM->getBoardSizeY();


   myFood->getFoodPos(foodPos);

    

    for (int i = 0; i < sizeX; i++){ //10

        for(int j = 0; j < sizeY; j++){ //20
            
            if(i == 0 || i == sizeX-1){ //9
                symbolArray[i][j] = '#'; 

            }else if (i>=1 && i<=sizeX-2 && (j == 0 || j == sizeY-1)){ //8, 19
                symbolArray[i][j] = '#';   

            }else {
                symbolArray[i][j] = ' '; 
            }

             //update position of snake in the symbolArray
            for(int k = 0; k < playerBody->getSize(); k++){
                playerBody->getElement(tempBody, k);
                if(tempBody.x == i && tempBody.y == j){
                    symbolArray[i][j] = tempBody.symbol;

                }
            }

        }
    }

    
    playerBody->getHeadElement(myPos);
    // playerBody->getElement(element2, 1);
    // playerBody->getElement(element3, 2);


     //MacUILib_printf("\nScore: %d", score);
   int score = myGM->getScore();
   MacUILib_printf("\nScore: %d\n", score);

    symbolArray[foodPos.x][foodPos.y] = 'o';
    

    //PRINTING symbolArray[][] on the screen (including snake!!)
    for (int i = 0; i < sizeX; i++){ //10

        for(int j = 0; j < sizeY; j++){ //20

            MacUILib_printf("%c", symbolArray[i][j]);
        }
        MacUILib_printf("\n");
       
        
    }

    //display the loosing message if both flags are true
    if(myGM->getLoseFlagStatus() == true){ 
        MacUILib_printf("GAME OVER!");

    }
    
}

void LoopDelay(void){
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}


void CleanUp(void)
{
    MacUILib_clearScreen();    
  
    MacUILib_uninit();

    delete myGM;       // Delete the GameMechs object
    delete myPlayer;   // Delete the Player object
    delete myFood;
}