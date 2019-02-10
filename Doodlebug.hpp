/********************************************************************
 * Header file for Doodlebug Class
 * ****************************************************************/

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

      void move(Critter *** &);
      void breed(const Critter *** &);
      //helper function for setAge
      void setAge(int ageIn);
};

#endif
