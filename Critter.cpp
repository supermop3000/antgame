/******************************************************************************
 ** Author:      Winter 162 400 Group 4
 ** Date:        02/01/2019
 ** Description: This is the implementation of the Critter, Ant, and Doodlebug
 **              classes.
 ******************************************************************************/

#include "Critter.hpp"
#include "Group4Utils.hpp"

#include <iostream>

using std::cout;
using std::endl;

/******************************************************************************
 ** description: Critter constructor
 ******************************************************************************/
Critter::Critter()
{
    //this->x_pos = x_pos;
    //this->y_pos = y_pos;
    this->age = 0;
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

void Critter::setRows(int r)
{
    rows =r;
}

void Critter::setColumns(int c)
{
    columns = c;
}

//Get functions
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

void Critter::move(Critter *** &boardIn)
{
    std::cout << "in critter move" << std::endl;
}

/******************************************************************************
 **                    Critter::moveOutOfBounce(int direction)
 ** Description: moveOutOfBounce takes an integer that represents the direction
 **              the critter is trying to move.  It checks to make sure the
 **              move will not result in the critter moving out of bounds.
 **              It returns false if the move does not go out of bounds, and
 **              true if the move would result in going out of bounds.
 ******************************************************************************/
bool Critter::checkBounds(int new_x, int new_y)
{
    bool outOfBounce = true;

    if(new_x < 0 || new_x > 19) //TODO NEED TO MAKE ROWS AND COLUMNS PART OF CRITTER CONSTRUCTOR TO USE ROWS AND COLUMNS CRITERIA FOR BOUNDS FUNCTION
      outOfBounce = false;

    if(new_y < 0 || new_y > 19)
      outOfBounce = false;

 /*   if (direction == 0) //Direction North (move row down 1)
    {
        if (this->x_pos -1 < 0)
        {
            outOfBounce = false;
        }
    }
    else if (direction == 1) //Direction East (move col up 1)
    {
        if (this->y_pos + 1 > 19)
        {
            outOfBounce =  false;
        }
    }
    else if (direction == 2) //Direction South (move row up 1)
    {
        if (this->x_pos + 1 > 19)
        {
            outOfBounce = false;
        }
    }
    else //Direction = 3, Direction West (move column down 1)
    {
        if (this->y_pos -1 < 0)
        {
            outOfBounce = false;
        }
    }*/
    return outOfBounce;
}

void Critter::createBoard(Critter *** board, int rowIn, int colIn, int numAntsIn, int numDoodsIn)
{

}

void Critter::print_board(Critter *** board, int rows, int cols)
{
  for(int i = 0; i < cols; i++)
  {
    for(int k = 0; k < rows; k++)
      {
        cout << board[i][k]->getSymbol();
      }
      cout << endl;
  }
}

void Critter::resetMoveSuccess()
{
   this->moveSuccess = 0;
}

int Critter::getMoveSuccess()
{
   return this->moveSuccess;
}
/*helper function for breed testing
void Critter::setAge(int ageIn)
{

}*/
