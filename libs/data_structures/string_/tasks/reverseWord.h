#ifndef STRING_REVERSEWORD_H
#define STRING_REVERSEWORD_H
#include "../string_.h"

void reverseWords(char *s) {
    *copy(s, getEndOfString(s), stringBuffer) = '\0';
    getBagOfWords(&_bag2, stringBuffer);
    char *copyS = s;
    for (int i = _bag2.size - 1; i >= 0; i--) {
        s = copy(_bag2.words[i].begin, _bag2.words[i].end, s);
        *s++ = ' ';
    }
    if (copyS != s)
        --s;
    *s = '\0';
}

void test_reverseWords_manyWords() {
    char s[MAX_STRING_SIZE] = "number1 number2 number3";
    reverseWords(s);
    ASSERT_STRING("number3 number2 number1", s);
}

void test_reverseWords_oneWord() {
    char s[MAX_STRING_SIZE] = "number1";
    reverseWords(s);
    ASSERT_STRING("number1", s);
}


void test_reverseWords_oneLetter() {
    char s[MAX_STRING_SIZE] = "a b c";
    reverseWords(s);
    ASSERT_STRING("c b a", s);
}

void test_reverseWords_empty() {
    char s[MAX_STRING_SIZE] = "";
    reverseWords(s);
    ASSERT_STRING("", s);
}

void test_reverseWords() {
    test_reverseWords_empty();
    test_reverseWords_oneLetter();
    test_reverseWords_oneWord();
    test_reverseWords_manyWords();
}
#endif
