#include <stdio.h>
#include "libs/data_structures/string_/string_.h"

void test_strLen() {
    char a[12] = "itIsWorking";
    assert(strlen_(a) == 11);
}

void test_find(){
    char a[12] = "itIsWorking";
    int ch = 87;
    assert(find(&a[0], &a[11], ch) == &a[4]);
}

void test_findNonSpace(){
    char a[12] = "      rking";

    assert(findNonSpace(&a[0]) == &a[6]);
}

void test_findSpace(){
    char a[12] = "itIsWo king";

    assert(findSpace(&a[0]) == &a[6]);
}
void test_findNonSpaceReverse(){
    char a[11] = {'i', 't','I','s','W','o','r',' ',' ',' ',' ' };

    assert(findNonSpaceReverse(&a[10], &a[-1]) == &a[6]);
}

void test_findSpaceReverse(){
    char a[11] = {'i', 't','I','s','W','o',' ','k','i','n','g' };

    assert(findSpaceReverse(&a[10], &a[-1]) == &a[6]);
}

void test_strcmp(){
    char a[12] = "itIsWorking";
    char b[12] = "itIsWorking";
    assert(strcmp(a, b) == 0);
}

void test_strcmp2(){
    char a[5] = "abcd";
    char b[3] = "ab";
    assert(strcmp(a, b) != 0);
}
int main() {
    test_strcmp2();
    test_findSpaceReverse();
    test_findNonSpaceReverse();
    test_strLen();
    test_find();
    test_findNonSpace();
    test_findSpace();
    test_strcmp();
    return 0;
}
