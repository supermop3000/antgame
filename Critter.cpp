/******************************************************************************
 ** Author:      Winter 162 400 Group 4
 ** Date:        02/01/2019
 ** Description: This is the implementation of the Critter, Ant, and Doodlebug
 **              classes.
 ******************************************************************************/

#include "Critter.hpp"

#include <iostream>

/******************************************************************************
 ** description: Critter constructor
 ******************************************************************************/
Critter::Critter()
{
    //this->x_pos = x_pos;
    //this->y_pos = y_pos;
    this->age = 0;
    this->symbol = ' ';
}

bool Critter::move(Critter ***boardIn)
{
    std::cout << "in critter move" << std::endl;
    return true;
}


char Critter::getSymbol()
{
    return this->symbol;
}

void Critter::print_board(Critter ***, int rows, int cols)
{
   for(int 1 = 0; i < rows; i++)
   {
      for(int k = 0; k < cols; k++)
      {
         std::cout << board[i][k]->getSymbol();
      }
      std::cout << std::endl;
   }
}
