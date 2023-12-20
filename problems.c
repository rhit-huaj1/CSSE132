/**
 * CSSE 132
 * Rose-Hulman Institute of Technology
 * Computer Science and Software Engineering
 *
 * This file contains code for exam 1 in the CSSE 132 class.
 * When you edit this file, be sure to put your name here!
 *
 * Edited by
 * NAME: Jason Hua
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * (5 pts)
 *
 * getMedian():
 *
 * Given a SORTED int array, computes the arithmetic median of this array
 * (not mean/average).  If the number of items is even, the median will be
 * the average of the two numbers in the middle.
 *
 *
 * @params array - a pointer to the sorted array
 * @params len - the length of the sorted array
 * @return - the median of the array.
 */
int getMedian(int* array, int length) {
  if (length % 2 == 0) {

    return (array[length / 2 - 1] + array[length / 2]) / 2;
  } else {

    return array[length / 2];
  }
}
/**
 * (5 pts)
 *
 * CountROSE():
 *
 * Given a string (represented by a char pointer) as the input, the function
 * will count how many times the word, "ROSE", appeared in the string.  Again,
 * the word is "ROSE", in all capital case (not including the quotation marks).
 *
 * Note that you are NOT allowed to call any other library functions in this
 * function, like strncmp and etc.
 *
 * For calibration, my solution uses 10 lines of code.
 *
 * For example,
 * 1)
 * char* str = "ROSE is not Rose";
 * int ret = countROSE(str);
 * Then ret will be 1
 *
 * 2)
 * char* str = "Go RRRRROSE Go";
 * int ret = countROSE(str);
 * Then ret will be 1
 *
 * 3)
 * char* str = "--ROSEEROSE---";
 * int ret = countROSE(str);
 * Then ret will be 2
 *
 * 4)
 * char* str = "Rose-Hulman";
 * int ret = countROSE(str);
 * Then ret will be 0
 *
 * @params: str - a pointer to a string
 * @return: the number of appearances of the word ROSE
 */

int countROSE(char* str) {
  int count = 0;
  while (*str) {
    if (*str == 'R' && *(str + 1) == 'O' && *(str + 2) == 'S' && *(str + 3) == 'E') {
      count++;
      str += 4;
    } else {
      str++;
    }
  }
  return count;
}

/**
 * (7 pts)
 *
 * print_addition_result()
 *
 * Given an input string (represented by a char pointer) that describes the addition
 * between two ONE-digit numbers with the format "x + y" (e.g., "5 + 4"), the function
 * will calculate the addition result and print it with the specific format:
 * "x + y = z" where x and y are the numbers in the input, and z is the addition result.
 *
 * NOTE: You need to print a '\n' at the end of the result.
 *
 * HINT: You should parse the input string to extract the two one-digit numbers and perform
 * the addition. You can assume that the input string always follows the format exactly.
 *
 * Example:
 *    input_string -> "5 + 4"
 *    printout: "5 + 4 = 9" (followed by a new line \n)
 *
 *    input_string -> "3 + 8"
 *    printout: "3 + 8 = 11" (followed by a new line \n)
 *
 * You may not use sscanf or similar functions to extract the numbers.
 *
 * For calibration, my solution uses 4 lines of code.
 *
 * @param: input_string - a pointer that points to a string in the format "x + y".
 * @return: Do not return anything. Just print the addition result on the screen.
 */
void print_addition_result(char* input_string) {
  int x = input_string[0] - '0';
  int y = input_string[4] - '0';
  int result = x + y;
  printf("%d + %d = %d\n", x, y, result);
}

/**
 *
 * (8 pts)
 *
 * struct_setMax()
 */
struct data {
  int max;
  int array[10];
};
/**
 * Given the struct data defined above, the function will take a struct pointer
 * as the input. The pointer points to a struct instance, which has already been
 * created before calling this function. This function will
 * 1) find the maximum entry value in the array specified by the field "array",
 * 2) assign this maximum value to the field "max".
 *
 * HINT: the "array" size is hard-coded as 10.
 *
 * For calibration, my solution uses 6 lines of code.
 *
 * Example (pseudo code):
 *
 * struct myArray test_array;
 * test_array.array = {1,2,3,4,5,6,7,8,9,10}
 * struct_setMax(&test_array);
 *
 * // test_array.max is 10 now.
 *
 * @params: sp - a struct data pointer
 * @return: Nothing
 */
void struct_setMax(struct data* sp) {
  sp->max = sp->array[0];
  for (int i = 1; i < 10; i++) {
    if (sp->array[i] > sp->max) {
      sp->max = sp->array[i];
    }
  }
}
