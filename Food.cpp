#include "GameMechs.h"
#include "MacUILib.h"
#include "Food.h"

#include <cstdlib>
#include <ctime>

Food::Food()
{
    srand(time(0));
    // Initialization code for the Food class, if any
}

Food::~Food()
{
    // Destructor code for the Food class, if any
}

void Food::generateFood(objPos blockOff)
{
    srand(time(0));

    // Step 2: Random food generation method
    do
    {
        foodPos.x = rand() % gameMechs.getBoardSizeX();
        foodPos.y = rand() % gameMechs.getBoardSizeY();
    } while (foodPos.isPosEqual(&blockOff) || foodPos.x == 0 || foodPos.y == 0 || foodPos.x == gameMechs.getBoardSizeX() || foodPos.y == gameMechs.getBoardSizeY());
//foodPos.x == blockOff.x && foodPos.y == blockOff.y

}

void Food::getFoodPos(objPos &returnPos)
{
    // Step 2: Food objPos getter method
    returnPos = foodPos;

}