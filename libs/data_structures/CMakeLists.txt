add_library(data_structures
        string_/string_.c
        string_/tasks/removeNonLetters.h
        string_/tasks/removeExtraSpaces.h
        string_/tasks/digitToStart.h)

target_link_libraries(data_structures algorithms)