#ifndef STRING_DIGITSTOSPACES_H
#define STRING_DIGITSTOSPACES_H

#include "../string_.h"

void writeSpacesInsteadOfDigit(char *s) {
    char *endOfString = getEndOfString(s);
    char *startOfNewDestination = stringBuffer;
    char *endOfNewDestination = copy(s, endOfString, startOfNewDestination);
    *endOfNewDestination = '\0';

    while (*startOfNewDestination != '\0') {
        if (isalpha(*startOfNewDestination))
            *s++ = *startOfNewDestination;
        else if (isdigit(*startOfNewDestination)) {
            while (*startOfNewDestination - 48 != 0) {
                *s++ = ' ';
                (*startOfNewDestination)--;
            }
        }
        startOfNewDestination++;
    }
}

void test_writeSpacesInsteadOfDigit_empty() {
    char s[MAX_STRING_SIZE] = "";
    writeSpacesInsteadOfDigit(s);
    ASSERT_STRING("", s);
}

void test_writeSpacesInsteadOfDigit_noLetters() {
    char s[MAX_STRING_SIZE] = "123";
    writeSpacesInsteadOfDigit(s);
    ASSERT_STRING("      ", s);
}

void test_writeSpacesInsteadOfDigit_noDigit() {
    char s[MAX_STRING_SIZE] = "ABC";
    writeSpacesInsteadOfDigit(s);
    ASSERT_STRING("ABC", s);
}

void test_writeSpacesInsteadOfDigit_digitsInWord() {
    char s[MAX_STRING_SIZE] = "A3B0C1";
    writeSpacesInsteadOfDigit(s);
    ASSERT_STRING("A   BC ", s);
}

void test_writeSpacesInsteadOfDigit() {
    test_writeSpacesInsteadOfDigit_empty();
    test_writeSpacesInsteadOfDigit_noLetters();
    test_writeSpacesInsteadOfDigit_noDigit();
    test_writeSpacesInsteadOfDigit_digitsInWord();
}

#endif
