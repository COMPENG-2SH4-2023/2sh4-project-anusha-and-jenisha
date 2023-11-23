#include "Player.h"

//CONSTRUCTOR !!!

Player::Player(GameMechs* thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    myDir = STATE_IDLE; //USED to be STOP, change back if causing errors STOP;

    // more actions to be included

    //initiazing the initial position of the symbol
    //.setObjPos is a function in objPos.cpp
    //playerPos.setObjPos(5, 9, '*');
    playerPos.setObjPos(mainGameMechsRef->getBoardSizeX()/2, mainGameMechsRef->getBoardSizeY()/2, '*');
}


Player::~Player()
{
    // delete any heap members here
}

void Player::getPlayerPos(objPos &returnPos)
{
    // return the reference to the playerPos arrray list

    //right now we only have 1 position
    //.setObjPos is a method in objPos.cpp

    //returnPos is an object, and the below line is setting the position of this object to the current position of the character
    returnPos.setObjPos(playerPos.x, playerPos.y, playerPos.symbol);
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

   //update player position based on STATE not input character
    if(myDir == STATE_UP){
        
        //update the X-position in the array
        playerPos.x = playerPos.x - 1; //posX = posX - 1;


    }else if(myDir == STATE_LEFT){
        
        //update the Y-position in the array
        playerPos.y = playerPos.y -1; //posY = posY - 1;
        

    }else if(myDir == STATE_DOWN){

        //update the X-position in the array
        playerPos.x = playerPos.x + 1; //posX = posX + 1;

       
    }else if(myDir == STATE_RIGHT){

        //update the Y-position in the array
        playerPos.y = playerPos.y + 1; //posY = posY + 1;

    
    }


      //wraparound of the * symbol
      //need to figure out how to access the array that's printed
      //i think you can just change the array in the draw method by calling these different coords and symbols!!!
      //remove the symbolArray stuff here when you've confirmed this
     if(myDir == STATE_UP &&  playerPos.x  == 0){
         
         playerPos.symbol = '#';
        
        //symbolArray[movePos.x][movePos.y] = movePos.symbol;
        
        //update the X-position in the array
        //the playerPos should be 1 less than the X boardsize (ie. 1 less than the # symbol)
        playerPos.x = mainGameMechsRef->getBoardSizeX()-1; //8;

    }else if(myDir == STATE_LEFT &&  playerPos.y  == 0){
        
        playerPos.symbol = '#';
        
        //symbolArray[movePos.x][movePos.y] = movePos.symbol;

        //update the Y-position in the array
        //the playerPos should be 1 less than the boardsize Y
        playerPos.y = mainGameMechsRef->getBoardSizeY()-1; //18;

    }else if(myDir == STATE_DOWN &&  playerPos.x == mainGameMechsRef->getBoardSizeX()){ //9

        playerPos.symbol = '#';
        
        //symbolArray[movePos.x][movePos.y] = movePos.symbol;

        //update the X-position in the array
        playerPos.x = 1;

    }else if(myDir == STATE_RIGHT &&  playerPos.y  == mainGameMechsRef->getBoardSizeY()){ //19

         playerPos.symbol = '#';
        
        //symbolArray[movePos.x][movePos.y] = movePos.symbol;

        //update the Y-position in the array
        playerPos.y = 1;
    
    }else{
        playerPos.symbol = '*';
        //normal movement - no wraparound here
        
        //symbolArray[movePos.x][movePos.y] = movePos.symbol;
       
    }


    //mainGameMechsRef


}

