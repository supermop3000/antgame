/**************************************************************************************************
** Program name:Group Project - Predator-Prey Game
** Author:	Group 4
** Date:	2019/02/04
** Description: THIS IS THE HEADER FILE OF THE DOODLEBUG CLASS
**              It is a derived class from the Critter class.  In addition to the protected member
**              variables and public functions it contains a default constructor and destructor,
**              a void move function, and a boolean starve function.
**************************************************************************************************/
#ifndef DOODLEBUG_HPP
#define DOODLEBUG_HPP

#include "Critter.hpp"

class Doodlebug : public Critter
{
    private:
      int hunger;

    public:
      Doodlebug(int, int);
      ~Doodlebug(){};

      virtual void move(Critter *** &, int, int);
      virtual bool starve(Critter***);
};

#endif
