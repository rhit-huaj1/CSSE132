/**
 * CSSE 132
 * Rose-Hulman Institute of Technology
 * Computer Science and Software Engineering
 *
 * problems.s: this file is where you implement your solutions
 *             for the homework assignment in ARM assembly.
 *
 * NOTE: the .global and .type lines expose the functions to your 
 * C programs (including the tests).
 *
 * This file contains code for homework in the CSSE 132 class.
 * When you edit this file for class, be sure to put your name here!
 *
 * Edited by
 * NAME: Jason Hua
 */

/**
 swap
 * This function takes two addresses as inputs and it swaps the values stored in
 * these two places. 
 * 
 * @param r0: first arg, address for x
 * @param r1: second arg, address of y
 * The function swap the values of x and y
 */
.global swap
.type swap, %function
swap:
  /* TODO: finish this procedure here. */

ldr r2, [r0]

ldr r3, [r1]

str r2, [r1]

str r3, [r0]

  /* return from this procedure (jump to lr) */
  bx lr


/**
 mult
 * This function multiplies two arguments and returns the result.
 * To make the problem easier, you can assume the second argument is always a
 * non-negative number.
 * Remember that the return value is placed in r0 before returning.
 * 
 * NOTE: You are not allowed to use any multiplication instructions in ARM
 * 
 * @param r0: first arg, x
 * @param r1: second arg, y (a non-negative number)
 * @returns the multiplication of the two
 */
.global mult
.type mult, %function
mult:
  /* TODO: finish this procedure here. */

mov r2, #0

cmp r1, #0

beq .ENDMULT


.LOOP:

add r2,r2,r0
subs r1,r1,#1

cmp r1, #0

bne .LOOP

.ENDMULT:

mov r0,r2


  /* return from this procedure (jump to lr) */
  bx lr


/**
if_zero
* The function will iterate through an array to check if the array include any
* zero values. If yes, it will return 1; Otherwise, it returns 0.

* The functions takes two input arguments: 1) the address of the first item in
* the array, 2) the length of the array, i.e., number of items in the array.

* Each item is 4-byte in this array. The index starts from 0.

* Note: When writing loop(s), avoid using duplicated TAGS.

 * @param r0: first arg, address of an array
 * @param r1: second arg, length of the array (a positive number)
 * @returns 1 if the array includes at least a zero
 *          0 if no zero is found
 */

.global if_zero
.type if_zero, %function
if_zero:
  /* Your code starts here. */
 
mov r2, #0
mov r3, #0

.LOOPS:

cmp r2,r1
beq .ENDLOOP

ldr r4, [r0,r2, LSL #2]

cmp r4, #0
beq .ZERO_FOUND

add r2,r2,#1
b .LOOPS

.ZERO_FOUND:
mov r3, #1
b .ENDLOOP

.ENDLOOP:
mov r0,r3





  /* Your code ends here. */
  bx lr



/**
 find_zero
 * The function finds first item with zero value in an array and return its
 * index. It takes two input arguments: the first argument is the address of the
 * first item in the array, the second argument is the length of the array,
 * i.e., number of items in the array. 
 * The function returns the index of the first zero in the array.

 * Each item is 4-byte in this array. The index starts from 0.

 * To make the problem easier, you can assume the given array will always
 * include at least one zero.

 * Remember that the return value is placed in r0 before returning.
 * 
 * Note: you may need to use TAGs to write loop(s) in both this function and the
 * previous function. Make sure to name different tags as they are like global
 * variables that can not be duplicated.
 
 * @param r0: first arg, address of an array
 * @param r1: second arg, length of the array (a positive number)
 * @returns the index of the first zero item
 */
.global find_zero
.type find_zero, %function
find_zero:
  /* TODO: finish this procedure here. */

mov r2, #0

.LOOP4:

ldr r3,[r0,r2,LSL #2]

cmp r3, #0
beq .FIND_ZERO

add r2,r2,#1
b .LOOP4

.FIND_ZERO:
mov r0,r2

  /* return from this procedure (jump to lr) */
  bx lr
