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

int main()
{
    int playGame;
    int customSettings;
    int timeSteps;
    int size_x = 20;
    int size_y = 20;
    int numAnts = 10;
    int numDoodbugs = 5;
    int maxAnts;
    int maxDoodbugs;

    Critter ***board;
    
    // display the main menu
    dispMainMenu();

    playGame = validSelection();

    if(playGame == 1)
    {
      // ask the user for the number of steps
      queryNumSteps();

      timeSteps = validInt();

      // ask the user if they want default settings or custom settings
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
    }

    //quit game
    else if(playGame == 2)
    {
      return 0;
    }

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

    int doodCount = 0;
    int antCount = 0;

    //helper variable setting age to 8 for breed test
    //int age = 8;

    //add starting doodle bugs to the board - this should be a function outside of main that just gets called
    while (doodCount < numDoodbugs)
    {
      int doodRowPlace = randIntRange(0, size_x-1);
      int doodColPlace = randIntRange(0, size_y-1);
      if(board[doodRowPlace][doodColPlace]==NULL)
      {
        board[doodRowPlace][doodColPlace] = new Doodlebug(doodRowPlace, doodColPlace);
        //helper function setting doodlebug age to 8 to try to get breed to work
        //board[doodRowPlace][doodColPlace]->setAge(age);
        doodCount++;
      }
    }


    //add starting ants to the board - this should be a function outside of main that just gets called
    while (antCount < numAnts)
    {
      int antRowPlace = randIntRange(0, size_x-1);
      int antColPlace = randIntRange(0, size_y-1);
      if(board[antRowPlace][antColPlace]==NULL)
      {
        board[antRowPlace][antColPlace] = new Ant(antRowPlace, antColPlace);

        antCount++;
      }
    }

    //print starting board - this should be a function outside of main that just gets called
    printBoard(board, size_y, size_x);
    
    //test moving doodlebug
    for(int i=0; i<size_y; i++)
    {
      for(int j=0; j<size_x; j++)
      {
          if(board[i][j] != NULL && board[i][j]->getSymbol() == 'X')
          {
            if(board[i][j]->getMoveSuccess() == 0)
            {
              cout << "Attempting to move from row " << i;
              cout << " and col " << j << "\n";
                 board[i][j]->move(board);
            }
          }
      }
    }
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


    //call breed - this should be a function outside of main that just gets called
/*    for(int i=0; i<size_y; i++)
    {
      for(int j=0; j<size_x; j++)
      {
          if(board[i][j] != NULL && board[i][j]->getSymbol() == 'X')
            {
              cout << "Attempting to breed from row " << i;
              cout << " and col " << j << "\n";
              board[i][j]->breed(board);
            }
      }
    }
*/
    cout << "\n" << "Printing board again" << "\n\n";

    //print board again to see if breed worked
    printBoard(board, size_y, size_x);

    //Doodlebug *doodle = new Doodlebug(10, 10);


    //add as print board function in utilities folder print_board(Critter ***, rows, col)

    //doodle->move(board);
    /*doodle->breed(board);
    for(int i = 0; i < size_y; i++)
    {
        for(int k = 0; k < size_x; k++)
        {
            std::cout << board[i][k]->getSymbol();
        }
        std::cout << std::endl;
    }*/
    //doodle->move(board);
    // get steps
    // get steps
    // place critters
    // display initial board
    // do while (int steps = 0 < steps)
        // below could be function moveCritters(Critter***, char symbol)
        // first call moveCritters with symbol X
        // for i < size_x
            // for j < size_y
                // if (board[size_x][size_y]->getSymbol == 'X')
                    // if (board[size_x][size_y]->move(board)) ... deallocate the spot the bug is moving to, new spot = old spot
                        // board[size_x][size_y] = new Critter... former spot will be set to new critter
                    // if move() returns false nothing happens
        // call moveCritters with symbol 'O'
        // breedCritters function called on doodle
        // breedCritters called on ant
        // starve function
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
