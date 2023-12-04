#include "GameMechs.h"
#include "MacUILib.h"

GameMechs::GameMechs()
{

    input = 0;
    score = 0;
    exitFlag = false;
    boardSizeX = 10;
    boardSizeY = 30;
    loseFlag = false;

   

}

GameMechs::GameMechs(int boardX, int boardY)
{

    input = 0;
    score = 0;
    exitFlag = false;
    boardSizeX = boardX;
    boardSizeY = boardY;
    loseFlag = false;

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
    exitFlag = false;
}

void GameMechs::setInput(char this_input)
{
    input = this_input;

}

void GameMechs::clearInput()
{
    //input = NULL;
    input = 0;
}

void GameMechs::incrementScore()
{
    score++;
}

void GameMechs::setLoseFlag()
{
    loseFlag = true;
}

bool GameMechs::getLoseFlagStatus()
{
    return loseFlag;
}