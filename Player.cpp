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

    /*playerPosList->insertHead(tempPos);
    playerPosList->insertHead(tempPos);
    playerPosList->insertHead(tempPos);
    playerPosList->insertHead(tempPos);

    playerPosList->insertHead(tempPos);
    playerPosList->insertHead(tempPos);
    playerPosList->insertHead(tempPos);
    playerPosList->insertHead(tempPos);*/
    
    // more actions to be included


    //OLD CODE: no longer true for array list
    //initiazing the initial position of the symbol
    //.setObjPos is a function in objPos.cpp
    //playerPos.setObjPos(5, 9, '*');
    //playerPos.setObjPos(mainGameMechsRef->getBoardSizeX()/2, mainGameMechsRef->getBoardSizeY()/2, '*');
}

int Player::constrFlag(){

    int constrFlag = 1;
    return constrFlag;
}


Player::~Player()
{
    // delete any heap members here
    //no [] here - only 1 position in the list
    delete playerPosList;
}

//must change this method to accomodate for the array reference
//void Player::getPlayerPos(objPos &returnPos)
objPosArrayList* Player::getPlayerPos()
{
    // return the reference to the playerPos arrray list
    //returns the pointer to the start of the 200 element list initialized in objPosArrayList()
    return playerPosList;

    //OLD CODE for returning the position of 1 symbol character
    //right now we only have 1 position
    //.setObjPos is a method in objPos.cpp

    //returnPos is an object, and the below line is setting the position of this object to the current position of the character
    //returnPos.setObjPos(playerPos.x, playerPos.y, playerPos.symbol);
}

void Player::updatePlayerDir()
{
    // PPA3 input processing logic  

    //where do i get the input; how do i check for input
    //hint1 - definitely not by calling MacUILib_GetChar();
    //hint 2: coordinate with team member who's designing the GameMechanism class
    //hint 3: there will be a method in gamemechanism class that collectively checks input and stores the most recent input
    //you just need to figure out how to get to it.

    //how?? it lies wihtin the GameMechs* inside you private method GameMechs* mainGameMechsRef; in Player.h

    //the PLayer class (the first one here) will have a reference to the HameMechs* class
    //the GameMechs* class is already accessible from your Player.h class

    //myDir is a private variable type enum Dir myDir in Player.h
    //myDir != UP      

    //mainGameMechsRef is a pointer variable of type GameMechs (this is the name of the class in file GameMechs.h) 
    //getInput() is the name of the function that we are reading the input from
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

    //objPos additions;
    //playerPosList.getTailElement(additions);
    //additions.x = additions.x+1;
    //additions.y = additions.

    //int count = 0;


   //update player position based on STATE not input character
    if(myDir == STATE_UP){
        
        //update the X-position in the array
        currHead.x = currHead.x - 1; //posX = posX - 1;


        //for testing only///////////////
        //get the last tail pos then add 1 to each xy coord
        //playerPosList->insertTail(additions);
       /* if(count <= 1){
            playerPosList->insertHead(currHead);
            MacUILib_printf("currHead.x status: %d\n", currHead.x);
            MacUILib_printf("currHead.y status: %d\n", currHead.y); 
            count++;
        }*/

    }else if(myDir == STATE_LEFT){
        
        //update the Y-position in the array
        currHead.y = currHead.y -1; //posY = posY - 1;
        

    }else if(myDir == STATE_DOWN){

        //update the X-position in the array
        currHead.x = currHead.x + 1; //posX = posX + 1;

       
    }else if(myDir == STATE_RIGHT){

        //update the Y-position in the array
        currHead.y = currHead.y + 1; //posY = posY + 1;

    
    }


      //wraparound of the * symbol
      //need to figure out how to access the array that's printed
      //i think you can just change the array in the draw method by calling these different coords and symbols!!!
      //remove the symbolArray stuff here when you've confirmed this
     if(myDir == STATE_UP &&  currHead.x  == 0){
         
         
         currHead.symbol = '#';
        // MacUILib_printf("STATE UP x = 0 # \n");
        
        
        //symbolArray[movePos.x][movePos.y] = movePos.symbol;
        
        //update the X-position in the array
        //the playerPos should be 1 less than the X boardsize (ie. 1 less than the # symbol)
        currHead.x = mainGameMechsRef->getBoardSizeX()-2; //8;
        currHead.symbol = '*';

    }else if(myDir == STATE_LEFT &&  currHead.y  == 0 ){
        
        currHead.symbol = '#';
        //MacUILib_printf("STATE LEFT y = 0 # \n");
        

        //symbolArray[movePos.x][movePos.y] = movePos.symbol;

        //update the Y-position in the array
        //the playerPos should be 1 less than the boardsize Y
        currHead.y = mainGameMechsRef->getBoardSizeY()-2; //18;
        currHead.symbol = '*';

    }else if(myDir == STATE_DOWN &&  currHead.x == 9){  //xlim) //9 //board goes from 0-29 

    
        currHead.symbol = '#';
        /* MacUILib_printf("STATE DOWN x = 9 # \n");
         MacUILib_printf("max x coord: %d \n", xlim); // mainGameMechsRef->getBoardSizeX()-1);
         MacUILib_printf("currHead.x : %d \n", currHead.x);
         MacUILib_printf("myDir : %d \n", myDir);
*/

        //symbolArray[movePos.x][movePos.y] = movePos.symbol;

        //update the X-position in the array
        currHead.x = 1;
        currHead.symbol = '*';

    }else if(myDir == STATE_RIGHT &&  currHead.y == ylim){ //mainGameMechsRef->getBoardSizeY()-1){ //19 //board from 0-9

        
         currHead.symbol = '#';
        /* MacUILib_printf("STATE DOWN x = 29 # \n");
         MacUILib_printf("max x coord: %d \n", mainGameMechsRef->getBoardSizeY()-1);
        */
        
        //symbolArray[movePos.x][movePos.y] = movePos.symbol;

        //update the Y-position in the array
        currHead.y = 1;
        currHead.symbol = '*';
    }
    /*}else{
        currHead.symbol = '*';
        MacUILib_printf("head symbol * \n");
        //normal movement - no wraparound here
        
        //symbolArray[movePos.x][movePos.y] = movePos.symbol;
       
    }*/

 


    //new current head should be inserted to the head of the list
    playerPosList->insertHead(currHead);

    //then remove tail
    playerPosList->removeTail();

//////
    //playerPosList->insertHead(currHead);

    objPos foodPos;
    mainFoodRef->getFoodPos(foodPos);

    // Check if the head overlaps with the food
    if (checkFoodConsumption())
    {
        // If yes, increase the player length without removing the tail
        increasePlayerLength();

        // Generate new food
        mainFoodRef->generateFood(*playerPosList); 
        mainGameMechsRef->incrementScore();
    }
   /* else
    {
        playerPosList->removeTail();
    }*/
///////////

    //need to change the symbol of the 2nd array element back to *
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
    // Insert the head, but DO NOT remove the tail
    objPos newHead;
    playerPosList->getHeadElement(newHead);
    playerPosList->insertHead(newHead);
}

//must check for self collision
bool Player:: checkSelfCollision(){

    //must check if the head coords = any of the snake body coords
    //need to loop through elements in playerPosList array
    
    //getting the current head coords
    objPos currHeadC;
    playerPosList->getHeadElement(currHeadC); 

    //must get listSize
    //objPosArrayList playerPosRef;
    int posListSize = playerPosList->getSize();

    //array coords of each element will be saved here
    objPos arrayElements;
    bool loseFlag = false;

    //the playerPosList array size must be >= 1 to check for collision 
    if(posListSize > 1){
        //MacUILib_printf("posListSize status: %d\n", posListSize);


        for(int i = 1; i < posListSize; i++){

            //coords are saved into arrayElements variable (type ObjPos)
            playerPosList->getElement(arrayElements, i);

            /*
            MacUILib_printf("currHeadC.x status: %d\n", currHeadC.x);
            MacUILib_printf("currHeadC.y status: %d\n", currHeadC.y);
            MacUILib_printf("arrayElements.x status: %d\n", arrayElements.x);
            MacUILib_printf("arrayElements.y status: %d\n", arrayElements.y);
            */

            if(currHeadC.x == arrayElements.x && currHeadC.y == arrayElements.y){
            //if(arrayElements.isPosEqual(currHeadC)){
                //set the loseFlag to true
                loseFlag = true;
                mainGameMechsRef->setLoseFlag(loseFlag);
                //MacUILib_printf("loseFlag status: %d\n", loseFlag);

                //set the exit flag to true
                //mainGameMechsRef->setExitTrue();
                //MacUILib_printf("exitFlag status: %d\n",  mainGameMechsRef->getExitFlagStatus());


            }
        }
    }else{

        loseFlag = false;
        //MacUILib_printf("ELSE loseFlag status: %d\n", loseFlag);

    }

    return loseFlag;

}

