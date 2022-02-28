#ifndef STRING_REMOVEEXTRASPACES_H
#define STRING_REMOVEEXTRASPACES_H

#include "../string_.h"

void removeExtraSpaces(char *s) {
    char *now = s;
    char before = *now;
    char *neededString = now;
    while (*now != '\0') {
        if (before != ' ' || *now != before)
            *neededString++ = *now;
        before = *now;
        now++;
    }
    if (before == ' ')
        neededString--;
    *neededString = '\0';
}

void test_removeExtraSpaces_spaceBetween() {
    char s[] = "    Hi  123    ";
    removeExtraSpaces(s);
    ASSERT_STRING("Hi 123", s);
}


void test_removeExtraSpaces_withoutSpace() {
    char s[] = "Hi123";
    removeExtraSpaces(s);
    ASSERT_STRING("Hi123", s);
}

void test_removeExtraSpaces_empty() {
    char s[] = "";
    removeExtraSpaces(s);
    ASSERT_STRING("", s);
}

void test_removeExtraSpaces() {
    test_removeExtraSpaces_spaceBetween();
    test_removeExtraSpaces_withoutSpace();
    test_removeExtraSpaces_empty();
}


#endif