#include "objPosArrayList.h"

// Paste your CUTE Tested implementation here.
// Paste your CUTE Tested implementation here.
// Paste your CUTE Tested implementation here.


// Check lecture contents on general purpose array a construction, 
// and modify it to support objPos array a construction.


//constructor to initialize aList, sizeList, sizeArray
objPosArrayList::objPosArrayList()
{
    
    //initialize the instance (a of pointers) on the heap
    aList = new objPos[ARRAY_MAX_CAP]();

    //initialize capacity and size
    arrayCapacity = ARRAY_MAX_CAP; //200
    listSize = 0; //no elements in the array
}


//destructor
objPosArrayList::~objPosArrayList()
{

    delete[] aList; 

}

int objPosArrayList::getSize()
{
    return listSize;
}

//insert the snake's head at the start of the list
//move all other elements down one index
void objPosArrayList::insertHead(objPos thisPos)
{

    //thisPos is the x, y, & symbol of the head we are inserting
  
    //first check if the array is at full capacity
    if(listSize == arrayCapacity){

        //exit the function using return;
        return; //must do return when you encounter an error

    }else{

        if(listSize != 0){
            
            //move every element back by one index
            for(int i=listSize; i > 0; i--){

                aList[i].setObjPos(aList[i-1]);
            }
        
            //insert the x, y coord & symbol at the head
            aList[0].setObjPos(thisPos);

            //increase the listSize by 1 bc we are inserting 1 element
            listSize++; 

        }else if (listSize == 0){

            aList[0].setObjPos(thisPos);
             //increase the listSize by 1 bc we are inserting 1 element
            listSize++;
        }
    }

}

void objPosArrayList::insertTail(objPos thisPos)
{
    //first check if the arrayList is full
    if(listSize == arrayCapacity){
        
        //exit the function using return;
        return; 

    }else{

        //add the new element (x, y, symbol) at the end at index listSize
        aList[listSize].setObjPos(thisPos);

        //increase the listSize by 1 bc we are inserting 1 element at the end
        listSize++; 
    }    
}

void objPosArrayList::removeHead()
{

    //MAY NEED TO CHANGE THE CONDITON HERE LATER ON
    //in the actual game, the list size should be 1 at all times
    //however, the test case lets you remove head when there's only 1 element in it?


    if(listSize == 0){

        //cout << "list is empty, cannot remove" << endl;
        return;
    }else{

        //shuffle all elements forward, this overwrites the current head values in the array
        for(int i =0; i < listSize-1; i++){
            aList[i] = aList[i+1];

        }

        //make the last element null since everything shifted forward
        aList[listSize-1].x = 0; // NULL; 
        aList[listSize-1].y = 0;
        aList[listSize-1].symbol = 0;

        //decrease the listSize by 1 bc we are removing 1 element at the end
        listSize--;
    }
}

void objPosArrayList::removeTail()
{

    //MAY NEED TO CHANGE THE CONDITON HERE LATER ON
    //in the actual game, the list size should be 1 at all times
    //however, the test case lets you remove tail when there's only 1 element in it?


    if(listSize == 0){

        //cout << "list is empty, cannot remove" << endl;
        return;

    }else{
        //make the tail element 0
        aList[listSize-1].x = 0; //NULL;
        aList[listSize-1].y = 0;
        aList[listSize-1].symbol = 0;

        //decrease the listSize by 1 bc we are removing 1 element at the end
        listSize--;
    }

}

void objPosArrayList::getHeadElement(objPos &returnPos)
{
    returnPos.setObjPos(aList[0]);

}

void objPosArrayList::getTailElement(objPos &returnPos)
{
    returnPos.setObjPos(aList[listSize-1]);
}

void objPosArrayList::getElement(objPos &returnPos, int index)
{

    returnPos.setObjPos(aList[index]); 


}


//added a method to update the symbol data in the array list
//updates symbol at a particular index
void objPosArrayList::updateSymbol(int index, char newSymbol){
    aList[index].symbol = newSymbol;

}