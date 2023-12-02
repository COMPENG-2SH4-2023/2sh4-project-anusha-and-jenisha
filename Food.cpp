#include "GameMechs.h"
#include "MacUILib.h"
#include "Food.h"


#include <iostream>
#include <cstdlib>
#include <ctime>


using namespace std;


Food::Food(GameMechs* thisGMRef)
{
   //game mech reference input - pointer
   //assign pointer to input
   mainGameMechsRef = thisGMRef;
   foodPos.setObjPos(mainGameMechsRef->getBoardSizeX()/2, mainGameMechsRef->getBoardSizeY()/2, 'o');
}


Food::~Food()
{
   cout << "Destructor Called" << endl;
}


void Food::generateFood(objPosArrayList& playerPosList)
{

   srand(time(NULL));
   int i, j;
   int isEqual = 0;
   int candidate = 0;
   int candidateCoords[10][30];
   int flag = 0;


   for (i = 0; i < 10; i++) {
       for (j = 0; j < 30; j++) {
           candidateCoords[i][j] = 0;
       }
   }


   do {
       foodPos.x = rand() % mainGameMechsRef->getBoardSizeX();
       foodPos.y = rand() % mainGameMechsRef->getBoardSizeY();


       // Ensure food position is within bounds
       foodPos.x = max(1, min(foodPos.x, mainGameMechsRef->getBoardSizeX() - 2));
       foodPos.y = max(1, min(foodPos.y, mainGameMechsRef->getBoardSizeY() - 2));


for (i = 0; i < playerPosList.getSize(); i++)
{

    if (i >= playerPosList.getSize()) {
        // Additional safety check to avoid going out of bounds
        break;
    }
    objPos tempPos;
    playerPosList.getElement(tempPos, i);


   if (tempPos.isPosEqual(&foodPos))
   {
      flag = 1;
      
   }
}


//go through all position
   } while (flag == 1 ||
            foodPos.x == 0 || foodPos.y == 0 ||
            foodPos.x == mainGameMechsRef->getBoardSizeX() - 1 ||
            foodPos.y == mainGameMechsRef->getBoardSizeY() - 1 ||
            candidateCoords[foodPos.x][foodPos.y] != 0);


   // Mark the generated coordinates as used
   candidateCoords[foodPos.x][foodPos.y] = 1;


   // Print a message to indicate that the food has been generated
   cout << "Food generated successfully at position: (" << foodPos.x << ", " << foodPos.y << ")" << endl;
}
void Food::getFoodPos(objPos &returnPos)
{
   // Step 2: Food objPos getter method
   returnPos = foodPos;


}
