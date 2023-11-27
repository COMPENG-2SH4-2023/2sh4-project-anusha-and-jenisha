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
    foodPos.setObjPos(mainGameMechsRef->getBoardSizeX()/2, mainGameMechsRef->getBoardSizeY()/2, '&');
}

Food::~Food()
{
    cout << "Destructor Called" << endl;
}

void Food::generateFood(objPos blockOff)
{

    srand(time(NULL));
    int i, j;
    int candidate = 0;
    int candidateCoords[10][30];

    for (i = 0; i < 10; i++) {
        for (j = 0; j < 30; j++) {
            candidateCoords[i][j] = 0;
        }
    }

    do {
        foodPos.x = rand() % mainGameMechsRef->getBoardSizeX();
        foodPos.y = rand() % mainGameMechsRef->getBoardSizeY();

        // Ensure food position is within bounds
        foodPos.x = std::max(1, std::min(foodPos.x, mainGameMechsRef->getBoardSizeX() - 2));
        foodPos.y = std::max(1, std::min(foodPos.y, mainGameMechsRef->getBoardSizeY() - 2));


    } while (foodPos.isPosEqual(&blockOff) ||
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