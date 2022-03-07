
#ifndef STRING_ISORDEREDWORD_H
#define STRING_ISORDEREDWORD_H

#include "../string_.h"


bool isWordsOrdered(char *s) {
    WordDescriptor now;
    if (!getWord(s, &now))
        return true;

    WordDescriptor last = now;
    while (getWord(s, &now)) {
        if (areWordsEqual(now, last) < 0)
            return false;
        last = now;
        s = now.end;
    }
    return true;
}

void test_isWordsOrdered_oneSymbol() {
    char s[] = "a b c";
    assert(isWordsOrdered(s));
}

void test_isWordsOrdered_oneSymbol2() {
    char s[] = "a f b";
    assert(!isWordsOrdered(s));
}

void test_isWordsOrdered_ordered() {
    char s[] = "aaaa fffff wwwww";
    assert(isWordsOrdered(s));
}

void test_isWordsOrdered_unordered() {
    char s[] = "ffffff aaaaaa gggggg";
    assert(!isWordsOrdered(s));
}

void test_isWordsOrdered_emptyString() {
    char s[] = "";
    assert(isWordsOrdered(s));
}

void test_isWordsOrdered() {
    test_isWordsOrdered_emptyString();
    test_isWordsOrdered_oneSymbol();
    test_isWordsOrdered_oneSymbol2();
    test_isWordsOrdered_ordered();
    test_isWordsOrdered_unordered();
}

#endif
