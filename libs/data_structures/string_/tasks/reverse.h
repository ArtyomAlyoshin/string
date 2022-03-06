#ifndef STRING_REVERSE_H
#define STRING_REVERSE_H

#include "../string_.h"



void task7(char *s) {
    *copy(s, getEndOfString(s), stringBuffer) = '\0';
    getBagOfWords(&_bag, stringBuffer);
    char *begin = s;
    for (int i = 0; i < _bag.size; i++) {
        *copyReverse(_bag.words[i].end - 1, _bag.words[i].begin - 1, begin) = '\0';
        printf("%s \n", begin);
    }
}


void test_task7() {
    char s[] = "hello word!";
    task7(s);
}

#endif
