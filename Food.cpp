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
    foodPos.setObjPos(2, 2, 'o'); //mainGameMechsRef->getBoardSizeX()/2, mainGameMechsRef->getBoardSizeY()/2, 'o');
    foodBucket = new objPosArrayList();
}

Food::~Food()
{
    //delete foodBucket;
    cout << "Destructor Called" << endl;
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

    // Print a message to indicate that the food has been generated
    //cout << "Food generated successfully at position: (" << foodPos.x << ", " << foodPos.y << ")" << endl;
}


void Food::generateSpecialFood(objPosArrayList& playerPosList) {
    for (int i = 0; i < 3; ++i) {
        generateFood(playerPosList);

        objPos regularFoodPos;
        getFoodPos(regularFoodPos);
        foodBucket->insertTail(regularFoodPos);
        
    }

    // Generate one special food item
    bool overlap = true;
    do {
        // Generate random coordinates within bounds
        foodPos.x = rand() % (mainGameMechsRef->getBoardSizeX() - 2) + 1;
        foodPos.y = rand() % (mainGameMechsRef->getBoardSizeY() - 2) + 1;

        overlap = false;
        for (int i = 0; i < playerPosList.getSize(); i++) {
            objPos tempPos;
            playerPosList.getElement(tempPos, i);

            if (tempPos.isPosEqual(&foodPos)) {
                overlap = true;
                break;  
            }
        }
    } while (overlap);

    foodPos.symbol = 'X';  

    foodBucket->insertTail(foodPos);
}

void Food::getFoodPos(objPos &returnPos)
{
    // Step 2: Food objPos getter method
    returnPos = foodPos;

}

void Food::getSpecialFoodPos(objPos& returnPos) {

    //returnPos = specialFoodPos;
    returnPos = foodPos;

}