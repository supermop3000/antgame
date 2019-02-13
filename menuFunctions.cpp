/********************************************************************
** Program name:Group Project - Predator-Prey Game
** Author:      Group 4
** Date:        2019/02/10
** Description: THIS IS THE IMPLEMENTATION FILE OF THE MENUFUNCTIONS
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
    cout << "|  NOTE:EXTRA CREDIT WAS COMPLETED   |\n";
    cout << "======================================\n";
    cout << "- Enter the Number For Your Selection -\n\n";
    cout << "     1. Play Game\n";
    cout << "     2. Quit\n\n";
}

/********************************************************************
** void queryNumSteps():
** description: This function queries the user for the number of
** 		steps to run for the program
** notes:	
********************************************************************/
void queryNumSteps()
{
    cout << "Enter an integer greater than 1 for the number of steps\n\n";
}

/********************************************************************
** void querySettings();
** description: This functions queries the user for whether they
**		would like default settings or custom settings for
**		the program.
** notes:	
********************************************************************/
void querySettings()
{
    cout << "\n";
    cout << "Would You Like Custom Settings or Default Settings?\n\n";
    cout << "     1. Default Settings\n";
    cout << "     2. Custom Settings\n\n";
}

/********************************************************************
** void queryCustRows()
** description: This functions queries the user for the number of
**		rows of the board should have.
** notes:	
********************************************************************/
void queryCustRows()
{
    cout << "\n";
    cout << "Enter an integer greater than 1 for the number of rows\n\n";
}

/********************************************************************
** void queryCustCols()
** description: This functions queries the user for the number of
**		columns of the board should have.
** notes:	
********************************************************************/
void queryCustCols()
{
    cout << "\n";
    cout << "Enter an integer greater than 1 for the number of columns\n\n";
}

/********************************************************************
** void queryNumAnts(int)
** description: This function queries the user for the number of
**		ants the board should have. Takes an integer to
**		represent the max possible ants on the board.
** notes:	
********************************************************************/
void queryNumAnts(int maxAnts)
{
   cout << "\n";
   cout << "Enter an integer greater than 1 and less than \n";
   cout << maxAnts << " for the number of Ants\n\n";

}

/********************************************************************
** void queryNumDood(int)
** description: This function queries the user for the number of
**		Doodlebugs the board should have. Takes an integer to
**		represent the max possible Doodlebugs on the board.
** notes:	
********************************************************************/
void queryNumDood(int maxDoodBugs)
{
   cout << "\n";
   cout << "Enter an integer greater than 1 and less than \n";
   cout << maxDoodBugs << " for the number of Doodlebugs\n\n";
}


/********************************************************************
** void queryNumDood(int)
** description: This function queries the user for the number of
**  steps the user would like to to take, or  exit the program.
** notes:	
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
