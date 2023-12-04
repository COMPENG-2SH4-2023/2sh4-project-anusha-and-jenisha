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
    foodPos.setObjPos(2, 2, 'o');

}

Food::~Food()
{

}

void Food::generateFood(objPosArrayList& playerPosList)
{

    srand(time(NULL));
    int flag = 0;
    int i;
    bool overlap = true;

    do {
        // Generate random coordinates within bounds
        foodPos.x = rand() % (mainGameMechsRef->getBoardSizeX() - 2) + 1;
        foodPos.y = rand() % (mainGameMechsRef->getBoardSizeY() - 2) + 1;

        overlap = false;
        for (i = 0; i < playerPosList.getSize(); i++) {
            objPos tempPos;
            playerPosList.getElement(tempPos, i);

            if (tempPos.isPosEqual(&foodPos)) {
                overlap = true;
                break;  // Exit the loop if overlap is found
            }
        }
    } while (overlap);
}


void Food::getFoodPos(objPos &returnPos)
{
   // Step 2: Food objPos getter method
   returnPos = foodPos;

}