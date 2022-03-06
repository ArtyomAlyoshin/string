#ifndef STRING_INTERCHANGEWORDS_H
#define STRING_INTERCHANGEWORDS_H

#include "../string_.h"

void interchangingWords(char *s, char *s1, char *s2) {
    WordDescriptor word1, word2;
    bool isW1Found, isW2Found;
    char *sCopy = s;
    char *beginSearch1 = s1, *beginSearch2 = s2;
    while ((isW1Found = getWord(beginSearch1, &word1)),
            (isW2Found = getWord(beginSearch2, &word2)),
            isW1Found || isW2Found) {

        if (isW1Found) {
            s = copy(word1.begin, word1.end, s);
            *s++ = ' ';
            beginSearch1 = word1.end;
        }
        if (isW2Found) {
            s = copy(word2.begin, word2.end, s);
            *s++ = ' ';
            beginSearch2 = word2.end;
        }
    }
    if (s != sCopy)
        --s;
    *s = '\0';
}

void test_interchangingWords_equalWordCount() {
    char s[MAX_STRING_SIZE];
    interchangingWords(s, "aaaa bbbb", "cccc dddd");
    ASSERT_STRING("aaaa cccc bbbb dddd", s);
}

void test_interchangingWords_moreWordInFirstString() {
    char s[MAX_STRING_SIZE];
    interchangingWords(s, "aaaa bbbb cccc", "dddd");
    ASSERT_STRING("aaaa dddd bbbb cccc", s);
}

void test_interchangingWords_secondStringIsEmpty() {
    char s[MAX_STRING_SIZE];
    interchangingWords(s, "aaaa bbbb cccc", "");
    ASSERT_STRING("aaaa bbbb cccc", s);
}

void test_interchangingWords_stringsAreEmpty() {
    char s[MAX_STRING_SIZE];
    interchangingWords(s, " ", " ");
    ASSERT_STRING("", s);
}

void test_interchangingWords() {
    test_interchangingWords_equalWordCount();
    test_interchangingWords_moreWordInFirstString();
    test_interchangingWords_secondStringIsEmpty();
    test_interchangingWords_stringsAreEmpty();
}

#endif
