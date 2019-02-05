/******************************************************************************
 ** Author:      Winter 162 400 Group 4
 ** Date:        02/01/2019
 ** Description: This program runs a Predator-Prey Game with "Doodlebug"
 **              predators and "Ant" prey.
 ******************************************************************************/

#include "Critter.hpp"
// #include "Game.hpp"

#include <iostream>
#include <string>

int main()
{
    string playGameString;
    string timeStepsString;
    string settingsString;
    int timeSteps;
    string rowsString;
    string colsString;
    int size_x = 20;
    int size_y = 20;
    int numAnts = 100;
    int numDoodBugs = 5;

    cout << "\n\n" << "* - * - * PREDATOR PREY GAME * - * - *" << "\n";
    cout << "- - enter the number for your selection - -" << "\n\n";
    cout << "- - please note we did the extra credit - -" << "\n\n";
    cout << "1. Play Game" << "\n";
    cout << "2. Quit" << "\n\n";

    validSelection(playGameString);

    if(playGameString == "1")
    {
      cout << "Enter an integer greater than 1 for the number of steps." << "\n\n";
      validInt(timeStepsString);
      stringstream convertSteps(timeStepsString);
      convertSteps >> timeSteps;

      cout << "- - Would you like custom settings or default settings? - -" << "\n\n";
      cout << "1. Default Settings" << "\n";
      cout << "2. Custom Settings" << "\n\n";
      validSelection(settingsString);

      if(settingsString == "1")
      {
        //start game with defaults
      }

      if(settingsString == "2")
      {
        cout << "\n";
        cout << "Enter an integer greater than 1 for the number of rows" << "\n\n";
        validInt(rowsString);
        stringstream convertRows(rowsString);
        convertRows >> numRows;

        cout << "Enter an integer greater than 1 for the number of columns" << "\n\n";
        validInt(cols);
        stringstream convertCols(colsString);
        convertCols >> numCols;

        cout << "Enter an integer greater than 1 for the number of ants" << "\n\n";
        validInt(antsString);
        stringstream convertRows(antsString);
        convertRows >> numAnts;

        cout << "Enter an integer greater than 1 for the number of doodlebugs" << "\n\n";
        validInt(cols);
        stringstream convertCols(colsString);
        convertCols >> numDoodBugs;
      }
    }
    else if(playGame == "2")
    {
      return 0;
    }

    Critter ***board = new Critter**[size_y];
        for(int i = 0; i < size_y; i++)
         {
            board[i] = new Critter*[size_x];

            for(int j = 0; j < size_x; j++)
            {
               board[i][j] = new Critter();
            }
        }
    Doodlebug *doodle = new Doodlebug(10, 10);

    //add as print board function in utilities folder print_board(Critter ***, rows, col)
    for(int i = 0; i < size_y; i++)
    {
        for(int k = 0; k < size_x; k++)
        {
            std::cout << board[i][k]->getSymbol();
        }
        std::cout << std::endl;
    }
    //doodle->move(board);
    doodle->breed(board);
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
   delete doodle;
   doodle = NULL;
   return 0;
}
