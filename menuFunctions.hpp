/************************************************************
** Program name:Group Project - Predator-Prey Game
** Author:	Group 4
** Date:	2019/02/04
** Description: THIS IS THE HEADER FILE OF THE MENUFUNCTIONS
************************************************************/

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
