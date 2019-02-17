/**************************************************************************************************
** Program name:Group Project - Predator-Prey Game
** Author:	Group 4
** Date:	2019/02/04
** Description: THIS IS THE IMPLEMENTATION FILE OF THE ANT CLASS
**              This program runs a Predator-Prey Game with "Doodlebug"
**              predators and "Ant" prey. The program starts with a menu and
**              has the user set the number steps for the simulation to take.
**              Once the simulation is complete, the user is queried for the
**              whether they want to continue with more steps or quit.
**************************************************************************************************/
// Ant.cpp

#include "Critter.hpp"
#include "Ant.hpp"
#include "Group4Utils.hpp"

/**************************************************************************************************
** Description: Ant()
**              This is the default constructor for the Ant Class
**************************************************************************************************/
Ant::Ant(int x_pos, int y_pos):Critter(x_pos, y_pos)
{
   this->breedAge = 3;
   this->symbol = 'O';
}


/**************************************************************************************************
** Description: void move(Critter***, int, int))
**              This function moves an Ant on the board.
**              The Critter*** argument represents the board the Critters are on.
**              The two integers represent the dimensions of the board.
**************************************************************************************************/
void Ant::move(Critter *** &boardIn, int size_x, int size_y)
{
      int new_x, new_y;
      bool cellFree = false;
      bool inBounds = false;
      int random = randIntRange(0,3);
      int attempts = 0;
//      switch (random) 
      while(attempts < 4)
      {
         //case 0: 
         if(random == 0)
	 {
          	 new_x = this->x_pos - 1;
                 new_y = this->y_pos;
                 inBounds = checkBounds(new_x, new_y, size_x, size_y);
                 if(inBounds && boardIn[new_x][new_y] == NULL)
                 {
                    cellFree = true;   
	            break;
                 }
                 else if(attempts >= 4)
                    break;
                 else
                 {  
                    attempts++;
                    random = 1;
                 }
	}
	if(random == 1)
	{
         //case 1: 
         	 new_x = this->x_pos;
                 new_y = this->y_pos + 1;
                 inBounds = checkBounds(new_x, new_y, size_x, size_y);
                 if(inBounds && boardIn[new_x][new_y] == NULL)
                 {
                    cellFree = true;
      	            break;
                 }
                 else if(attempts >= 4)
                    break;
                 else
                 {
                    attempts++;
                    random = 2;
                 }
	}
	if(random == 2)
	{  
         //case 2: 
         	new_x = this->x_pos + 1;
                 new_y = this->y_pos;
                 inBounds = checkBounds(new_x, new_y, size_x, size_y);
                 if(inBounds && boardIn[new_x][new_y] == NULL)
                 {
                    cellFree = true;
	            break;
                 }
                 else if(attempts >= 4)
                    break;
                 else
                 {
                    attempts++;
                    random = 3;
                 }
	}
	if(random == 3)
	{
         //case 3: 
         	 new_x = this->x_pos;
                 new_y = this->y_pos - 1;
                 inBounds = checkBounds(new_x, new_y, size_x, size_y);
                 if(inBounds && boardIn[new_x][new_y] == NULL)
                 {
                    cellFree = true;
	            break;
                 }
                 else if(attempts >= 4)
                    break;
                 else
                 {
                    attempts++;
                    random = 0;
                 }
	}
      }

      if(cellFree == true)
      {
         //delete  boardIn[new_x][new_y];
         boardIn[new_x][new_y] = boardIn[this->x_pos][this->y_pos];
         boardIn[this->x_pos][this->y_pos] = NULL;
         this->x_pos = new_x;
         this->y_pos = new_y;
	 this->moveSuccess = 1;
      }

      else
      {
         this->moveSuccess = 1;
         return;
      }
   
     // age ants
     age++;
   
}

/*    if (direction == 0) //move North (up)
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

    this->age++;*/
