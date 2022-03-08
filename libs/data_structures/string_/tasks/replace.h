#ifndef STRING_REPLACE_H
#define STRING_REPLACE_H

#include "../string_.h"

bool areEqual(char *s, char *w) {
    while (*w != '\0')
        if (*s++ != *w++)
            return 0;
    return 1;
}

void replace(char *source, char *w1, char *w2) {
    size_t w1Size = strlen_(w1);
    size_t w2Size = strlen_(w2);
    WordDescriptor word1 = {w1, w1 + w1Size};
    WordDescriptor word2 = {w2, w2 + w2Size};

    char *readPtr, *recPtr;
    if (w1Size >= w2Size) {
        readPtr = source;
        recPtr = source;
    } else {
        copy(source, getEndOfString(source), stringBuffer);
        *(stringBuffer + strlen_(source)) = '\0';
        readPtr = stringBuffer;
        recPtr = source;
    }

    while (*readPtr != '\0') {
        if (areEqual(readPtr, w1)) {
            char *copyW = w2;
            for (int i = 0; i < w2Size; ++i)
                *recPtr++ = *copyW++;
            readPtr += w1Size;
        } else
            *recPtr++ = *readPtr++;
    }
    *recPtr = '\0';
}

void test_replace_firstWord() {
    char s[MAX_STRING_SIZE] = "aaaa bbbb";
    char w1[] = "aaaa";
    char w2[] = "zzzz";
    replace(s, w1, w2);
    ASSERT_STRING("zzzz bbbb", s);
}

void test_replace_lastWord() {
    char s[MAX_STRING_SIZE] = "aaaa bbbb";
    char w1[] = "bbbb";
    char w2[] = "zzzz";
    replace(s, w1, w2);
    ASSERT_STRING("aaaa zzzz", s);
}

void test_replace_middleWord() {
    char s[MAX_STRING_SIZE] = "aaaabbbb";
    char w1[] = "ab";
    char w2[] = "ZZ";
    replace(s, w1, w2);
    ASSERT_STRING("aaaZZbbb", s);
}

void test_replace_twoWord() {
    char s[MAX_STRING_SIZE] = "aaaa aaaa";
    char w1[] = "aaaa";
    char w2[] = "xxxx";
    replace(s, w1, w2);
    ASSERT_STRING("xxxx xxxx", s);
}

void test_replace_empty() {
    char s[MAX_STRING_SIZE] = "";
    char w1[] = "zzzz";
    char w2[] = "xxxx";
    replace(s, w1, w2);
    ASSERT_STRING("", s);
}

void test_replace() {
    test_replace_empty();
    test_replace_firstWord();
    test_replace_lastWord();
    test_replace_middleWord();
    test_replace_twoWord();
}

#endif
