/********************************************************************
 * Program name: Group Project - Predator Prey Sim
 * Header file for Doodlebug Class
 * Author: Group 4
 * Date: 02/16/2019
 * Description: This is the header file of the Doodlebug class
 *  This program runs a Predator-Prey Game with "Doodlebug"
 *  predators and "Ant" prey. The program starts with a menu and
 *  has the user set the number steps for the simulation to take.
 *  Once the simulation is complete, the user is queried for the
 *  whether they want to continue with more steps or quit.
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
