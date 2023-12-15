/*
 * CSSE 132
 * Rose-Hulman Institute of Technology
 * Computer Science and Software Engineering
 *
 * problems.c: this file is where you implement your solutions
 *             for the homework assignment.
 *
 * This file contains code for homework in the CSSE 132 class.
 * When you edit this file for class, be sure to put your name here!
 *
 * Edited by
 * NAME: Jason Hua
 *
 */
#include <stdio.h>
#include <stdlib.h>

/**
 * (6 pts)
 * 
 * Given an int array, this function will count the number of odd numbers in the array.
 * If this number is not zero, the function will print out the message as
 * "There are N odd numbers in the array.\n" (Note: N is the real count, \n is
 * the new line character)
 * If the count is zero, the function will print out a different message saying
 * "No odd number is found.\n"
 *
 * Note that for testing purpose, the printf function won't really print on the
 * screen. It will print into a buffer for comparison. 
 *
 * @param arr - an array name (the address to the begining of an array)
 * @param len - the length of the array
 * @returns No return, instead, print a message acccordingly
 */
void print_odd(int* arr, int len) {
    /* Your code goes here */
   int oddCount = 0;

    for (int i = 0; i < len; i++) {
        if (arr[i] % 2 != 0) {
            oddCount++;
        }
    }

    if (oddCount > 0) {
        printf("There are %d odd numbers in the array.\n", oddCount);
    } else {
        printf("No odd number is found.\n");
    }
    /* Your code ends here */
}


/**
 * (7 pts)
 * 
 * This function counts the number of characters in the given string.
 *
 * For example: length("Thing") returns 5.
 * For this function, You MUST use the array brackets: [ and ].
 * You MUST NOT call other functions from length().
 *
 * @param str - a string to measure
 * @returns the number of characters, excluding the null terminator.
 */
int length(char* string) {
  /* Your code goes here */

    int count = 0;

    while (string[count] != '\0') {
        count++;
    }

    return count;

  /* Your code ends here */
}

/**
 * (7 pts)
 * 
 * This function is the same as length() but doesn't use array operators.
 *
 * For this function, You MUST NOT use the square brackets: [ or ].
 * You MUST NOT call other functions from lengthNoArrays().
 *
 * @param str - a string to measure
 * @returns the number of characters, excluding the null terminator.
 */
int lengthNoArrays(char* string) {
  /* Your code goes here */
   int count = 0;

    while (*string != '\0') {
        count++;
        string++;
    }

    return count;
  /* Your code ends here */
}

/**
 * (10 pts)
 * 
 * This function iterates through a string and changes any lowercase vowels
 * (a, e, i, o, u) to their uppercase equivalents.
 *
 * This function modifies the string (it does not make a copy).
 * You can assume the string is properly null-terminated.
 * Write this function yourself using a for loop.
 *
 * @param tochange - the string to change
 * @return the number of vowels up-cased.
 */
int upcaseVowels(char* tochange) {
  /* Your code goes here */
    int vowelCount = 0;

    for (int i = 0; tochange[i] != '\0'; i++) {
        switch (tochange[i]) {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
                tochange[i] -= ('a' - 'A'); // Convert to uppercase
                vowelCount++;
                break;
        }
    }

    return vowelCount;
  /* Your code ends here */
}

struct student {
    char name[12];
    int id;
};
/**
 *
 * (10 pts)
 *
 * searchStructID():
 *
 * Given an array of struct student (the struct is defined as defined above),
 * the function will find the particular struct instance with a specific ID,
 * then return a char pointer to the name field of that struct instance.
 *
 * The function takes two input arguments: 1) a struct student array (represented
 * by a struct student pointer to the first item), 2) the length of this array,
 * and 3) the ID (an int) to look up.
 *
 * Note that each item in this array is a struct student instance, NOT a pointer to
 * struct student.
 *
 * @params: array - a struct student array (represented by a struct student
 *                  pointer to the first item)
 * @params: length - the length of the array (a positive number)
 * @params: id - an int ID to look up (guaranteed existed)
 * @return: - the pointer to the name of the struct with that ID.
 *
 */

char* searchStructID(struct student* array, int length, int id){
    /* Your code goes here */
  for (int i = 0; i < length; i++) {
        if (array[i].id == id) {
            return array[i].name;
        }
    }

    return NULL;
    /* Your code ends here */
}


/** DO NOT create a main function in this file or the test executable won't work. **/
