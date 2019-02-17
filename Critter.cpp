/******************************************************************************
 ** Author:      Winter 162 400 Group 4
 ** Date:        02/01/2019
 ** Description: This is the implementation of the Critter, Ant, and Doodlebug
 **              classes.
 **              This program runs a Predator-Prey Game with "Doodlebug"
 **              predators and "Ant" prey. The program starts with a menu and
 **              has the user set the number steps for the simulation to take.
 **              Once the simulation is complete, the user is queried for the
 **              whether they want to continue with more steps or quit.
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
 ** description: Critter constructor
 ******************************************************************************/
Critter::Critter(int x_pos, int y_pos)
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

/******************************************************************************
 **                    Critter::moveOutOfBounce(int direction)
 ** Description: moveOutOfBounce takes an integer that represents the direction
 **              the critter is trying to move.  It checks to make sure the
 **              move will not result in the critter moving out of bounds.
 **              It returns false if the move does not go out of bounds, and
 **              true if the move would result in going out of bounds.
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

void Critter::resetMoveSuccess()
{
   this->moveSuccess = 0;
}

int Critter::getMoveSuccess()
{
   return this->moveSuccess;
}

/******************************************************************
 ** Description: void breed(Critter***))
 ** PUBLIC::2019.02.05::HD-JA**
 ** function accepts 2D Critter board, identifies if critter is of age
 ** to breed, identifies whether there are available spots to breed to,
 ** then randomly selects a spot to breed to
 ******************************************************************/
void Critter::breed(Critter *** boardIn, int size_x, int size_y)
{
    // check if critter is of breeding age
    if ((age != 0) && (age % breedAge == 0))
    {
        
         // holds the randomly generated integer for choosing a direction
         int randomRoll;
        
         // checks if any adjacent cells are free
         bool cellFree = false;
        
         // holds values that indicate the location of an open space
         std::vector<int> openSpace;
        
         // Check if x_pos + 1 is free 
         if (checkBounds((x_pos + 1), y_pos, size_x, size_y) && boardIn[x_pos + 1][y_pos] == NULL)
         {
             // 0 indicates the east space is free
             openSpace.push_back(0);
             
             if (cellFree == false)
             {
                 // Set cell free to show to indicate an open adjacent cell
                 cellFree = true;
             }
         }
         // Check if x_pos - 1 is free
         if (checkBounds((x_pos - 1), y_pos, size_x, size_y) && boardIn[x_pos - 1][y_pos] == NULL)
         {
             // 1 indicates the west free
             openSpace.push_back(1);
             
             if (cellFree == false)
             {
                 cellFree = true;
             }
         }
        
         // Check if y_pos + 1 is free
         if (checkBounds(x_pos, (y_pos + 1), size_x, size_y) && boardIn[x_pos][y_pos + 1] == NULL)
         {
             // 2 indicates north free
             openSpace.push_back(2);
             if (cellFree == false)
             {
                 cellFree = true;
             }
         }
        
         // Check if y_pos - 1 is free
         if (checkBounds(x_pos, (y_pos - 1), size_x, size_y) && boardIn[x_pos][y_pos - 1] == NULL)
         {
             // 3 indicates south free
             openSpace.push_back(3);
             if (cellFree == false)
             {
                 cellFree = true;
             }
         }
        
         // adjacent open cell exists
         if (cellFree == true)
         {
             //cout << "a " << symbol << " critter of age " << age << " is breeding" << endl;
             
             // randomly roll a number between 0 and (size of open Space vector - 1)
             randomRoll = randIntRange(0, (int)openSpace.size() - 1);
             
             // INTEGERS INSIDE VECTOR INDICATE THE FOLLOWING
             // 0 = x_pos + 1
             // 1 = x_pos - 1
             // 2 = y_pos + 1
             // 3 = y_pos - 1
             if (openSpace[randomRoll] == 0)
             {
                 // add critter at age of 0 to the east (x_pos + 1)
                 if (symbol == 'O')
                 {
                     boardIn[x_pos + 1][y_pos] = new Ant(x_pos + 1, y_pos);
                 }
                 
                 else if (symbol == 'X')
                 {
                     boardIn[x_pos + 1][y_pos] = new Doodlebug(x_pos + 1, y_pos);
                 }
             }
             
             else if (openSpace[randomRoll] == 1)
             {
                 // add critter at age of 0 to the west (x_pos - 1)
                 if (symbol == 'O')
                 {
                     boardIn[x_pos - 1][y_pos] = new Ant(x_pos - 1, y_pos);
                 }
                 
                 else if (symbol == 'X')
                 {
                     boardIn[x_pos - 1][y_pos] = new Doodlebug(x_pos - 1, y_pos);
                 }
             }
             
             else if (openSpace[randomRoll] == 2)
             {
                 // add critter at age of 0 to the north (y_pos + 1)
                 if (symbol == 'O')
                 {
                     boardIn[x_pos][y_pos + 1] = new Ant(x_pos, y_pos + 1);
                 }
                 
                 else if (symbol == 'X')
                 {
                     boardIn[x_pos][y_pos + 1] = new Doodlebug(x_pos, y_pos + 1);
                 }

             }
             
             else if (openSpace[randomRoll] == 3)
             {
                 // add critter at age of 0 to the south (y_pos - 1)
                 if (symbol == 'O')
                 {
                     boardIn[x_pos][y_pos - 1] = new Ant(x_pos, y_pos - 1);
                 }
                 
                 else if (symbol == 'X')
                 {
                     boardIn[x_pos][y_pos - 1] = new Doodlebug(x_pos, y_pos - 1);
                 }
             }
         }
    }
}

bool Critter::starve(Critter***)
{
    cout << "\n<!>ERROR:CRITTER MOVE WAS CALLED<!>\n" << endl;
    return false;
}
