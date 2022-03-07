#ifndef STRING_PRINTWORDBEFOREFIRSTWORDWITHA_H
#define STRING_PRINTWORDBEFOREFIRSTWORDWITHA_H

#include "../string_.h"

typedef enum WordBeforeFirstWordWithAReturnCode {
    FIRST_WORD_WITH_A,
    NOT_FOUND_A_WORD_WITH_A,
    WORD_FOUND,
    EMPTY_STRING
} WordBeforeFirstWordWithAReturnCode;

WordBeforeFirstWordWithAReturnCode getWordBeforeFirstWordWithA(char *s, char **beginWordBefore, char **endWordBefore) {
    WordDescriptor word;
    char *begin = s;
    if (!getWord(begin, &word))
        return EMPTY_STRING;
    else if (find(word.begin, word.end, 'a') != word.end || find(word.begin, word.end, 'A') != word.end)
        return FIRST_WORD_WITH_A;
    WordDescriptor word2;
    while (getWord(begin, &word2)) {
        if (find(word2.begin, word2.end, 'A') != word2.end || find(word2.begin, word2.end, 'a') != word2.end) {
            *beginWordBefore = word.begin;
            *endWordBefore = word.end;

            return WORD_FOUND;
        }
        word = word2;
        begin = word.end + 1;
    }
    return NOT_FOUND_A_WORD_WITH_A;

}

void testAll_getWordBeforeFirstWordWithA() {
    char *beginWord, *endWord;

    char s1[] = "";
    assert(getWordBeforeFirstWordWithA(s1, &beginWord, &endWord) == EMPTY_STRING);

    char s2[] = " ABC";
    assert(getWordBeforeFirstWordWithA(s2, &beginWord, &endWord) == FIRST_WORD_WITH_A);

    char s3[] = "BC A";
    assert(getWordBeforeFirstWordWithA(s3, &beginWord, &endWord) == WORD_FOUND);
    char got[MAX_WORD_SIZE];
    copy(beginWord, endWord, got);
    got[endWord - beginWord] = '\0';
    ASSERT_STRING("BC", got);

    char s4[] = "B Q WE YR OW IUWR ";
    assert(getWordBeforeFirstWordWithA(s4, &beginWord, &endWord) == NOT_FOUND_A_WORD_WITH_A);
}

#endif
