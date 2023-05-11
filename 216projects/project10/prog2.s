#
# David Perez
# dperez7
# 117915402
# CMSC216 (0107) Project 10 prog2.s
#
# I pledge on my honor that I have not given or received any unauthorized
# assistance on this assignment.
#
# Converts prog2.c to MIPS R2000 assembly code, which reads in two integer 
# values from the user, number and base, and then calls the function num_digits 
# with these values as arguments. The num_digits function calculates the number 
# of digits in number when it is expressed in the given base, and returns this 
# value. The main function then prints out this value.
#

.data
number: .word 0
base: .word 0
result: .word 0
newline: .asciiz "\n"

.text

main:
    li $sp, 0x7ffffffc  # set stack pointer to top of stack

    li $v0, 5   # scanf("%d", &number)
    syscall
    sw $v0, number

    li $v0, 5   # scanf("%d", &base)
    syscall
    sw $v0, base

    lw $t0, number
    sw $t0, ($sp)
    sub $sp, $sp, 4    # push number onto stack

    lw $t1, base
    sw $t1, ($sp)
    sub $sp, $sp, 4   # push base onto stack

    jal num_digits  # num_digits(number, base)
    add $sp, $sp, 8  # pop number and base off stack

    sw $v0, result

    # print result
    li $v0, 1
    lw $a0, result
    syscall
    la $a0, newline
    li $v0, 4
    syscall

    # exit
    li $v0, 10
    syscall

num_digits:
    # prologue
    sub $sp, $sp, 12    # set $sp
    sw $ra, 12($sp) # save $ra
    sw $fp, 8($sp)  # save $fp
    add $fp, $sp, 12    # set new $fp

    li $t0, 0   # set result to 0
    sw $t0, 4($sp) # store result

    lw $t1, 8($fp)  # store n argument
    lw $t2, 4($fp)  # store base argument

    blez $t2, base_error    # check if base is negative
    beqz $t1, n_zero     # check if n is zero
    bltz $t1, n_negative    # check if n is negative

    j count_digits


# loop to count digits
count_digits:

    # check is base is 1
    li $t4, 1
    beq $t2, $t4, base_one

    loop:
        lw $t1, 8($fp)
        beqz $t1, exit_num_digits # exit if n is zero

        add $t0, $t0, 1 # increment result
        sw $t0, 4($sp)  # store result

        div $t1, $t1, $t2   # n = n / base
        sw $t1, 8($fp)  # store n
        j loop  # repeat loop

base_error:
    li $t0, -1  # return -1 if base is negative
    sw $t0, 4($sp)   # store result
    j exit_num_digits

base_one:
    lw $t0, 8($sp)
    sw $t0, 4($sp)
    j exit_num_digits

n_zero:
    li $t0, 1   # return 1 if n is zero
    sw $t0, 4($sp)
    j exit_num_digits

n_negative:
    neg $t1, $t1    # n = -n
    sw $t1, 8($fp)
    j count_digits

exit_num_digits:
    move $v0, $t0

    # epilogue
    lw $ra, 12($sp)
    lw $fp, 8($sp)
    add $sp, $sp, 12
    jr $ra  # return to main