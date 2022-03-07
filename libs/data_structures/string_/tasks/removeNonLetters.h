#ifndef STRING_REMOVENONLETTERS_H
#define STRING_REMOVENONLETTERS_H

#include "../string_.h"


void removeNonLetters(char *s) {
    char *endSource = getEndOfString(s);
    char *destination = copyIf(s, endSource, s, isgraph);
    *destination = '\0';
}

void test_removeNonLetters_withoutSpace() {
    char s[] = "Hi123";
    removeNonLetters(s);
    ASSERT_STRING("Hi123", s);
}

void test_removeNonLetters_withSpaces() {
    char s[] = "H i 1 2 3";
    removeNonLetters(s);
    ASSERT_STRING("Hi123", s);
}


void test_removeNonLetters_empty() {
    char s[] = "";
    removeNonLetters(s);
    ASSERT_STRING("", s);
}


void test_removeNonLetters() {
    test_removeNonLetters_withoutSpace();
    test_removeNonLetters_withSpaces();
    test_removeNonLetters_empty();
}

#endif
