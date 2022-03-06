#ifndef STRING_REPLACE_H
#define STRING_REPLACE_H

#include "../string_.h"

bool comp(char *string, char *word) {
    char *copyString = string;
    char *copyWord = word;
    while (*copyString != ' ' && *copyString != '\0') {
        if (*copyString != *copyWord)
            return false;
        copyString++;
        copyWord++;
    }
    return true;
}
void replace_(char *source, WordDescriptor *word2, WordDescriptor word1, char *w2Size ){
    while (w2Size != 0) {
        *source = *word2->begin;
        w2Size--;
    }
    while (word1.end - 1 - word2->begin != 0) {
        *source = ' ';
        word2->begin++;
    }
}
//не готова(
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
        readPtr = stringBuffer;
        recPtr = source;
    }
    char *copySource = source;
    size_t copyW2Size = w2Size;
    if (comp(copySource, word1.begin)) {

    }
}


#endif
