/**************************************************************************************************
** Program name:Group Project - Predator-Prey Game
** Author:	Group 4
**		Herbert Diaz  <diazh@oregonstate.edu>
**      Janet Anderson <andejane@oregonstate.edu>
**		INSERT NAME IF YOU HAVE CONTRIBUTED TO THIS FILE
** Date:	2019/02/04
** Description: THIS IS THE IMPLEMENTATION FILE OF THE ANT CLASS
**		TODO: DESCRIPTION OF PROGRAM
**************************************************************************************************/
// Ant.cpp

#include "Critter.hpp"
#include "Ant.hpp"
#include "Group4Utils.hpp"

//!!!COPY AND PASTE THIS BEFORE YOUR FUNCTIONS SO WE CAN KEEP ALL THE INFORMATION TOGETHER!!!!
/**************************************************************************************************
** Description: INSERT PROTOTYPE				**PUBLIC::DATE::INITIALS OF AUTHORS**
**              INSERT DESCRIPTION	 **************************
**************************************************************************************************/


/**************************************************************************************************
** Description: Ant()							 **PUBLIC::2019.02.04::HD**
**              This is the default constructor for the Ant Class	 **************************
**************************************************************************************************/
Ant::Ant(int x_pos, int y_pos):Critter()
{
   this->x_pos = x_pos;
   this->y_pos = y_pos;
   this->age = 0;
   this->symbol = 'O';
}


/**************************************************************************************************
** Description: void move(TODO: PARAMETERS TBA)				 **PUBLIC::2019.02.04::HD**
**              TODO:DESCRIBE ARGUMENTS	 **************************
**		This function also
**************************************************************************************************/
void Ant::move(Critter ***boardIn, int rows, int cols)
{
    int direction = randIntRange(0,3);

    if (direction == 0) //move North (up)
    {
        //check that board[x_pos -1][y] is not out of bounds and has symbol = ' '
        if (this->x_pos -1 > 0)
        {
            if (boardIn[this->x_pos -1][this->y_pos]->getSymbol() == ' ')
            {
                //Copy Ant to New Location
                //Delete Ant in Old Location

            }
        }

        //else the ant stays in its current cell
    }
    else if (direction == 1) //move South (down)
    {
        //check that board[x_pos + 1][y] is not out of bounds and has symbol = ' ' (check that x_pos+1 > rows -1)
		if (this->x_pos + 1 <rows)
		{
        	if (boardIn[this->x_pos + 1][this->y_pos]->getSymbol() == ' ')
        	{
            	//Copy Ant to New Location
            	//Delete Ant in Old Location
			}
        }

		//else the ant stays in its current cell
    }
    else if (direction == 2) //move East (right)
    {
        //check that position[x_pos][y_pos + 1] is not out of bounds and has symbol = ' '
        if (this->y_pos + 1 < cols)
        {
            if (boardIn[this->x_pos][this->y_pos + 1]->getSymbol() == ' ')
			{
				//Copy Ant to New Location
            	// Ant in Old Location
			}
        }

		//else the ant stays in its current cell
    }
    else //move West (left)
    {
        //check that position[x_pos][y_pos -1] is not out of bounds and has null pointer or symbol ' '
        if (this->y_pos -1 > 0)
        {
            if (boardIn[this->x_pos][this->y_pos-1]->getSymbol() == ' ')
            {
                //Copy Ant to New Location
                //Delete Ant in Old Location

            }
        }

		//else ant stays in its current cell
    }

    this->age++;
}
