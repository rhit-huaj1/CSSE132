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
 * (10 points)
 * 
 * This function sums an array.
 *
 * You'll need a loop for this, and will probably want to
 * use a few registers (r0-r5) as temporary storage.
 *
 * 
 * @param r0: the base address of the array (pointer)
 * @param r1: the number of elements in the array
 * @returns the sum of the elements in the array
 */
.global sumArray
.type sumArray, %function
sumArray:
  /* Your code goes here */
  
    MOV r2, #0
    MOV r3, r1

    loop_start:
        CMP r3, #0
        BEQ end_loop
        LDR r4, [r0], #4
        ADD r2, r2, r4
        SUB r3, r3, #1
        B loop_start

    end_loop:
    MOV r0, r2


  /* Your code ends here */
  /* return from this procedure (jump to lr) */
  bx lr

/**
 * (10 points)
 * 
 * max()
 *
 * This function will find and return the maximum in the array.
 *
 * When using TAG for branching, don't duplicate the tag names with the previous
 * tags.
 * 
 * @param r0: the base address of the array (pointer)
 * @param r1: the number of elements in the array (a positive number)
 * @returns: the value of the maximum
 */
.global max
.type max, %function
max:
  /* Your code goes here */
CMP r1, #0
    BEQ end_max

    LDR r2, [r0], #4
    loop_start_max:
        CMP r1, #1
        BEQ end_max

        LDR r3, [r0], #4
        CMP r3, r2
        MOVGT r2, r3

        SUB r1, r1, #1
        B loop_start_max

    end_max:
    MOV r0, r2
  /* Your code ends here */
  /* return from this procedure (jump to lr) */
  bx lr
