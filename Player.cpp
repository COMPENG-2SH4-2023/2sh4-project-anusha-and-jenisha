#include "Player.h"
#include "objPos.h"

#include <iostream>
#include "MacUILib.h"

//CONSTRUCTOR !!!

Player::Player(GameMechs* thisGMRef, Food* thisFoodRef)
{
    mainGameMechsRef = thisGMRef;
    mainFoodRef = thisFoodRef;


    myDir = STATE_IDLE; //USED to be STOP, change back if causing errors STOP;

    //create a temporary position and then insert it in the list (insertHead)
    objPos tempPos;
    tempPos.setObjPos(mainGameMechsRef->getBoardSizeX()/2, mainGameMechsRef->getBoardSizeY()/2, '*');

    //create an array on the heap
    playerPosList = new objPosArrayList();
    playerPosList->insertHead(tempPos);
    //playerPosList->insertHead(tempPos);


    constrFlag();

    //constrFlag = 1;
    MacUILib_printf("Constructor Called! \n");


}

int Player::constrFlag(){

    int constrFlag = 1;
    return constrFlag;
}


Player::~Player()
{
    delete playerPosList;
}


objPosArrayList* Player::getPlayerPos()
{

    return playerPosList;

}

void Player::updatePlayerDir()
{

    char input = mainGameMechsRef->getInput();


        switch(input)
        {      
            case 27: //esc exit key

                mainGameMechsRef->setExitTrue();
                break;


            case 'w':  //press w (UP)

                if (myDir == STATE_LEFT || myDir == STATE_RIGHT || myDir == STATE_UP || myDir == STATE_IDLE){
                    //must update the state
                    myDir = STATE_UP;
                }
                break;

            case 'a':  //press a (LEFT)

                if (myDir == STATE_UP || myDir == STATE_DOWN || myDir == STATE_LEFT || myDir == STATE_IDLE){
                    //must update the state
                    myDir = STATE_LEFT; 
                } 
                break;

            case 's':  //press s (DOWN)

                if (myDir == STATE_LEFT || myDir == STATE_RIGHT || myDir == STATE_DOWN || myDir == STATE_IDLE){
                    //must update the state
                    myDir = STATE_DOWN;
                }

                break;

            case 'd':  //press d (RIGHT)

                if (myDir == STATE_IDLE || myDir == STATE_UP || myDir == STATE_DOWN || myDir ==  STATE_RIGHT){                   
                    //must update the state
                    myDir = STATE_RIGHT;
                }

                break;

            default:
                break;
        }
}

void Player::movePlayer()
{
    // PPA3 Finite State Machine logic

    objPos currHead; //holding the position information of the current head 
    playerPosList->getHeadElement(currHead);

    int xlim = mainGameMechsRef->getBoardSizeX()-1;
    int ylim = mainGameMechsRef->getBoardSizeY()-1; 

    if(myDir == STATE_UP){

        //update the X-position in the array
        currHead.x = currHead.x - 1; 



    }else if(myDir == STATE_LEFT){

        //update the Y-position in the array
        currHead.y = currHead.y -1;


    }else if(myDir == STATE_DOWN){

        //update the X-position in the array
        currHead.x = currHead.x + 1; 


    }else if(myDir == STATE_RIGHT){

        //update the Y-position in the array
        currHead.y = currHead.y + 1; 


    }


     if(myDir == STATE_UP &&  currHead.x  == 0){


         currHead.symbol = '#';

        currHead.x = mainGameMechsRef->getBoardSizeX()-2; //8;
        currHead.symbol = '*';

    }else if(myDir == STATE_LEFT &&  currHead.y  == 0 ){

        currHead.symbol = '#';

        currHead.y = mainGameMechsRef->getBoardSizeY()-2; 
        currHead.symbol = '*';

    }else if(myDir == STATE_DOWN &&  currHead.x == 9){  


        currHead.symbol = '#';

        currHead.x = 1;
        currHead.symbol = '*';

    }else if(myDir == STATE_RIGHT &&  currHead.y == ylim){ 


        currHead.symbol = '#';
        currHead.y = 1;
        currHead.symbol = '*';
    }


    if(checkSelfCollision()==true){

        mainGameMechsRef->setLoseFlag();
        mainGameMechsRef->setExitTrue();

    } else{


        if (checkFoodConsumption())
        {
             // If yes, increase the player length without removing the tail
            increasePlayerLength();
             // Generate new food
            mainFoodRef->generateFood(*playerPosList);
            mainGameMechsRef->incrementScore();
        }

        playerPosList->insertHead(currHead);
        playerPosList->removeTail();


    }

    // Check if the head overlaps with the food
    objPos tempbody_pos2;
    playerPosList->getElement(tempbody_pos2, 1);
    tempbody_pos2.symbol = '*';

    playerPosList->updateSymbol(1, tempbody_pos2.symbol);

}


bool Player::checkFoodConsumption()
{
    objPos currHead;
    playerPosList->getHeadElement(currHead);

    objPos foodPos;
    mainFoodRef->getFoodPos(foodPos);

    return (currHead.x == foodPos.x && currHead.y == foodPos.y);
}


void Player::increasePlayerLength()
{

    objPos currHead;
    playerPosList->getHeadElement(currHead);
    playerPosList->insertHead(currHead);
}



bool Player::checkSelfCollision(){

    objPos tempBodyPart;
    objPos currHeadC;
    playerPosList->getHeadElement(currHeadC);
    int i;


     for(i = 1; i < playerPosList->getSize(); i++){
        playerPosList->getElement(tempBodyPart, i);

        if(currHeadC.isPosEqual(&tempBodyPart)){
            return true;
        }
    }


     return false;

}

