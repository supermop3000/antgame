/**************************************************************************************************
** Program name:Group Project - Predator-Prey Game
** Author:	Group 4
**		Herbert Diaz  <diazh@oregonstate.edu>
**		INSERT NAME IF YOU HAVE CONTRIBUTED TO THIS FILE
** Date:	2019/02/04
** Description: THIS IS THE IMPLEMENTATION FILE OF THE ANT CLASS
**		TODO: DESCRIPTION OF PROGRAM
**************************************************************************************************/
// Ant.cpp

#include "Critter.hpp"


//!!!COPY AND PASTE THIS BEFORE YOUR FUNCTIONS SO WE CAN KEEP ALL THE INFORMATION TOGETHER!!!!
/**************************************************************************************************
** Description: INSERT PROTOTYPE				**PUBLIC::DATE::INITIALS OF AUTHORS**
**              INSERT DESCRIPTION	 **************************
**************************************************************************************************/


/**************************************************************************************************
** Description: Ant()							 **PUBLIC::2019.02.04::HD**
**              This is the default constructor for the Ant Class	 **************************
**************************************************************************************************/
Ant::Ant() : Critter()
{
	// TODO: WHAT SHOULD BE INITALIZED FOR THE ANT
}


/**************************************************************************************************
** Description: void move(TODO: PARAMETERS TBA)				 **PUBLIC::2019.02.04::HD**
**              TODO:DESCRIBE ARGUMENTS	 **************************
**		This function also 
**************************************************************************************************/
void Ant::move()
{
	// If the Ant Can Move
//TODO	if( antCanMove == true)
	{
		bool hasMoved == false;
		int roll;
		while (hasMoved == false)
		{
			// randomly choose a number between 0 and 3
			roll = rand() % 4

			if(roll == 0)
			{
				// TODO:Copy Ant to New Location
				// TODO:Delete Ant in Old Location
				// Set hasMoved to true
				hasMoved == True
			}
			else if (roll == 1)
			{
				// TODO:Copy Ant to New Location
				// TODO:Delete Ant in Old Location
				// Set hasMoved to true
				hasMoved == True
			}
			else if (roll == 2)
			{
				// TODO:Copy Ant to New Location
				// TODO:Delete Ant in Old Location
				// Set hasMoved to true
				hasMoved == True
			}
			else
			{
				// TODO:Copy Ant to New Location
				// TODO:Delete Ant in Old Location
				// Set hasMoved to true
				hasMoved == True
			}

		}
	}
	//Increase Ant's Age
	
}
