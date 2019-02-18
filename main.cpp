/******************************************************************************
 ** Author:      Winter 162 400 Group 4
 ** Date:        02/01/2019
 ** Description: This program runs a Predator-Prey Game with "Doodlebug"
 **              predators and "Ant" prey.
 ******************************************************************************/
#include "Group4Utils.hpp"
#include "Critter.hpp"
#include "Doodlebug.hpp"
#include "Ant.hpp"
#include "menuFunctions.hpp"
#include <iostream>
#include <string>
using std::cout;

//Prototype functions for displaying moving, breeding, and starving Critter functions
void moveCritters(Critter ***, int, int, char);
void resetCritterMoveSuccess(Critter ***, int, int);
void breedCritters(Critter ***, int, int, char);
void starveCritters(Critter ***, int, int, char);

int main()
{
    int playGame;
    int timeSteps;
    int size_x = 20;
    int size_y = 20;
    //int numAnts = 100;
    //int numDoodbugs = 5;
    Critter ***board;


/*********************************************************************************
** This area serves as the menu for the user to configure the ants, doodlebugs,
** the board, and the number of steps the program should take.
*********************************************************************************/

    //Display the main menu
    dispMainMenu();

    //Make menu choice (input validated to ensure only a 1 or 2 is selected)
    playGame = validSelection();

    if(playGame == 1) //Play the game
    {
        queryNumSteps(); //Ask the user for the number of steps
        timeSteps = validInt(); //Validate it's a non-negative integer
    }
    else //quit game
    {
      return 0;
    }

/*********************************************************************************
** This area holds the creation of the board, along with its accompanying Ants
** and Doodlebugs.
*********************************************************************************/
    //Initialize the board
    board = new Critter**[size_x];
    for(int i = 0; i < size_x; i++)
    {
        board[i] = new Critter*[size_y];

        for(int j = 0; j < size_y; j++)
        {
            board[i][j] = NULL;
        }
    }

    //Counters for the number of each Critter being placed.
    //int doodCount = 0;
    //int antCount = 0;

    //Place Doodlebugs on the board
    //placeDoodles(board, doodCount, numDoodbugs, size_x, size_y);

    //Place Ants on the board
    //placeAnts(board, antCount, numAnts, size_x, size_y);

    board[1][1] = new Doodlebug(1,1);
    board[0][1] = new Doodlebug(0,1);


    //Print starting board 
    printBoard(board, size_x, size_y);

    
    

/*********************************************************************************
** This area contains all the simulated movement/feeding, breeding, and starving
** the Ants and the Doodlebugs will take part in.
*********************************************************************************/
    // loop through the simulation until the user decides to end the simulation
    while (timeSteps != 0)
    {
        
        /*************************************
        ** MOVE THE DOODLEBUGS
        *************************************/
        moveCritters(board, size_x, size_y, 'X');
        
        resetCritterMoveSuccess(board, size_x, size_y);
        
        /*************************************
         ** MOVE THE ANTS
         *************************************/
        moveCritters(board, size_x, size_y, 'O');
        
        resetCritterMoveSuccess(board, size_x, size_y);

        /*************************************
        ** STARVE THE DOODLEBUGS
        *************************************/
        starveCritters(board, size_x, size_y, 'X');

        /*************************************
        ** BREED THE CRITTERS
        *************************************/    
        breedCritters(board, size_x, size_y, 'X');
        breedCritters(board, size_x, size_y, 'O');
        
        //Print board
        printBoard(board, size_x, size_y);

        // decrease the number of steps
        timeSteps--;

        // if the program is about to end, ask the user to enter more steps or quit
        if (timeSteps == 0)
        {
            queryContinue();
            timeSteps = validNonNegative();
        }

    }

/*********************************************************************************
** This area deletes the dynamically allocated Critter array
*********************************************************************************/
    for(int i = 0; i <  size_x; i++)
    {
        for(int j = 0; j < size_y; j++)
        {
            delete board[i][j];
        }
        delete[] board[i];
    }
    delete[] board;
    board = NULL;

    return 0;
}


/*********************************************************************************
** moveCritters(Critter***, int, int, char)
** Description: The moveCritters function iterates through the game board, checking
**              to see if there is a pointer to a Critter at each entry and that
**              the Critter symbol matches the one inputted.  If these conditions
**              are met and the Critter has not moved yet, the move function is
**              called for that Critter.    
*********************************************************************************/
void moveCritters(Critter *** board, int size_x, int size_y, char symbol)
{
    //Iterate through the game board
    for(int i=0; i<size_y; i++)
    {
        for(int j=0; j<size_x; j++)
        {
            /*Check if there is a Critter and 
              that the Critter symbol matches the input symbol */
            if(board[i][j] != NULL && board[i][j]->getSymbol() == symbol)
            {
                //Check to see if the Critter has moved yet
                if(board[i][j]->getMoveSuccess() == 0)
                {
                    //Run the move function for the Critter
                    board[i][j]->move(board, size_x, size_y);
                }
            }
        }
    }
}

/*********************************************************************************
** resetCritterMoveSuccess(Critter***, int, int)
** Description: The resetCritterMoveSuccess function iterates through the game 
**              board, and resets the move success for use in the next time step. 
*********************************************************************************/
void resetCritterMoveSuccess(Critter *** board, int size_x, int size_y)
{
    //Iterate through the board 
    for(int i=0; i<size_y; i++)
    {
        for(int j=0; j<size_x; j++)
        {
            //Check if there is a pointer to a Critter
            if(board[i][j] != NULL)
            {
                //Reset moveSuccess for next time step
                board[i][j]->resetMoveSuccess();
            }
        }
    }
}

/*********************************************************************************
** breedCritter(Critter***, int, int, char)
** Description: The breedCritter function iterates through the game board, checking
**              to see if there is a pointer to a Critter at each entry and that
**              the Critter symbl matches the one inputted.  If these conditions
**              are met, then the breed function is called for that Critter. 
*********************************************************************************/
void breedCritters(Critter *** board, int size_x, int size_y, char symbol)
{
    //Iterate through the game board
    for(int i=0; i<size_y; i++)
    {
        for(int j=0; j<size_x; j++)
        {
            /*Check if there is a Critter and 
              that the Critter symbol matches the input symbol */
            if(board[i][j] != NULL && board[i][j]->getSymbol() == symbol)
            {
                //Run the breed function
                board[i][j]->breed(board, size_x, size_y);
            }
        }
    }
}

/*********************************************************************************
** starveCritter(Critter***, int, int, char)
** Description: The starveCritter function iterates through the game board, checking
**              to see if there is a pointer to a Critter at each entry and that
**              the Critter symbl matches the one inputted.  If these conditions
**              are met, then the starve function is called for that Critter. 
*********************************************************************************/
void starveCritters(Critter *** board, int size_x, int size_y, char symbol)
{
    //Iterate through game board
    for(int i=0; i<size_y; i++)
    {
        for(int j=0; j<size_x; j++)
        {
            /*Check if there is a Critter and 
              that the Critter symbol matches the input symbol */
            if(board[i][j] != NULL && board[i][j]->getSymbol() == symbol)
            {
                //If the Critter starved, remove it from the board
                if(board[i][j]->starve(board))
		        {
			        delete board[i][j];
			        board[i][j] = NULL;
		        }
                
            }
        }
    }
}
