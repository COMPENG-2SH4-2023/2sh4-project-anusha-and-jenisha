#ifndef FOOD_H
#define FOOD_H

#include "GameMechs.h"
#include "MacUILib.h"


class Food
{
    private:
        // Food generation
        objPos foodPos;
        GameMechs* mainGameMechsRef;
        objPosArrayList *foodBucket;  

 //use pointer
    public:
        Food(GameMechs* thisGMRef); // Default constructor for Food class
        ~Food(); // Destructor 


    // Method for generating random food
    void generateFood(objPosArrayList& playerPosList);

    // Getter method for obtaining the current position of the food
    void getFoodPos(objPos &returnPos);

};

#endif