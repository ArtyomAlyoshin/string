add_library(data_structures
        string_/string_.c string_/string_.h
        string_/tasks/removeNonLetters.h
        string_/tasks/removeExtraSpaces.h)

target_link_libraries(data_structures algorithms)