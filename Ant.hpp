/**************************************************************************************************
** Program name:Group Project - Predator-Prey Game
** Author:	Group 4
** Date:	2019/02/04
** Description: THIS IS THE HEADER FILE OF THE ANT CLASS
**              It is a derived class from the Critter class.  In addition to the protected member
**              variables and public functions it contains a default constructor and destructor,
**              and a void move function.
**************************************************************************************************/
#ifndef ANT_HPP
#define ANT_HPP
#include "Critter.hpp"
#include <vector>
using std::vector;

class Ant : public Critter
{
	public:
		Ant(int x_pos, int y_pos);
		~Ant(){};
		virtual void move(Critter *** &, int, int);
};

#endif
