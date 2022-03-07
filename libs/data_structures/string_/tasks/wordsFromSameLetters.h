

#ifndef STRING_WORDSFROMSAMELETTERS_H
#define STRING_WORDSFROMSAMELETTERS_H
#include "../string_.h"

int cmp(const void *a, const void *b) {
    return *(const char *) a - *(const char *) b;
}

bool wordsFromSameLetters(char *s) {
    *copy(s, getEndOfString(s), stringBuffer) = '\0';
    getBagOfWords(&_bag, stringBuffer);

    for (int i = 0; i < _bag.size; i++)
        qsort(_bag.words[i].begin, _bag.words[i].end - _bag.words[i].begin, sizeof(char), cmp);

    return hasEqualWords(stringBuffer);
}

void test_wordsFromSameLetters_hasThisWords() {
    char s[] = "ababab bababa zxzxzx";
    assert(wordsFromSameLetters(s));
}

void test_wordsFromSameLetters_hasThisWords2() {
    char s[] = "abcdefg gfedcba";
    assert(wordsFromSameLetters(s));
}

void test_wordsFromSameLetters_hasNotThisWords() {
    char s[] = "zxczxc abcabc";
    assert(!wordsFromSameLetters(s));
}

void test_wordsFromSameLetters_empty() {
    char s[] = "";
    assert(!wordsFromSameLetters(s));
}

void test_wordsFromSameLetters() {
    test_wordsFromSameLetters_empty();
    test_wordsFromSameLetters_hasThisWords();
    test_wordsFromSameLetters_hasThisWords2();
    test_wordsFromSameLetters_hasNotThisWords();
}

#endif
