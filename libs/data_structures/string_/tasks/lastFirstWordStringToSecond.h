#ifndef STRING_LASTFIRSTWORDSTRINGTOSECOND_H
#define STRING_LASTFIRSTWORDSTRINGTOSECOND_H

#include "../string_.h"

void wordDescriptorToString(WordDescriptor word, char *destination) {
    *copy(word.begin, word.end, destination) = '\0';
}

WordDescriptor getLastWordInFirstStringAndInTheSecondString(char *s1, char *s2) {
    getBagOfWords(&_bag, s1);
    getBagOfWords(&_bag2, s2);
    for (int i = _bag.size - 1; i >= 0; i--)
        for (int j = 0; j < _bag2.size; j++)
            if (areWordsEqual(_bag.words[i], _bag2.words[j]) == 0) {
                return _bag.words[i];
            }
    WordDescriptor word = {NULL, NULL};
    return word;
}

void test_getLastWordInFirstStringAndTheSecondString_hasWordInStrings() {
    char s1[MAX_STRING_SIZE] = "aaaa bbbb cccc";
    char s2[MAX_STRING_SIZE] = "cccc ffff aaaa";
    WordDescriptor word = getLastWordInFirstStringAndInTheSecondString(s1, s2);

    char s3[MAX_STRING_SIZE];
    wordDescriptorToString(word, s3);
    ASSERT_STRING ("cccc", s3);
}

void test_getLastWordInFirstStringAndTheSecondString_hasOneWordInStrings() {
    char s1[MAX_STRING_SIZE] = "aaaa bbbb cccc";
    char s2[MAX_STRING_SIZE] = "ffff gggg cccc";
    WordDescriptor word = getLastWordInFirstStringAndInTheSecondString(s1, s2);

    char s3[MAX_STRING_SIZE];
    wordDescriptorToString(word, s3);
    ASSERT_STRING ("cccc", s3);
}

void test_getLastWordInFirstStringAndTheSecondString_hasNotNeeddedWord() {
    char s1[MAX_STRING_SIZE] = "aaaa bbbb cccc";
    char s2[MAX_STRING_SIZE] = "dddd ffff gggg";
    WordDescriptor word = getLastWordInFirstStringAndInTheSecondString(s1, s2);

    char s3[MAX_STRING_SIZE];
    wordDescriptorToString(word, s3);
    ASSERT_STRING ("", s3);
}

void test_getLastWordInFirstStringAndTheSecondString_emptyStrings() {
    char s1[MAX_STRING_SIZE] = "";
    char s2[MAX_STRING_SIZE] = "";
    WordDescriptor word = getLastWordInFirstStringAndInTheSecondString(s1, s2);

    char s3[MAX_STRING_SIZE];
    wordDescriptorToString(word, s3);
    ASSERT_STRING ("", s3);
}

void test_getLastWordInFirstStringAndTheSecondString() {
    test_getLastWordInFirstStringAndTheSecondString_emptyStrings();
    test_getLastWordInFirstStringAndTheSecondString_hasNotNeeddedWord();
    test_getLastWordInFirstStringAndTheSecondString_hasWordInStrings();
    test_getLastWordInFirstStringAndTheSecondString_hasOneWordInStrings();
}


#endif
