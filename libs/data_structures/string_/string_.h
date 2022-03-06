#ifndef STRING_STRING__H
#define STRING_STRING__H

#include <stdbool.h>
#include <stdio.h>
#include <ctype.h>
#include <memory.h>
#include <assert.h>

#define MAX_STRING_SIZE 100
#define MAX_N_WORDS_IN_STRING 100
#define MAX_WORD_SIZE 20

static char stringBuffer[MAX_STRING_SIZE + 1];

#define ASSERT_STRING(expected, got) assertString(expected, got, \
__FILE__ , __FUNCTION__ , __LINE__ )



void assertString(const char *expected, char *got,
                  char const *fileName, char const *funcName,
                  int line);

typedef struct WordDescriptor {
    char *begin;
    char *end;
} WordDescriptor;

typedef struct BagOfWords {
    WordDescriptor words[MAX_N_WORDS_IN_STRING];
    size_t size;
} BagOfWords;

static BagOfWords _bag;
static BagOfWords _bag2;
bool getWord(char *beginSearch, WordDescriptor *word);

bool getWordReverse(char *rbegin, char *rend, WordDescriptor *word);

size_t strlen_(char *begin);

char *find(char *begin, char *end, int ch);

char *findNonSpace(char *begin);

char *findSpace(char *begin);

char *findNonSpaceReverse(char *rbegin, const char *rend);

char *findSpaceReverse(char *rbegin, const char *rend);

int strcmp(const char *lhs, const char *rhs);

char *copy(const char *beginSource, const char *endSource, char *beginDestination);

char *copyIf(char *beginSource, const char *endSource, char *beginDestination, int (*f)(int));

char *copyIfReverse(char *rbeginSource, const char *rendSource,
                    char *beginDestination, int (*f)(int));

char *getEndOfString(char *s);

void getBagOfWords(BagOfWords *bag, char *s);

char *copyReverse(char *rbeginSource, const char *rendSource,
                  char *beginDestination);

#endif
