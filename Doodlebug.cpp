

#include "Doodlebug.hpp"

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
   //check that adjacent cell is free, i.e. printSymbol() of the object of that cell returns ' '
   while(cellFree == false)
   {
	   if(boardIn[this->y_pos + 1][this->x_pos]->getSymbol() == ' ')
	   {
	      new_y = y_pos + 1;
	      new_x = x_pos;
	      cellFree = true;
	      break;      
	   }
	   if(boardIn[this->y_pos - 1][this->x_pos]->getSymbol() == ' ')
	   {
	      new_y = y_pos - 1;
	      new_x = x_pos;
	      cellFree = true;
              break;
	   }
	   if(boardIn[this->y_pos][this->x_pos + 1]->getSymbol() == ' ')
	   {
	      new_y = y_pos;
	      new_x = x_pos + 1;
	      cellFree = true;
              break;
	   }
	   if(boardIn[this->y_pos][this->x_pos - 1]->getSymbol() == ' ')
	   {
	      new_y = y_pos;
	      new_x = x_pos - 1;
	      cellFree = true;
              break;
	   }
   }
      cout << new_y << " " << new_x <<endl;
      delete boardIn[new_y][new_x];
      Doodlebug *doodle = new Doodlebug(new_y, new_x);
      boardIn[new_y][new_x] = doodle;
}
