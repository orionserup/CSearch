/**
 * \file Linear.h
 * \author Orion Serup (orionserup@gmail.com)
 * \brief 
 * \version 0.1
 * \date 2022-01-18
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "Utils.h"

#ifndef LINEAR_SEARCH

/**
 * \brief Uses the Linear Search Algorithm To Find the Value in the array
 * 
 * \param array: Array to search
 * \param size: Size of the array
 * \param value: Value to look for
 * \return size_t: The Index of the Value: size if not found
 */
size_t LinearSearch(const Data* const array, const size_t size, const Data value);

/// Global Linear Search Literal
#define LINEAR_SEARCH (Search){ LinearSearch, "LinearSearch" }

#endif



