/******************************************************************************
** Program name:Group Project - Predator Prey Sim
** Author:      Winter 162 400 Group 4
** Date:        02/04/2019
** Description: This is an implementation of utility functions.
**              This program runs a Predator-Prey Game with "Doodlebug"
**              predators and "Ant" prey. The program starts with a menu and
**              has the user set the number steps for the simulation to take.
**              Once the simulation is complete, the user is queried for the
**              whether they want to continue with more steps or quit.
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
** Description: gets rand ranged int, seed is static
*********************************************************************/
int randIntRange(int min, int max)
{
    static std::random_device rd;
    static std::mt19937 mTwist(rd());
    std::uniform_int_distribution<> dist(min, max);

    return dist(mTwist);
}

/*********************************************************************
** Description: validates user input for a selection between 1 and 2
*********************************************************************/
int validSelection()
{
  string selection = "";
  int value =0;
  bool cont = true;
  //Error output
  string error = "Invalid input. Please enter a valid number";

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
    else if ((ss >> value && value >= 1) && value <=2)
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
** Description: validates user input for an interger > 0
*********************************************************************/
int validInt()
{
  string input = "";
  bool cont = true;
  int value = 0;
  string error = "Invalid input. Please enter an integer greater than 0";

  while (cont)
  {
    getline(cin, input);
    stringstream ss(input);
    ss >> value;

    //if input is non integer or <=0, error
    if (value <= 0)
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

/*********************************************************************
** Description: validates user input for an interger > 0 and < maxInput
*********************************************************************/
int validIntMax(int maxInput)
{
  string input = "";
  bool cont = true;
  int value = 0;
  string error = "Invalid input. Please enter an integer greater than 0";

  while (cont)
  {
    getline(cin, input);
    stringstream ss(input);
    ss >> value;

    //if input is non integer or <=0, error
    if (value <= 0 || value > maxInput)
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


/*********************************************************************
** Description: validates user input for a non-negative integer
*********************************************************************/
int validNonNegative()
{
  string input = "";
  bool cont = true;
  int value = 0;
  string error = "Invalid input. Please enter non-negative integer";

  while (cont)
  {
    getline(cin, input);
    stringstream ss(input);
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
** void printBoard(Critter***, int numRows, int numCols
** Description:	This function prints the board of the program
**  This function takes a triple-pointer to a critter object in order to view
**  the board with ants and doodlebugs. The 2 integers it takes represent the
**  dimensions of the board.
******************************************************************************/
void printBoard(Critter*** board, int size_y,int size_x)
{
    cout << "\n" << string(size_y + 2, '=') << "\n";
    for(int i=0; i<size_y; i++)
    {
      cout << "|";
      for(int j=0; j<size_x; j++)
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
** Description:	This function adds starting doodlebugs to the board
**  This function takes a triple-pointer to a critter object to add critters
**  to the board. Furthermore this function takes a reference to an integer
**  that serves as a counter for the number of doodlebugs, and integer to
**  represent the number of doodlebugs to be created, and and 2 integers
**  representing the side of the board.
******************************************************************************/
void placeDoodles(Critter*** board, int &doodCount, int numDoodbugs, int size_x, int size_y)
{
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
}

/******************************************************************************
** void placeAnts(Critter***, int&, int, int, int);
** Description:	This function adds starting ants to the board
**  This function takes a triple-pointer to a critter object to add critters
**  to the board. Furthermore this function takes a reference to an integer
**  that serves as a counter for the number of ants, and integer to
**  represent the number of ants to be created, and and 2 integers
**  representing the side of the board.
******************************************************************************/
void placeAnts(Critter*** board, int& antCount, int numAnts, int size_x, int size_y)
{
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
}
