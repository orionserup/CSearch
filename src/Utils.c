/**
 * \file SearchUtils.c
 * \author Orion Serup (orionserup@gmail.com)
 * \brief Contains the Implementation of the Searching Utilities in C 
 * \version 0.1
 * \date 2022-01-17
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "Utils.h"

size_t FindMax(const Data* const array, const size_t size) {

    Assert(array, "Invalid Array in Find Max");
    
    size_t index = 0; // track the highest value
    for(size_t i = 1; i < size; i++)
        if(array[i] > array[index])
            index = i;

    return index;

}

size_t FindMin(const Data* const array, const size_t size) {
    
    Assert(array, "Invalid Array in Find Max");
    
    size_t index = 0; // track the index with the minimum value
    for(size_t i = 1; i < size; i++)
        if(array[i] < array[index])
            index = i; // if we find a lower value store the index

    return index; // return the Index of the Lowest Value

}

