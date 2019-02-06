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
        bool move(Critter ***);
        void breed(Critter *** &);
};

#endif
