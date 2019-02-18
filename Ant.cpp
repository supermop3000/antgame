/**************************************************************************************************
** Program Name:Group Project - Predator-Prey Game
** Author:	Group 4
** Date:	2019/02/04
** Description: THIS IS THE IMPLEMENTATION FILE OF THE ANT CLASS
**		          It contains the default constructor creating an Ant object and the move function
**              that will move the Ant object on the board based on randomly selecting a cardinal
**              direction and checking that the move would not push the ant off the board and the
**              space is not occupied before moving.
**************************************************************************************************/
#include "Critter.hpp"
#include "Ant.hpp"
#include "Group4Utils.hpp"

/**************************************************************************************************
** Description: Ant(int,int)							 
**              This is the default constructor for the Ant Class that sets the breeding age of the 
**              Ant to 3, the board symbol representing the Ant to 'O', and the moveSuccess to 0.
**************************************************************************************************/
Ant::Ant(int x_pos, int y_pos):Critter(x_pos, y_pos)
{
   this->breedAge = 3;
   this->symbol = 'O';
   this->moveSuccess = 0;
}

Ant::Ant(int x, int y, int antAge):Critter(x_pos,y_pos,age)
{
   this->breedAge = 3;
   this->symbol = 'O';
   this->moveSuccess = 0;
}

/**************************************************************************************************
** Description: void move(Critter*** &, int, int))		   
**		          The move function for the Ant class will randomly call a number between 0-3, which
**              represents the cardinal directions (NORTH, EAST, SOUTH, and WEST).  Based on the
**              random direction, the ant will attempt to move to that location as long as the 
**              move will not go out of bounce and the space is unoccupied.
**************************************************************************************************/
void Ant::move(Critter *** &boardIn, int size_x, int size_y)
{
   int new_x, new_y;
   bool cellFree = false;
   bool inBounds = false;
   int random = randIntRange(0,3);

   //Move based on direction that was randomly choosen
   if(random == 0) //Ant move direction NORTH
	{
      //Assign the potential x and y positions
      new_x = this->x_pos - 1;
      new_y = this->y_pos;
   }
   else if (random == 1) //Ant move direction EAST
   {
      //Assign the potential x and y positions
      new_x = this->x_pos;
      new_y = this->y_pos + 1;
   }
   else if (random == 2) //Ant move direction SOUTH
   {
      //Assign the potential x and y positions
      new_x = this->x_pos + 1;
      new_y = this->y_pos;
   }
   else //Ant move direction WEST
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

   //Update that move function has finished for the Ant
   this->moveSuccess = 1; 

   //Age the ant
   age++;   
}