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

    // Step 1: Create an objPos member to track the food position
    // This is already declared in the class as foodPos

    // Step 2: Random food generation method
    do
    {
        foodPos.x = rand() % gameMechs.getBoardSizeX();
        foodPos.y = rand() % gameMechs.getBoardSizeY();
    } while (foodPos.isPosEqual(&blockOff) || foodPos.x == 0 || foodPos.y == 0 || foodPos.x == gameMechs.getBoardSizeX() || foodPos.y == gameMechs.getBoardSizeY());
//foodPos.x == blockOff.x && foodPos.y == blockOff.y

    // Step 3: Initialization routine
    // No specific action required here since initialization is done in generateFood

    // Step 4: In the draw routine, make sure you can get the objPos information of the food,
    // and print its symbol at its corresponding x-y position.
    // This depends on your drawing routine. You might use the obtained position to print the symbol.
}

void Food::getFoodPos(objPos &returnPos)
{
    // Step 2: Food objPos getter method
    returnPos = foodPos;
    // Note: Depending on how you structure your drawing routine, you might use this
    // position information to print the symbol at the corresponding x-y position.
    // For example:
    // printSymbolAtPosition(foodPos.x, foodPos.y, foodPos.symbol);
    // Make sure to implement the printSymbolAtPosition function based on your drawing routine.
}