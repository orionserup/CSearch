cmake_minimum_required(VERSION 3.10)

project(CSearches LANGUAGES C)

file(GLOB SOURCES ../src/*.c)
file(GLOB INCLUDES ../include/*.h)
file(GLOB BENCHMARK_SOURCES ../test/Benchmark/*.c)

add_executable(Benchmark ${BENCHMARK_SOURCES} ${SOURCES})

target_include_directories(Benchmark PUBLIC ../include)

if(MSVC)
    set(CMAKE_C_FLAGS "/W4 /D_CRT_SECURE_NO_DEPRECATE")
    set(CMAKE_C_FLAGS_DEBUG "/DEBUG /Od /DDEBUG /D_DEBUG /DLOG")
    set(CMAKE_C_FLAGS_RELEASE "/Ox /GL /LTCG /DNDEBUG")
else()
    set(CMAKE_C_FLAGS "-Wall -Wextra -pedantic -Wfloat-equal")
    set(CMAKE_C_FLAGS_DEBUG "-Og -g -DDEBUG -DLOG")
    set(CMAKE_C_FLAGS_RELEASE "-Ofast -DNDEBUG -mtune=native -march=native -fopenmp")
    set(CMAKE_LINK_FLAGS_RELEASE "-flto -fopenmp")
endif()

set(BENCHMARK_SEARCH_DATA uint64_t)
set_target_properties(Benchmark PROPERTIES
                      COMPILE_DEFINITIONS "SEARCH_DATA=${BENCHMARK_SEARCH_DATA}")

set_target_properties(Benchmark PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "../bin"
)

file(MAKE_DIRECTORY ../data)

install(FILES ${INCLUDES} DESTINATION ${CMAKE_SYSTEM_INCLUDE_PATH})
