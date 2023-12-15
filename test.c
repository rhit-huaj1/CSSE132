/*
 * CSSE 132
 * Rose-Hulman Institute of Technology
 * Computer Science and Software Engineering
 *
 * test.c - Source file with tests for the homework.
 *          This is a file you need to hand in!
 *
 *          This file contains the tests you run to verify
 *          the code for homework 3.
 *
 * This file contains code used by labs in the CSSE 132 class.
 * If you edit this file for class, be sure to put your name(s) here!
 *
 * Edited by
 * NAMES:
 *
 */
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "unity/unity.h"

struct student {
    char name[12];
    int id;
};
// functions tested by this test harness
void print_odd(int* arr, int len);
int length(char* string);
int lengthNoArrays(char* string);
int upcaseVowels(char* tochange);
char* searchStructID(struct student* ptr, int len, int id);

// change this to zero if you want to allow fgets to work when the
// G_FGETS_INPUT buffer is empty.
#define FAIL_ON_EMPTY_FGETS_BUFFER 1

char* G_PRINTF_OUTPUT;
char* G_FGETS_INPUT;

// for forwarding non-wrapped i/o calls.
extern int __real_printf(const char* fmt, ...);

/**
 * Free and nullify any printf buffer to start over.  This is used for the
 * intercepted calls to printf.
 */
void resetPrintfBuffer() {
    //   __real_printf("Freeing %x\n", G_PRINTF_OUTPUT);
    if (G_PRINTF_OUTPUT) free(G_PRINTF_OUTPUT);
    G_PRINTF_OUTPUT = NULL;
}

/**
 * wrapper for capturing output from printf.
 */
int __wrap_printf(const char* fmt, ...) {
    int rv;
    va_list args;
    va_start(args, fmt);

    // allocate some space.
    char buf[1024];
    char* tmp = NULL;
    int prevLen = 0;
    int newLen = prevLen;
    memset(buf, 0, 1024 * sizeof(char));
    rv = vsprintf(buf, fmt, args);
    __real_printf(buf);

    // make sure the global buffer has space
    prevLen = G_PRINTF_OUTPUT ? strlen(G_PRINTF_OUTPUT) : 0;
    newLen = prevLen + strlen(buf);

    // the +1 is for a null terminator
    tmp = realloc(G_PRINTF_OUTPUT, (prevLen + newLen + 1) * sizeof(char));
    if (tmp == NULL) return 0;
    G_PRINTF_OUTPUT = tmp;

    // append the new string
    memcpy(G_PRINTF_OUTPUT + prevLen, buf, newLen + 1);

    va_end(args);
    return rv;
}

void setUp(void) {}
void tearDown(void) {}

void test_print_odd(void) {
    int arr[] = {0, 2, 4, 6, 8, -2, 1, 4, 3, 999};

    resetPrintfBuffer();
    print_odd(arr, 10);
    TEST_ASSERT_EQUAL_STRING_LEN("There are 3 odd numbers in the array.\n", G_PRINTF_OUTPUT, 38);

    resetPrintfBuffer();
    print_odd(arr + 8, 2);
    TEST_ASSERT_EQUAL_STRING_LEN("There are 2 odd numbers in the array.\n", G_PRINTF_OUTPUT, 38);

    resetPrintfBuffer();
    print_odd(arr, 5);
    TEST_ASSERT_EQUAL_STRING_LEN("No odd number is found.\n", G_PRINTF_OUTPUT, 25);
}

void test_length(void) {
    TEST_ASSERT_EQUAL_INT(0, length(""));
    TEST_ASSERT_EQUAL_INT(1, length("a"));
    TEST_ASSERT_EQUAL_INT(26, length("abcdefghijklmnopqrstuvwxyz"));
    TEST_ASSERT_EQUAL_INT(10, length("Whee! fun!"));
}

void test_lengthNoArrays(void) {
    TEST_ASSERT_EQUAL_INT(0, lengthNoArrays(""));
    TEST_ASSERT_EQUAL_INT(1, lengthNoArrays("a"));
    TEST_ASSERT_EQUAL_INT(26, lengthNoArrays("abcdefghijklmnopqrstuvwxyz"));
    TEST_ASSERT_EQUAL_INT(10, lengthNoArrays("Whee! fun!"));
}

void test_upcaseVowels(void) {
    char str0[] = "e";
    char str0_exp[] = "E";

    // printf(" ... testing \"%s\" ... \n", str0);
    TEST_ASSERT_EQUAL_INT(1, upcaseVowels(str0));
    TEST_ASSERT_EQUAL_STRING(str0_exp, str0);

    char str1[] = "aeiou";
    char str1_exp[] = "AEIOU";

    // printf(" ... testing \"%s\" ... \n", str1);
    TEST_ASSERT_EQUAL_INT(5, upcaseVowels(str1));
    TEST_ASSERT_EQUAL_STRING(str1_exp, str1);

    char str2[] = "Thr n vwls hr.";

    // printf(" ... testing \"%s\" ... \n", str2);
    TEST_ASSERT_EQUAL_INT(0, upcaseVowels(str2));
    TEST_ASSERT_EQUAL_STRING(str2, str2);

    char str3[] = "Hi there you silly.";
    char str3_exp[] = "HI thErE yOU sIlly.";

    // printf(" ... testing \"%s\" ... \n", str3);
    TEST_ASSERT_EQUAL_INT(6, upcaseVowels(str3));
    TEST_ASSERT_EQUAL_STRING(str3_exp, str3);
}

void test_searchStructID(void) {
    struct student array[10];
    char* names[12];
    char* sptr;
    int values[10] = {12, 123, 8912, 3, 40, 10, INT32_MAX - 1,
                      INT32_MAX - 3, 321, 412};
    for (int i = 0; i < 10; i++) {
        char* ptr = (char*)(array + i);
        sprintf(ptr, "name%d", i);
        memcpy(ptr + 12, values + i, sizeof(int));
    }

    sptr = searchStructID(array, 10, values[4]);
    TEST_ASSERT_EQUAL_STRING_LEN(array + 4, sptr, 6);

    sptr = searchStructID(array, 10, values[9]);
    TEST_ASSERT_EQUAL_STRING_LEN(array + 9, sptr, 6);
}

int main(int argc, char** argv) {
    UnityBegin("HW3 test.c");

    RUN_TEST(test_print_odd);
    RUN_TEST(test_length);
    RUN_TEST(test_lengthNoArrays);
    RUN_TEST(test_upcaseVowels);
    RUN_TEST(test_searchStructID);

    UnityEnd();
}
