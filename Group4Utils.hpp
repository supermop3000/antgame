/******************************************************************************
 ** Author:      Winter 162 400 Group 4
 ** Date:        02/04/2019
** Description: This is a declaration of utility funcitons.
******************************************************************************/

#ifndef GROUP4UTILS_HPP
#define GROUP4UTILS_HPP

#include <string>
#include <iostream>
#include "Critter.hpp"
#include "Doodlebug.hpp"
#include "Ant.hpp"

using std::string;

  // random
  int randIntRange(int, int );
  //validate user input, selection between 2 choices
  int validSelection();
  //validate integer input greater than 0
  int validInt();
  //validate integer input is non-negative
  int validNonNegative();
  //validate integer input greater than 0 with a max variable
  int validIntMax(int maxInput);
  // print the board of the program
  void printBoard(Critter***, int, int);
  // add starting doodlebugs to the board
  void placeDoodles(Critter***, int&, int, int, int);
  // add starting ants to the board
  void placeAnts(Critter***, int&, int, int, int);

#endif
