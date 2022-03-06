#ifndef STRING_REVERSEWORD_H
#define STRING_REVERSEWORD_H
#include "../string_.h"

void reverseWords(char *s) {
    char *s_ = copy(s, getEndOfString(s), stringBuffer);
    *s_ = '\0';

    BagOfWords bag;
    getBagOfWords(&bag, s);
    char *begin = s;
    int isChanged = 0;
    for (int i = bag.size - 1; i >= 0; i--) {
        isChanged = 1;
        begin = copy(bag.words[i].begin, bag.words[i].end, begin);
        *begin++ = ' ';
    }
    if (isChanged)
        begin--;
    *begin = '\0';
}

void test_reverseWords_manyWords() {
    char s[MAX_STRING_SIZE] = "number1 number2 number3";
    reverseWords(s);

    ASSERT_STRING("number3 number2 number1", s);
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
    test_reverseWords_manyWords();


}
#endif
