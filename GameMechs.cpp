#include "GameMechs.h"
#include "MacUILib.h"


GameMechs::GameMechs()
{

    input = 0;
    exitFlag = false;
    boardSizeX = 20;
    boardSizeY = 10;

}

GameMechs::GameMechs(int boardX, int boardY)
{

    input = 0;
    exitFlag = false;
    boardSizeX = boardX;
    boardSizeY = boardY;

}

// do you need a destructor?



bool GameMechs::getExitFlagStatus()
{
    return exitFlag;

}

char GameMechs::getInput()
{

    if(MacUILib_hasChar()) //Check whether there's an input for process
    {
        input = MacUILib_getChar();
    }

    return input;

}

int GameMechs::getBoardSizeX()
{
    return boardSizeX;
}

int GameMechs::getBoardSizeY()
{
    return boardSizeY;
}


void GameMechs::setExitTrue()
{
    exitFlag = true;

}

void GameMechs::setInput(char this_input)
{
    input = this_input;

}

void GameMechs::clearInput()
{
    input = NULL;
    //input = 0;
}

void GameMechs::incrementScore()
{
    // Increment the score and print a debug message
    score++;
    // Add appropriate print statement for debugging
    // For example:
    // std::cout << "Score incremented! Current score: " << score << std::endl;
}

void GameMechs::setLoseFlag(bool value)
{
    // Set the lose flag and print a debug message
    loseFlag = value;
    // Add appropriate print statement for debugging
    // For example:
    // std::cout << "Lose flag set to: " << (loseFlag ? "true" : "false") << std::endl;
}

bool GameMechs::getLoseFlagStatus()
{
    return loseFlag;
}
