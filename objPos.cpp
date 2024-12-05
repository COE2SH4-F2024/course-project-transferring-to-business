#include "objPos.h"

objPos::objPos() //default constructor for object position
{
    pos = new Pos; //allocate memory for the object position 
    pos->x = 0; 
    pos->y = 0;
    symbol = 0; //NULL
}

objPos::objPos(int xPos, int yPos, char sym)
{
    pos = new Pos; 
    pos->x = xPos; //assign x coordinate for object
    pos->y = yPos; //assign y coordinate for object
    symbol = sym;  //assign symbol to the object
}

objPos::objPos(const objPos &other) {
    symbol = other.symbol; //copy symbol from source object

    pos =  new Pos;
    pos->x =  other.pos->x; //copy x coordinate from source object
    pos->y =  other.pos->y; //copy y coordinate from source object

}

objPos& objPos::operator=(const objPos &other) {
    if (this != &other) { 
        symbol = other.symbol; //copy symbol 
        this->pos->x =  other.pos->x;  //copy x coordinate
        this->pos->y =  other.pos->y; //copy y coordinate
    }
    return *this; //return current object to chain of assignments

}

objPos::~objPos() {
    delete[] pos; //deconstructor to delete the memory of pos
}

void objPos::setObjPos(objPos o)
{
    pos->x = o.pos->x; 
    pos->y = o.pos->y; 
    symbol = o.symbol; 
}

void objPos::setObjPos(int xPos, int yPos, char sym)
{
    pos->x = xPos; 
    pos->y = yPos; 
    symbol = sym; 
}

objPos objPos::getObjPos() const
{
    objPos returnPos;
    returnPos.pos->x = pos->x;
    returnPos.pos->y = pos->y;
    returnPos.symbol = symbol;
    
    return returnPos;

    //deep copy, creates new objPos object each time called
}

char objPos::getSymbol() const
{
    return symbol;
}

bool objPos::isPosEqual(const objPos* refPos) const
{
    return (refPos->pos->x == pos->x && refPos->pos->y == pos->y); //compare coordinates of current and reference position
}

char objPos::getSymbolIfPosEqual(const objPos* refPos) const
{
    if(isPosEqual(refPos)) //check for position equality
        return symbol;
    else
        return 0;
}
