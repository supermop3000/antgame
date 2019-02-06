

#include "Doodlebug.hpp"
#include "Group4Utils.hpp"
#include <iostream>

using std::cout;
using std::endl;

Doodlebug::Doodlebug(int x_pos, int y_pos):Critter()
{
   this->x_pos = x_pos;
   this->y_pos = y_pos;
   this->age = 0;
   this->hunger = 0;
   this->symbol = 'X';
}

bool Doodlebug::move(Critter ***boardIn)
{
   cout << "in doodlemove" << endl;
   return true;
}

void Doodlebug::breed(Critter *** &boardIn)
{
   bool cellFree = false;
   int new_x, new_y;
   int direction = randIntRange(0,3);
   int randIterator = 0;
   //check that adjacent cell is free, i.e. printSymbol() of the object of that cell returns ' '
   if(age ==8)
   {
     while(cellFree == false && randIterator != 3)
     {
  	   if(direction == 1 && boardIn[this->x_pos + 1][this->y_pos]==NULL)
  	   {
  	      new_x = x_pos + 1;
  	      new_y = y_pos;
  	      cellFree = true;
          cout << "New doodlebug born at row " << new_x << "and col " << new_y;
                break;
  	   }
  	   if(direction == 0 && boardIn[this->x_pos - 1][this->y_pos]==NULL)
  	   {
  	      new_x = x_pos - 1;
  	      new_y = y_pos;
  	      cellFree = true;
          cout << "New doodlebug born at row " << new_x << "and col " << new_y;
                break;
  	   }
  	   if(direction == 2 && boardIn[this->x_pos][this->y_pos + 1]==NULL)
  	   {
  	      new_x = x_pos;
  	      new_y = y_pos + 1;
  	      cellFree = true;
          cout << "New doodlebug born at row " << new_x << "and col " << new_y;
                break;
  	   }
  	   if(direction == 3 && boardIn[this->x_pos][this->y_pos - 1]==NULL)
  	   {
  	      new_x = x_pos;
  	      new_y = y_pos - 1;
  	      cellFree = true;
          cout << "New doodlebug born at row " << new_x << "and col " << new_y;
                break;
  	   }
       if(direction != 3 && randIterator <3)
       {
         direction = direction + 1;
         randIterator ++;
       }
       else if (direction==3 && randIterator <3)
       {
         direction = 0;
         randIterator++;
       }
       else
       {
         return;
       }
     }
     if(cellFree == true)
     {
       cout << new_x << " " << new_y <<endl;
       delete boardIn[new_x][new_y];
       Doodlebug *doodle = new Doodlebug(new_x, new_y);
       boardIn[new_x][new_y] = doodle;
     }
     else
     {
       return;
     }


  }
}

//helper function for breed test
void Doodlebug::setAge(int ageIn)
{
  this->age = ageIn;
}
