/**************************************************************************************************
** Program name:Group Project - Predator-Prey Game
** Author:	Group 4
** Date:	2019/02/04
** Description: THIS IS THE HEADER FILE OF THE ANT CLASS
**		ABSTRACTION OF:	The Ants, or Prey, of the Game
**		PURPOSE:
**		HOW TO USE:
**		SUMMARY:
**************************************************************************************************/


#ifndef ANT_HPP
#define ANT_HPP

#include "Critter.hpp"
#include <vector>

using std::vector;

class Ant : public Critter
{
	private:

	public:
		Ant(int x_pos, int y_pos);
		~Ant(){};
		void move(Critter *** &, int, int);
	 	// void breed(Critter*** &, int, int);	// TODO: DETERMINE NECESSARY PARAMETERS ~HD
};

#endif
