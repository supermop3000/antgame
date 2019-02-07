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
** Description: void move(Critter***, int, int))		   **PUBLIC::2019.02.04::HD-JA-CC**
**              TODO:DESCRIBE ARGUMENTS	 			   ********************************
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


/**************************************************************************************************
** Description: void breed(Critter***, int, int))		      **PUBLIC::2019.02.05::HD-JA**
**              TODO:DESCRIBE ARGUMENTS	 			      *****************************
**		TODO:DESCRIBE FUNCTION
**************************************************************************************************/
void Ant::breed(Critter** boardIn, int rows, int cols)
{
	int randomRoll;	// holds the randomly generated integer for choosing a direction
	bool cellFree = true;	// checks if any adjacent cells are free
	vector<int> openSpace;	// holds values that indicate the location of an open space

	// Check to see if any of the cells are free **CAN BE MADE INTO HELPER FUNCTION**
	// Check if x_pos + 1 is free TODO: OR OUT OF BOUNDS
	if (boardIn[this->x_pos + 1][this->y_pos] == NULL)
	{
		openSpace.push_back(0);		// **0 is used to indicate the east space is free
		if (cellFree == false)		// ^^^^^CAN BE CHANGED INTO AN ENUMERATED VALUE(?)
		{	cellFree = true;	// Set cell free to show to indicate an open adjacent cell
		}
	}
	// Check if x_pos - 1 is free TODO: OR OUT OF BOUNDS
	if (boardIn[this->x_pos - 1][this->y_pos] == NULL)
	{
		if (cellFree == false)		// **1 is used to indicate the west space is free
		openSpace.push_back(1);
		{	cellFree = true;
		}
	}
	// Check if y_pos + 1 is free TODO: OR OUT OF BOUNDS
	if (boardIn[this->x_pos][this->y_pos + 1] == NULL)
	{
		openSpace.push_back(2);		// **2 is used to indicate the north space is free
		if (cellFree == false)
		{	cellFree = true;
		}
	}
	// Check if y_pos - 1 is free TODO: OR OUT OF BOUNDS
	if (boardIn[this->x_pos + 1][this->y_post] == NULL)
	{
		openSpace.push_back(3);		// **3 is used to indicate the south space is free
		if (cellFree == false)
		{	cellFree = true;
		}
	}

	// If the Ant has Been Alive 3 turns && There Are Adjacent Spaces That Are Open
	if ((this->age % 3) == 2 && cellFree == true)
	{
		// randomly roll a number between 0 and (size of open Space vector - 1)
		randomRoll = randIntRange(0, openSpace.size() - 1)

		// INTEGERS INSIDE VECTOR INDICATE THE FOLLOWING
		// 0 = x_pos + 1
		// 1 = x_pos - 1
		// 2 = y_pos + 1
		// 3 = y_pos - 1
		if (openSpace[randomRoll] == 0)
		{
			// add an Ant with an age of 0 to the east (x_pos + 1)
			Critter[this->x_pos + 1][this->y_pos] = new Ant;
		}
		else if (openSpace[randomRoll] == 1)
		{
			// add an Ant with an age of 0 to the west (x_pos - 1)
			Critter[this->x_pos - 1][this->y_pos] = new Ant;

		}
		else if (openSpace[randomRoll] == 2)
		{
			// add an Ant with an age of 0 to the north (y_pos + 1)
			Critter[this->x_pos][this->y_pos + 1] = new Ant;

		}
		else if (openSpace[randomRoll] == 3)
		{
			// add an Ant with an age of 0 to the south (y_pos - 1)
			Critter[this->x_pos][this->y_pos - 1] = new Ant;

		}
	}
		
}
