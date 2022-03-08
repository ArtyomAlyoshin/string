#ifndef STRING_AREWORDLETTERSINSTRING_H
#define STRING_AREWORDLETTERSINSTRING_H

#include "../string_.h"

bool lettersInWordInString(char *s, char *word) {
    static int arrayOfSymbolIndexes[255];

    if (*word == '\0' || *s == '\0')
        return false;

    while (*s != '\0') {
        arrayOfSymbolIndexes[*s] = 1;
        s++;
    }

    while (*word != '\0') {
        if (!arrayOfSymbolIndexes[*word])
            return false;
        word++;
    }

    return true;
}

void test_lettersInWordInString_hasEqualLetters() {
    char s[MAX_STRING_SIZE] = "abcde";
    char word[MAX_STRING_SIZE] = "de";

    assert(lettersInWordInString(s, word));
}

void test_lettersInWordInString_hasNoEqualLetters() {
    char s[MAX_STRING_SIZE] = "abcde";
    char word[MAX_STRING_SIZE] = "def";

    assert(!lettersInWordInString(s, word));
}

void test_lettersInWordInString_spaces() {
    char s[MAX_STRING_SIZE] = "a b c d e f g t y u";
    char word[MAX_STRING_SIZE] = "abc";

    assert(lettersInWordInString(s, word));
}

void test_lettersInWordInString_wordIsEmpty() {
    char s[MAX_STRING_SIZE] = "abc";
    char word[MAX_STRING_SIZE] = "";

    assert(!lettersInWordInString(s, word));
}

void test_lettersInWordInString() {
    test_lettersInWordInString_hasEqualLetters();
    test_lettersInWordInString_hasNoEqualLetters();
    test_lettersInWordInString_wordIsEmpty();
    test_lettersInWordInString_spaces();
}

#endif
