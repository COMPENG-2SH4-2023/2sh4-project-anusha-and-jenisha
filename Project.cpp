
#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "Player.h"
#include "GameMechs.h"
#include "Food.h"
#include "objPosArrayList.h"


using namespace std;


#define DELAY_CONST 100000


//board size is defined in GameMechs.h class
//global declaration of variable of type objPos
//we can use any of the functions defined in the objPos.h class
objPos myPos;


//these are both references (pointers) of their respective class type
GameMechs* myGM;
Player* myPlayer;
Food* myFood;




//get the position of the food
objPos foodPos;


//bool exitFlag;


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





   // myFood->generateFood(*playerPosList);
   // objPosArrayList* foodPosition = myFood->getFoodPos();


   //objPos foodPosition = myFood->generateFood(*playerPosList);
// Assuming you have a method to retrieve food positions




   //contains an address to a structure on the heap for game mechanics
   myGM = new GameMechs(10, 30); //define new object and constructor (initializer) is called


   myFood = new Food(myGM);
  
   //Constructor: this sets the initial starting position of the '*' - see the Player(GameMechs* thisGMRef) method
   myPlayer = new Player(myGM, myFood);



   objPosArrayList* playerBody = myPlayer->getPlayerPos();
   objPos tempBody;


   //food
   //objPos tempPos{1, 1, 'o'};
   //myGM->generateFood(tempPos); //change this to an array list operation






   //initialize the starting position of the symbol
   //myPos.setObjPos(5, 9, '*');


   //exitFlag = false;


}


void GetInput(void)
{
  myGM -> getInput(); // In input collection stage, collect the input ASCII character into the corresponding field in gameMechanics object using the correct setter method
}


void RunLogic(void)
{


   //call the updatePlayerDir method
   //this method checks if the keyboard input is "wasd" and updates the position accordingly
   myPlayer->updatePlayerDir();


   //must move the player after updating position in previous line
   myPlayer->movePlayer();


   //clear the key input so it's not repeated processed
   myGM->clearInput();

 
}


void DrawScreen(void)
{
   MacUILib_clearScreen();  


   //Why pass tempPos in? ans: the input parameter of the function is (objPos &returnPos) an address of type objPos




   objPosArrayList* playerBody = myPlayer->getPlayerPos();
   objPos tempBody;


   //OLD CODE
   //objPos tempPos;
   //myPlayer->getPlayerPos(tempPos); //get the player pos


   /*MacUILib_printf("BoardSize: %dx%d, Player Pos: <%d, %d> + %c\n",
                   myGM->getBoardSizeX(),
                   myGM->getBoardSizeY(),
                   tempPos.x, tempPos.y, tempPos.symbol);*/




   //initialize the gameboard as an array (# = border)
   char symbolArray [10][30];


   //save the boardsize values into variables
   int sizeX = myGM->getBoardSizeX();
   int sizeY = myGM->getBoardSizeY();

    //int score = myGM->incrementScore();


 
 
   myFood->getFoodPos(foodPos);




   //For loop assigns #'s and ' 's to the array (no-printing here)
   //Border height=10 (0-9) width=20 (0-19)
   //outer loop controls iterating through the height, inner loop checks width
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
    //MacUILib_printf("\nScore: %d", score);
   int score = myGM->getScore();
   MacUILib_printf("\nScore: %d", score);
   MacUILib_printf("\nFood Position: (%d, %d)\n", foodPos.x, foodPos.y);

   






 


   //must access the x and y position coords and symbol, then update their location in the symbolArray
   //update the xy coords and position of the symbol
   //symbolArray[tempPos.x][tempPos.y] = tempPos.symbol;


  
   //put the food symbol in the array
   symbolArray[foodPos.x][foodPos.y] = 'o';


  


   //PRINTING symbolArray[][] on the screen (including snake!!)
   for (int i = 0; i < sizeX; i++){ //10


       for(int j = 0; j < sizeY; j++){ //20


           MacUILib_printf("%c", symbolArray[i][j]);
           //cout << symbolArray[i][j];
       }
       MacUILib_printf("\n");
     
      
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
