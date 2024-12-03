#include "objPosArrayList.h"

objPosArrayList::objPosArrayList() //default constructor
{
    arrayCapacity = 200;
    listSize = 0;
    aList = new objPos[arrayCapacity]; //dynamic allocation array of objPos objects with size of arrayCapacity
}

objPosArrayList::~objPosArrayList() //destructor
{
    delete[] aList;
}

int objPosArrayList::getSize() const
{
    return listSize;
}

void objPosArrayList::insertHead(objPos thisPos)
{
    if (listSize != arrayCapacity) { //check for array capacity
        listSize++; //increase size of list
        for (int i =listSize; i > 0;i--) {
            aList[i] = aList[i-1]; 

    }  

    aList[0] = thisPos; //put new element at index 0 (head)
    }
}

void objPosArrayList::insertTail(objPos thisPos)
{
    if (listSize != arrayCapacity) {
        listSize++;
        aList[listSize-1] = thisPos; //place new element at last index (tail)
    }
}

void objPosArrayList::removeHead()
{
    for (int i =0; i < listSize; i++) { 
        aList[i] = aList[i+1]; //shift elements once to the left for head 
    }
    listSize--;
}

void objPosArrayList::removeTail()
{
    listSize--;
}

objPos objPosArrayList::getHeadElement() const
{
    return aList[0];
}

objPos objPosArrayList::getTailElement() const
{
    return aList[listSize-1];
}

objPos objPosArrayList::getElement(int index) const
{
    return aList[index];
}