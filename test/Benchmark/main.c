/**
 * \file main.c
 * \author Orion Serup (orionserup@gmail.com)
 * \brief 
 * \version 0.1
 * \date 2022-01-18
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "Benchmark.h"
#include "Searches.h"

#define MIN  1
#define MAX  5
#define STEP 1
#define SIZE (MAX - MIN)/STEP + 1

int main() {

    Search searches[] = { LINEAR_SEARCH, BINARY_SEARCH };
    size_t numsearches = sizeof(searches)/sizeof(Search);

    Data n[SIZE];

    for(size_t i = 0; i < SIZE; i++)
        n[i] = MIN + STEP * i;

    BenchmarkSearches(searches, numsearches, n, SIZE, 5);

}