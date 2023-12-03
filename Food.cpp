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

    //bonus
    foodBucket = new objPosArrayList();

}

Food::~Food()
{
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
    
    //generate the normal 3 food items
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

           //getting the snake body position
            objPos tempPos;
            playerPosList.getElement(tempPos, i);

            /////////check if there's overlap of special food with previously generated food
           //must loop through foodbucket array of normal food
            for(int j =0; j < foodBucket.getSize(); j++){

                //getting the position of the normal food generated above
                objPos tempFoodPart;
                foodBucket->getElement(tempFoodPart, j);

                if (tempFoodPart.isPosEqual(&foodPos)) {
                overlap = true;
                break;  
            }
            //this breaks out of the outer for loop so we can generate new coords
            if(overlap == true){
                break;
            }
          
                //}

            //check if there's overlap with the snake body
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


//get the tail element of the foodBucket
void Food::getSpecialFoodPosTail(objPos& returnPos) {

    
    //playerPosList.getTailElement(additions);
    foodBucket.getTailElement(returnPos);
    //returnPos = foodPos;

}
