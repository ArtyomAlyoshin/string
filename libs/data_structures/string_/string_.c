#include "string_.h"


void assertString(const char *expected, char *got,
                  char const *fileName, char const *funcName,
                  int line) {
    int x = strcmp(expected, got);
    if (x) {
        fprintf(stderr, " File %s\n", fileName);
        fprintf(stderr, "%s - failed on line %d\n", funcName, line);
        fprintf(stderr, " Expected : \"%s\"\n", expected);
        fprintf(stderr, "Got: \"%s\"\n\n", got);
    } else
        fprintf(stderr, "%s - OK\n", funcName);
}


size_t strlen_(char *begin) {
    char *endL = begin;
    while (*endL != '\0')
        endL++;
    return endL - begin;
}

char *find(char *begin, char *end, int ch) {
    while (begin != end && *begin != ch)
        begin++;
    return begin;
}

char *findNonSpace(char *begin) {
    while (*begin != '\0' && isspace(*begin))
        begin++;
    return begin;
}

char *findSpace(char *begin) {
    while (*begin != '\0' && !isspace(*begin))
        begin++;
    return begin;
}

char *findNonSpaceReverse(char *rbegin, const char *rend) {
    while (rbegin != rend && isspace(*rbegin))
        rbegin--;
    return rbegin;
}

char *findSpaceReverse(char *rbegin, const char *rend) {
    while (rbegin != rend && !isspace(*rbegin))
        rbegin--;
    return rbegin;
}

int strcmp(const char *lhs, const char *rhs) {
    while (*rhs && *lhs && *lhs == *rhs)
        lhs++, rhs++;
    return (unsigned char) *lhs - (unsigned char) *rhs;
}

char *copy(const char *beginSource, const char *endSource, char *beginDestination) {
    memcpy(beginDestination, beginSource, endSource - beginSource);
    return beginDestination + (endSource - beginSource);
}

char *copyIf(char *beginSource, const char *endSource, char *beginDestination, int (*f)(int)) {
    while (beginSource != endSource) {
        if (f(*beginSource)) {
            *beginDestination = *beginSource;
            beginDestination++;
        }
        beginSource++;
    }
    return beginDestination;
}

char *copyIfReverse(char *rbeginSource, const char *rendSource,
                    char *beginDestination, int (*f)(int)) {
    while (rbeginSource != rendSource) {
        if (f(*rbeginSource)) {
            *beginDestination = *rbeginSource;
            beginDestination++;
        }
        rbeginSource--;
    }
    return beginDestination;
}

bool getWord(char *beginSearch, WordDescriptor *word) {
    word->begin = findNonSpace(beginSearch);
    if (*word->begin == '\0')
        return 0;

    word->end = findSpace(word->begin);
    return 1;
}

bool getWordReverse(char *rbegin, char *rend, WordDescriptor *word) {
    word->begin = findNonSpaceReverse(rbegin, rend);
    if (word->begin == rend)
        return 0;

    word->end = findSpaceReverse(word->begin, rend);
    return 1;
}

void getBagOfWords(BagOfWords *bag, char *s) {
    bag->size = 0;
    WordDescriptor word;
    while (getWord(s, &word)) {
        bag->words[bag->size] = word;
        bag->size+=1;
        s = word.end;
    }
}

char *copyReverse(char *rbeginSource, const char *rendSource,
                  char *beginDestination) {
    while (rbeginSource != rendSource) {
        *beginDestination++ = *rbeginSource;
        rbeginSource--;
    }
    return beginDestination;
}