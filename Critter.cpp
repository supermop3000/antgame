/******************************************************************************
 ** Author:      Winter 162 400 Group 4
 ** Date:        02/01/2019
** Description: This is the implementation file of the Critter class.
**		        It contains the default constructor to create a Critter object, 
**              get and set methods, a checkBounds function, and virtual move, 
**              breed, and starve functions.
******************************************************************************/
#include "Ant.hpp"
#include "Critter.hpp"
#include "Doodlebug.hpp"
#include "Group4Utils.hpp"
#include <iostream>
#include <vector>
using std::cout;
using std::endl;

/******************************************************************************
** Description: Critter(int,int)				
** This is the default constructor for the Critter Class that sets the x and y
** values that were input into the constructor function, the breeding age to 
** -1, the age to 0, the symbol to ' ', and moveSuccess to 0.
*******************************************************************************/
Critter::Critter(int x_pos, int y_pos)
{
    this->x_pos = x_pos;
    this->y_pos = y_pos;
    this->age = 0;
    this->breedAge = -1;
    this->symbol = ' ';
    this->moveSuccess = 0;
}

Critter::Critter(int x_pos, int y_pos, int age)
{
    this->x_pos = x_pos;
    this->y_pos = y_pos;
    this->age = 0;
    this->breedAge = -1;
    this->symbol = ' ';
    this->moveSuccess = 0;
}

//Set functions
void Critter::setX_pos(int x)
{
    x_pos = x;
}

void Critter::setY_pos(int y)
{
    y_pos = y;
}

//helper function for breed testing
void Critter::setAge(int ageIn)
{
    age = ageIn;
}
 
// Get functions
char Critter::getSymbol()
{
    return this->symbol;
}

int Critter::getX_pos()
{
    return x_pos;
}

int Critter::getY_pos()
{
    return y_pos;
}

int Critter::getAge()
{
    return age;
}

int Critter::getMoveSuccess()
{
   return this->moveSuccess;
}

/******************************************************************************
** Critter::checkBounds(int, int, int, int)
** Description: checkBounds is a boolean function that checks to ensure the  
**              x and y coordinates input into the function are on the board.
**              It returns true if the x and y coordinates are legal, and 
**              false otherwise.
******************************************************************************/
bool Critter::checkBounds(int new_x, int new_y, int size_x, int size_y)
{
    bool outOfBounce = true;

    if(new_x < 0 || new_x > size_x - 1)
      outOfBounce = false;

    if(new_y < 0 || new_y > size_y - 1)
      outOfBounce = false;

    return outOfBounce;
}


/******************************************************************************
** Critter::resetMoveSuccess()
** Description: resetMoveSuccess resets the moveSuccess to 0.  
******************************************************************************/
void Critter::resetMoveSuccess()
{
   this->moveSuccess = 0;
}


/******************************************************************************
** Critter::breed(Critter***, int, int)
** Description: breed is a void function that takes a 2D Critter board, the x
**              and y coordinates of a Critter. The function checks that the
**              Critter is of breeding age. If the Critter is of breeding age,
**              it checks if there are any open adjacent spots to the Critter,
**              and adds those adjacent spots to a vector where one is randomly 
**              choosen from this vector. A new Critter is then created and 
**              placed in the random adjacent spot.  The age of the Critter is
**              then reset.  If there are no open spots or the Critter is not
**              of breeding age, no breeding occurs.
******************************************************************************/
void Critter::breed(Critter *** boardIn, int size_x, int size_y)
{
    //Check if critter is of breeding age
    if (age >= breedAge)
    {       
        //Bool for whether a free cell exists
        bool cellFree = false;
        
        //Vector that holds the directions of open spaces using integer representatives
        std::vector<int> openSpace;
        
        // Check if NORTH direction is available
        if (checkBounds((x_pos - 1), y_pos, size_x, size_y) && boardIn[x_pos - 1][y_pos] == NULL)
        {
            // 0 indicates the NORTH space is free
            openSpace.push_back(0);

            cellFree = true;
        }
        // Check if EAST direction is available
        if (checkBounds(x_pos, (y_pos + 1), size_x, size_y) && boardIn[x_pos][y_pos + 1] == NULL)
        {
            // 1 indicates the EAST space is free
            openSpace.push_back(1);
        
            cellFree = true;
        }
        
        // Check if SOUTH direction is available
        if (checkBounds((x_pos + 1), y_pos, size_x, size_y) && boardIn[x_pos + 1][y_pos] == NULL)
        {
            // 2 indicates the SOUTH space is free
            openSpace.push_back(2);

            cellFree = true;
        }
        
        // Check if WEST direction is available
        if (checkBounds(x_pos, (y_pos - 1), size_x, size_y) && boardIn[x_pos][y_pos - 1] == NULL)
        {
            // 3 indicates the WEST space is free
            openSpace.push_back(3);

            cellFree = true;
        }
        
        // If an adjacent cell exists, randomly add Ant/Doodlebug to one of the free spaces
        if (cellFree == true)
        {           
            // randomly roll a number between 0 and (size of open Space vector - 1)
            int randomRoll = randIntRange(0, (int)openSpace.size() - 1);
            
            // INTEGERS INSIDE VECTOR INDICATE THE FOLLOWING
            // 0 = NORTH (x_pos - 1)
            // 1 = EAST  (y_pos + 1)
            // 2 = SOUTH (x_pos + 1)
            // 3 = WEST  (y_pos - 1)
            if (openSpace[randomRoll] == 0)
            {
                //Add critter to the NORTH (x_pos - 1)
                if (symbol == 'O')
                {
                    boardIn[x_pos - 1][y_pos] = new Ant(x_pos - 1, y_pos);
                }
                else // symbol == 'X'
                {
                    boardIn[x_pos - 1][y_pos] = new Doodlebug(x_pos - 1, y_pos);
                }
            } 
            else if (openSpace[randomRoll] == 1)
            {
                //Add critter to the EAST (y_pos + 1)
                if (symbol == 'O')
                {
                    boardIn[x_pos][y_pos + 1] = new Ant(x_pos, y_pos + 1);
                }
                else //symbol == 'X'
                {
                    boardIn[x_pos][y_pos + 1] = new Doodlebug(x_pos, y_pos + 1);
                }
            }
            else if (openSpace[randomRoll] == 2)
            {
                //Add critter to the SOUTH (x_pos + 1)
                if (symbol == 'O')
                {
                    boardIn[x_pos + 1][y_pos] = new Ant(x_pos + 1, y_pos);
                }
                else //symbol == 'X'
                {
                    boardIn[x_pos + 1][y_pos] = new Doodlebug(x_pos, y_pos);
                }
            }
            else //openSpace[randomRoll] == 3
            {
                //Add critter to the WEST (y_pos - 1)
                if (symbol == 'O')
                {
                    boardIn[x_pos][y_pos - 1] = new Ant(x_pos, y_pos - 1);
                }
                else //symbol == 'X'
                {
                    boardIn[x_pos][y_pos - 1] = new Doodlebug(x_pos, y_pos - 1);
                }
            }

            /*Reset age of Critter that bred 
              (must survive breedAge more steps before can breed again) */
            this->age = 0;
        }
    }
}

/******************************************************************************
** Critter::starve(Critter***)
** Description: virtual function that should not be called in Critter class  
******************************************************************************/
bool Critter::starve(Critter***)
{
    cout << "\n<!>ERROR:CRITTER MOVE WAS CALLED<!>\n" << endl;
    return false;
}
