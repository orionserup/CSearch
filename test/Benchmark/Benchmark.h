/**
 * \file Benchmark.h
 * \author Orion Serup (orionserup@gmail.com)
 * \brief 
 * \version 0.1
 * \date 2022-01-17
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "Utils.h"

#ifndef SEARCH_BENCHMARK
#define SEARCH_BENCHMARK

/// Checks if a Data Type is Signed or Not
#define issigned(t) (((t)(-1)) < ((t) 0))

/// Gets the Unsigned Max of a Type
#define umaxof(t) (((0x1ULL << ((sizeof(t) * 8ULL) - 1ULL)) - 1ULL) | \
                    (0xFULL << ((sizeof(t) * 8ULL) - 4ULL)))

/// Gets the Signed Max of a Type t
#define smaxof(t) (((0x1ULL << ((sizeof(t) * 8ULL) - 1ULL)) - 1ULL) | \
                    (0x7ULL << ((sizeof(t) * 8ULL) - 4ULL)))

/// Gets the Maximum Value of a Type t
#define maxof(t) ((unsigned long long) (issigned(t) ? smaxof(t) : umaxof(t)))

/// Gets the Minimum Value of a Type t
#define minof(t) ((issigned(t) * -maxof(t)) - 1 + !issigned(t)*1)

typedef struct {
    
    size_t n;
    double time_ms;
    size_t index; ///< Where the Value was Found

} SearchData;

/**
 * \brief 
 * 
 * \param search: The Function Pointer of the Search
 * \param array
 * \param size
 * \param value
 * \return SearchData 
 */
SearchData TimeSearch(const SearchFunction search, const Data* const array, const size_t size, const Data value);

/**
 * \brief 
 * 
 * \param search
 * \param trials
 * \param numtrials
 * \param numtimes
 */
void BenchmarkSearch(const Search search, const Data* const trials, const size_t numtrials, const size_t numtimes);

/**
 * \brief 
 * 
 * \param searches
 * \param numsearches
 * \param trials
 * \param numtrials
 * \param numtimes
 */
void BenchmarkSearches(const Search* const searches, const size_t numsearches, const Data* const trials, const size_t numtrials, const size_t numtimes);

/**
 * \brief  Prints an Array to a File
 * \note   File can Also be stdout, see \ref PrintArray
 * \param  array: Array to Print
 * \param  size: Size of the Array
 */
void fPrintArray(FILE* const file, const Data* const array, const size_t size);

/// A Special Case to Print to the Standard output
#define PrintArray(array, size) (fPrintArray(stdout, array, size))


#endif


