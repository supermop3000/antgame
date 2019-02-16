/**************************************************************************************************
** Program name:Group Project - Predator-Prey Game
** Author:	Group 4
** Date:	2019/02/04
** Description: THIS IS THE HEADER FILE OF THE ANT CLASS
**              This program runs a Predator-Prey Game with "Doodlebug"
**              predators and "Ant" prey. The program starts with a menu and
**              has the user set the number steps for the simulation to take.
**              Once the simulation is complete, the user is queried for the
**              whether they want to continue with more steps or quit.
**		ABSTRACTION OF:	The Ants, or Prey, of the Game
**		PURPOSE: This program encapsulates all the functions related to an Ant object.
**		HOW TO USE: Use the constructor to create an Ant object.
**		SUMMARY: The Ant class is a derived class of the Critter class. Use the move function to
**      move an Ant on the board.
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
};

#endif
