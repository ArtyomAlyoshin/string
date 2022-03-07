#ifndef STRING_ADDLASTWORDS_H
#define STRING_ADDLASTWORDS_H

#include "../string_.h"

void addLastWords(char *s1, char *s2, int n1, int n2) {
    WordDescriptor word;
    char *s1End = getEndOfString(s1) ;
    char *s2End = getEndOfString(s2) - 1;
    int difference = n2 - n1;
    while (difference) {
        char *begin = findSpaceReverse(s2End, s2) ;
        getWordReverse(s2End, begin, &word);
        *s1End++ = ' ';
        while (word.begin != word.end) {
            *s1End++ = *word.begin++;
        }
        s2End = begin - 1;
        n1++;
        difference--;
    }
}

void addLastWords_(char *s1, char *s2, int size1, int size2) {
    if (size1 == size2)
        return;
    if (size1 < size2)
        addLastWords(s1, s2, size1, size2);
    else
        addLastWords(s2, s1, size2, size1);
}

void test_addLastWords_firstStringMoreSecond() {
    char s1[MAX_STRING_SIZE] = "aaaa bbbb cccc dddd";
    char s2[MAX_STRING_SIZE] = "zzzz xxxx";

    addLastWords_(s1, s2, 4, 2);

    ASSERT_STRING("zzzz xxxx dddd cccc", s2);
}

void test_addLastWords_oneWordInFirst() {
    char s1[MAX_STRING_SIZE] = "aaaa";
    char s2[MAX_STRING_SIZE] = "aaaa bbbb";

    addLastWords_(s1, s2, 1, 2);

    ASSERT_STRING("aaaa bbbb", s1);
}

void test_addLastWords_oneWordInStrings() {
    char s1[MAX_STRING_SIZE] = "aaaa";
    char s2[MAX_STRING_SIZE] = "";

    addLastWords_(s1, s2, 1, 0);

    ASSERT_STRING("aaaa", s1);
}

void test_addLastWords_emptyStrings() {
    char s1[MAX_STRING_SIZE] = "";
    char s2[MAX_STRING_SIZE] = "";

    addLastWords_(s1, s2, 0, 0);

    ASSERT_STRING("", s1);
    ASSERT_STRING("", s2);
}


void test_addLastWords() {
    test_addLastWords_emptyStrings();
    test_addLastWords_oneWordInStrings();
    test_addLastWords_firstStringMoreSecond();
    test_addLastWords_oneWordInFirst();
}

#endif
