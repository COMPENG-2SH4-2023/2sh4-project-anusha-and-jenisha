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
    void generateSpecialFood(objPosArrayList& playerPosList); 

    // Getter method for obtaining the current position of the food
    void getFoodPos(objPos &returnPos);
    void getSpecialFoodPos(objPos& returnPos);

    void getFoodBucketElement(objPos& returnPos, int index);

    
   
    void getSpecialFoodPosTail(objPos& returnPos);

    // Need a reference to the Main Game Mechanisms
    
};

#endif