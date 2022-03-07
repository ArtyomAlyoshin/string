add_library(data_structures
        string_/string_.c
        string_/tasks/removeNonLetters.h
        string_/tasks/removeExtraSpaces.h
        string_/tasks/digitToStart.h
        string_/tasks/digitsToSpaces.h string_/tasks/replace.h string_/tasks/IsOrderedWord.h string_/tasks/reverseWord.h string_/tasks/isPoly.h string_/tasks/reverse.h string_/tasks/interchangeWords.h string_/tasks/printWordBeforeFirstWordWithA.h string_/tasks/equalWords.h string_/tasks/deleteSameWordsAsLastWord.h string_/tasks/wordsFromSameLetters.h string_/tasks/lastFirstWordStringToSecond.h)

target_link_libraries(data_structures algorithms)