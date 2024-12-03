#ifndef OBJPOS_H
#define OBJPOS_H

// Not really a C++ thing
typedef struct 
{
    int x;
    int y;
} Pos;

class objPos
{
    public:
        Pos* pos; //pointer to position of object, stored in dynamic memory  
        char symbol;  

        objPos(); //default constructor
        objPos(int xPos, int yPos, char sym); //additional constructor
        objPos(const objPos &other); //copy constructor
        objPos& operator=(const objPos &other); //assignment operator constructor
        ~objPos(); //destructor


        
        void setObjPos(objPos o); //updates position and symbol through objPos      
        void setObjPos(int xPos, int yPos, char sym); 

        objPos getObjPos() const; //deep copy, returns new objPos object with same position and symbol
        char getSymbol() const; 
        char getSymbolIfPosEqual(const objPos* refPos) const; //checks if position matching reference position 
        
        bool isPosEqual(const objPos* refPos) const; //compares coordinates of object with reference position
};

#endif