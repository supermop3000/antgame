/******************************************************************************
** Author:      Winter 162 400 Group 4
** Date:        02/04/2019
** Description: This is an implementation of utility functions.
******************************************************************************/

#include "Group4Utils.hpp"
#include <random>

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
