/******************************************************************************
** Author:      Winter 162 400 Group 4
** Date:        02/04/2019
** Description: This is an implementation of utility functions.
******************************************************************************/

#include "Group4Utils.hpp"
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
