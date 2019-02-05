

#include "Critter.hpp"

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
   //check that adjacent cell is free, i.e. printSymbol() of the object of that cell returns ' '
   if(boardIn[this->x_pos + 1][this->y_pos]->getSymbol() == ' ')
   {
      delete boardIn[this->x_pos + 1][this->y_pos];
      Doodlebug *doodle = new Doodlebug(this->x_pos + 1, this->y_pos);
      boardIn[this->x_pos + 1][this->y_pos] = doodle;
      cout <<  "new symbol in array " << boardIn[this->x_pos + 1][this->y_pos]->getSymbol() << endl;
      
      //delete doodle;
   }
}
