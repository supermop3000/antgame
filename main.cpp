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
    int size_x = 20; //TODO update for user input
    int size_y = 20; //TODO update for user input

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
