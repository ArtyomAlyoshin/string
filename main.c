#include <stdio.h>
#include "libs/data_structures/string_/string_.h"
#include "libs/data_structures/string_/tasks/removeNonLetters.h"
#include "libs/data_structures/string_/tasks/removeExtraSpaces.h"
#include "libs/data_structures/string_/tasks/digitToStart.h"
#include "libs/data_structures/string_/tasks/digitsToSpaces.h"
#include "libs/data_structures/string_/tasks/replace.h"
#include "libs/data_structures/string_/tasks/IsOrderedWord.h"
#include "libs/data_structures/string_/tasks/reverseWord.h"
#include "libs/data_structures/string_/tasks/isPoly.h"
#include "libs/data_structures/string_/tasks/reverse.h"
#include "libs/data_structures/string_/tasks/interchangeWords.h"
#include "libs/data_structures/string_/tasks/printWordBeforeFirstWordWithA.h"
#include "libs/data_structures/string_/tasks/equalWords.h"
#include "libs/data_structures/string_/tasks/deleteSameWordsAsLastWord.h"
#include "libs/data_structures/string_/tasks/wordsFromSameLetters.h"
#include "libs/data_structures/string_/tasks/lastFirstWordStringToSecond.h"
#include "libs/data_structures/string_/tasks/addLastWords.h"
#include "libs/data_structures/string_/tasks/areWordLettersInString.h"


int main() {
    test_addLastWords();
    test_getLastWordInFirstStringAndTheSecondString();
    test_wordsFromSameLetters();
    test_deleteSameWordsAsLastWord();
    test_hasEqualWords();
    testAll_getWordBeforeFirstWordWithA();
    test_interchangingWords();
    test_countOfPalindrome();
    test_reverseWords();
    test_isWordsOrdered();
    test_writeSpacesInsteadOfDigit();
    test_applyDigitToStartForString();
    test_removeExtraSpaces();
    test_removeNonLetters();
    return 0;
}
