#ifndef STRING_ISPOLY_H
#define STRING_ISPOLY_H

#include "../string_.h"

bool isPalindrome(char *begin, char *end) {
    end--;
    while (end - begin > 0) {
        if (*begin != *end)
            return false;

        begin++;
        end--;
    }
    return true;
}

size_t countOfPalindrome(char *s) {
    char *end = getEndOfString(s);
    char *begin = s;
    int count = 0;

    char comma = 44;
    char *commaPosition = find(begin, end, comma);

    int isLastComma = 0;
    while (*commaPosition != '\0' || isLastComma) {
        count += isPalindrome(begin, commaPosition);
        begin = commaPosition + 1;
        if (isLastComma)
            break;

        commaPosition = find(begin, end, comma);
        isLastComma = *commaPosition == '\0';
    }
    return count;
}

void test_countOfPalindrome_hasPoly() {
    char s[] = "abcba,hhhhh,aboba,123321,ddsbisic";
    assert(countOfPalindrome(s) == 4);
}

void test_countOfPalindrome_noPoly() {
    char s[] = "123,abc,zxc";
    assert(countOfPalindrome(s) == 0);
}

void test_countOfPalindrome_oneLetter() {
    char s[] = "a,b,c";
    assert(countOfPalindrome(s) == 3);
}

void test_countOfPalindrome() {
    test_countOfPalindrome_oneLetter();
    test_countOfPalindrome_noPoly();
    test_countOfPalindrome_hasPoly();
}

#endif
