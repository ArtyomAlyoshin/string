#ifndef STRING_DIGITTOSTART_H
#define STRING_DIGITTOSTART_H

#include "../string_.h"


void digitToStart(WordDescriptor word) {
    char *endStringBuffer = copy(word.begin, word.end, stringBuffer);
    char *recPosition = copyIf(stringBuffer, endStringBuffer, word.begin, isdigit);
    copyIf(stringBuffer, endStringBuffer, recPosition, isalpha);
}

void applyDigitToStartForString(char *s) {
    char *beginSearch = s;
    WordDescriptor word;
    while (getWord(beginSearch, &word)) {
        digitToStart(word);
        beginSearch = word.end;
    }
}

void test_applyDigitToStartForString_empty() {
    char s[] = "";
    applyDigitToStartForString(s);
    ASSERT_STRING("", s);
}

void test_applyDigitToStartForString_noLetters() {
    char s[] = "123 123";
    applyDigitToStartForString(s);
    ASSERT_STRING("123 123", s);
}

void test_applyDigitToStartForString_noDigits() {
    char s[] = "Hi abc";
    applyDigitToStartForString(s);
    ASSERT_STRING("Hi abc", s);
}

void test_applyDigitToStartForString_digitsWithWords() {
    char s[] = "Hi123  Hi312";
    applyDigitToStartForString(s);
    ASSERT_STRING("123Hi  312Hi", s);
}

void test_applyDigitToStartForString_digitsInWord() {
    char s[] = "H1i2       H123i123";
    applyDigitToStartForString(s);
    ASSERT_STRING("12Hi       123123Hi", s);
}

void test_applyDigitToStartForString() {
    test_applyDigitToStartForString_empty();
    test_applyDigitToStartForString_noLetters();
    test_applyDigitToStartForString_noDigits();
    test_applyDigitToStartForString_digitsWithWords();
    test_applyDigitToStartForString_digitsInWord();
}

#endif
