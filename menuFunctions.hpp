/****************************************************************************
** Program name:Group Project - Predator-Prey Game
** Author:	Group 4
** Date:	2019/02/04
** Description: THIS IS THE HEADER FILE OF THE MENUFUNCTIONS
**              This program runs a Predator-Prey Game with "Doodlebug"
**              predators and "Ant" prey. The program starts with a menu and
**              has the user set the number steps for the simulation to take.
**              Once the simulation is complete, the user is queried for the
**              whether they want to continue with more steps or quit.
*****************************************************************************/

#ifndef MENUFUNCTIONS_HPP
#define MENUFUNCTIONS_HPP

#include <iostream>

using std::cout;

// Display Functions
void dispMainMenu();
void queryNumSteps();
void querySettings();
// Custom Settings Displays
void queryCustRows();
void queryCustCols();
void queryNumAnts(int);
void queryNumDood(int);

void queryContinue();

#endif
