#include "objPosArrayList.h"

// Check lecture contents on general purpose array list construction, 
// and modify it to support objPos array list construction.

objPosArrayList::objPosArrayList()
{
    arrayCapacity = 200;
    listSize = 0;
    aList = new objPos[arrayCapacity];
}

objPosArrayList::~objPosArrayList()
{
    delete[] aList;
}

int objPosArrayList::getSize() const
{
    return listSize;
}

void objPosArrayList::insertHead(objPos thisPos)
{
    if (listSize != arrayCapacity) {
        listSize++;
        for (int i =0; i < listSize;i++) {
            aList[i+1] = aList[i]; 

    }  

    aList[0] = thisPos;
    }
}

void objPosArrayList::insertTail(objPos thisPos)
{
    if (listSize != arrayCapacity) {
        listSize++;
        aList[listSize-1] = thisPos;
    }
}

void objPosArrayList::removeHead()
{
    for (int i =0; i < listSize; i++) {
        aList[i] = aList[i+1];
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