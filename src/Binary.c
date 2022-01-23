/**
 * \file Binary.c
 * \author Orion Serup (orionserup@gmail.com)
 * \brief Contains the Implementation of the Binary Search Algorithm in C
 * \version 0.1
 * \date 2022-01-18
 * 
 * \copyright Copyright (c) 2022
 * 
 */

#include "Binary.h"

// Finds The value value in the array and returns its index if found
size_t BinarySearch(const Data* const array, const size_t size, const Data value) {

    Assert(array, "Invalid Array in Binary Search");

    if(size == 1) // if the array is only one big if that element is the value then return its index
        return array[0] == value? 0: SIZE_MAX; // otherwise return Not Found

    size_t middle = size / 2; // find the middle index
    Data middleval = array[middle]; // find the middle value

    if(middleval == value) 
        return middle; // if the middle value matches the value return the middle index
    else if(middleval < value)  // If we are lower than the value we look to the right
        return BinarySearch(array + middle, size - middle, value) + middle; // the value is on the right, search the right
    else 
        return BinarySearch(array, middle, value); // the value is on the left, search the left

}
