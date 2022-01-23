/**
 * \file SearchUtils.h
 * \author Orion Serup (orionserup@gmail.com)
 * \brief 
 * \version 0.1
 * \date 2022-01-17
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef SEARCH_UTILS
#define SEARCH_UTILS

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>

#ifndef SEARCH_DATA
#pragma message "Please Define SEARCH_DATA to the Appropriate data type"
typedef uint64_t Data;
#else 
typedef SEARCH_DATA Data;
#endif

// Fancy Assert For Much Easier Debug, Prints Custom Message, Line Number and File Name in Red
#ifdef __unix__
/// Linux/MAC Debug Assert, Adds Coloration, Messages, and File and Line Numbers for Better Debugging
#define Assert(condition, msg) assert(condition || !fprintf(stderr, "\x1B[31m%s on Line: %d of File %s\n\x1B[0m", msg, __LINE__, __FILE__))
#else
/// Implementation of any other OS, no Colors but otherwise the same
#define Assert(condition, msg) assert(condition || !fprintf(stderr, "\t%s on Line: %d of File %s\n", msg, __LINE__, __FILE__))
#endif

typedef size_t (*const SearchFunction)(const Data* const array, const size_t size, const Data value);

/// Structure to Hold The Function and Name of a Search
typedef struct {

    const SearchFunction function; ///< The Actual Function that does the searching, matches the profile above
    const char* const name; ///< The Name of the Search

} Search;

/**
 * \brief Finds the Index of the Maximum Value in the 
 * 
 * \param array: Array to Look into
 * \param size: Size of the Array
 * \return size_t: The Index of the Maximum Value in the Array 
 */
size_t FindMax(const Data* const array, const size_t size);

/// Finds the Minimum Value of an Array
#define Max(array, size) array[FindMax(array, size)]

/**
 * \brief Finds the Minimum Element of an Array and returns its index
 * 
 * \param array: The Array to Look Through
 * \param size: The Size of the Array
 * \return size_t: The Index of the Minimum Value
 */
size_t FindMin(const Data* const array, const size_t size);

/// Finds the Minimum Value of an Array
#define Min(array, size) array[FindMin(array, size)]

#endif