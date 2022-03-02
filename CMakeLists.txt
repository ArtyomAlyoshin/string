cmake_minimum_required(VERSION 3.21)
project(string C)

set(CMAKE_C_STANDARD 23)

add_executable(string main.c libs/algorithms/algorithms.c libs/algorithms/algorithms.h libs/data_structures/string_/string_.c libs/data_structures/string_/string_.h libs/data_structures/string_/tasks/removeNonLetters.h libs/data_structures/string_/tasks/removeExtraSpaces.h libs/data_structures/string_/tasks/digitToStart.h)


add_subdirectory(libs)
target_link_libraries(string data_structures)
target_link_libraries(string algorithms)