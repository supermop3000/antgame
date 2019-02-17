/********************************************************************
** Program name:Group Project - Predator-Prey Game
** Author:      Group 4
** Date:        2019/02/10
** Description: THIS IS THE IMPLEMENTATION FILE OF THE MENUFUNCTIONS
**              The menuFunctions will display the main menu, the 
**              menu asking the user to input number of steps in the
**              simulation, and  the continue or quit menu.
********************************************************************/
#include "menuFunctions.hpp"

/********************************************************************
** void dispMainMenu():
** description: This function displays the main menu of the program
** notes:	2/10-HD:Added short description and formatting to
**			the output
********************************************************************/
void dispMainMenu()
{
    cout << "\n\n";
    cout << "======================================\n";
    cout << "| - * - * PREDATOR PREY GAME * - * - |\n";
    cout << "======================================\n";
    cout << "| This program is a simulation of a  |\n";
    cout << "|  predator-prey interaction where   |\n";
    cout << "|  ants are prey and doodlebugs are  |\n";
    cout << "|    doodlebugs. Critters move and   |\n";
    cout << "|   breed. Doodlebugs eat ants and   |\n";
    cout << "|     starve if they do not eat.     |\n";
    cout << "======================================\n";
    cout << "- Enter the Number For Your Selection -\n\n";
    cout << "     1. Play Game\n";
    cout << "     2. Quit\n\n";
}

/********************************************************************
** void queryNumSteps():
** Description: This function queries the user for the number of
** 		steps to run for the program	
********************************************************************/
void queryNumSteps()
{
    cout << "Enter an integer greater than 1 for the number of steps.\n\n";
}

/********************************************************************
** void queryNumDood(int)
** Description: This function queries the user for the number of
**              additional steps the user would like to to take, or  
**              enter 0 to exit the program.
********************************************************************/
void queryContinue()
{
    cout << "\n";
    cout << "====================================\n";
    cout << "|Predator Prey Simulation Complete!|\n";
    cout << "====================================\n\n";
    cout << "How Many More Steps Would You Like\n";
    cout << "     the Simulation to Take?\n";
    cout << "  (Enter 0 To Quit the Program)\n";
}
