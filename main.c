#include <stdio.h>
#include "libs/data_structures/string_/string_.h"
#include "libs/data_structures/string_/tasks/removeNonLetters.h"
#include "libs/data_structures/string_/tasks/removeExtraSpaces.h"
#include "libs/data_structures/string_/tasks/digitToStart.h"
#include "libs/data_structures/string_/tasks/digitsToSpaces.h"
#include "libs/data_structures/string_/tasks/replace.h"
#include "libs/data_structures/string_/tasks/IsOrderedWord.h"
int main() {
    test_isWordsOrdered();
    test_writeSpacesInsteadOfDigit();
    test_applyDigitToStartForString();
    test_removeExtraSpaces();
    test_removeNonLetters();
    return 0;
}
