/******************************************************************************
 ** Author:      Winter 162 400 Group 4
 ** Date:        02/01/2019
 ** Description: This is the implementation of the Critter, Ant, and Doodlebug
 **              classes.
 ******************************************************************************/

#include "Critter.hpp"

/******************************************************************************
 ** description: Critter constructor
 ******************************************************************************/
Critter::Critter(int x_pos, int y_pos)
{
    this->x_pos = x_pos;
    this->y_pos = y_pos;
    age = 0;
    symbol = ' ';
}
