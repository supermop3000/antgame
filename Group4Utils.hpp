/******************************************************************************
 ** Author:      Winter 162 400 Group 4
 ** Date:        02/04/2019
** Description: This is a declaration of utility funcitons.  These functions
**              help to validate integers for user selections, generation of 
**              random numbers, and functions to display and initialize the 
**              game board and Critters.
******************************************************************************/

#ifndef GROUP4UTILS_HPP
#define GROUP4UTILS_HPP
#include <string>
#include <iostream>
#include "Critter.hpp"
#include "Doodlebug.hpp"
#include "Ant.hpp"
using std::string;

//Prototype function for random generation in an integer range
int randIntRange(int, int);

//Prototype functions for validating integers
int validSelection(); //validate user input, selection between 2 choices
int validInt(); //validate integer input greater than 0
int validNonNegative(); //valide integer is non-negative

//Prototype functions for displaying and updating the game board 
void printBoard(Critter***, int, int); // print the board of the program
void placeDoodles(Critter***, int&, int, int, int); // add starting Doodlebugs to the board
void placeAnts(Critter***, int&, int, int, int); // add starting Ants to the board

#endif
