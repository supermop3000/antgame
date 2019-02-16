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

      void move(Critter *** &, int, int);
      // void breed(Critter *** &);
      bool starve(Critter***);
      //helper function for setAge
      void setAge(int ageIn);
};

#endif
