/**
 * \file Linear.c
 * \author Orion Serup (orionserup@gmail.com)
 * \brief Contains the Implementation of the Linear Search in C
 * \version 0.1
 * \date 2022-01-18
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "Linear.h"

// Searches the Array Using the Linear Search Algorithm
size_t LinearSearch(const Data* const array, const size_t size, const Data value) {

    Assert(array, "Invalid Array in the Linear Search"); // make sure we have a valid array

    for(size_t i = 0; i < size; i++) // go through each element in the array
        if(array[i] == value) // if the current value matches
            return i; // return the index of the value

    return SIZE_MAX; // if the value isn't found return the max size

}