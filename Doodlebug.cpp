/**********************************************************************
** Program name: Group Project
** Author:  Group 4
** Date: 2/15/2019
** Description: This is the implementation file of the Doodlebug class
 * Description: This is the header file of the Doodlebug class
 *  This program runs a Predator-Prey Game with "Doodlebug"
 *  predators and "Ant" prey. The program starts with a menu and
 *  has the user set the number steps for the simulation to take.
 *  Once the simulation is complete, the user is queried for the
 *  whether they want to continue with more steps or quit.

**********************************************************************/

#include "Doodlebug.hpp"
#include "Group4Utils.hpp"
#include <iostream>

using std::cout;
using std::endl;

/*********************************************************************
** Description: This is the constructor for the Doodlebug class
*********************************************************************/

Doodlebug::Doodlebug(int x_pos, int y_pos):Critter(x_pos, y_pos)
{
   this->breedAge = 8;
   this->hunger = 0;
   this->symbol = 'X';
   this->moveSuccess = 0;
}

/**********************************************************************
** Description: This function moves the Doodlebug on the board.
**  This function takes a Critter*** argument that represents the
**  board the Doodlebugs are on. The two integer arguments represent
**  the dimensions of the board.
**********************************************************************/

void Doodlebug::move(Critter*** &boardIn, int size_x, int size_y)
{
   int random = randIntRange(0,3);
   bool antNear = false;
   bool inBounds = false;
   bool cellFree = false;

   int new_x, new_y;
   int attempts = 0;

   //check if ant is in an adjacent cell
   //switch (random) 
   //{
      while(attempts < 4)
      {
          if(random == 0)
          {
     /* case 0:*/ new_x = this->x_pos - 1;
              new_y = this->y_pos;
              inBounds = checkBounds(new_x, new_y, size_x, size_y);
              if(inBounds && boardIn[new_x][new_y] != NULL && boardIn[new_x][new_y]->getSymbol() == 'O')
              {
                 antNear = true;   
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
      //case 1:
         if(random == 1)
         { 
              new_x = this->x_pos;
              new_y = this->y_pos + 1;
              inBounds = checkBounds(new_x, new_y, size_x, size_y);
              if(inBounds && boardIn[new_x][new_y] != NULL && boardIn[new_x][new_y]->getSymbol() == 'O')
              {
                 antNear = true;
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
      //case 2: 
        if(random == 2)
        {
              new_x = this->x_pos + 1;
              new_y = this->y_pos;
              inBounds = checkBounds(new_x, new_y, size_x, size_y);
              if(inBounds && boardIn[new_x][new_y] != NULL && boardIn[new_x][new_y]->getSymbol() == 'O')
              {
                 antNear = true;
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
      //case 3: 
        if(random == 3)
        {
              new_x = this->x_pos;
              new_y = this->y_pos - 1;
              inBounds = checkBounds(new_x, new_y, size_x, size_y);
              if(inBounds && boardIn[new_x][new_y] != NULL && boardIn[new_x][new_y]->getSymbol() == 'O')
              {
                 antNear = true;
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

   if(antNear == true)
   {
      cout << "ant near doodlebug. Doodlebug at row " << x_pos << "column " <<y_pos<< "ant at row " <<new_x<< "col " << new_y << endl;
      delete boardIn[new_x][new_y]; //delete Ant at the new x,y position
      //set pointer at new x,y position equal to the Doodlebug point that is moving
      boardIn[new_x][new_y] = boardIn[this->x_pos][this->y_pos];      
      //reset the pointer at the old position to NULL to signify that the space is empty
      boardIn[this->x_pos][this->y_pos] = NULL;
      //update x and y position for the Doodlebug
      this->x_pos = new_x;
      this->y_pos = new_y;
      this->hunger = 0;
      this->moveSuccess = 1;
   }
 
   else //if antNear == false
   {
      attempts = 0;
      this->hunger += 1;
      random = randIntRange(0,3);
  //    switch (random) 
      while(attempts < 4)
      {
        // case 0: 
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
       //  case 1: 
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
   }
    
    // age doodlebug
    age++;
}

/******************************************************************
 ** Description: void breed(Critter***))
 ** PUBLIC::2019.02.10:: LL-HD
 ** delete doodlebug if it hasn't eaten in 3 turns
 ******************************************************************/
bool Doodlebug::starve(Critter*** board)
{
    if (this->hunger == 3)
    {
        cout << "a doodlebug has beed deleted at row " << x_pos << " col " << y_pos << endl;
        //delete board[x_pos][y_pos];
        //board[x_pos][y_pos] = NULL;
        return true;
    }
    else
        return false;
}
