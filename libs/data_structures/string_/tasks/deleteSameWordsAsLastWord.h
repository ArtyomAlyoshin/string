#ifndef STRING_DELETESAMEWORDSASLASTWORD_H
#define STRING_DELETESAMEWORDSASLASTWORD_H
#include "../string_.h"

void deleteSameWordsAsLastWord(char *s) {
    WordDescriptor lastWord;
    getWordReverse(getEndOfString(s), s - 1, &lastWord);

    char *copy2 = s;
    char *copy1 = s;
    WordDescriptor now;
    while (getWord(copy2, &now)) {
        if (areWordsEqual(now, lastWord) != 0) {
            s = copy(now.begin, now.end, s);
            *s++ = ' ';
        }
        copy2 = now.end;
    }
    if (s != copy1)
        --s;
    *s = '\0';
}

void test_deleteSameWordsAsLastWord_someLastWords() {
    char s[MAX_STRING_SIZE] = "aaaa bbbb aaaa aaaa cccc aaaa";
    deleteSameWordsAsLastWord(s);
    ASSERT_STRING("bbbb cccc", s);
}

void test_deleteSameWordsAsLastWord_equalWords() {
    char s[MAX_STRING_SIZE] = "aaaa aaaa";
    deleteSameWordsAsLastWord(s);
    ASSERT_STRING("", s);
}

void test_deleteSameWordsAsLastWord_oneWord() {
    char s[MAX_STRING_SIZE] = "aaaa";
    deleteSameWordsAsLastWord(s);
    ASSERT_STRING("", s);
}

void test_deleteSameWordsAsLastWord_empty() {
    char s[MAX_STRING_SIZE] = "";
    deleteSameWordsAsLastWord(s);
    ASSERT_STRING("", s);
}

void test_deleteSameWordsAsLastWord() {
    test_deleteSameWordsAsLastWord_empty();
    test_deleteSameWordsAsLastWord_oneWord();
    test_deleteSameWordsAsLastWord_someLastWords();
    test_deleteSameWordsAsLastWord_equalWords();
}

#endif
