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

// prototypes
void moveCritters(Critter ***, int, int, char, std::string);

void resetCritterMoveSuccess(Critter ***, int, int);

void breedCritters(Critter ***, int, int, char, std::string);

void starveCritters(Critter ***, int, int, char, std::string);

int main()
{
    int playGame;
//    int customSettings;
    int timeSteps;
    int size_x = 20;
    int size_y = 20;
    int numAnts = 100;
    int numDoodbugs = 5;
//    int maxAnts;
//    int maxDoodbugs;

    Critter ***board;


/*********************************************************************************
** This area serves as the menu for the user to configure the ants, doodlebugs,
** the board, and the number of steps the program should take.
*********************************************************************************/

    // display the main menu
    dispMainMenu();

    playGame = validSelection();

    if(playGame == 1)
    {
      // ask the user for the number of steps
      queryNumSteps();

      timeSteps = validInt();

/*      // ask the user if they want default settings or custom settings
      querySettings();
      customSettings = validSelection();
      cout << "\n";

      if(customSettings == 1)
      {
        cout << "Starting game with default settings" << "\n\n";
      }

      else if(customSettings == 2)
      {
        // ask the user for the number of rows for the board
        queryCustRows();
        size_x = validInt();

	    // ask the user for the number of columns for the board
	    queryCustCols();
        size_y = validInt();

	    // ask the user for the number of ants for the board
        maxAnts = (size_x * size_y -1);
	    queryNumAnts(maxAnts);
        numAnts = validIntMax(maxAnts);

	    // ask the user for the number of Doodlebugs for the board
        maxDoodbugs = (size_x * size_y - maxAnts);
	    queryNumDood(maxDoodbugs);
        numDoodbugs = validIntMax(maxDoodbugs);
        cout << "\n";

      }
*/
    }

    //quit game
    else if(playGame == 2)
    {
      return 0;
    }


/*********************************************************************************
** This area holds the creation of the board, along with its accompanying ants
** and doodlebugs.
*********************************************************************************/
/* SET UP VARIABLES HERE FOR THE PURPOSE OF TESTING

    size_x = 10;
    size_y = 10;

SET UP VARIABLES HERE FOR THE PURPOSE OF TESTING*/

    //set board spaces to null
    /*board = new Critter**[size_y];
    for(int i = 0; i < size_y; i++)
    {
      board[i] = new Critter*[size_x];
      for(int j = 0; j < size_x; j++)
      {
        board[i][j] = NULL;
      }
    }*/
    board = new Critter**[size_y];
    for(int i = 0; i < size_y; i++)
    {
        board[i] = new Critter*[size_x];

        for(int j = 0; j < size_x; j++)
        {
            board[i][j] = NULL;
        }
    }

    // counters for the number of each Critter being placed.
    int doodCount = 0;
    int antCount = 0;

    //helper variable setting age to 8 for breed test
    //int age = 8;

    // Place Doodlebugs on the board
    placeDoodles(board, doodCount, numDoodbugs, size_x, size_y);

    // Place Ants on the board
    placeAnts(board, antCount, numAnts, size_x, size_y);

    //print starting board - this should be a function outside of main that just gets called
    printBoard(board, size_y, size_x);


/*********************************************************************************
** This area contains all the simulated movement/feeding, breeding, and starving
** the Ants and the Doodlebugs will take part in.
*********************************************************************************/

/* SET UP VARIABLES HERE FOR THE PURPOSE OF TESTING

    timeSteps = 1;

SET UP VARIABLES HERE FOR THE PURPOSE OF TESTING*/
    int stepCounter = 0;

    // loop through the simulation until the user decides to end the simulation
    while (timeSteps != 0)
    {
        
        /*************************************
        ** MOVE THE DOODLEBUGS
        *************************************/
        
        moveCritters(board, size_x, size_y, 'X', "doodlebug");
        
        resetCritterMoveSuccess(board, size_x, size_y);
        
        /*************************************
         ** MOVE THE ANTS
         *************************************/
        
        moveCritters(board, size_x, size_y, 'O', "ant");
        
        resetCritterMoveSuccess(board, size_x, size_y);

        /*************************************
        ** BREED THE CRITTERS
        *************************************/

    
        breedCritters(board, size_x, size_y, 'X', "doodlebug");
        breedCritters(board, size_x, size_y, 'O', "ant");
        
        /*************************************
        ** STARVE THE DOODLEBUGS
        *************************************/
        starveCritters(board, size_x, size_y, 'X', "doodlebug");

        cout << "\nStep " << ++stepCounter << " Completed!\n";
        cout << "\n" << "Printing board again" << "\n\n";

        //print board again to see if breed worked
        printBoard(board, size_y, size_x);

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

    for(int i = 0; i <  size_y; i++)
    {
      for(int j = 0; j < size_x; j++)
      {
         delete board[i][j];
      }
      delete[] board[i];
    }
    delete[] board;
    board = NULL;
    //delete doodle;
    //doodle = NULL;
    return 0;
}

void moveCritters(Critter *** board, int size_x, int size_y, char symbol, std::string type)
{
    for(int i=0; i<size_y; i++)
    {
        for(int j=0; j<size_x; j++)
        {
            if(board[i][j] != NULL && board[i][j]->getSymbol() == symbol)
            {
                if(board[i][j]->getMoveSuccess() == 0)
                {
                    // cout << "Attempting to move " << type << " from row " << i;
                    // cout << " and col " << j << "\n";
                    board[i][j]->move(board, size_x, size_y);
                }
            }
        }
    }
}

void resetCritterMoveSuccess(Critter *** board, int size_x, int size_y)
{
    //reset move success for next round,
    for(int i=0; i<size_y; i++)
    {
        for(int j=0; j<size_x; j++)
        {
            if(board[i][j] != NULL)
            {
                board[i][j]->resetMoveSuccess();
            }
        }
    }
}

void breedCritters(Critter *** board, int size_x, int size_y, char symbol, std::string type)
{
    for(int i=0; i<size_y; i++)
    {
        for(int j=0; j<size_x; j++)
        {
            if(board[i][j] != NULL && board[i][j]->getSymbol() == symbol)
            {
                board[i][j]->breed(board, size_x, size_y);
            }
        }
    }
}

void starveCritters(Critter *** board, int size_x, int size_y, char symbol, std::string type)
{
    for(int i=0; i<size_y; i++)
    {
        for(int j=0; j<size_x; j++)
        {
            if(board[i][j] != NULL && board[i][j]->getSymbol() == symbol)
            {
                cout << "A " << type << " has starved at row" << i;
                cout << " and col " << j << "\n";
                if(board[i][j]->starve(board))
		{
			delete board[i][j];
			board[i][j] = NULL;
		}
                
            }
        }
    }
}
