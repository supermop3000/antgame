/******************************************************************************
** Author:      Winter 162 400 Group 4
** Date:        02/04/2019
** Description: This is an implementation of utility functions. These functions
**              help to validate integers for user selections, generation of 
**              random numbers, and functions to display and initialize the 
**              game board and Critters.
******************************************************************************/

#include "Group4Utils.hpp"
#include "Critter.hpp"
#include <random>
#include <iostream>
#include <string>
#include <sstream>
using std::cout;
using std::cin;
using std::string;
using std::stringstream;

/*********************************************************************
** randIntRange(int,int)
** Description: Generates a random number from a uniform distribution
**              in the range [min,max] with a static seed.
*********************************************************************/
int randIntRange(int min, int max)
{
    static std::random_device rd;
    static std::mt19937 mTwist(rd());
    std::uniform_int_distribution<> dist(min, max);

    return dist(mTwist);
}

/*********************************************************************
** validSelection()
** Description: Validates the user input is the integer 1 or 2.
*********************************************************************/
int validSelection()
{
  string selection = "";
  int value;
  bool cont = true;
  //Error output
  string error = "Invalid input. Please enter a valid number.";

  while (cont)
  {
    //validating string of user input using string stream
    //work cited: https://www.youtube.com/watch?v=S3_jCTb3fm0
    getline(cin, selection);
    stringstream ss(selection);

    //if more than one value inputted, error
    if(selection.size()!=1)
    {
      cout << error << "\n";
    }
    //if selection is between 1 and 2 validation is success
    else if ((ss >> value) && (value == 1 || value ==2))
    {
      cont = false;
      cout << "\n";
    }
    //if input is empty, error
    else if (selection.empty())
    {
      cout << error << "\n";
    }
    //fail all other inputs
    else
    {
      cout << error << "\n";
    }
  }
  return value;
}

/*********************************************************************
** validInt()
** Description: Validates the user input is an integer > 0
*********************************************************************/
int validInt()
{
  string input = "";
  bool cont = true;
  int value;
  string error = "Invalid input. Please enter an integer greater than 0.";

  while (cont)
  {
    //Get user input
    getline(cin, input);
    stringstream ss(input);

    //Try to put input into an integer variable
    ss >> value;

    //If input is non integer or <=0, error
    if (value <= 0)
    {
      cout << error << "\n";
    }
    //If input empty, error
    else if (input.empty())
    {
      cout << error << "\n";
    }
    //If input contains decimal, error
    else if(input.find('.')!=string::npos)
    {
      cout << error << "\n";
    }
    else
    {
      cont = false;
    }
  }
  return value;
}


/*********************************************************************
** validNonNegative()
** Description: Validates the user input is non-negative
*********************************************************************/
int validNonNegative()
{
  string input = "";
  bool cont = true;
  int value = 0;
  string error = "Invalid input. Please enter non-negative integer";

  while (cont)
  {
    //Get user input
    getline(cin, input);
    stringstream ss(input);

    //Try to put input into an int variable
    ss >> value;

    //if input is non integer or <=0, error
    if (value < 0)
    {
      cout << error << "\n";
    }

    //if input empty, error
    else if (input.empty())
    {
      cout << error << "\n";
    }

    //if input contains decimal, error
    else if(input.find('.')!=string::npos)
    {
      cout << error << "\n";
    }

    else
    {
      return value;
    }
  }
  return value;
}

/******************************************************************************
** void printBoard(Critter***, int size_x, int size_y)
** Description: This function takes a triple-pointer to a critter object in 
**              order to view the board with ants and doodlebugs.  The variable
**              size_x represents the number of rows, and size_y represents the
**              the number of columns of the board.  It prints the board.
******************************************************************************/
void printBoard(Critter*** board, int size_x,int size_y)
{
    cout << "\n" << string(size_y + 2, '=') << "\n";
    for(int i=0; i < size_x; i++)
    {
      cout << "|";
      for(int j=0; j < size_y; j++)
      {
        if(board[i][j] == NULL)
        {
          cout << " ";
        }
        else if(board[i][j]->getSymbol()=='X')
        {
          cout << "X";
        }
        else if(board[i][j]->getSymbol()=='O')
        {
          cout << "O";
        }
      }
      cout << "|\n";
    }
    cout << string(size_y + 2, '=') << "\n";
}

/******************************************************************************
** void placeDoodles(Critter***, int&, int, int, int);
** Description:	The placeDoodles function adds starting Doodlebugs to the board.
**              It takes a triple-pointer to a critter object to add critters
**              to the board. Furthermore this function takes a reference to int
**              doodCount that serves as a counter for the number of Doodlebugs, 
**              and int numDoodbugs that represents the number of Doodlebugs to 
**              be created, and and 2 ints (size_x, size_y) representing the 
**              side of the board. 
******************************************************************************/
void placeDoodles(Critter*** board, int &doodCount, int numDoodbugs, int size_x, int size_y)
{
  while (doodCount < numDoodbugs)
  {
    //Generate random row and column places
    int doodRowPlace = randIntRange(0, size_x-1);
    int doodColPlace = randIntRange(0, size_y-1);

    //If the randomly generated x and y places result in an empty cell, add a Doodlebug
    if(board[doodRowPlace][doodColPlace]==NULL)
    {
      board[doodRowPlace][doodColPlace] = new Doodlebug(doodRowPlace, doodColPlace);

      //Update Doodlebug count
      doodCount++;
    }
  }
}



/******************************************************************************
** void placeAnts(Critter***, int&, int, int, int);
** Description:	The placeAnts function adds starting Ants to the board. It takes
**              a triple-pointer to a critter object to add critters to the
**              board. Furthermore this function takes a reference to int
**              antCount that serves as a counter for the number of Ants, and  
**              int numAnts that represents the number of Ants to be created, 
**              and and 2 ints (size_x, size_y) representing the 
**              side of the board. 
******************************************************************************/
void placeAnts(Critter*** board, int& antCount, int numAnts, int size_x, int size_y)
{
  while (antCount < numAnts)
  {
    //Generate random row and column places
    int antRowPlace = randIntRange(0, size_x-1);
    int antColPlace = randIntRange(0, size_y-1);

    //If the randomly generated x and y places result in an empty cell, add an Ant
    if(board[antRowPlace][antColPlace]==NULL)
    {
      board[antRowPlace][antColPlace] = new Ant(antRowPlace, antColPlace);

      //Update Ant count
      antCount++;
    }
  }
}
