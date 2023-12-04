#ifndef PLAYER_H
#define PLAYER_H

#include "GameMechs.h"
#include "objPos.h"
#include "objPosArrayList.h"
#include "Food.h"

class Player
{
    // Construct the remaining declaration from the project manual.

    // Only some sample members are included here

    // You will include more data members and member functions to complete your design.

    public:
        enum Dir {STATE_UP, STATE_DOWN, STATE_LEFT, STATE_RIGHT, STATE_IDLE, STOP};  // This is the direction state

        Player(GameMechs* thisGMRef, Food* thisFoodRef);
        ~Player();

        //void getPlayerPos(objPos &returnPos); // Upgrade this in iteration 3.
        objPosArrayList* getPlayerPos();
        //returns objPosArrayList reference to the array: *playerPosList
        void updatePlayerDir();
        void movePlayer();

        //new functions added for feature 2
        bool checkFoodConsumption();
        bool checkSpecialFoodConsumptionTail();
        bool checkSpecialFoodConsumption();
        void increasePlayerLength();

        //check for self collision
        bool checkSelfCollision();
        int constrFlag();



    private:
        //objPos playerPos; 
        objPosArrayList *playerPosList;   // Upgrade this in iteration 3 to arrayList      
        enum Dir myDir;

        // Need a reference to the Main Game Mechanisms
        GameMechs* mainGameMechsRef;
        Food* mainFoodRef;  // Add a member for the Food reference
};

#endif