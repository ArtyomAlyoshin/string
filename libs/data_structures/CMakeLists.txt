add_library(data_structures
        string_/string_.c
        string_/tasks/removeNonLetters.h
        string_/tasks/removeExtraSpaces.h
        string_/tasks/digitToStart.h
        string_/tasks/digitsToSpaces.h string_/tasks/replace.h string_/tasks/IsOrderedWord.h string_/tasks/reverseWord.h string_/tasks/isPoly.h string_/tasks/reverse.h string_/tasks/interchangeWords.h)

target_link_libraries(data_structures algorithms)