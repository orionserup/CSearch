/**
 * \file SearchBenchmark.c
 * \author Orion Serup (orionserup@gmail.com)
 * \brief 
 * \version 0.1
 * \date 2022-01-17
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "Benchmark.h"

static void WriteSearchDataToFile(FILE* const file, const SearchData* const data, const size_t size);

SearchData TimeSearch(const SearchFunction search, const Data* const array, const size_t size, const Data value) {

    clock_t begin = clock();
    size_t index = search(array, size, value);
    clock_t end = clock();

    return (SearchData){ .n = size, .time_ms = (end - begin)*1000.0f/CLOCKS_PER_SEC, .index = index };

}

// Benchmark One Sort
void BenchmarkSearch(const Search search, const Data* const trials, const size_t numtrials, const size_t numtimes) {

    #ifndef _MSC_VER
    const char path[] = "../data/";
    #else
    const char* const path = "..\\..\\data";
    #endif

    char buffer[100];

    strcpy(buffer, path);
    strcat(buffer, search.name);
    strcat(buffer, ".csv");

    FILE* const file = fopen(buffer, "w");
    const size_t size = Max(trials, numtrials);

    #ifdef VLA
    SearchData data[numtrials * numtimes];
    Data array[size];
    #else 
    SearchData* data = malloc(sizeof(SearchData) * numtrials * numtimes);
    Data* array = malloc(sizeof(Data) * size);
    #endif

    #ifdef LOG
    const size_t offset = sizeof(path) + strlen(search.name); 
    strcpy(buffer + offset - 1, ".log");
    FILE* log = fopen(buffer, "w");
    fprintf(log, "%s Log\n\n", search.name);
    #endif

    srand(clock());
    
    for(size_t i = 0; i < numtimes; i++) {

        Data start = (Data)rand();
        while((start + Max(trials, numtrials)) > maxof(Data))
            start = (Data)rand(); // make sure we find a good, random starting point

        for(Data i = 0; i < Max(trials, numtrials); i++)
            array[i] = start + i;

        for(size_t j = 0; j < numtrials; j++) { 
            
            Data value = start + rand() % trials[j]; 
            data[j + i * numtrials] = TimeSearch(search.function, array, trials[j], value);
            
            #ifdef LOG
            SearchData curr = data[j + i * numtrials];
            fPrintArray(log, array, trials[j]); 
            
            bool found = (curr.index != SIZE_MAX);
            
            if(!found)
                fprintf(log, "Value %lu Not Found\n", (uint64_t)value);
            else
                fprintf(log, "Value %lu Found at Index %zu in %lf ms\n", (uint64_t)value, curr.index, curr.time_ms);          
            
            fprintf(log, "Valid Result: %s\n\n", (found? "True": "False"));
            #endif
        }
    }

    for(size_t i = 0; i < numtrials; i++) { 
        
        for(size_t j = 1; j < numtimes; j++) 
            data[i].time_ms += data[ i + j * numtrials].time_ms;

        data[i].time_ms /= numtimes;        

    }

    WriteSearchDataToFile(file, data, numtrials);

    #ifndef VLA
    free(data);
    free(array);
    #endif

    fclose(file);
    #ifdef LOG
    fclose(log);
    #endif

}

// Benchmark Every Search in an Array
void BenchmarkSearches(const Search* const searches, const size_t numsearches, const Data* const trials, const size_t numtrials, const size_t numtimes) {

    Assert(searches, "Invalid Search Array in Benchmark");

    for(size_t i = 0; i < numsearches; i++)
        BenchmarkSearch(searches[i], trials, numtrials, numtimes);

}


void WriteSearchDataToFile(FILE* const file, const SearchData* const data, const size_t size) {

    Assert(file, "Bad File Pointer in Writing Search Data");
    Assert(data, "Bad SearchData Array in Writing Search Data to File");

    for(size_t i = 0; i < size; i++)
        fprintf(file, "%zu,%lf\n", data[i].n, data[i].time_ms);

}
// Prints An Array to a File
void fPrintArray(FILE* const file, const Data* const array, const size_t size) {

    Assert(file, "Invalid File Pointer in Print Array");
    Assert(array, "Invalid Array Pointer in Print Array");

    for(size_t i = 0; i < size; i++)
        fprintf(file, "%lu ", (uint64_t)array[i]);

    fputc('\n', file);
}
