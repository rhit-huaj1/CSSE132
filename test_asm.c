/*
 * CSSE 132
 * Rose-Hulman Institute of Technology
 * Computer Science and Software Engineering
 *
 * test_asm.c - Source file with tests for the homework.
 *          This is a file you need to hand in!
 *
 *          This file contains the tests you run to verify
 *          the Assembly code for homework 3.
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

// functions in asm files
int sumArray(int* arr, int size);
int max(int* arr, int size);

void setUp(void) {}
void tearDown(void) {}

void test_sumArray(void) {
    int a1[4];
    a1[0] = 1;
    a1[1] = 20;
    a1[2] = 343;
    a1[3] = 47;

    TEST_ASSERT_EQUAL(1, sumArray(a1, 1));
    TEST_ASSERT_EQUAL(411, sumArray(a1, 4));
}


void test_max(void) {
  int ints[10] = {0, 16, -32, 32765, 12, -2147483645, 18, 0, 16, 56};
  TEST_ASSERT_EQUAL_INT(0, max(ints, 1));
  TEST_ASSERT_EQUAL_INT(32765, max(ints, 10));
  TEST_ASSERT_EQUAL_INT(-2147483645, max(ints+5, 1));
  TEST_ASSERT_EQUAL_INT(56, max(ints+4, 6));
}

int main(int argc, char** argv) {
    UnityBegin("HW3 test_asm.c");

    RUN_TEST(test_sumArray);
    RUN_TEST(test_max);

    UnityEnd();
}
