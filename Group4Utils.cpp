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
int Group4Utils::randIntRange(int min, int max)
{
    static std::random_device rd;
    static std::mt19937 mTwist(rd());
    std::uniform_int_distribution<> dist(min, max);

    return dist(mTwist);
}

//This function is for validating user input between 2 choices.
void validSelection(string& selection)
{
  {
    int value =0;
    bool cont = true;                                                             //Set bool of cont to true
    string error = "Invalid input. Please enter a valid number";                  //Variable for the error I want this validation test to output. This makes it easy to change for future programs.

    while (cont)                                                                //While cont is true do the following
    {
      getline(cin, selection);                                                  //Work cited for validating string of user input using string stream //https://www.youtube.com/watch?v=S3_jCTb3fm0
      stringstream ss(selection);
      if(selection.size()!=1)                                                   //If the user inputs more than one value for the string output our error
      {
        cout << error << "\n";
      }
      else if ((ss >> value && value >= 1) && value <=2)
      {                                                                         //This confirms a successful user input
        cont = false;
        cout << "\n";
      }
      else if (selection.empty())                                               //Check if string inputted was empty or just a space, if so output error statement
      {
        cout << error << "\n";                                                  //https://stackoverflow.com/questions/43371834/how-to-check-when-a-user-presses-the-enter-key-without-providing-a-value-in-c
      }
      else
      {
        cout << error << "\n";                                                  //Fail all other inputs
      }
    }
  }
}

void validInt(string& input)
{
  bool cont = true;
  int testVal;
  string error = "Invalid input. Please enter an integer greater than 0";       //Error to output for invalid user inputs

    while (cont)
    {
      getline(cin, input);                                                      //Work cited for this function validation help https://www.youtube.com/watch?v=S3_jCTb3fm0
      stringstream ss(input);
      ss >> testVal;
      if (testVal <= 0)                                                         //This ensures we receive an integer greater than 1 and no text/characters which have int value of 0
      {
        cout << error << "\n";
      }
      else if (input.empty())                                                   //Output error if user input is empty or space(s), work cited below
      {
        cout << error << "\n";                                                  //https://stackoverflow.com/questions/43371834/how-to-check-when-a-user-presses-the-enter-key-without-providing-a-value-in-c
      }
      else if(input.find('.')!=string::npos)                                    //Checks if string contains a decimal and outputs error.
      {
        cout << error << "\n";                                                  //https://stackoverflow.com/questions/2340281/check-if-a-string-contains-a-string-in-c
      }
      else
      {
        cont = false;                                                           //If input passes all previous statements than we have a successful input
      }
    }
}
