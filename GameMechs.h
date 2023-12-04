#ifndef GAMEMECHS_H
#define GAMEMECHS_H

#include <cstdlib>
#include <time.h>

#include "objPos.h"
#include "objPosArrayList.h"
// #include "Food.h"


using namespace std;

class GameMechs
{


    private:
        char input;
        bool exitFlag;
        bool loseFlag;
        int score;

        int boardSizeX;
        int boardSizeY;

    public:
        GameMechs();
        GameMechs(int boardX, int boardY);
        ~GameMechs();
        
        bool getExitFlagStatus();
        void setExitTrue();

        char getInput();
        void setInput(char this_input);
        void clearInput();
        int getScore();

        int getBoardSizeX();
        int getBoardSizeY();


        void incrementScore();
        void setLoseFlag();
        bool getLoseFlagStatus();

    
};
#endif