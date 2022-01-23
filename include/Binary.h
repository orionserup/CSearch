/**
 * \file Binary.h
 * \author Orion Serup (orionserup@gmail.com)
 * \brief 
 * \version 0.1
 * \date 2022-01-17
 * 
 * \copyright Copyright (c) 2022
 * 
 */
#include "Utils.h"

#ifndef BINARY_SEARCH 

/**
 * \brief Finds the index of the given value in the array using the binary search algorithm 
 * \note Array must be presorted
 * \param array: Array to Search for the value in
 * \param size: The Size of the Array
 * \param value: The Value to Look For
 * \return size_t: The Index where the data was found: size if not found
 */
size_t BinarySearch(const Data* const array, const size_t size, const Data value);

/// Global Binary Search Literal 
#define BINARY_SEARCH (Search){ BinarySearch, "BinarySearch" }

#endif
