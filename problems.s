/**
 * CSSE 132
 * Rose-Hulman Institute of Technology
 * Computer Science and Software Engineering
 *
 *
 * NOTE: the .global and .type lines expose the functions to the
 * C code.
 *
 * This file contains code for exam 1 in the CSSE 132 class.
 * When you edit this file, be sure to put your name here!
 *
 * Edited by
 * NAME: Jason Hua
 */


/**
 *
 * (5 pts)
 *
 * tripleIt:
 *
 * Reads an integer from the memory address specified by r0, multiplies it by 3,
 * and stores the result back at the same memory address.
 *
 * HINT: you don't need to call any multiplication instructions. Just use add. Avoid
 * quadrupling by doubling it twice.
 *
 * For calibration, my solution uses 5 lines of code.
 *
 * Examples:
 * int num = 10;
 * tripleIt(&num);
 * // The variable num is 30 now;
 *
 * @parameter r0: memory address of the integer
 * @return: None
 */
.global tripleIt
.type tripleIt, %function
tripleIt:
    ldr r1, [r0]
    mov r2, r1
    add r1, r1, r2
    add r1, r1, r2
    str r1, [r0]
    bx lr





/**
 *
 * (7 pts)
 *
 * round2tens:
 *
 * Given an integer in the range 0 to 20 (inclusive) as the input, the function
 * rounds the number to the nearest multiple of 10. Namely, if the last digit is
 * less than 5, we will round it down; otherwise, we round it up.
 *
 * HINT: You can compare the number first with 5 and then with 15, to put the
 * number under one of the three cases: 0-4, 5-14, 15-20. For each case, it
 * returns 0, 10, 20 accordingly. To implement this, you need to compare the
 * number with 5 first then with 15, and create 2 (or 3) tags to branch/jump to
 * accordingly. Under each tag, you can assign r0 to the corresponding number
 * (0, 10, 20) and then call "bx lr" to return from that case.
 *
 * For calibration, my solution uses 12 lines of code.
 *
 * Examples:
 *
 * round2tens(3) rounds to 0
 *
 * round2tens(5) rounds to 10
 *
 * round2tens(7) rounds to 10
 *
 * round2tens(15) rounds to 20
 *
 * @parameter r0: an integer between 0 to 20
 * @return: rounded value to the nearest 10
 */
.global round2tens
.type round2tens, %function
round2tens:
    cmp r0, #5
    blt round2tens_less_than_5
    cmp r0, #15
    blt round2tens_less_than_15
    mov r0, #20
    bx lr

round2tens_less_than_5:
    mov r0, #0
    bx lr

round2tens_less_than_15:
    mov r0, #10
    bx lr



/**
 * (8 pts)
 *
 * get_entry_byIndex:
 *
 * Given an int array (each entry is 4 bytes) and an index, the function will
 * return the value of the entry given that index. For example, get_entry_byIndex(array, 4)
 * will return array[4]. Note that, given an array with n entries,
 * the index ranges from 0 to n-1.
 *
 * NOTE: To make things easier, you can safely assume the input index is
 * in-bound, i.e., less than the length of the array.
 *
 * NOTE: No multiplication instructions are allowed. You need to write a loop
 * to implement this.
 *
 *
 * For calibration, my solution uses 9 lines of code.
 *
 * Warning: You will use several labels/tags in this function. Make sure to avoid
 * naming duplicate labels/tags as used in the other functions.
 *
 *
 * @parameter r0: the address to an array
 * @parameter r1: an index (a non-negative number)
 * @return: the value of the entry with the specified index.
 */
.global get_entry_byIndex
.type get_entry_byIndex, %function
get_entry_byIndex:
    lsl r1, r1, #2
    add r0, r0, r1
    ldr r0, [r0]
    bx lr
