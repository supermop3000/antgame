/**************************************************************************************************
** Program name: Group Project
** Author:  Group 4
** Date: 2/15/2019
** Description: This is the implementation file of the Doodlebug class.
**		          It contains the default constructor creating a Doodlebug object, the move function
**              attempt to eat an Ant if they are near, or move the Doodlebug object on the board 
**              based on randomly selecting a cardinal direction and checking that the move would
**              not push the ant off the board and the space is not occupied before moving, and 
**              the boolean function that checks if a Doodlebug has starved or not.         
**************************************************************************************************/
#include "Doodlebug.hpp"
#include "Group4Utils.hpp"
#include <iostream>
using std::cout;
using std::endl;

/**************************************************************************************************
** Description: Doodlebug(int,int)							 
**              This is the default constructor for the Doodlebug Class that sets the breeding age 
**              of the Doodlebug to 8, the board symbol representing the Doodlebug to 'X', the 
**              hunger of the Doodlebug to 0, and the moveSuccess to 0.   
**************************************************************************************************/
Doodlebug::Doodlebug(int x_pos, int y_pos):Critter(x_pos, y_pos)
{
   this->breedAge = 8;
   this->hunger = 0;
   this->symbol = 'X';
   this->moveSuccess = 0;
}


/**************************************************************************************************
** Description: void move(Critter*** &, int, int))		   
**		          The move function for the Doodle will first check to see if there are any ants in 
**              the adjacent cells starting in the NORTH direction and proceed to check in the 
**              CLOCKWISE direction until it has found an ant or all the cardinal directions have
**              been checked.  If an ant is found to be near, the Doodlebug will eat the Ant.
**              Otherwise, the Doodlebug will attempt to move by choosing a random direction 
**              (simulated by randomly calling a number between 0-3), which represents the cardinal
**              directions (NORTH, EAST, SOUTH, and WEST).  Based on the random direction, the 
**              Doodlebug will attempt to move to that location as long as the move will not go out 
**              of bounds and the space is unoccupied.
**************************************************************************************************/
void Doodlebug::move(Critter*** &boardIn, int size_x, int size_y)
{
   int random = randIntRange(0,3);
   bool antNear = false;
   bool inBounds = false;
   bool cellFree = false;
   int new_x, new_y;

   //check if ant is in an adjacent cell
   for (int j = 0; j < 4; j++)
   {
      //Check that a previous adjacent cell does not contain an ant
      if (!antNear)
      {
         /*Start with the NORTH direction and then as j increases 
           check other directions */
         if (j == 0)
         {
            //Assign the potential x and y positions
            new_x = this->x_pos - 1;
            new_y = this->y_pos;
         }
         else if (j == 1) //EAST direction
         {
            //Assign the potential x and y positions
            new_x = this->x_pos;
            new_y = this->y_pos + 1;  
         }
         else if (j == 2) //SOUTH direction
         {
            //Assign the potential x and y positions
            new_x = this->x_pos + 1;
            new_y = this->y_pos;
         }
         else //j ==4; WEST direction
         {
            //Assign the potential x and y positions
            new_x = this->x_pos;
            new_y = this->y_pos - 1; 
         }

         //Check that the move would be in bounds
         inBounds = checkBounds(new_x, new_y, size_x, size_y);

         //Check to see if an Ant is in the adjacent cell
         if(inBounds && boardIn[new_x][new_y] != NULL && boardIn[new_x][new_y]->getSymbol() == 'O')
         {
            antNear = true;   
         }
      }
   }
      
   //If an Ant is adjacent, have the Doodlebug eat the Ant
   if(antNear)
   {
      delete boardIn[new_x][new_y]; //delete Ant at the new x,y position

      //Set pointer at new x,y position equal to the Doodlebug point that is moving
      boardIn[new_x][new_y] = boardIn[this->x_pos][this->y_pos];     

      //Reset the pointer at the old position to NULL to signify that the space is empty
      boardIn[this->x_pos][this->y_pos] = NULL;

      //Update x and y position for the Doodlebug
      this->x_pos = new_x;
      this->y_pos = new_y;
      this->hunger = 0;
   }
   else //No ants are near, try to move the Doodlebug
   {
      //Update Doodlebug's hunger since Doodlebug didn't eat
      this->hunger += 1;

      //Move based on direction that was randomly choosen
      if(random == 0) //Doodlebug move direction NORTH
	   {
         //Assign the potential x and y positions
         new_x = this->x_pos - 1;
         new_y = this->y_pos;
      }
      else if (random == 1) //Doodlebug move direction EAST
      {
         //Assign the potential x and y positions
         new_x = this->x_pos;
         new_y = this->y_pos + 1;
      }
      else if (random == 2) //Doodlebug move direction SOUTH
      {
         //Assign the potential x and y positions
         new_x = this->x_pos + 1;
         new_y = this->y_pos;
      }
      else //Doodlebug move direction WEST
      {
         //Assign the potential x and y positions
         new_x = this->x_pos;
         new_y = this->y_pos - 1;
      }

      //Check that the move is a legal move 
      inBounds = checkBounds(new_x, new_y, size_x, size_y);

      //Check the space and assign cellFree to true if space is free
      if(inBounds && boardIn[new_x][new_y] == NULL)
      {
         cellFree = true;   
      }

	   //If the space is free, move the ant to the new location
      if(cellFree == true)
      {
         //Set the pointer for the moving Ant to the new x,y position
         boardIn[new_x][new_y] = boardIn[this->x_pos][this->y_pos];

         //Set the pointer of the Ant's old x,y position to NULL
         boardIn[this->x_pos][this->y_pos] = NULL;

         //Set the Ant's x,y position variables to the new x,y position
         this->x_pos = new_x;
         this->y_pos = new_y;
      }
   }

   //Update that move function has finished for the Doodlebug
   this->moveSuccess = 1;

   //Update the Doodlebug Age
   age++;   
}

/******************************************************************
 ** Description: bool starve(Critter***))
 ** PUBLIC::2019.02.10:: LL-HD
 ** Boolean function to test if the Doodlebug has starved.
 ******************************************************************/
bool Doodlebug::starve(Critter*** board)
{
   if (this->hunger == 3)
   {
      return true;
   }
   else
   {
      return false;
   }
}

