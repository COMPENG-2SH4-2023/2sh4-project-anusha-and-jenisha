#include "GameMechs.h"
#include "MacUILib.h"


GameMechs::GameMechs()
{

    input = 0;
    exitFlag = false;
    boardSizeX = 10;
    boardSizeY = 30;

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

int GameMechs::getScore() {
      return score;
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
    score++;
}

void GameMechs::setLoseFlag(bool value)
{

    loseFlag = value;

}

bool GameMechs::getLoseFlagStatus()
{
    return loseFlag;
}


